# Sumo_Robot

## Librarys

### Ultrasonic
The ultrasonic is a self library to use the ultrasonic sensor HC-SR04
model
####  Beging the:
to start, first set the TRIG(input pin) and the ECHO(output pin)
and conect us on the expected pins on the sensor. review the
conection.
between the board and sensor and test using the comand:

- "(variableName) =(objectName).ReturnDistance()" // Obs: the
distance is in mm,

####  Request distance on range:
this method returns a boolean value, when distance is on range, 
mentioned below the retorned value is True, else, the retorned value 
is False. the standed range values is 0m - 1.5m that's can be chaged 
use the methods "Set" below.
#####   Set range:
the method "Set" are used to change the range of distance(in mm).
the methoda are:
- SetMinDistance (MinDist);
- SetMaxDistance (MaxDist);
- SetRange (minDist, maxDist);

####  Set pulse duration:
A wave can louse energy depending the object that wave's is crossing,
the pulse duration need be more longer to cross athes objects in more
distance.
to use this methoh, insert a value in microseconds. with example:

    void loop() {
        ...
        (objectName).SetPulseDuration(value)
        ...
    }


### Motor driver:
The motor driver library is a H-bridge controller used to controll 
the L298 H-bridge and similars
####  Beging the:
to start, frist ser the pin Outputs and attach the enables to library
with the method:

    void Setup(){
        ...
        (objectName).AttachEnables(enableA, enableB); // use PWM
        pins
        ...
    }

####  Drive motors:
use this method to activate the motor and contorl with altomatic the 
direction(use DEGs) and the velocity(use char limit)
#####   change velocity and direction:
The methods "Set" are used to change the values of velocity and
directions.
the methods are:
-void SetVelocity (vel)
-void SetDirection (dir)
-void SetDirectionalVelocity (dir, vel);