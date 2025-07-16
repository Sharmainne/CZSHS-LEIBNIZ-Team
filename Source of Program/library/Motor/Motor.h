#ifndef MOTOR_H
#define MOTOR_H

class Motor {
    public: 
        Motor(int Pin1, int Pin2);
        void setup(int Pin1, int Pin2);
        void setup();
        void write(int speed);
        int read();
        void reset();

    private:
        int pin1;  // Pin for motor control
        int pin2;  // Second pin for motor control
        int last_speed = 0; // Track last written speed
};

#endif // !MOTOR_H
