#include "Gyro.h"

// Constructor
Gyro::Gyro(uint8_t I2C_SDA, uint8_t I2C_SCL) : I2C_SDA_DEFAULT(I2C_SDA), I2C_SCL_DEFAULT(I2C_SCL) {}

void Gyro::setup() {
    setup(I2C_SDA_DEFAULT, I2C_SCL_DEFAULT);
}

void Gyro::setup(uint8_t I2C_SDA, uint8_t I2C_SCL) {
    this->I2C_SDA_DEFAULT = I2C_SDA;
    this->I2C_SCL_DEFAULT = I2C_SCL;
    Wire.begin(I2C_SDA, I2C_SCL);

    // Initialize MPU6050
    initialize();

    // Initialize DMP
    if (dmpInitialize() == 0) {
        setDMPEnabled(true);
        dmpReady = true;
        packetSize = dmpGetFIFOPacketSize();
        
        // Initialize stabilization variables
        resetStabilizationCheck();
        
    } else {
        dmpReady = false;
    }
}

void Gyro::getData() {
    if (!dmpReady) return;
    getMotion6(&RawAccelX, &RawAccelY, &RawAccelZ, &RawGyroX, &RawGyroY, &RawGyroZ);

    if (dmpGetCurrentFIFOPacket(fifoBuffer)) {
        dmpGetQuaternion(&q, fifoBuffer);
        dmpGetGravity(&gravity, &q);
        dmpGetYawPitchRoll(angle, &q, &gravity);
    }
}

void Gyro::readAll() {
    // Convert to degrees
    float rawX = angle[0] * RAD_TO_DEG;
    float rawY = angle[1] * RAD_TO_DEG;
    float rawZ = angle[2] * RAD_TO_DEG;
    
    // Apply zero reference (current position as zero)
    AngleX = rawX - zeroReference[0];
    AngleY = rawY - zeroReference[1];
    AngleZ = rawZ - zeroReference[2];
    
    // Wrap angles to -180 to 180 range
    AngleX = wrapAngle(AngleX);
    AngleY = wrapAngle(AngleY);
    AngleZ = wrapAngle(AngleZ);
    
    // Update accumulated angles
    if (firstReading) {
        AccumAngleX = AngleX;
        AccumAngleY = AngleY;
        AccumAngleZ = AngleZ;
        firstReading = false;
    } else {
        AccumAngleX += angleDifference(AngleX, lastAngle[0]);
        AccumAngleY += angleDifference(AngleY, lastAngle[1]);
        AccumAngleZ += angleDifference(AngleZ, lastAngle[2]);
    }
    
    // Store current angles for next iteration
    lastAngle[0] = AngleX;
    lastAngle[1] = AngleY;
    lastAngle[2] = AngleZ;
}

float Gyro::readX() {
    return AngleX;
}

float Gyro::readY() {
    return AngleY;
}

float Gyro::readZ() {
    return AngleZ;
}

float Gyro::readAccumX() {
    return AccumAngleX;
}

float Gyro::readAccumY() {
    return AccumAngleY;
}

float Gyro::readAccumZ() {
    return AccumAngleZ;
}

bool Gyro::isStabilized() {
    if (!dmpReady) return false;
    
    // Get current raw readings
    float rawX = angle[0] * RAD_TO_DEG;
    float rawY = angle[1] * RAD_TO_DEG;
    float rawZ = angle[2] * RAD_TO_DEG;
    
    // Check if this is the first reading
    if (stabilizationSampleCount == 0) {
        // Store first reading
        stabilizationBuffer[0] = rawX;
        stabilizationBuffer[1] = rawY;
        stabilizationBuffer[2] = rawZ;
        stabilizationSampleCount = 1;
        stabilizationStartTime = millis();
        return false;
    }
    
    // Calculate difference from first reading
    float diffX = abs(rawX - stabilizationBuffer[0]);
    float diffY = abs(rawY - stabilizationBuffer[1]);
    float diffZ = abs(rawZ - stabilizationBuffer[2]);
    
    // Check if readings are within stability threshold
    bool isStable = (diffX <= STABILITY_THRESHOLD && 
                    diffY <= STABILITY_THRESHOLD && 
                    diffZ <= STABILITY_THRESHOLD);
    
    if (isStable) {
        stabilizationSampleCount++;
        
        // Check if we've been stable for minimum time AND minimum samples
        unsigned long elapsedTime = millis() - stabilizationStartTime;
        if (elapsedTime >= MIN_STABILIZATION_TIME && 
            stabilizationSampleCount >= MIN_STABLE_SAMPLES) {
            
            // Set current reading as zero reference
            zeroReference[0] = rawX;
            zeroReference[1] = rawY;
            zeroReference[2] = rawZ;
            
            isCalibrated = true;
            resetAccumulation();
            return true;
        }
    } else {
        // Reset if not stable
        resetStabilizationCheck();
    }
    
    return false;
}

void Gyro::waitForStabilization() {
    if (!dmpReady) return;
    
    while (!isStabilized()) {
        getData();
        delay(STABILIZATION_CHECK_INTERVAL);
    }
}

void Gyro::resetStabilizationCheck() {
    stabilizationSampleCount = 0;
    stabilizationStartTime = 0;
    stabilizationBuffer[0] = 0;
    stabilizationBuffer[1] = 0;
    stabilizationBuffer[2] = 0;
}

void Gyro::calibrate(int samples) {
    // This method is now deprecated in favor of stabilization-based calibration
    // Keeping it for backward compatibility, but it just calls waitForStabilization
    waitForStabilization();
}

void Gyro::setCurrentAsZero() {
    if (!dmpReady) return;
    
    // Get current reading
    getData();
    if (dmpGetCurrentFIFOPacket(fifoBuffer)) {
        dmpGetQuaternion(&q, fifoBuffer);
        dmpGetGravity(&gravity, &q);
        dmpGetYawPitchRoll(angle, &q, &gravity);
        
        // Convert to degrees and set as zero reference
        zeroReference[0] = angle[0] * RAD_TO_DEG;
        zeroReference[1] = angle[1] * RAD_TO_DEG;
        zeroReference[2] = angle[2] * RAD_TO_DEG;
    }
    
    isCalibrated = true;
    // Reset accumulated angles after setting new zero
    resetAccumulation();
}

void Gyro::resetAccumulation() {
    AccumAngleX = 0;
    AccumAngleY = 0;
    AccumAngleZ = 0;
    firstReading = true;
}

void Gyro::reset() {
    // Reset zero reference
    zeroReference[0] = 0;
    zeroReference[1] = 0;
    zeroReference[2] = 0;
    
    isCalibrated = false;
    
    // Reset accumulated angles
    resetAccumulation();
    
    // Reset stabilization check
    resetStabilizationCheck();
}

float Gyro::wrapAngle(float angle) {
    while (angle > 180) angle -= 360;
    while (angle < -180) angle += 360;
    return angle;
}

float Gyro::angleDifference(float current, float previous) {
    float diff = current - previous;
    
    // Handle wrap-around cases
    if (diff > 180) {
        diff -= 360;
    } else if (diff < -180) {
        diff += 360;
    }
    
    return diff;
}
