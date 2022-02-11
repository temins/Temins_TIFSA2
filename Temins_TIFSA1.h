#ifndef Temins_TIFSA1_h
#define Temins_TIFSA1_h

#include "Arduino.h"

class Temins_TIFSA1
{
    public:
    Temins_TIFSA1(uint8_t pin);
    float getFrequency();
    static float getPeriod();
  private:
    //int _pin;
};

#endif
