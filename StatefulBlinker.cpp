#include "StatefulBlinker.h"

StatefulBlinker::StatefulBlinker(int gpio, int fHz)
{
    this->gpio = gpio;
    tPeriod = (int)(1000.0 / fHz) / 2;
}

void StatefulBlinker::onSetup()
{
    pinMode(gpio, OUTPUT);
}

void StatefulBlinker::onLoop()
{
    long now = millis();
    if (now - lastSwap > tPeriod)
    {
        state = state == HIGH ? LOW : HIGH;
        digitalWrite(gpio, state);
        lastSwap = now;
    }
}
