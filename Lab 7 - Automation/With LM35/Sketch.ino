#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// OLED configuration
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET    -1
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

// LM35 Pin
const int tempPin = A0; 
const float threshold = 40.0; // Set your caution threshold here

void setup() {
  Serial.begin(9600);

  // Initialize OLED
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { 
    Serial.println(F("SSD1306 allocation failed"));
    for(;;);
  }
  
  display.clearDisplay();
  display.setTextColor(SSD1306_WHITE);
}

void loop() {
  // 1. Read Analog Value
  int analogValue = analogRead(tempPin);

  // 2. Convert to Temperature
  // Formula: (ADC_Value * Reference_Voltage / 1024) / 10mV
  // For 5V Arduino: (analogValue * 500.0) / 1024.0
  float temperatureC = (analogValue * 500.0) / 1024.0;

  display.clearDisplay();
  display.setCursor(0, 0);
  
  // 3. Logic for Caution Message
  if (temperatureC > threshold) {
    display.setTextSize(2);
    display.println(" CAUTION!");
    display.setTextSize(1);
    display.println("\n Temp too high!");
    display.print(" Current: ");
    display.print(temperatureC, 1);
    display.print("C");
  } else {
    display.setTextSize(1);
    display.println("System Status: OK");
    display.println("");
    display.setTextSize(2);
    display.print(temperatureC, 1);
    display.println(" C");
  }

  display.display();
  delay(500); // Update every half second
}