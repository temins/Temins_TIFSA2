#ifndef Temins_TIFSA2_h
#define Temins_TIFSA2_h

#include "Arduino.h"

class Temins_TIFSA1
{
    public:
    Temins_TIFSA1(uint8_t pin);
    float getFrequency();
    float getPeriod();
  private:
    //int _pin;
};

#endif
