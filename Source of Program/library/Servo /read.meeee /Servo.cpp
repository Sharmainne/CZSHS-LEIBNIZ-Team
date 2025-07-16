#include "Servo_Motor.h"
#include <Arduino.h>

Servo_Motor::Servo_Motor(uint8_t pin, int PWM_Freq, int PWM_Min, int PWM_Max) : ServoPin(pin), PWM_Freq(PWM_Freq), PWM_Min(PWM_Min), PWM_Max(PWM_Max) {
  setup(ServoPin, PWM_Freq, PWM_Min, PWM_Max);  // Call setup to initialize the servo motor
}

Servo_Motor::Servo_Motor(uint8_t pin, int PWM_Freq, int PWM_Min, int PWM_Max, int center) : ServoPin(pin), PWM_Freq(PWM_Freq), PWM_Min(PWM_Min), PWM_Max(PWM_Max), center(center) {
  setup(ServoPin, PWM_Freq, PWM_Min, PWM_Max);  // Call setup to initialize the servo motor
  
  // Set default min/max relative to center to maintain 0-360 range
  this->min = -center;
  this->max = 360 - center;
  this->use_clamping = true;
}

Servo_Motor::Servo_Motor(uint8_t pin, int PWM_Freq, int PWM_Min, int PWM_Max, int center, int min, int max) : ServoPin(pin), PWM_Freq(PWM_Freq), PWM_Min(PWM_Min), PWM_Max(PWM_Max), center(center), min(min), max(max) {
  setup(ServoPin, PWM_Freq, PWM_Min, PWM_Max);  // Call setup to initialize the servo motor
  this->use_clamping = true;
}

void Servo_Motor::setup(int ServoPin,int PWM_Freq, int PWM_Min, int PWM_Max) {
  this->ServoPin = ServoPin;
  this->PWM_Freq = PWM_Freq;
  setPeriodHertz(PWM_Freq); // Set servo frequency to 50Hz
  attach(ServoPin, PWM_Min, PWM_Max); // Attach servo to pin
}

void Servo_Motor::write360(int angle) {
    int input_angle = angle;
    
    // Apply clamping if enabled
    if (use_clamping) {
        input_angle = constrain(angle, min, max);
    }
    
    int adjusted = input_angle + center;  // Apply centering offset
    adjusted = constrain(adjusted, 0, 360);  // Clamp to servo physical limits

    int pulse = map(adjusted, 0, 360, PWM_Min, PWM_Max);
    writeMicroseconds(pulse);

    last_angle = input_angle;  // Store the clamped input angle
}

void Servo_Motor::write360(double angle) {
    double input_angle = angle;
    
    // Apply clamping if enabled
    if (use_clamping) {
        input_angle = constrain(angle, (double)min, (double)max);
    }
    
    double adjusted = input_angle + center;

    // Now clamp the result so it doesn't go beyond servo limits
    adjusted = constrain(adjusted, 0.0, 360.0);

    int pulse = map(adjusted, 0, 360, PWM_Min, PWM_Max);
    writeMicroseconds(pulse);

    last_angle = static_cast<int>(input_angle);  // Store the clamped input angle
}

void Servo_Motor::clamp(int min, int max) {
  this->min = min;
  this->max = max;
  this->use_clamping = true;
}

void Servo_Motor::reset() {
  write(0);
}

int Servo_Motor::read() {
  return last_angle;
}
