#include "PID.h"
#include <Arduino.h>

PID::PID(double Kp, double Ki, double Kd) 
    : Kp(Kp), Ki(Ki), Kd(Kd), last_dt(0), previous_error(0), integral(0), clamp(false), min(-500.0), max(500.0){
}

PID::PID(double Kp, double Ki, double Kd, double min, double max) 
    : Kp(Kp), Ki(Ki), Kd(Kd), last_dt(0), previous_error(0), integral(0), clamp(true), min(min), max(max) {
}

void PID::Setup(double Kp, double Ki, double Kd) {
    this->Kp = Kp;
    this->Ki = Ki;
    this->Kd = Kd;
}

void PID::Setup(double Kp, double Ki, double Kd, double min, double max) {
    this->Kp = Kp;
    this->Ki = Ki;
    this->Kd = Kd;
    this->min = min;
    this->max = max;
    clamp = true;  // Enable clamping
}


void PID::Clamp(double min, double max) {
    this->min = min;
    this->max = max;
    clamp = true;  // Enable clamping
}

void PID::NoClamp() {
    clamp = false;  // Disable clamping
}

void PID::Deadband(double deadband) {
    this->deadband = deadband;  // Set deadband for error
}

void PID::IntegralWindup(bool windup) {
    this->windup = windup;  // Enable or disable integral windup prevention
}

void PID::reset() {
    last_dt = millis();  // Reset last delta time to current time
    previous_error = 0;  // Reset previous error
    integral = 0;        // Reset integral term
}

double PID::read(double target, double current) {
    double current_dt = millis();
    double dt = (current_dt - last_dt) / 1000.0;
    if (dt <= 0) dt = 0.001;

    // Calculate error
    double error = target - current;

    // Proportional term
    double P = Kp * error;

    // Derivative term
    double derivative = (error - previous_error) / dt;
    double D = Kd * derivative;

    // ===== Integral windup protection BEFORE output calculation =====
    if (windup && clamp) {
        double potential_integral = integral + error * dt;
        double I_temp = Ki * potential_integral;
        double output_test = P + I_temp + D;
        if (output_test > max || output_test < min) {
            // Don't accumulate integral — output would saturate
        } else {
            integral = potential_integral;
        }
    } else {
        // Normal accumulation
        integral += error * dt;
    }

    // Integral term
    double I = Ki * integral;

    // Combine
    double output = P + I + D;

    // Clamp output
    if (clamp) {
        output = constrain(output, min, max);
    }

    // Store states
    previous_error = error;
    last_dt = current_dt;

    return output;
}
