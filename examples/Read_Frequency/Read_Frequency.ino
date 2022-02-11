#include <Temins_TIFSA1.h>

Temins_TIFSA1 sensorFreq(2); //Pin used to connect to sensor. This example use pin 2

void setup() {
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  float periode = sensorFreq.getPeriod();
  float frekuensi = sensorFreq.getFrequency();
  Serial.print("Periode : ");
  Serial.println(periode);
  Serial.print("Frekuensi : ");
  Serial.println(frekuensi);
  delay(1000);
}
