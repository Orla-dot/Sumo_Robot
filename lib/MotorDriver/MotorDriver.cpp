#include "MotorDriver.h"

MotorDriver::MotorDriver(uint8_t pinA1, uint8_t pinA2, uint8_t pinB1, uint8_t pinB2)
{
    motorA1 = pinA1;
    motorA2 = pinA2;
    motorB1 = pinB1;
    motorB2 = pinB2;

    pinMode(motorA1, OUTPUT);
    pinMode(motorA2, OUTPUT);
    pinMode(motorB1, OUTPUT);
    pinMode(motorB2, OUTPUT);
}
void MotorDriver::AttachEnables(uint8_t enA, uint8_t enB)
{
    enable_A = enA;
    enable_B = enB;

    pinMode(enable_A, OUTPUT);
    pinMode(enable_B, OUTPUT);
}

void MotorDriver::DriveMotors()
{
    bool dirA, dirB = ReturnDirection();
    char velA, velB = ReturnVelocity();
    
    analogWrite(enable_A, velA);
    analogWrite(enable_B, velB);

    digitalWrite(motorA1,  dirA);
    digitalWrite(motorA2, !dirA);
    digitalWrite(motorB1,  dirB);
    digitalWrite(motorB2, !dirB);
}

char MotorDriver::SendVelocits(double percentA, double percentB){
    char velocA = char(velocity * percentA);
    char velocB = char(velocity * percentA);

    return velocA, velocB;
}
void MotorDriver::SetDirectionalVelocity(int8_t dir, uint8_t vel)
{
    SetDirection(dir);
    SetVelocity(vel);
}

unsigned char MotorDriver::ReturnVelocity()
{
    double percent = abs(direction) / 180;

    double percA = (0 + percent);
    double percB = (1 - percent);


    if (direction > 0) return SendVelocits(percA, percB);

    if (direction < 0) return SendVelocits(percB, percA);

    return SendVelocits(1, 1);
}
bool MotorDriver::ReturnDirection()
{
    if (direction > 0) return true, false;

    if (direction < 0) return false, true;
    
    return true, true;
}
