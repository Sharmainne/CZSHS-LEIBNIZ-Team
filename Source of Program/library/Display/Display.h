// Display.h - Updated header with proper memory management
#ifndef DISPLAY_H
#define DISPLAY_H

#include <Arduino.h>
#include <U8g2lib.h>
#include "Ultra_Sonic.h"
#include "Gyro.h"
#include "Motor.h"
#include "Servo_Motor.h"
#include "PID.h"
#include "Button.h"

enum DisplayState {
    NORMAL,
    UPDATING,
    EMERGENCY
};

enum OTAStage {
    OTA_WIFI_CONNECTING,
    OTA_WIFI_CONNECTED,
    OTA_INITIALIZING,
    OTA_READY,
    OTA_UPDATING,
    OTA_COMPLETE,
    OTA_ERROR
};

class Display : public U8G2_ST7920_128X64_F_SW_SPI {
public:
    // Constructor
    Display(int clock = 18, int data = 23, int cs = 5, 
            Gyro* gyro = nullptr, Motor* motor = nullptr, Button* button = nullptr, 
            Servo_Motor* servoSteering = nullptr, Servo_Motor* servoCamera = nullptr, 
            Ultra_Sonics* mySonars = nullptr);
    
    // Setup and basic operations
    void setup();
    void clearScreen();
    void displayData();
    
    // State management
    void changeState(DisplayState state);
    void Error(const char* Title, const char* Detail1 = nullptr, const char* Detail2 = nullptr, 
               const char* Detail3 = nullptr, const char* Detail4 = nullptr);
    
    // Status updates
    void status(int num, const char* input);
    void statusf(int num, const char* fmt, ...);
    void statusClear();
    
    // OTA specific methods
    void setOTAStage(OTAStage stage);
    void setOTAProgress(unsigned int progress);
    void setOTAError(const String& error);
    void setIPAddress(const String& ip);
    
    // Display methods
    void drawNormal();
    void drawUpdate();
    void drawEmergency();

private:
    // Constants for buffer sizes
    static const size_t STATUS_BUFFER_SIZE = 64;
    static const size_t TITLE_BUFFER_SIZE = 32;
    
    // Display state
    DisplayState currentState = NORMAL;
    OTAStage otaStage = OTA_WIFI_CONNECTING;
    
    // Hardware components
    Gyro* myGyro;
    Motor* myMotor;
    Button* myButton;
    Servo_Motor* myServoSteering;
    Servo_Motor* myServoCamera;
    Ultra_Sonics* mySonars;
    
    // Display content - now using fixed-size buffers
    char Title[TITLE_BUFFER_SIZE];
    char status1[STATUS_BUFFER_SIZE];
    char status2[STATUS_BUFFER_SIZE];
    char status3[STATUS_BUFFER_SIZE];
    char status4[STATUS_BUFFER_SIZE];
    
    // OTA display data
    String ipAddress = "";
    String otaError = "";
    unsigned int otaProgress = 0;
    
    // Timing and effects
    long lastTime;
    bool flashState = false;
    unsigned long lastFlashTime = 0;
    
    // Helper methods
    void drawOTAStatus();
    const char* getOTAStageText();
    void sonarRead();
    void checkRotation();
};

#endif
