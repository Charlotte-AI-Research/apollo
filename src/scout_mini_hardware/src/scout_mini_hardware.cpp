// Copyright (c) 2023, ROAS Inc.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include <iostream>
#include <bitset>

#include "scout_mini_hardware/scout_mini_hardware.hpp"

namespace scout_mini_hardware
{
hardware_interface::CallbackReturn ScoutMiniHardware::on_init(const hardware_interface::HardwareInfo& info)
{
  if (hardware_interface::SystemInterface::on_init(info) != CallbackReturn::SUCCESS)
  {
    return hardware_interface::CallbackReturn::ERROR;
  }

  interface_ = info_.hardware_parameters["interface"];
  wheel_radius_ = stod(info_.hardware_parameters["wheel_radius"]);
  wheel_separation_ = stod(info_.hardware_parameters["wheel_separation"]);
  timeout_ns_ = std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::duration<double>(0.01));

  hw_commands_.resize(info_.joints.size(), std::numeric_limits<double>::quiet_NaN());
  hw_positions_.resize(info_.joints.size(), std::numeric_limits<double>::quiet_NaN());
  hw_velocities_.resize(info_.joints.size(), std::numeric_limits<double>::quiet_NaN());
  hw_efforts_.resize(info_.joints.size(), std::numeric_limits<double>::quiet_NaN());

  for (const hardware_interface::ComponentInfo& joint : info_.joints)
  {
    if (joint.command_interfaces.size() != 1)
    {
      RCLCPP_FATAL(rclcpp::get_logger("ScoutMiniHardware"), "Joint '%s' has %zu command interfaces found. 1 expected.",
                   joint.name.c_str(), joint.command_interfaces.size());
      return hardware_interface::CallbackReturn::ERROR;
    }

    if (joint.command_interfaces[0].name != hardware_interface::HW_IF_VELOCITY)
    {
      RCLCPP_FATAL(rclcpp::get_logger("ScoutMiniHardware"),
                   "Joint '%s' have %s command interfaces found. '%s' expected.", joint.name.c_str(),
                   joint.command_interfaces[0].name.c_str(), hardware_interface::HW_IF_VELOCITY);
      return hardware_interface::CallbackReturn::ERROR;
    }

    if (joint.state_interfaces.size() != 3)
    {
      RCLCPP_FATAL(rclcpp::get_logger("ScoutMiniHardware"), "Joint '%s' has %zu state interface. 3 expected.",
                   joint.name.c_str(), joint.state_interfaces.size());
      return hardware_interface::CallbackReturn::ERROR;
    }

    if (joint.state_interfaces[0].name != hardware_interface::HW_IF_POSITION)
    {
      RCLCPP_FATAL(rclcpp::get_logger("ScoutMiniHardware"),
                   "Joint '%s' have '%s' as first state interface. '%s' expected.", joint.name.c_str(),
                   joint.state_interfaces[0].name.c_str(), hardware_interface::HW_IF_POSITION);
      return hardware_interface::CallbackReturn::ERROR;
    }

    if (joint.state_interfaces[1].name != hardware_interface::HW_IF_VELOCITY)
    {
      RCLCPP_FATAL(rclcpp::get_logger("ScoutMiniHardware"),
                   "Joint '%s' have '%s' as second state interface. '%s' expected.", joint.name.c_str(),
                   joint.state_interfaces[1].name.c_str(), hardware_interface::HW_IF_VELOCITY);
      return hardware_interface::CallbackReturn::ERROR;
    }
  }

  // Initialize Node
  node_ = std::make_shared<rclcpp::Node>("scout_mini_hardawre_node");
  pub_driver_state_ = node_->create_publisher<scout_mini_msgs::msg::DriverState>("scout_mini/driver_state", 1);
  pub_light_state_ = node_->create_publisher<scout_mini_msgs::msg::LightState>("scout_mini/light_state", 1);
  pub_motor_state_ = node_->create_publisher<scout_mini_msgs::msg::MotorState>("scout_mini/motor_state", 1);
  pub_robot_state_ = node_->create_publisher<scout_mini_msgs::msg::RobotState>("scout_mini/robot_state", 1);
  rp_driver_state_ =
      std::make_shared<realtime_tools::RealtimePublisher<scout_mini_msgs::msg::DriverState>>(pub_driver_state_);
  rp_light_state_ =
      std::make_shared<realtime_tools::RealtimePublisher<scout_mini_msgs::msg::LightState>>(pub_light_state_);
  rp_motor_state_ =
      std::make_shared<realtime_tools::RealtimePublisher<scout_mini_msgs::msg::MotorState>>(pub_motor_state_);
  rp_robot_state_ =
      std::make_shared<realtime_tools::RealtimePublisher<scout_mini_msgs::msg::RobotState>>(pub_robot_state_);
  sub_led_cmd_ = node_->create_subscription<scout_mini_msgs::msg::LightCommand>(
      "scout_mini/light/command", rclcpp::QoS(10),
      [=](const scout_mini_msgs::msg::LightCommand::SharedPtr msg) { lightCmdCallback(msg); });

