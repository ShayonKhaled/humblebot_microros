#ifndef MOTOR_CONTROL_H
#define MOTOR_CONTROL_H

#include <Arduino.h>
#include <ESP32Servo.h>

class MotorControl {
public:
    MotorControl(int leftPin, int rightPin);
    
    void initialize();  // Initializes ESCs
    void calibrate();   // Calibrates ESCs
    void stop();        // Stops both motors
    void setSpeed(int leftSpeed, int rightSpeed); // Sets motor speeds

private:
    Servo leftMotor;
    Servo rightMotor;
    int leftPin;
    int rightPin;
};

#endif // MOTOR_CONTROL_H
