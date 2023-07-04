/* Library written by Temins
    Dibuat sendiri oleh tim kami. Mohon beli produk asli dari kami untuk mensupport kami. */

#include <Temins_TIFSA2.h>

Temins_TIFSA2 sensorFreq(2); //Pin used to connect to sensor. This example use pin 2

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
