#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2);
const int LDRpin = A0;

void setup() {
  lcd.init();
  lcd.clear();
  lcd.backlight();
  
}

void loop() {
  int LDRvalue = analogRead(LDRpin);
  lcd.setCursor(2,0);
  lcd.print("Hello World");

  lcd.setCursor(0, 1);
  lcd.print("LDR Value : ");
  lcd.print(LDRvalue);
}
