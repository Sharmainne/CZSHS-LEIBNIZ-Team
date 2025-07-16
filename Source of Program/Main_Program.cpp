#include <Arduino.h>       // For basic Arduino functions
#include "Display.h"        // For display handling
#include "Ultra_Sonic.h"   // For Ultrasonic Sensors
#include "Servo_Motor.h"    // For Servo control
#include "Gyro.h"           // For Gyro Sensor
#include "Motor.h"          // For Motor control
#include "PID.h"            // For PID control
#include "Button.h"         // For Starter's button
#include "OTA.h"            // For OTA functionality

#define ButtonPin 15 

#define Gyro_I2C_SDA 21
#define Gyro_I2C_SCL 22

#define ServoSteeringPin 27
#define ServoCameraPin 4

#define Motor_1 32
#define Motor_2 33

#define Ultra_Sonic_Trig_1 17
#define Ultra_Sonic_Echo_1 36
#define Ultra_Sonic_Trig_2 16
#define Ultra_Sonic_Echo_2 39
#define Ultra_Sonic_Trig_3 26
#define Ultra_Sonic_Echo_3 34
#define Ultra_Sonic_Trig_4 25
#define Ultra_Sonic_Echo_4 35

Button myButton(ButtonPin);
Gyro myGyro(Gyro_I2C_SDA, Gyro_I2C_SCL);
Motor myMotor(Motor_1, Motor_2);

Servo_Motor myServoSteering(ServoSteeringPin, 50, 500, 2500, 190, -30, 30); //
Servo_Motor myServoCamera(ServoCameraPin, 50, 500, 2500, 180); //

Ultra_Sonics mySonars(200,  Ultra_Sonic_Trig_1, Ultra_Sonic_Echo_1, 
                            Ultra_Sonic_Trig_2, Ultra_Sonic_Echo_2, 
                            Ultra_Sonic_Trig_3, Ultra_Sonic_Echo_3, 
                            Ultra_Sonic_Trig_4, Ultra_Sonic_Echo_4); // The limitation of ultrasonic detection is 200
//PID for Gyro steering
float KpGyro=0.6;
float KiGyro=0.0;
float KdGyro=0.1;

//PID for Wall Avoidance, to make our robot align itself at the middle between walls
float KpWall=0.8;
float KiWall=0.0;
float KdWall=0.1;

PID mySteeringPID(KpGyro, KiGyro, KdGyro); // PID for steering control
PID myWallSteer(KpWall, KiWall, KdWall);

void setup() {
  Serial.begin(115200);
  Serial.println("Robot ESP32 starting..."); // To determine if our robot is ready enough to make a run

  // To setup the values to 0
  myMotor.setup();
  myGyro.setup();
  myButton.setup();
  
  myServoSteering.write360(0);  // To stop the rear wheels from moving
  
  // Now wait for button press to start
  while (!myButton.Pressed()) {
    // setup the value of gyro to 0 and run the ultrasonics
      myGyro.getData();
      myGyro.readAll();
      mySonars.read();
   
    // To monitor the value of gyro and ultrasonics
      Serial.print(" ANGLE: ");
      Serial.print(myGyro.AccumAngleX); Serial.print(" ");
      Serial.print(" Sonars: ");
      Serial.print(mySonars.getLeft()); Serial.print(" ");
      Serial.print(mySonars.getFrontLeft()); Serial.print(" ");
      Serial.print(mySonars.getFrontRight()); Serial.print(" ");
      Serial.print(mySonars.getRight()); Serial.println(" ");
  }

  myMotor.write(140); // To make the robot move forward
}

//=============================================================//
// to initialize these variables to 0
int turn = 0;
int direction = 0;
int targetAngle = 0;
int turnTime = 0;
int nextTurn = 0;

// For global calibration of these variables
int turntimemax = 25; // Maximum time to turn
int nextturnmax = 60; // Maximum time to wait before next turn
int totalwidth = 200; // Minimum distance to side wall for turning
int gyrodriftcompensation = 1.2; // Gyro drift compensation factor
int targetAngleRange = 50; // Acceptable range for target angle
int frontDistance = 400; // Maximum distance to front wall for turning

