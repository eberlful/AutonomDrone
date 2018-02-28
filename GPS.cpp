#include "GPS.h"
#include <TinyGPS.h>
#include <SoftwareSerial.h> 

TinyGPS gps;
float lat = 28.5458,lon = 77.1703;
SoftwareSerial ss;

/*
1. GPS mittels Konstruktor erstellen
2. GPS-Serial kommunikation starten
*/

GPS::GPS(int pin1, int pin2)
{
    ss(pin1, pin2);
}

GPS::init()
{
    gpsSerial.begin(9600); // connect gps sensor
    ss.begin(9600);
    Serial.begin(9600);
}

GPS::getGPS()
{
    if (gpsSerial.available()){
        if (gps.encode(gpsSerial.read())){
            gps.f_get_position(&lat,&lon);
        }
    }

    while (ss.available() > 0){
        byte gpsData = ss.read();
        Serial.write(gpsData);
    }
}


