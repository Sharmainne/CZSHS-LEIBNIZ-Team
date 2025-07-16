// Display.cpp - Updated implementation with memory safety

#include "Display.h"

Display::Display(int clock, int data, int cs,
                 Gyro* gyro, Motor* motor, Button* button, 
                 Servo_Motor* servoSteering, Servo_Motor* servoCamera, 
                 Ultra_Sonics* mySonars) :
                 U8G2_ST7920_128X64_F_SW_SPI(U8G2_R0, clock, data, cs, U8X8_PIN_NONE),
                 myGyro(gyro), myMotor(motor), myButton(button), myServoSteering(servoSteering), 
                 myServoCamera(servoCamera), mySonars(mySonars) {
    // Initialize status strings with empty strings
    Title[0] = '\0';
    status1[0] = '\0';
    status2[0] = '\0';
    status3[0] = '\0';
    status4[0] = '\0';
}

void Display::setup() {
    begin();
    setFont(u8g2_font_6x10_tf);
    setContrast(255); // Max contrast for better visibility
}

void Display::clearScreen() {
    clear();
}

void Display::changeState(DisplayState state) {
    this->currentState = state;
}

void Display::setOTAStage(OTAStage stage) {
    this->otaStage = stage;
}

void Display::setOTAProgress(unsigned int progress) {
    this->otaProgress = progress;
}

void Display::setOTAError(const String& error) {
    this->otaError = error;
}

void Display::setIPAddress(const String& ip) {
    this->ipAddress = ip;
}

void Display::Error(const char* title, const char* Detail1, const char* Detail2, 
                   const char* Detail3, const char* Detail4) {
    changeState(EMERGENCY);
    
    // Safe string copying with null termination
    if (title) {
        strncpy(Title, title, TITLE_BUFFER_SIZE - 1);
        Title[TITLE_BUFFER_SIZE - 1] = '\0';
    } else {
        Title[0] = '\0';
    }
    
    if (Detail1) {
        strncpy(status1, Detail1, STATUS_BUFFER_SIZE - 1);
        status1[STATUS_BUFFER_SIZE - 1] = '\0';
    } else {
        status1[0] = '\0';
    }
    
    if (Detail2) {
        strncpy(status2, Detail2, STATUS_BUFFER_SIZE - 1);
        status2[STATUS_BUFFER_SIZE - 1] = '\0';
    } else {
        status2[0] = '\0';
    }
    
    if (Detail3) {
        strncpy(status3, Detail3, STATUS_BUFFER_SIZE - 1);
        status3[STATUS_BUFFER_SIZE - 1] = '\0';
    } else {
        status3[0] = '\0';
    }
    
    if (Detail4) {
        strncpy(status4, Detail4, STATUS_BUFFER_SIZE - 1);
        status4[STATUS_BUFFER_SIZE - 1] = '\0';
    } else {
        status4[0] = '\0';
    }
}

void Display::status(int num, const char* input) {
    if (!input) return; // Guard against null pointer
    
    switch (num) {
        case 2:
            strncpy(status2, input, STATUS_BUFFER_SIZE - 1);
            status2[STATUS_BUFFER_SIZE - 1] = '\0';
            break;
        case 3:
            strncpy(status3, input, STATUS_BUFFER_SIZE - 1);
            status3[STATUS_BUFFER_SIZE - 1] = '\0';
            break;
        case 4:
            strncpy(status4, input, STATUS_BUFFER_SIZE - 1);
            status4[STATUS_BUFFER_SIZE - 1] = '\0';
            break;
        default:
            strncpy(status1, input, STATUS_BUFFER_SIZE - 1);
            status1[STATUS_BUFFER_SIZE - 1] = '\0';
            break;
    }
}

void Display::statusf(int num, const char* fmt, ...) {
    static char buffer[64];  // shared temp buffer (adjust size as needed)
    va_list args;
    va_start(args, fmt);
    vsnprintf(buffer, sizeof(buffer), fmt, args);
    va_end(args);
    status(num, buffer);  // reuse your existing `status()` function
}

void Display::statusClear() {
    Title[0] = '\0';
    status1[0] = '\0';
    status2[0] = '\0';
    status3[0] = '\0';
    status4[0] = '\0';
}

void Display::displayData() {
    switch (currentState) {
    case UPDATING:
        drawUpdate();
        break;
    case EMERGENCY:
        drawEmergency();
        break;
    default:
        drawNormal();
    }
}

