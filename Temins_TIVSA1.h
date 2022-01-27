#ifndef Temins_TIVSA1_h
#define Temins_TIVSA1_h

#include "Arduino.h"

class Temins_TIVSA1
{
    public:
    Temins_TIVSA1(uint8_t pin);
    float getFrequency();
    float getPeriod();
  private:
    int _pin;
    static void hitung_freq(void);
};

#endif