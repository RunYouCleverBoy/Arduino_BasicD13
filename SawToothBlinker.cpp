#include "SawToothBlinker.h"

void SawToothBlinker::onLoop() {
    long uSec = micros();
    int intens = intensity(uSec);
    int tFrame = (uSec / 10) % 256;
    digitalWrite(gpio, (tFrame < intens) ? HIGH : LOW); 
}

void SawToothBlinker::onSetup() {
    pinMode(gpio, OUTPUT);
}

int SawToothBlinker::intensity(long t) {
    return ((int)((float)t * fHz * 256.0/1000000.0)) % 256;
}