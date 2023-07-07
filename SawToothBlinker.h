#ifndef _SAWTOOTH_BLINKER_H_
#define _SAWTOOTH_BLINKER_H_

#include <Arduino.h>
#include "Runner.h"

class SawToothBlinker : public Runner {
    private:
        float fHz;
        int gpio;
        long lastSetTs = 0;
        int intensity(long t);
    public:
        SawToothBlinker(int gpio, float fHz) {
            this->gpio = gpio;
            this->fHz = fHz;
        }
        void onLoop();
        void onSetup();
};
#endif