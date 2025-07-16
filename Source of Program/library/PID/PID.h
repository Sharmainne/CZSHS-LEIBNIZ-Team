#ifndef PID_H
#define PID_H

class PID{
    public:
        double Kp; // Proportional gain
        double Ki; // Integral gain
        double Kd; // Derivative gain
        double deadband = 0.0; // Deadband for error

        PID(double Kp, double Ki, double Kd);
        PID(double Kp, double Ki, double Kd, double min, double max);
        void Setup(double Kp, double Ki, double Kd);
        void Setup(double Kp, double Ki, double Kd, double min, double max);
        double read(double target, double current);
        void reset();
        void Clamp(double min, double max);
        void NoClamp();
        void IntegralWindup(bool windup);
        void Deadband(double deadband);
    private:
        double last_dt; // Last delta time
        double previous_error; // Reference to previous error
        double integral; // Reference to integral term
        bool clamp; // Clamp output to
        double min;
        double max;
        bool windup; // Integral windup prevention

};

#endif // !PID_H
