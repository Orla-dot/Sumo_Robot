# Sumo_Robot
## Librarys
### Ultrasonic
The ultrasonic is a self library to use the ultrasonic sensor HC-SR04
model

#### Beging the 
to start, first set the TRIG(input pin) and the ECHO(output pin)
and conect us on the expected pins on the sensor. review the
conection.
between the board and sensor and test using the comand:

- "(variableName) =(objectName).ReturnDistance()"

#### Return distance
this returns a float value representing the distance in cm

#### Request distance on range
this method returns a boolean value, when distance is on range,
mentioned below the retorned value is True, else, the retorned value
is False. the standed range value is 0cm - 15cm that's can be chaged
use the methods "Set" below.
##### set max and min distance
the method "Set" are used to change the range of distance.
the methoda are:
- SetMinDistance (MinDist);
- SetMaxDistance (MaxDist);
- SetRange (minDist, maxDist);