#include "GPS.h"
#include <TinyGPS.h>
#include <SoftwareSerial.h> 

TinyGPS gps;
float lat = 28.5458,lon = 77.1703;

GPS::GPS(int pin)
{
    pinMode(pin, OUTPUT);
}

GPS::init()
{
    gpsSerial.begin(9600); // connect gps sensor
}

GPS::getGPS()
{
    if (gpsSerial.available()){
        if (gps.encode(gpsSerial.read())){
            gps.f_get_position(&lat,&lon);
        }
    }
}