  // Initialize SocketCan
  try
  {
    receiver_ = std::make_unique<drivers::socketcan::SocketCanReceiver>(interface_, false);
    receiver_->SetCanFilters(drivers::socketcan::SocketCanReceiver::CanFilterList("0:0"));
  }
  catch (const std::exception& ex)
  {
    RCLCPP_FATAL(rclcpp::get_logger("ScoutMiniHardware"), "Error opening CAN receiver: %s - %s", interface_.c_str(),
                 ex.what());
    return hardware_interface::CallbackReturn::ERROR;
  }

  try
  {
    sender_ = std::make_unique<drivers::socketcan::SocketCanSender>(interface_, false);
  }
  catch (const std::exception& ex)
  {
    RCLCPP_FATAL(rclcpp::get_logger("ScoutMiniHardware"), "Error opening CAN sender: %s - %s", interface_.c_str(),
                 ex.what());
    return hardware_interface::CallbackReturn::ERROR;
  }

  receiver_thread_ = std::make_unique<std::thread>(&ScoutMiniHardware::receive, this);

  return hardware_interface::CallbackReturn::SUCCESS;
}

std::vector<hardware_interface::StateInterface> ScoutMiniHardware::export_state_interfaces()
{
  std::vector<hardware_interface::StateInterface> state_interfaces;
  for (std::size_t i = 0; i < info_.joints.size(); i++)
  {
    state_interfaces.emplace_back(hardware_interface::StateInterface(
        info_.joints[i].name, hardware_interface::HW_IF_POSITION, &hw_positions_[i]));
    state_interfaces.emplace_back(hardware_interface::StateInterface(
        info_.joints[i].name, hardware_interface::HW_IF_VELOCITY, &hw_velocities_[i]));
    state_interfaces.emplace_back(
        hardware_interface::StateInterface(info_.joints[i].name, hardware_interface::HW_IF_EFFORT, &hw_efforts_[i]));
  }

  return state_interfaces;
}

std::vector<hardware_interface::CommandInterface> ScoutMiniHardware::export_command_interfaces()
{
  std::vector<hardware_interface::CommandInterface> command_interfaces;
  for (std::size_t i = 0; i < info_.joints.size(); i++)
  {
    command_interfaces.emplace_back(hardware_interface::CommandInterface(
        info_.joints[i].name, hardware_interface::HW_IF_VELOCITY, &hw_commands_[i]));
  }

  return command_interfaces;
}

hardware_interface::CallbackReturn ScoutMiniHardware::on_activate(const rclcpp_lifecycle::State& /*previous_state*/)
{
  RCLCPP_INFO(rclcpp::get_logger("ScoutMiniHardware"), "Activating ...please wait...");

  for (std::size_t i = 0; i < hw_positions_.size(); i++)
  {
    if (std::isnan(hw_positions_[i]))
    {
      hw_commands_[i] = 0.0;
      hw_positions_[i] = 0.0;
      hw_velocities_[i] = 0.0;
      hw_efforts_[i] = 0.0;
    }
  }

  rp_light_state_->msg_.mode = "NONE";
  rp_motor_state_->msg_.name = { "front_left_wheel_joint", "front_right_wheel_joint", "rear_left_wheel_joint",
                                 "rear_right_wheel_joint" };
  rp_robot_state_->msg_.robot = "scout_mini";

  can_msgs::msg::Frame enable_msg;
  enable_msg.data[0] = 0x01;
  try
  {
    sender_->send(
        enable_msg.data.data(), 0x08,
        drivers::socketcan::CanId(0x421, 0, drivers::socketcan::FrameType::DATA, drivers::socketcan::StandardFrame),
        timeout_ns_);
  }
  catch (const std::exception& ex)
  {
    RCLCPP_WARN_THROTTLE(node_->get_logger(), *node_->get_clock(), 1000, "Error sending enable message: %s - %s",
                         interface_.c_str(), ex.what());
    return hardware_interface::CallbackReturn::ERROR;
  }

  RCLCPP_INFO(rclcpp::get_logger("ScoutMiniHardware"), "System Successfully activated!");
  return hardware_interface::CallbackReturn::SUCCESS;
}

