#include "MotorControl.h"

#define minPulse 1000  // Minimum pulse length in µs
#define maxPulse 2000  // Maximum pulse length in µs
#define stopPulse 1500        // Stop signal for ESC

MotorControl::MotorControl(int leftPin, int rightPin) 
    : leftPin(leftPin), rightPin(rightPin) {}

void MotorControl::initialize() {
    ESP32PWM::allocateTimer(1);
    ESP32PWM::allocateTimer(2);

    leftMotor.attach(leftPin, minPulse, maxPulse);
    rightMotor.attach(rightPin, minPulse, maxPulse);

    calibrate();
}

void MotorControl::calibrate() {
    Serial.println("Calibrating motors...");
    leftMotor.writeMicroseconds(stopPulse);
    rightMotor.writeMicroseconds(stopPulse);
    delay(3000);
    Serial.println("Calibration complete.");
}

void MotorControl::stop() {
    leftMotor.writeMicroseconds(stopPulse);
    rightMotor.writeMicroseconds(stopPulse);
}

void MotorControl::setSpeed(int leftSpeed, int rightSpeed) {
    leftMotor.writeMicroseconds(stopPulse + leftSpeed * 5);
    rightMotor.writeMicroseconds(stopPulse - rightSpeed * 5);
}
