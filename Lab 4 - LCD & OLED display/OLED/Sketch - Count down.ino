#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

void setup() {
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(64, 32);
  display.display();
  delay(1000);
}

void loop() {
  for(int i=5;i>=0;i--)
  {
    display.clearDisplay();
    display.setCursor(64, 32);
    display.println(i);
    display.display();
    delay(1000);
  }
}
