#include "Ultra_Sonic.h"
#include <Arduino.h>

Ultra_Sonics::Ultra_Sonics(int max_distance, int trigPin1, int echoPin1, 
                           int trigPin2, int echoPin2, 
                           int trigPin3, int echoPin3, 
                           int trigPin4, int echoPin4) : 
                           mySonar1(trigPin1, echoPin1, max_distance),
                           mySonar2(trigPin2, echoPin2, max_distance),
                           mySonar3(trigPin3, echoPin3, max_distance),
                           mySonar4(trigPin4, echoPin4, max_distance) {}

void Ultra_Sonics::read() {
    sonar1 = mySonar1.ping_cm();
    sonar1 = sonar1 == 0 ? maxDistance : sonar1;
    sonar2 = mySonar2.ping_cm();
    sonar2 = sonar2 == 0 ? maxDistance : sonar2;
    sonar3 = mySonar3.ping_cm();
    sonar3 = sonar3 == 0 ? maxDistance : sonar3;
    sonar4 = mySonar4.ping_cm();
    sonar4 = sonar4 == 0 ? maxDistance : sonar4;
}

void Ultra_Sonics::maxDist(int max) {
    this->maxDistance = max;
}

void Ultra_Sonics::read(int delayms) {
    sonar1 = mySonar1.ping_cm();
    sonar1 = sonar1 == 0 ? maxDistance : sonar1;
    delay(delayms);
    sonar2 = mySonar2.ping_cm();
    sonar2 = sonar2 == 0 ? maxDistance : sonar2;
    delay(delayms);
    sonar3 = mySonar3.ping_cm();
    sonar3 = sonar3 == 0 ? maxDistance : sonar3;
    delay(delayms);
    sonar4 = mySonar4.ping_cm();
    sonar4 = sonar4 == 0 ? maxDistance : sonar4;
}

bool Ultra_Sonics::allResponding() {
    if (
        sonar1 == maxDistance ||
        // sonar2 == maxDistance ||
        // sonar3 == maxDistance ||
        sonar4 == maxDistance
    ) return false; // return false if one sensor is in max dist
    return true; // else all sensor responding
}

long Ultra_Sonics::getLeft() {
    return sonar1;
}

long Ultra_Sonics::getFrontLeft() {
    return sonar2;
}

long Ultra_Sonics::getFrontRight() {
    return sonar3;
}

long Ultra_Sonics::getRight() {
    return sonar4;
}

long Ultra_Sonics::getFront() {
    return sonar2 + sonar3;
}

long Ultra_Sonics::getSide() {
    return sonar1 + sonar4;
}
