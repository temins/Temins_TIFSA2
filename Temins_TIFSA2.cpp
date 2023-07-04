#include "Arduino.h"
#include "Temins_TIFSA2.h"

#define TOut 2000000
static unsigned long time1, time2, waktu;
static int _pin;
static float periode,frekuensi;

Temins_TIFSA2::Temins_TIFSA2(uint8_t pin) {
    _pin = pin;
    pinMode(_pin, INPUT);
}

float Temins_TIFSA2::getPeriod() {
    waktu = micros();
    while (digitalRead(_pin) == LOW) {
        if (micros()-waktu>TOut){
            return 0;
        }
        yield();
    }
    while (digitalRead(_pin) == HIGH) {
        if (micros()-waktu>TOut){
            return 0;
        }
        yield();
    }
    time1 = micros();
    while (digitalRead(_pin) == LOW) {
        if (micros()-waktu>TOut){
            return 0;
        }
        yield();
    }
    time2 = micros();
    periode = time2 - time1;
    periode*=1.035;
    periode+=450;
    return periode*2;
}

float Temins_TIFSA2::getFrequency() {
    frekuensi = (1.0/getPeriod())*1000000.0;
    return frekuensi;
}