void loop() {

  myGyro.getData();
  myGyro.readAll();
  mySonars.read();

  targetAngle = ((turn * 90) - (turn * gyrodriftcompensation * -direction)) * direction;  // To guide the robot's turn consecutively then calculated value will be received by gyro

  // logic to turn based on the following:
  // 1. the angle is within range of +/-10 of the target angle
  // 2. the front is is less than 

  if ((targetAngle - targetAngleRange <= myGyro.AccumAngleX && myGyro.AccumAngleX <= targetAngle + targetAngleRange) 
      && mySonars.getFront() <= frontDistance
      && mySonars.getSide() >= totalwidth
      && nextTurn == 0
    ) {
    turn++;
    turnTime = turntimemax;
    nextTurn = nextturnmax;
    if (direction == 0) {
      if (mySonars.getLeft() > mySonars.getRight()) {
        direction = -1; // if the ultaronic on the left side is greater than ultraonic on right side, he direction(-1) will be multiplied to 90° turn of servo steering motor
      } else {
        direction = 1; // if the ultaronic on the left side is greater than ultraonic on right side, the direction (1) will be multiplied to 90° turn of servo steering motor
      }
    }
  }

  // front obstacle avoidance
  int frontLeft = mySonars.sonar2; // Limit to 100 for avoidance logic
  int frontRight = mySonars.sonar3;
  int left = mySonars.sonar1;
  int right = mySonars.sonar4;

  int wallsteer = myWallSteer.read(0, left - right);

  int pid;
  if (turnTime == 0) {
    pid = mySteeringPID.read(wallsteer + targetAngle, myGyro.readAccumX());
  } else {
    pid = mySteeringPID.read(targetAngle, myGyro.readAccumX());
    turnTime--;
  }
  if (nextTurn != 0) {
    nextTurn--;
  }

  //calculate PID based on Gyro and add left and right wall avoidance
  myServoSteering.write360(-pid);
  myMotor.write(constrain((mySonars.getFront()/1.5) + 20, 100, 255)); // gather sensor data

  // To monior the behavior of our robot
  Serial.print("TARGET: ");
  Serial.print(targetAngle); Serial.print(" ");
  Serial.print(" ANGLE: ");
  Serial.print(myGyro.AccumAngleX); Serial.print(" ");
  Serial.print(" Sonars: ");
  Serial.print(mySonars.getLeft()); Serial.print(" ");
  Serial.print(mySonars.getFrontLeft()); Serial.print(" ");
  Serial.print(mySonars.getFrontRight()); Serial.print(" ");
  Serial.print(mySonars.getRight()); Serial.print(" ");


  
  Serial.print(" COND: ");
  Serial.print(targetAngle - targetAngleRange <= myGyro.AccumAngleX); Serial.print(" ");
  Serial.print(myGyro.AccumAngleX <= targetAngle + targetAngleRange); Serial.print(" ");
  Serial.print(mySonars.getFront() <= frontDistance); Serial.print(" ");
  Serial.print(mySonars.getSide() >= totalwidth); Serial.print(" ");
  Serial.print(turnTime); Serial.print("");

  Serial.print(" WALLSTEER: ");
  Serial.print(wallsteer); Serial.print(" ");
  Serial.print(nextTurn); Serial.print(" ");
  Serial.print(turnTime); Serial.print(" ");
  Serial.print(-pid); Serial.print(" ");
  Serial.print(direction); Serial.print("");

  Serial.print(" TURN: ");
  Serial.print(turn); Serial.print(" ");
  Serial.print(direction == 0 && mySonars.getLeft() > mySonars.getRight()); Serial.print(" | ");
  Serial.print(mySonars.getFront()); Serial.print(" ");
  Serial.print(mySonars.getSide()); Serial.println();
}
