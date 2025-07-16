#ifndef ULTRA_SONIC_H
#define ULTRA_SONIC_H

#include <Arduino.h>
#include <NewPing.h>

class Ultra_Sonics {
    public:
        NewPing mySonar1;
        NewPing mySonar2;
        NewPing mySonar3;
        NewPing mySonar4;
        long sonar1;
        long sonar2;
        long sonar3;
        long sonar4;
        int maxDistance = 200;

        Ultra_Sonics(int max_distance,  int trigPin1, int echoPin1, 
                                        int trigPin2, int echoPin2, 
                                        int trigPin3, int echoPin3, 
                                        int trigPin4, int echoPin4);

        void read();  
        void read(int delayms); 
        void maxDist(int max);
        bool allResponding();
        long getFront();
        long getSide();
        long getLeft();
        long getFrontLeft();
        long getFrontRight();
        long getRight();
};

#endif // !ULTRA_SONIC_H
