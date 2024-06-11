#ifndef ULTRASONIC_H
#define ULTRASONIC_H


#include "Arduino.h"

class Ultrasonic
{
    public:
        Ultrasonic(uint8_t trig, uint8_t echo);

        inline void SetPulseDuration(unsigned char pulseDur) {pulseDuration = pulseDur;}
        inline void SetMinDistance  (unsigned int minDist  ) {minDistance = minDist;}
        inline void SetMaxDistance  (unsigned int maxDist  ) {maxDistance = maxDist;}
        void SetRange(unsigned int minDist, unsigned int maxDist);

        bool   RequestDistanceOnRange();
        double ReturnDistance();

    private:
        uint8_t TRIG;
        uint8_t ECHO;

        const int speedOfSound = 0.343;

        double distance;
        unsigned long pulseDuration = 10;
        unsigned  int minDistance   = 0 ;
        unsigned  int maxDistance   = 1500;

}; // Ultrasonic_Class


#endif // ULTRASONIC_H