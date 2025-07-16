#include "CamSerial.h"

SerialComm::SerialComm(HardwareSerial* serialPort) {
    serial = serialPort;
    inputBuffer = "";
    frameActive = false;
    currentFrameId = 0;
}

void SerialComm::begin(long baudRate) {
    serial->begin(baudRate);
}

String SerialComm::getValue(String data, String key) {
    int startPos = data.indexOf(key + "=");
    if (startPos == -1) return "";
    
    startPos += key.length() + 1; // Skip "key="
    int endPos = data.indexOf(",", startPos);
    if (endPos == -1) endPos = data.length();
    
    return data.substring(startPos, endPos);
}

DetectedObject SerialComm::parseObjectData(String data) {
    DetectedObject obj;
    obj.valid = false;
    
    // Remove "OBJ:" prefix
    data = data.substring(4);
    
    obj.color = getValue(data, "color");
    obj.x = getValue(data, "x").toInt();
    obj.y = getValue(data, "y").toInt();
    obj.pixels = getValue(data, "pixels").toInt();
    obj.width = getValue(data, "w").toInt();
    obj.height = getValue(data, "h").toInt();
    obj.minX = getValue(data, "minx").toInt();
    obj.minY = getValue(data, "miny").toInt();
    obj.maxX = getValue(data, "maxx").toInt();
    obj.maxY = getValue(data, "maxy").toInt();
    
    if (obj.color.length() > 0) {
        obj.valid = true;
    }
    
    return obj;
}

ColorThreshold SerialComm::parseThresholdData(String data) {
    ColorThreshold thresh;
    
    // Remove "THRESH:" prefix
    data = data.substring(7);
    
    thresh.color = getValue(data, "color");
    thresh.hMin = getValue(data, "hmin").toInt();
    thresh.hMax = getValue(data, "hmax").toInt();
    thresh.sMin = getValue(data, "smin").toInt();
    thresh.sMax = getValue(data, "smax").toInt();
    thresh.vMin = getValue(data, "vmin").toInt();
    thresh.vMax = getValue(data, "vmax").toInt();
    
    return thresh;
}

CameraConfig SerialComm::parseConfigData(String data) {
    CameraConfig config;
    
    // Remove "CONFIG:" prefix
    data = data.substring(7);
    
    config.brightness = getValue(data, "brightness").toInt();
    config.contrast = getValue(data, "contrast").toInt();
    config.saturation = getValue(data, "saturation").toInt();
    
    return config;
}

void SerialComm::setFlashlight(bool on) {
    serial->print("FLASH:");
    serial->println(on ? "on" : "off");
}

void SerialComm::setCameraConfig(int brightness, int contrast, int saturation) {
    serial->print("CONFIG:brightness=");
    serial->print(brightness);
    serial->print(",contrast=");
    serial->print(contrast);
    serial->print(",saturation=");
    serial->println(saturation);
}

void SerialComm::setColorThreshold(String color, int hMin, int hMax, int sMin, int sMax, int vMin, int vMax) {
    serial->print("THRESH:color=");
    serial->print(color);
    serial->print(",hmin=");
    serial->print(hMin);
    serial->print(",hmax=");
    serial->print(hMax);
    serial->print(",smin=");
    serial->print(sMin);
    serial->print(",smax=");
    serial->print(sMax);
    serial->print(",vmin=");
    serial->print(vMin);
    serial->print(",vmax=");
    serial->println(vMax);
}

void SerialComm::setBatchColorThresholds(ColorThreshold* thresholds, int count) {
    for (int i = 0; i < count; i++) {
        setColorThreshold(thresholds[i].color, thresholds[i].hMin, thresholds[i].hMax,
                         thresholds[i].sMin, thresholds[i].sMax, thresholds[i].vMin, thresholds[i].vMax);
    }
}

bool SerialComm::update() {
    bool newDataProcessed = false;
    
    while (serial->available()) {
        char c = serial->read();
        
        if (c == '\n') {
            // Process complete line
            inputBuffer.trim();
            
            if (inputBuffer.startsWith("OBJ:")) {
                DetectedObject obj = parseObjectData(inputBuffer);
                if (obj.valid) {
                    onObjectDetected(obj);
                    newDataProcessed = true;
                }
            }
            else if (inputBuffer.startsWith("FRAME:")) {
                currentFrameId = inputBuffer.substring(6).toInt();
                frameActive = true;
                onFrameStart(currentFrameId);
                newDataProcessed = true;
            }
            else if (inputBuffer.startsWith("END")) {
                frameActive = false;
                onFrameEnd(currentFrameId);
                newDataProcessed = true;
            }
            else if (inputBuffer.startsWith("ACK:")) {
                String ackMessage = inputBuffer.substring(4);
                onAcknowledge(ackMessage);
                newDataProcessed = true;
            }
            else if (inputBuffer.startsWith("ERR:")) {
                String errorMessage = inputBuffer.substring(4);
                onError(errorMessage);
                newDataProcessed = true;
            }
            
            inputBuffer = "";
        } else {
            inputBuffer += c;
        }
    }
    
    return newDataProcessed;
}

DetectedObject SerialComm::getLastObject() {
    // This would need to be implemented with a buffer if you want to store the last object
    DetectedObject empty;
    empty.valid = false;
    return empty;
}

bool SerialComm::isFrameActive() {
    return frameActive;
}

int SerialComm::getCurrentFrameId() {
    return currentFrameId;
}
