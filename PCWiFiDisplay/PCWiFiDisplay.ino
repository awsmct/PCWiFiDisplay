#include <LiquidCrystal_I2C.h>;
LiquidCrystal_I2C lcd(0x3F, 16, 2); //0x27

void setup(void) 
{
  Serial.begin(115200);
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("WAKE UP NEO!");
  blink();
  lcd.setCursor(0, 1);
  lcd.print("WAKE UP");
  Serial.println("...ok...");
}

void loop(void) 
{
  
}

