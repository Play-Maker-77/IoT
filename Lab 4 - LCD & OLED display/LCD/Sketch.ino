#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Set the LCD address (usually 0x27 or 0x3F) and size (16x2)
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  lcd.init();          // Initialize the LCD
  lcd.backlight();     // Turn on the backlight
  lcd.print("Hello World!");
}

void loop() {
  lcd.scrollDisplayLeft(); // Scroll display left
  delay(300);              // Adjust speed
}
