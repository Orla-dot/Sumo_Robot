#include "Ultrasonic.h"

Ultrasonic::Ultrasonic(uint8_t trig, uint8_t echo)
{
    TRIG = trig;
    ECHO = echo;

    pinMode(ECHO, OUTPUT);
    pinMode(TRIG, INPUT );
}


void Ultrasonic::SetRange(unsigned int minDist, unsigned int maxDist)
{
    SetMinDistance(minDist);
    SetMaxDistance(maxDist);
}
bool  Ultrasonic::RequestDistanceOnRange()
{
    if (distance < minDistance || distance > maxDistance)
    {
        return false;
    }

    return true;
}
float Ultrasonic::ReturnDistance()
{
    digitalWrite(TRIG, HIGH);
    delayMicroseconds(10);
    digitalWrite(TRIG, LOW );

    int time = pulseIn(ECHO, HIGH);

    distance = time*speedOfSound/2;
}