hardware_interface::CallbackReturn ScoutMiniHardware::on_deactivate(const rclcpp_lifecycle::State& /*previous_state*/)
{
  RCLCPP_INFO(rclcpp::get_logger("ScoutMiniHardware"), "Deactivating ...please wait...");

  can_msgs::msg::Frame disable_msg;
  disable_msg.data[0] = 0x00;
  try
  {
    sender_->send(
        disable_msg.data.data(), 0x08,
        drivers::socketcan::CanId(0x421, 0, drivers::socketcan::FrameType::DATA, drivers::socketcan::StandardFrame),
        timeout_ns_);
  }
  catch (const std::exception& ex)
  {
    RCLCPP_WARN_THROTTLE(node_->get_logger(), *node_->get_clock(), 1000, "Error sending disable message: %s - %s",
                         interface_.c_str(), ex.what());
    return hardware_interface::CallbackReturn::ERROR;
  }

  RCLCPP_INFO(rclcpp::get_logger("ScoutMiniHardware"), "Successfully deactivated!");
  return hardware_interface::CallbackReturn::SUCCESS;
}

hardware_interface::return_type ScoutMiniHardware::read(const rclcpp::Time& /*time*/, const rclcpp::Duration& period)
{
  for (std::size_t i = 0; i < hw_positions_.size(); i++)
  {
    rp_motor_state_->msg_.position[i] += rp_motor_state_->msg_.velocity[i] * period.seconds();
    hw_positions_[i] = rp_motor_state_->msg_.position[i];
    hw_velocities_[i] = rp_motor_state_->msg_.velocity[i];
    hw_efforts_[i] = rp_motor_state_->msg_.current[i];
  }

  publish();

  return hardware_interface::return_type::OK;
}

hardware_interface::return_type ScoutMiniHardware::write(const rclcpp::Time& /*time*/,
                                                         const rclcpp::Duration& /*period*/)
{
  const double left_vel = (hw_commands_[0] + hw_commands_[1]) * 0.5 * wheel_radius_;
  const double right_vel = (hw_commands_[2] + hw_commands_[3]) * 0.5 * wheel_radius_;

  const double linear = (left_vel + right_vel) * 0.5;
  const double angular = (right_vel - left_vel) / wheel_separation_;

  std::stringstream ss_linear;
  ss_linear << std::hex << static_cast<int16_t>(linear * 1000.0);
  uint16_t cmd_linear = static_cast<uint16_t>(stoi(ss_linear.str(), nullptr, 16));

  std::stringstream ss_angular;
  ss_angular << std::hex << static_cast<int16_t>(angular * 1000.0);
  uint16_t cmd_angular = static_cast<uint16_t>(stoi(ss_angular.str(), nullptr, 16));

  drivers::socketcan::CanId send_id =
      drivers::socketcan::CanId(0x111, 0, drivers::socketcan::FrameType::DATA, drivers::socketcan::StandardFrame);
  can_msgs::msg::Frame send_msg;
  send_msg.data[0] = cmd_linear / 0x100;
  send_msg.data[1] = cmd_linear % 0x100;
  send_msg.data[2] = cmd_angular / 0x100;
  send_msg.data[3] = cmd_angular % 0x100;

  try
  {
    sender_->send(send_msg.data.data(), 0x08, send_id, timeout_ns_);
  }
  catch (const std::exception& ex)
  {
    RCLCPP_WARN_THROTTLE(node_->get_logger(), *node_->get_clock(), 1000, "Error sending command message: %s - %s",
                         interface_.c_str(), ex.what());
    return hardware_interface::return_type::ERROR;
  }

  return hardware_interface::return_type::OK;
}

