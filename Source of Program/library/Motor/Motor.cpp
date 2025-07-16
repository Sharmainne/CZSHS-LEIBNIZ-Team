#include "Motor.h"
#include <Arduino.h>

Motor::Motor(int Pin1, int Pin2) : pin1(Pin1), pin2(Pin2) {}

void Motor::setup(int Pin1, int Pin2) {
    this->pin1 = Pin1;
    this->pin2 = Pin2;
    pinMode(pin1, OUTPUT);
    pinMode(pin2, OUTPUT);
}

void Motor::setup() {
    pinMode(pin1, OUTPUT);
    pinMode(pin2, OUTPUT);
}

void Motor::write(int speed) {
    speed = constrain(speed, -255, 255); // Clamp the speed to the range [-255, 255]
    last_speed = speed;
    if (speed > 0) {
        speed = abs(speed);
        analogWrite(pin1, speed);
        analogWrite(pin2, 0);
    } else if (speed < 0) {
        speed = abs(speed);
        analogWrite(pin1, 0);
        analogWrite(pin2, speed);
    } else {
        analogWrite(pin1, 0);
        analogWrite(pin2, 0);
    }
}

int Motor::read() {
    return last_speed;
    // Clamp the value to the range [-255, 255]
}

void Motor::reset() {
    last_speed = 0;
    analogWrite(pin1, LOW);
    analogWrite(pin2, LOW);
}
