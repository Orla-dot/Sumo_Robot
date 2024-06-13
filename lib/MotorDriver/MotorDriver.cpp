#include "MotorDriver.h"


MotorDriver::MotorDriver(uint8_t pinA1, uint8_t pinA2, uint8_t pinB1, uint8_t pinB2)
{
    if (pinA1 >= 0 && pinA1 <= NUM_DIGITAL_PINS) return;
    if (pinA2 >= 0 && pinA2 <= NUM_DIGITAL_PINS) return;
    if (pinB1 >= 0 && pinB1 <= NUM_DIGITAL_PINS) return;
    if (pinB2 >= 0 && pinB2 <= NUM_DIGITAL_PINS) return;

    motorLeft1  = pinA1;
    motorLeft2  = pinA2;
    motorRight1 = pinB1;
    motorRight2 = pinB2;

    pinMode(motorLeft1 , OUTPUT);
    pinMode(motorLeft2 , OUTPUT);
    pinMode(motorRight1, OUTPUT);
    pinMode(motorRight2, OUTPUT);
    
}

void MotorDriver::AttachEnables(uint8_t enL, uint8_t enR)
{
    enableLeft  = enL;
    enableRight = enR;

    pinMode(enableLeft , OUTPUT);
    pinMode(enableRight, OUTPUT);
}

void MotorDriver::DriveMotors()
{
    bool dirLeft, dirRight;
    char velLeft, velRight;
    SendDirection(&dirLeft, &dirRight);
    SendVelocity (&velLeft, &velRight);
    
    analogWrite(enableLeft , velLeft );
    analogWrite(enableRight, velRight);

    digitalWrite(motorLeft1 ,  dirLeft );
    digitalWrite(motorLeft2 , !dirLeft );
    digitalWrite(motorRight1,  dirRight);
    digitalWrite(motorRight2, !dirRight);
}

void MotorDriver::SetDirectionalVelocity(int8_t dir, uint8_t vel)
{
    SetDirection(dir);
    SetVelocity (vel);
}

void MotorDriver::SendVelocity(char* velocLeft, char* velocRighe)
{
    if (direction == 0) {
        RelateVelocity(1, 1, velocLeft, velocRighe);
        return;
    }

    double percentage = abs(direction) / 180;

    double relationLeft ;
    double relationRight;


    if (direction > 0) {
        relationLeft  = 1 - percentage;
        relationRight = percentage;

    } else {

        relationLeft  = percentage;
        relationRight = 1 - percentage;
    }//(direction < 0)

    RelateVelocity(relationLeft, relationRight, velocLeft, velocRighe);
}

void MotorDriver::RelateVelocity(double percentL, double percentR, char* velocL, char* velocR){
    *velocL = char(velocity * percentL);
    *velocR = char(velocity * percentR);
}

void MotorDriver::SendDirection(bool* direcLeft, bool* direcRight)
{
    if (direction > 90) {
        *direcLeft  = false;
        *direcRight = true;
        return;
    }
        

    if (direction < -90) {
        *direcLeft  = true;
        *direcRight = false;
        return;
    }
        
    *direcLeft  = true;
    *direcRight = true;
}
