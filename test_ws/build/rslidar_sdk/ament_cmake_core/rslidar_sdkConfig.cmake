# generated from ament/cmake/core/templates/nameConfig.cmake.in

# prevent multiple inclusion
if(_rslidar_sdk_CONFIG_INCLUDED)
  # ensure to keep the found flag the same
  if(NOT DEFINED rslidar_sdk_FOUND)
    # explicitly set it to FALSE, otherwise CMake will set it to TRUE
    set(rslidar_sdk_FOUND FALSE)
  elseif(NOT rslidar_sdk_FOUND)
    # use separate condition to avoid uninitialized variable warning
    set(rslidar_sdk_FOUND FALSE)
  endif()
  return()
endif()
set(_rslidar_sdk_CONFIG_INCLUDED TRUE)

# output package information
if(NOT rslidar_sdk_FIND_QUIETLY)
  message(STATUS "Found rslidar_sdk: 1.5.16 (${rslidar_sdk_DIR})")
endif()

# warn when using a deprecated package
if(NOT "" STREQUAL "")
  set(_msg "Package 'rslidar_sdk' is deprecated")
  # append custom deprecation text if available
  if(NOT "" STREQUAL "TRUE")
    set(_msg "${_msg} ()")
  endif()
  # optionally quiet the deprecation message
  if(NOT ${rslidar_sdk_DEPRECATED_QUIET})
    message(DEPRECATION "${_msg}")
  endif()
endif()

# flag package as ament-based to distinguish it after being find_package()-ed
set(rslidar_sdk_FOUND_AMENT_PACKAGE TRUE)

# include all config extra files
set(_extras "")
foreach(_extra ${_extras})
  include("${rslidar_sdk_DIR}/${_extra}")
endforeach()
