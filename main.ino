#include <SPI.h>
#include <RF24.h>
#include "GPS.h"

/* Hardware configuration: Set up nRF24L01 radio on SPI bus plus pins 7 & 8 */
bool radioNumber = 0;
RF24 radio(9,10);
byte addresses[][6] = {"1Node","2Node"};

//Kalibrierungswert für einen Meter
int calib = 0;
const CLAIBVALUE = 0;

// Pins für alle analogen Eingänge
// Ultraschallsensoren
const ULTRASCHALL1 = 1
const ULTRASCHALL2 = 2
const ULTRASCHALL3 = 3
const ULTRASCHALL4 = 4
const ULTRASCHALL5 = 5

// Radarsensoren
const RADAR1 = 6;
const RADAR1 = 7;
const RADAR1 = 8;
const RADAR1 = 9;
const RADAR1 = 10;

// Variable für Analogpins Ultraschallsensoren
int ultraschall1Pin = ULTRASCHALL1;
int ultraschall2Pin = ULTRASCHALL2;
int ultraschall3Pin = ULTRASCHALL3;
int ultraschall4Pin = ULTRASCHALL4;
int ultraschall5Pin = ULTRASCHALL5;

// Variable für Analogpins Radarsensoren
int radar1Pin = RADAR1;
int radar2Pin = RADAR2;
int radar3Pin = RADAR3;
int radar4Pin = RADAR4;
int radar5Pin = RADAR5;

// Arrays für Values von Sensoren
int radar[5];
int ultraschall[5];

// Aktuallisiert die Werte der Radarsensoren
int [5] aktuallisierenRadar(){
    int array[5];
    array[0] = analogRead(radar1Pin);
    array[1] = analogRead(radar2Pin);
    array[2] = analogRead(radar3Pin);
    array[3] = analogRead(radar4Pin);
    array[4] = analogRead(radar5Pin);
    return array;
}

// Aktuallisiert die Werte der Ultraschallsensoren
int [5] aktuallisierenUltraschall(){
    int array[5];
    array[0] = analogRead(ultraschall1Pin);
    array[1] = analogRead(ultraschall2Pin);
    array[2] = analogRead(ultraschall3Pin);
    array[3] = analogRead(ultraschall4Pin);
    array[4] = analogRead(ultraschall5Pin);
    return array;
}

//Berechnet mittels Calibdatensatz die Entfernung in Meter
float berechneEntfernung(int sensorWert){
    float a = sensorWert/calib;
    return a;
}

/*
Berechnet die Reichweite mittels Vektoren, {x-Koordinate, y-Koordinate, Höhe}
*/
bool checkReichweite(int maxReichweite, int xGPS, int yGPS, int hight){
    return false;
}

// Initialisiert 2.4 GHz Antenne
void initSenderEmpfaenger(){
    radio.begin();
    // Set the PA Level low to prevent power supply related issues since this is a
    // getting_started sketch, and the likelihood of close proximity of the devices. RF24_PA_MAX is default.
    radio.setPALevel(RF24_PA_LOW);
    // Open a writing and reading pipe on each radio, with opposite addresses
    if(radioNumber){
        radio.openWritingPipe(addresses[1]);
        radio.openReadingPipe(1,addresses[0]);
        }else{
        radio.openWritingPipe(addresses[0]);
        radio.openReadingPipe(1,addresses[1]);
    }
    // Start the radio listening for data
    radio.startListening();
}

void initSerial(int baudRate){
    Serial.begin(9600);
}

GPS GPS = GPS(1,2);

void setup(){
    GPS.init(1,2);
}

void loop(){
    
}