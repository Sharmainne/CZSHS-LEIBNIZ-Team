#ifndef CAMSERIAL_H
#define CAMSERIAL_H

#include <Arduino.h>
#include <HardwareSerial.h>

struct DetectedObject {
    String color;
    int x, y;
    int pixels;
    int width, height;
    int minX, minY;
    int maxX, maxY;
    bool valid;
};

struct ColorThreshold {
    String color;
    int hMin, hMax;
    int sMin, sMax;
    int vMin, vMax;
};

struct CameraConfig {
    int brightness;
    int contrast;
    int saturation;
};

class SerialComm {
private:
    HardwareSerial* serial;
    String inputBuffer;
    bool frameActive;
    int currentFrameId;
    
    // Parse key=value pairs from a string
    String getValue(String data, String key);
    
    // Parse object data from OBJ: command
    DetectedObject parseObjectData(String data);
    
    // Parse color threshold data
    ColorThreshold parseThresholdData(String data);
    
    // Parse camera config data
    CameraConfig parseConfigData(String data);

public:
    SerialComm(HardwareSerial* serialPort = &Serial2);
    
    // Initialize serial communication
    void begin(long baudRate = 115200);
    
    // Send commands to ESP32-CAM
    void setFlashlight(bool on);
    void setCameraConfig(int brightness, int contrast, int saturation);
    void setColorThreshold(String color, int hMin, int hMax, int sMin, int sMax, int vMin, int vMax);
    void setBatchColorThresholds(ColorThreshold* thresholds, int count);
    
    // Receive and process data from ESP32-CAM
    bool update(); // Call this in loop() - returns true if new data processed
    
    // Get received data
    DetectedObject getLastObject();
    bool isFrameActive();
    int getCurrentFrameId();
    
    // Event callbacks (override these in your main code)
    virtual void onObjectDetected(DetectedObject obj) {}
    virtual void onFrameStart(int frameId) {}
    virtual void onFrameEnd(int frameId) {}
    virtual void onAcknowledge(String message) {}
    virtual void onError(String error) {}
};

#endif
