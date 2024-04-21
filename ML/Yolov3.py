import cv2
import numpy as np
import time

net = cv2.dnn.readNet("yolov3.weights", "darknet/cfg/yolov3.cfg")
classes = []
with open("coco.names", "r") as f:
    classes = [line.strip() for line in f.readlines()]
layer_names = net.getLayerNames()
output_layers_indices = net.getUnconnectedOutLayers()

# Convert scalar to a list if needed
if isinstance(output_layers_indices, int):
    output_layers_indices = [output_layers_indices]

output_layers = [layer_names[i - 1] for i in output_layers_indices]

cap = cv2.VideoCapture(0)

while True:
    ret, frame = cap.read()
    frame = cv2.flip(frame, 1)  # flip the frame horizontally

    height, width, channels = frame.shape

    # Measure preprocessing time
    preprocess_start_time = time.time()

    blob = cv2.dnn.blobFromImage(frame, 0.00392, (416, 416), (0, 0, 0), True, crop=False)

    preprocess_end_time = time.time()
    preprocess_time_ms = (preprocess_end_time - preprocess_start_time) * 1000

    net.setInput(blob)

    # Measure inference time
    inference_start_time = time.time()
    outs = net.forward(output_layers)
    inference_end_time = time.time()
    inference_time_ms = (inference_end_time - inference_start_time) * 1000

    class_ids = []
    confidences = []
    boxes = []
    for out in outs:
        for detection in out:
            scores = detection[5:]
            class_id = np.argmax(scores)
            confidence = scores[class_id]
            if confidence > 0.5:

                center_x = int(detection[0] * width)
                center_y = int(detection[1] * height)
                w = int(detection[2] * width)
                h = int(detection[3] * height)

                x = int(center_x - w / 2)
                y = int(center_y - h / 2)

                boxes.append([x, y, w, h])
                confidences.append(float(confidence))
                class_ids.append(class_id)

    # Measure postprocessing time
    postprocess_start_time = time.time()

    indexes = cv2.dnn.NMSBoxes(boxes, confidences, 0.5, 0.4)

    postprocess_end_time = time.time()
    postprocess_time_ms = (postprocess_end_time - postprocess_start_time) * 1000

    font = cv2.FONT_HERSHEY_PLAIN
    detected_objects = 0
    for i in range(len(boxes)):
        if i in indexes:
            detected_objects += 1
            x, y, w, h = boxes[i]
            label = str(classes[class_ids[i]])
            confidence = confidences[i]

            color = (255, 0, 0)
            cv2.rectangle(frame, (x, y), (x + w, y + h), color, 2)
            cv2.putText(frame, label + " " + str(round(confidence, 2)), (x, y + 30), font, 3, color, 2)
    
    # Printing Summary
    print('\n')

    print("Confidence -->", round(float(confidence), 2))

    print("Class name -->", label)

    print(f"{height}x{width} {detected_objects} {label}, {inference_time_ms:.1f}ms")

    print(f"Speed: {preprocess_time_ms:.1f}ms preprocess, {inference_time_ms:.1f}ms inference, {postprocess_time_ms:.1f}ms postprocess per image")

    cv2.imshow('YOLO Object Detection', frame)

    if cv2.waitKey(1) & 0xFF == ord('q'):
        break

cap.release()
cv2.destroyAllWindows()
