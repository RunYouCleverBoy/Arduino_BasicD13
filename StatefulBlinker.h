#include <Arduino.h>
#include "Runner.h"

#ifndef _STATEFUL_BLINKER_H_
#define _STATEFUL_BLINKER_H_

class StatefulBlinker: public Runner {
    private:
        int state = HIGH;
        long lastSwap = 0;
        int gpio = 13;
        int tPeriod;
    public:
        StatefulBlinker(int gpio, int fHz);
        void onSetup();
        void onLoop();
};

// class StatefulBlinker : public Runner
// {
// private:
//   int state = HIGH;
//   long lastSwap = 0;
//   int gpio = 13;
//   int tPeriod;

// public:
//   StatefulBlinker(int gpio, int fHz) : Runner()
//   {
//     this->gpio = gpio;
//     tPeriod = (int)(1000.0/fHz)/2;
//   }

//   void onSetup()
//   {
//     pinMode(gpio, OUTPUT);
//   }

//   void onLoop()
//   {
//     long now = millis();
//     if (now - lastSwap > tPeriod)
//     {
//       state = state == HIGH ? LOW : HIGH;
//       digitalWrite(gpio, state);
//       lastSwap = now;
//     }
//   }
// };

#endif