void Display::drawNormal() {
    clearBuffer();
    char buffer[30];
    int x = 1, y = 9;

    snprintf(buffer, sizeof(buffer), "%d MS %3d",myButton->getPressTypeInt() , millis() - lastTime);
    drawStr(70, y, buffer);
    lastTime = millis();

    if (myGyro) {
        snprintf(buffer, sizeof(buffer), "X %8.2f", myGyro->readAccumX());
        drawStr(x, y, buffer);
        y += 10;
    }

    if (myServoSteering && myServoCamera && myMotor) {
        snprintf(buffer, sizeof(buffer), "M %3d SS %3d SC %3d", myMotor->read(), myServoSteering->read(), myServoCamera->read());
        drawStr(x, y, buffer);
        y += 10;
    } else {
        if (myMotor) {
            snprintf(buffer, sizeof(buffer), "M %3d", myMotor->read());
            drawStr(x, y, buffer);
            x += getStrWidth(buffer) + 1;
        }
        if (myServoSteering) {
            snprintf(buffer, sizeof(buffer), "SS %3d", myServoSteering->read());
            drawStr(x, y, buffer);
            x += getStrWidth(buffer) + 1;
        }
        if (myServoCamera) {
            snprintf(buffer, sizeof(buffer), "SC %3d", myServoCamera->read());
            drawStr(x, y, buffer);
            x += getStrWidth(buffer) + 1;
        }
        y += 10;
        x = 1;
    }

    if (mySonars) {
        snprintf(buffer, sizeof(buffer), "U %3d %3d %3d %3d", mySonars->getLeft(), mySonars->getFrontLeft(), mySonars->getFrontRight(), mySonars->getRight());
        drawStr(x, y, buffer);
        y += 10;
    }

    drawStr(x, y, status1);
    y += 10;
    drawStr(x, y, status2);
    y += 10;
    drawStr(x, y, status3);
    y += 10;
    drawStr(x, y, status4);
    
    sendBuffer();
}

void Display::drawEmergency() {
    clearBuffer();
    char buffer[30];
    int x = 1, y = 25;
    
    // Flash effect for emergency
    unsigned long currentTime = millis();
    if (currentTime - lastFlashTime > 500) {
        flashState = !flashState;
        lastFlashTime = currentTime;
    }
    
    if (flashState) {
        setFont(u8g2_font_logisoso16_tf);
        drawStr(x, y, Title);
    }
    
    setFont(u8g2_font_6x10_tf);
    y += 10;
    drawStr(x, y, status1);
    y += 10;
    drawStr(x, y, status2);
    y += 10;
    drawStr(x, y, status3);
    y += 10;
    drawStr(x, y, status4);

    sendBuffer();
}

void Display::drawUpdate() {
    drawOTAStatus();
}

void Display::drawOTAStatus() {
    clearBuffer();
    char buffer[30];
    
    // Big Header
    setFont(u8g2_font_logisoso16_tf);
    const char* headerText = "OTA UPDATE";
    int headerWidth = getStrWidth(headerText);
    drawStr((128 - headerWidth) / 2, 18, headerText);
    
    // Status lines
    setFont(u8g2_font_6x10_tf);
    int y = 32;
    
    // Line 1: Current stage
    const char* stageText = getOTAStageText();
    drawStr(0, y, stageText);
    y += 10;
    
    // Line 2: IP Address (if available)
    if (ipAddress.length() > 0) {
        snprintf(buffer, sizeof(buffer), "IP: %s", ipAddress.c_str());
        drawStr(0, y, buffer);
        y += 10;
    }
    
    // Line 3: Progress or Error
    if (otaStage == OTA_UPDATING) {
        snprintf(buffer, sizeof(buffer), "Progress: %u%%", otaProgress);
        drawStr(0, y, buffer);
        y += 10;
        
        // Progress bar
        int barWidth = 100;
        int barHeight = 8;
        int barX = (128 - barWidth) / 2;
        int barY = y + 2;
        
        // Draw progress bar outline
        drawFrame(barX, barY, barWidth, barHeight);
        
        // Fill progress bar
        int fillWidth = (barWidth - 2) * otaProgress / 100;
        if (fillWidth > 0) {
            drawBox(barX + 1, barY + 1, fillWidth, barHeight - 2);
        }
    } else if (otaStage == OTA_ERROR && otaError.length() > 0) {
        snprintf(buffer, sizeof(buffer), "Error: %s", otaError.c_str());
        drawStr(0, y, buffer);
    }
    
    // Force immediate buffer send
    sendBuffer();
    
    // Add small delay for display processing
    if (otaStage == OTA_UPDATING) {
        delayMicroseconds(100);
    }
}

const char* Display::getOTAStageText() {
    switch (otaStage) {
        case OTA_WIFI_CONNECTING:
            return "WiFi Connecting...";
        case OTA_WIFI_CONNECTED:
            return "WiFi Connected";
        case OTA_INITIALIZING:
            return "Initializing OTA...";
        case OTA_READY:
            return "OTA Ready";
        case OTA_UPDATING:
            return "Updating Firmware...";
        case OTA_COMPLETE:
            return "Update Complete!";
        case OTA_ERROR:
            return "OTA Error";
        default:
            return "Unknown";
    }
}
