#ifndef ENCODER_H
#define ENCODER_H

#include <Arduino.h>

class Encoder {
public:
    Encoder(int pinA, int pinB);
    void initialize();

    static void IRAM_ATTR isrLeft();
    static void IRAM_ATTR isrRight();

    static int getLeftTicks();
    static int getRightTicks();
    void resetTicks();
    void printTicks();

private:
    int pinA;
    int pinB;
    
    static int leftEncoderA;  // Store left encoder A pin
    static int leftEncoderB;  // Store left encoder B pin
    static int rightEncoderA; // Store right encoder A pin
    static int rightEncoderB; // Store right encoder B pin

    static volatile int leftTicks;
    static volatile int rightTicks;
};

#endif
