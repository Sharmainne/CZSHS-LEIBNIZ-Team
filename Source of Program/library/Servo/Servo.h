#ifndef SERVO_MOTOR_H
#define SERVO_MOTOR_H

#include <Arduino.h>
#include <ESP32Servo.h>

class Servo_Motor : public Servo {
public:

    // Constructor
    Servo_Motor(uint8_t pin, int PWM_Freq, int PWM_Min, int PWM_Max);
    Servo_Motor(uint8_t pin, int PWM_Freq, int PWM_Min, int PWM_Max, int center);
    Servo_Motor(uint8_t pin, int PWM_Freq, int PWM_Min, int PWM_Max, int center, int min, int max);
    void setup(int ServoPin,int PWM_Freq, int PWM_Min, int PWM_Max);
    void clamp(int min, int max);
    void write360(int angle);
    void write360(double angle);
    int read();
    void reset();

private:
    uint8_t ServoPin;
    int PWM_Freq;         // Frequency for the PWM signal
    int PWM_Min;
    int PWM_Max;
    int last_angle = 0; // Track last written angle
    int center = 0;
    int min = 0;        // Default min angle (relative to center)
    int max = 0;        // Default max angle (relative to center)
    bool use_clamping = false;  // Flag to enable/disable clamping

};

#endif // SERVO_MOTOR_H
