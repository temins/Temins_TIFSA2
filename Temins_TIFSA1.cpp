#include "Arduino.h"
#include "Temins_TIFSA1.h"

#define MIN_PERIOD 1000
volatile unsigned long periode, periode2, waktu;
volatile int freq = 0;
float frekuensi;
int Tout = 1000;
int _pin;

Temins_TIFSA1::Temins_TIFSA1(uint8_t pin) {
    _pin = pin;
}

float Temins_TIFSA1::getPeriod() {
    return periode*2;
}

float Temins_TIFSA1::getFrequency() {
	attachInterrupt(digitalPinToInterrupt(_pin), hitung_freq, RISING);	
	delay(100);
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
    detachInterrupt(digitalPinToInterrupt(_pin));
    return frekuensi;
}

void Temins_TIFSA1::hitung_freq(void) {
    //Serial.println("terjadi");
    if (freq > 0) {
        periode = micros() - waktu;
    }
    waktu = micros();
    freq++;
}
