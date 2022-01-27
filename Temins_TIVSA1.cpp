#include "Arduino.h"
#include "Temins_TIVSA1.h"

#define MIN_PERIOD 1000
unsigned long periode, periode2, waktu;
int freq = 0;
float frekuensi;
int Tout = 1000;

Temins_TIVSA1::Temins_TIVSA1(uint8_t pin) {
    attachInterrupt(digitalPinToInterrupt(pin), hitung_freq, RISING);
    _pin = pin;
}

float Temins_TIVSA1::getPeriod() {
    return periode*2;
}

float Temins_TIVSA1::getFrequency() {
    if (periode > MIN_PERIOD) {
        frekuensi = ((1.0 / periode) * 1000000) / 2;
    } else {
        frekuensi = 0;
    }
    if (millis() - waktu > Tout) {
        if (periode == periode2) {
        periode = 0;
        }
        periode2 = periode;
        waktu = millis();
    }
    return frekuensi;
}

void Temins_TIVSA1::hitung_freq(void) {
    //Serial.println("terjadi");
    if (freq > 0) {
        periode = micros() - waktu;
    }
    waktu = micros();
    freq++;
}