void ScoutMiniHardware::receive()
{
  drivers::socketcan::CanId receive_id{};
  can_msgs::msg::Frame receive_msg(rosidl_runtime_cpp::MessageInitialization::ZERO);

  while (rclcpp::ok())
  {
    rclcpp::spin_some(node_);

    try
    {
      receive_id = receiver_->receive(receive_msg.data.data(), interval_ns_);
      uint8_t data[8];
      for (size_t i = 0; i < 8; i++)
        data[i] = receive_msg.data[i];

      switch (receive_id.identifier())
      {
        case 0x211:
          robotState(data);
          break;
        case 0x251:  // front right motor
          motorState(2, data);
          break;
        case 0x252:  // front left motor
          motorState(0, data);
          break;
        case 0x253:  // rear left motor
          motorState(1, data);
          break;
        case 0x254:  // rear right motor
          motorState(3, data);
          break;
        case 0x261:  // front right motor
          driverState(2, data);
          break;
        case 0x262:  // front left motor
          driverState(0, data);
          break;
        case 0x263:  // rear left motor
          driverState(1, data);
          break;
        case 0x264:  // rear right motor
          driverState(3, data);
          break;
        case 0x231:  // light state
          lightState(data);
          break;
        case 0x221:  // velocity
          velocity(data);
          break;
        // case 0x311:  // position
        //   position(data);
        //   break;
        default:
          break;
      }
    }
    catch (const std::exception& ex)
    {
      // RCLCPP_WARN_THROTTLE(node_->get_logger(), *node_->get_clock(), 1000, "Error receiving CAN message: %s - %s",
      //                      interface_.c_str(), ex.what());
      continue;
    }
  }
}

void ScoutMiniHardware::robotState(uint8_t* data)
{
  if (data[0] == 0x00)
    rp_robot_state_->msg_.normal_state = true;
  else if (data[0] == 0x02)
    rp_robot_state_->msg_.normal_state = false;

  if (data[1] == 0x00)
    rp_robot_state_->msg_.control_mode = "IDLE";
  else if (data[1] == 0x01)
    rp_robot_state_->msg_.control_mode = "CAN";
  else if (data[1] == 0x03)
    rp_robot_state_->msg_.control_mode = "REMOTE";
  else
    rp_robot_state_->msg_.control_mode = "NONE";

  rp_robot_state_->msg_.battery_voltage =
      static_cast<int16_t>((static_cast<uint16_t>(data[2]) << 8) | static_cast<uint16_t>(data[3])) / 10.0;

  rp_robot_state_->msg_.fault_state.battery_under_voltage_failure = std::bitset<8>(data[5])[0];
  rp_robot_state_->msg_.fault_state.battery_under_voltage_alarm = std::bitset<8>(data[5])[1];
  rp_robot_state_->msg_.fault_state.loss_remote_control = std::bitset<8>(data[5])[2];

  rp_driver_state_->msg_.communication_failure[2] = std::bitset<8>(data[5])[3];
  rp_driver_state_->msg_.communication_failure[0] = std::bitset<8>(data[5])[4];
  rp_driver_state_->msg_.communication_failure[1] = std::bitset<8>(data[5])[5];
  rp_driver_state_->msg_.communication_failure[3] = std::bitset<8>(data[5])[6];
}

void ScoutMiniHardware::motorState(size_t index, uint8_t* data)
{
  if (index < 4)
  {
    rp_motor_state_->msg_.current[index] =
        ((static_cast<uint16_t>(data[2]) << 8) | static_cast<uint16_t>(data[3])) / 10.0;
  }
}

void ScoutMiniHardware::driverState(size_t index, uint8_t* data)
{
  if (index < 4)
  {
    rp_motor_state_->msg_.temperature[index] = static_cast<int16_t>(data[4]);
    rp_driver_state_->msg_.driver_voltage[index] =
        ((static_cast<uint16_t>(data[0]) << 8) | static_cast<uint16_t>(data[1])) / 10.0;
    rp_driver_state_->msg_.driver_temperature[index] =
        static_cast<int16_t>((static_cast<uint16_t>(data[2]) << 8) | static_cast<uint16_t>(data[3]));
    rp_driver_state_->msg_.low_supply_voltage[index] = std::bitset<8>(data[5])[0];
    rp_driver_state_->msg_.motor_over_temperature[index] = std::bitset<8>(data[5])[1];
    rp_driver_state_->msg_.driver_over_current[index] = std::bitset<8>(data[5])[2];
    rp_driver_state_->msg_.driver_over_temperature[index] = std::bitset<8>(data[5])[3];
  }
}

