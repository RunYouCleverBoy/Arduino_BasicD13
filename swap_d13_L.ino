#include "StatefulBlinker.h"
#include "SawToothBlinker.h"

#define L_PIN 13

Runner *runner = NULL;

void setup()
{
  // put your setup code here, to run once:
  Serial.begin(115200);
  runner = new StatefulBlinker(L_PIN, 1);
  // runner = new SawToothBlinker(L_PIN, 0.5);
  runner->onSetup();
}

void loop()
{
  // put your main code here, to run repeatedly:
  runner->onLoop();
}

