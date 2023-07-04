/* Library written by Temins
    Dibuat sendiri oleh tim kami. Mohon beli produk asli dari kami untuk mensupport kami. */

#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Temins_TIFSA2.h>

Temins_TIFSA2 sensorFreq(2); //Pin used to connect to sensor. This example use pin 2
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Temins TIFSA1");
  lcd.setCursor(0, 1);
  lcd.print("Frequency Sensor");
  delay(1000);
  lcd.clear();
}

void loop() {
  float periode = sensorFreq.getPeriod();
  float frekuensi = sensorFreq.getFrequency();
  Serial.print("Periode : ");
  Serial.println(periode);
  Serial.print("Frekuensi : ");
  Serial.println(frekuensi);
  lcd.setCursor(0, 0);
  lcd.print("Freq:");
  lcd.print(frekuensi);
  lcd.print("Hz");
  lcd.setCursor(0, 1);
  lcd.print("Periode:");
  lcd.print(periode);
  lcd.print("us");
  delay(1000);
}
