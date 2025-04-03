#include "encoder.h"

volatile int Encoder::leftTicks = 0;
volatile int Encoder::rightTicks = 0;

int Encoder::leftEncoderA = -1;
int Encoder::leftEncoderB = -1;
int Encoder::rightEncoderA = -1;
int Encoder::rightEncoderB = -1;

Encoder::Encoder(int pinA, int pinB) : pinA(pinA), pinB(pinB) {}

void Encoder::initialize()
{
    pinMode(pinA, INPUT_PULLUP);
    pinMode(pinB, INPUT_PULLUP);

    if (leftEncoderA == -1) {
        leftEncoderA = pinA;
        leftEncoderB = pinB;
        attachInterrupt(digitalPinToInterrupt(leftEncoderA), isrLeft, RISING);
    } else if (rightEncoderA == -1) {
        rightEncoderA = pinA;
        rightEncoderB = pinB;
        attachInterrupt(digitalPinToInterrupt(rightEncoderA), isrRight, RISING);
    }
}

void IRAM_ATTR Encoder::isrLeft()
{
    if (digitalRead(leftEncoderB) == HIGH)
        leftTicks++;
    else
        leftTicks--;
}

void IRAM_ATTR Encoder::isrRight()
{
    if (digitalRead(rightEncoderB) == HIGH)
        rightTicks++;
    else
        rightTicks--;
}

int Encoder::getLeftTicks()
{
    return leftTicks;
}

int Encoder::getRightTicks()
{
    return rightTicks;
}

void Encoder::resetTicks()
{
    leftTicks = 0;
    rightTicks = 0;
}

void Encoder::printTicks()
{
    Serial.print("Left: ");
    Serial.print(leftTicks);
    Serial.print(" | Right: ");
    Serial.println(rightTicks);
}
