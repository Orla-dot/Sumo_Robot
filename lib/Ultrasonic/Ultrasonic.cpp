#include "Ultrasonic.h"

Ultrasonic::Ultrasonic(uint8_t trig, uint8_t echo)
{
    TRIG = trig;
    ECHO = echo;

    pinMode(ECHO, INPUT );
    pinMode(TRIG, OUTPUT);
}

void   Ultrasonic::SetRange(unsigned int minDist, unsigned int maxDist)
{
    SetMinDistance(minDist);
    SetMaxDistance(maxDist);
}

bool   Ultrasonic::RequestOnRange()
{
    if (distance < minDistance || distance > maxDistance) return false;
    
    return true;
}

double Ultrasonic::ReturnDistance()
{
    EmitPulse();
    
    int time = pulseIn(ECHO, HIGH);
    distance = double(time*speedOfSound/2);

    return distance;
}

void Ultrasonic::EmitPulse() {
    digitalWrite(TRIG, LOW );
    delayMicroseconds(2);

    digitalWrite(TRIG, HIGH);
    delayMicroseconds(pulseDuration);

    digitalWrite(TRIG, LOW );
}