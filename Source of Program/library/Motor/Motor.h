 #ifndef MOTOR_H
#define MOTOR_H

class Motor {
    public: 
        Motor(int pin1, int pin2);
        Motor(int pin1, int pin2, int deadzone);
        void setup(int pin1, int pin2);
        void write(int speed);
        int read();
        void reset();
        void deadzone(int deadzone);

    private:
        int pin1;  // Pin for motor control
        int pin2;  // Second pin for motor control
        int last_speed = 0; // Track last written speed
        int zone;
};

#endif // !MOTOR_H
