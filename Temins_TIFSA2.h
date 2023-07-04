#ifndef Temins_TIFSA2_h
#define Temins_TIFSA2_h

#include "Arduino.h"

class Temins_TIFSA2
{
    public:
    Temins_TIFSA2(uint8_t pin);
    float getFrequency();
    float getPeriod();
  private:
    //int _pin;
};

#endif
