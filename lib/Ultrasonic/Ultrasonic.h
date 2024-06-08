#ifndef ULTRASONIC_H
#define ULTRASONIC_H


#include "Arduino.h"

class Ultrasonic
{
    public:
        Ultrasonic(uint8_t trig, uint8_t echo);

        inline void SetMinDistance(unsigned int MinDist){minDistance = MinDist;}
        inline void SetMaxDistance(unsigned int MaxDist){maxDistance = MaxDist;}
        void SetRange(unsigned int minDist, unsigned int maxDist);

        bool  RequestDistanceOnRange();
        float ReturnDistance();

    private:
        uint8_t TRIG;
        uint8_t ECHO;

        const int speedOfSound = 0.0343;

        float distance;
        unsigned int   minDistance;
        unsigned int   maxDistance;

}; // Ultrasonic_Class


#endif // ULTRASONIC_H