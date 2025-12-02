#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

String messages[] = {
  "Welcome students!",
  "Today we will\nlearn something\namazing!",
  "Feel free to ask\nquestions anytime.",
  "Remember:\nLearning is a\njourney!",
  "Work together,\nsupport each other.",
  "You got this!\nLet's begin!",
};

int totalMessages = sizeof(messages) / sizeof(messages[0]);

void showMessage(String text, int waitTime) {
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0, 0);
  display.println(text);
  display.display();
  delay(waitTime);
}

void setup() {
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
}

void loop() {

  // Show each paragraph
  for (int i = 0; i < totalMessages; i++) {
    showMessage(messages[i], 3000); // each message for 3 seconds
  }

  // Blank screen for 5 seconds
  display.clearDisplay();
  display.display();
  delay(5000);
}
