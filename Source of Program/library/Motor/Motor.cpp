#include "Motor.h"
#include <Arduino.h>

Motor::Motor(int pin1, int pin2) : pin1(pin1), pin2(pin2) {
    pinMode(pin1, OUTPUT);
    pinMode(pin2, OUTPUT);
}
Motor::Motor(int pin1, int pin2, int deadzone) : pin1(pin1), pin2(pin2), zone(deadzone) {
    pinMode(pin1, OUTPUT);
    pinMode(pin2, OUTPUT);
}

void Motor::setup(int pin1, int pin2) {
    this->pin1 = pin1;
    this->pin2 = pin2;
    pinMode(pin1, OUTPUT);
    pinMode(pin2, OUTPUT);
}

void Motor::deadzone(int deadzone) {
    this->zone = deadzone;
}

void Motor::write(int speed) {
    speed = constrain(speed, -255, 255); // Clamp the speed to the range [-255, 255]
    last_speed = speed;
    if (-zone <= speed && speed <= zone) speed = 0;
    speed = abs(speed);
    if (speed > 0) {
        analogWrite(pin1, speed);
        digitalWrite(pin2, LOW);
    } else if (speed < 0) {
        digitalWrite(pin1, LOW);
        analogWrite(pin2, speed);
    } else {
        digitalWrite(pin1, LOW);
        digitalWrite(pin2, LOW);
    }
}

int Motor::read() {
    return last_speed;
    // Clamp the value to the range [-255, 255]
}

void Motor::reset() {
    last_speed = 0;
    digitalWrite(pin1, LOW);
    digitalWrite(pin2, LOW);
}
