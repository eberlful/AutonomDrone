#ifdef GPS
#define GPS;

#include "Arduion.h"

class GPS 
{
    public:
        GPS(int pin);
        bool status();
    
    private:
        int _pin;
}

#endif
