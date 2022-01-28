#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Temins_TIVSA1.h>

Temins_TIVSA1 sensorFreq(2); //Interrupt pin used to connect to sensor. Only use interrupt pin.
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  lcd.init();
  // Print a message to the LCD.
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("TIVSA1");
  lcd.setCursor(0, 1);
  lcd.print("Frequency Sensor");
  delay(1000);
  lcd.clear();
}

void loop() {
  // put your main code here, to run repeatedly:
  float periode = sensorFreq.getPeriod();
  float frekuensi = sensorFreq.getFrequency();
  Serial.println(periode);
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
