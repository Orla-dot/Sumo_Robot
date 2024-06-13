#ifndef MOTOR_DRIVER_H
#define MOTOR_DRIVER_H


#include "Arduino.h"



class MotorDriver
{
    public:
        MotorDriver(uint8_t pinA1, uint8_t pinA2, uint8_t pinB1, uint8_t pinB2);
        void AttachEnables(uint8_t enL, uint8_t enR);
        void SetDirectionalVelocity(int8_t dir, uint8_t vel);
        inline void SetDirection(int16_t dir) {if (abs(dir) <= 180 )direction = dir;}
        inline void SetVelocity (uint8_t vel) {if (abs(vel) <= 255) velocity  = vel;}
        void DriveMotors();
    
    private:

        void RelateVelocity(double percentA, double percentB, char* velocL, char* velocR);
        void SendVelocity (char* velocLeft, char* velocRighe);
        void SendDirection(bool* direcLeft, bool* direcRight);

        uint8_t motorLeft1;
        uint8_t motorLeft2;
        uint8_t motorRight1;
        uint8_t motorRight2;

        uint8_t enableLeft ;
        uint8_t enableRight;

        uint8_t velocity  = 255;
        int16_t direction = 0;
};


#endif // MOTOR_DRIVER_H