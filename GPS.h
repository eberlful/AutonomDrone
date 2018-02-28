#ifdef GPS
#define GPS;

#include "Arduion.h"
#include <SoftwareSerial.h> 
#include <TinyGPS.h>

class GPS 
{
    public:
        GPS(int pin);
        bool status();
        void init();
        String getGPS();
        
    
    private:
        int _pin;
        TinyGPS gps;
        SoftwareSerial gpsSerial(3,4);//rx,tx 
        float lat, lon;
}

#endif