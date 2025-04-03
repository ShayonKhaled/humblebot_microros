#include <Arduino.h>

#include "motorControl.h"
#include <encoder.h>
#include <microRos.h>

#define leftESC 26
#define rightESC 27
#define leftEncoderA 21
#define leftEncoderB 19
#define rightEncoderA 15
#define rightEncoderB 2

#define leftSpeed -50
#define rightSpeed -50

MotorControl motorControl(leftESC, rightESC);
Encoder leftEncoder(leftEncoderA, leftEncoderB);
Encoder rightEncoder(rightEncoderA, rightEncoderB);

const float baseWidth = 0.185; // adjust based on your robot's track width

int mapToPWM(float vel)
{
  return constrain((int)(vel * 100), -100, 100);
}
void setup()
{
  microRosInit();
  motorControl.initialize(); 

  leftEncoder.initialize();
  rightEncoder.initialize();
}

void loop()
{
  microRosCheck();
  float leftVel = linearVelocity - angularVelocity * baseWidth / 2.0;
  float rightVel = linearVelocity + angularVelocity * baseWidth / 2.0;

  motorControl.setSpeed(mapToPWM(leftVel), mapToPWM(rightVel));
}
