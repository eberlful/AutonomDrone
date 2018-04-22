#ifdef GPS
#define GPS;

class Checksum 
{
    public:
        Checksum();
        bool check(Byte[] speicher);
        
    
    private:
        Byte[] value;
        bool[] zerlegen(Byte register);
}

#endif