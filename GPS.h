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
        void getGPS();
        
    
    private:
        int _pin;
        TinyGPS gps;
        SoftwareSerial gpsSerial(3,4);//rx,tx 
}

#endif
