#ifndef GYRO_H
#define GYRO_H

#include <Arduino.h>
#include <MPU6050_6Axis_MotionApps20.h>

class Gyro : public MPU6050{
public:
    uint8_t I2C_SDA_DEFAULT;
    uint8_t I2C_SCL_DEFAULT;
    int16_t RawGyroX, RawGyroY, RawGyroZ; // Raw gyro values
    int16_t RawAccelX, RawAccelY, RawAccelZ; // Raw accelerometer values
    
    float AngleX, AngleY, AngleZ; // Estimated angles (calibrated, -180 to 180)
    float AccumAngleX, AccumAngleY, AccumAngleZ; // Accumulated angles (continuous)
    bool dmpReady = false; // DMP ready flag
    bool isCalibrated = false; // Calibration status
    int stabilizationSampleCount = 0;
    
    Gyro(uint8_t I2C_SDA, uint8_t I2C_SCL);
    void setup();
    void setup(uint8_t I2C_SDA, uint8_t I2C_SCL);
    void getData();
    void readAll();
    float readX();
    float readY();
    float readZ();
    float readAccumX();
    float readAccumY();
    float readAccumZ();
    void calibrate(int samples = 100); // Now uses stabilization instead of averaging
    void setCurrentAsZero();
    void resetAccumulation();
    void reset();
    
    // New stabilization methods
    bool isStabilized();
    void waitForStabilization();
    void resetStabilizationCheck();
    
private:
    // Stabilization constants
    static constexpr float STABILITY_THRESHOLD = 0.5;  // Degrees - adjust as needed
    static const unsigned long MIN_STABILIZATION_TIME = 3000; // 3 seconds minimum
    static const int MIN_STABLE_SAMPLES = 50; // Minimum stable readings
    static const int STABILIZATION_CHECK_INTERVAL = 50; // Check every 50ms
    
    // I2C pins
    unsigned long lastUpdate = 0;
    float angle[3];
    float zeroReference[3] = {0, 0, 0}; // Zero reference point
    float lastAngle[3] = {0, 0, 0}; // Previous angles for accumulation
    bool firstReading = true;
    uint16_t packetSize;
    uint8_t fifoBuffer[64];
    Quaternion q;
    VectorFloat gravity;
    
    // Stabilization variables
    
    unsigned long stabilizationStartTime = 0;
    float stabilizationBuffer[3] = {0, 0, 0}; // Store first reading for comparison
    
    // Helper function to handle angle wrapping
    float wrapAngle(float angle);
    float angleDifference(float current, float previous);
};

#endif // GYRO_H
