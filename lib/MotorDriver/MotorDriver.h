#ifndef MOTOR_DRIVER_H
#define MOTOR_DRIVER_H


#include "Arduino.h"

class MotorDriver
{
    public:
        MotorDriver(uint8_t pinA1, uint8_t pinA2, uint8_t pinB1, uint8_t pinB2);
        void AttachEnables(uint8_t enA, uint8_t enB);

        void DriveMotors();

        char SendVelocits(double percentA, double percentB);
        inline void SetVelocity(uint8_t vel) {velocity  = vel;}
        inline void SetDirection(int8_t dir) {direction = dir;}
        void SetDirectionalVelocity(int8_t dir, uint8_t vel);

        unsigned char ReturnVelocity();
        bool ReturnDirection();
    
    private:
        uint8_t motorA1;
        uint8_t motorA2;
        uint8_t motorB1;
        uint8_t motorB2;

        uint8_t enable_A;
        uint8_t enable_B;

        uint8_t velocity  = 255;
        int8_t  direction = 0;
};


#endif // MOTOR_DRIVER_H