void ScoutMiniHardware::lightState(uint8_t* data)
{
  rp_light_state_->msg_.control_enable = data[0];

  switch (data[1])
  {
    case 0x00:
      rp_light_state_->msg_.mode = "NC";
      break;
    case 0x01:
      rp_light_state_->msg_.mode = "NO";
      break;
    case 0x02:
      rp_light_state_->msg_.mode = "BL";
      break;
    case 0x03:
      rp_light_state_->msg_.mode = "CUSTOM";
      break;
    default:
      rp_light_state_->msg_.mode = "NONE";
      break;
  }
  rp_light_state_->msg_.brightness = data[2];
}

void ScoutMiniHardware::velocity(uint8_t* data)
{
  double linear = static_cast<int16_t>((static_cast<uint16_t>(data[0]) << 8) | static_cast<uint16_t>(data[1])) / 1000.0;
  double angular =
      static_cast<int16_t>((static_cast<uint16_t>(data[2]) << 8) | static_cast<uint16_t>(data[3])) / 1000.0;

  double left = (linear - (angular * wheel_separation_ * 0.5)) / wheel_radius_;
  double right = (linear + (angular * wheel_separation_ * 0.5)) / wheel_radius_;

  rp_motor_state_->msg_.velocity[0] = left;
  rp_motor_state_->msg_.velocity[1] = left;
  rp_motor_state_->msg_.velocity[2] = right;
  rp_motor_state_->msg_.velocity[3] = right;
}

void ScoutMiniHardware::position(uint8_t* data)
{
  int32_t left = static_cast<int32_t>((static_cast<uint32_t>(data[0]) << 24) | (static_cast<uint32_t>(data[1]) << 16) |
                                      (static_cast<uint32_t>(data[2]) << 8) | static_cast<uint32_t>(data[3]));
  int32_t right = static_cast<int32_t>((static_cast<uint32_t>(data[4]) << 24) | (static_cast<uint32_t>(data[5]) << 16) |
                                       (static_cast<uint32_t>(data[6]) << 8) | static_cast<uint32_t>(data[7]));

  rp_motor_state_->msg_.position[0] = left / 1000.0 / wheel_radius_;
  rp_motor_state_->msg_.position[1] = left / 1000.0 / wheel_radius_;
  rp_motor_state_->msg_.position[2] = right / 1000.0 / wheel_radius_;
  rp_motor_state_->msg_.position[3] = right / 1000.0 / wheel_radius_;
}

void ScoutMiniHardware::publish()
{
  if (rp_driver_state_->trylock())
  {
    rp_driver_state_->msg_.header.stamp = rclcpp::Clock().now();
    rp_driver_state_->unlockAndPublish();
  }

  if (rp_light_state_->trylock())
  {
    rp_light_state_->msg_.header.stamp = rclcpp::Clock().now();
    rp_light_state_->unlockAndPublish();
  }

  if (rp_motor_state_->trylock())
  {
    rp_motor_state_->msg_.header.stamp = rclcpp::Clock().now();
    rp_motor_state_->unlockAndPublish();
  }

  if (rp_robot_state_->trylock())
  {
    rp_robot_state_->msg_.header.stamp = rclcpp::Clock().now();
    rp_robot_state_->unlockAndPublish();
  }
}

void ScoutMiniHardware::lightCmdCallback(const scout_mini_msgs::msg::LightCommand::SharedPtr& msg)
{
  drivers::socketcan::CanId send_id =
      drivers::socketcan::CanId(0x121, 0, drivers::socketcan::FrameType::DATA, drivers::socketcan::StandardFrame);
  can_msgs::msg::Frame send_msg;
  send_msg.data[0] = 0x01;
  send_msg.data[1] = msg->mode;
  send_msg.data[2] = msg->brightness;

  try
  {
    sender_->send(send_msg.data.data(), 0x08, send_id, timeout_ns_);
  }
  catch (const std::exception& ex)
  {
    RCLCPP_WARN_THROTTLE(node_->get_logger(), *node_->get_clock(), 1000, "Error sending command message: %s - %s",
                         interface_.c_str(), ex.what());
  }
}

}  // namespace scout_mini_hardware

#include "pluginlib/class_list_macros.hpp"
PLUGINLIB_EXPORT_CLASS(scout_mini_hardware::ScoutMiniHardware, hardware_interface::SystemInterface)