#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Temins_TIVSA1.h>

Temins_TIVSA1 sensorFreq(2); //Interrupt pin used to connect to sensor. Only use interrupt pin.

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  float periode = sensorFreq.getPeriod();
  float frekuensi = sensorFreq.getFrequency();
  Serial.println(periode);
  Serial.println(frekuensi);
  delay(1000);
}
