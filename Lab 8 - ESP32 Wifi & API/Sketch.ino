#include <Adafruit_SSD1306.h>
#include <Wire.h>
#include <WiFi.h>
#include <HTTPClient.h>
#include <ArduinoJson.h>
#include "secrets.h" // WiFi Configuration (WiFi name and Password)


#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels
#define OLED_RESET     -1 // Reset pin # (or -1 if sharing Arduino reset pin)
#define SCREEN_ADDRESS 0x3C ///< See datasheet for Address; 0x3D for 128x64, 0x3C for 128x32
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

const char* ssid = SSID;
const char* password = WIFI_PASSWORD;

// Powered by Open Meteo- https://open-meteo.com/
const String url = "https://api.open-meteo.com/v1/forecast?latitude=25&longitude=45&timezone=Africa%2FCairo";

HTTPClient http;

void displayOutput(String var)
{
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0,0); 
  display.println(var);
  display.display();
  Serial.println("SSD is working");
}

void setup() {
  Serial.begin(115200);

  if (!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    Serial.println(F("SSD1306 allocation failed"));
    for (;;); // Don't proceed, loop forever
  }

  display.clearDisplay();
  display.setTextSize(1);           
  display.setTextColor(SSD1306_WHITE);      
  display.setCursor(0,0); 
  display.println("Connecting to WiFi...");
  display.display();

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
  }

  Serial.print("CONNECTED to SSID: ");
  Serial.println(ssid);

  display.print("Connected to ");
  display.println(ssid);
  display.display();
  delay(5000);
}

void loop() {
  if (WiFi.status() == WL_CONNECTED) {
    Serial.println("Getting current data...");

    http.begin(url);
    int httpCode = http.GET();
    Serial.print("HTTP Code: ");
    Serial.println(httpCode);
    if (httpCode > 0) {
      StaticJsonDocument<768> doc;
      DeserializationError error = deserializeJson(doc, http.getString());

      if (error) {
        Serial.print(F("deserializeJson failed: "));
        Serial.println(error.f_str());
        delay(2500);
        return;
      }


      String latitude = "latitude = " + doc["latitude"].as<String>();
      String longitude = "longitude = " + doc["longitude"].as<String>();
      String elevation = "elevation = " + doc["elevation"].as<String>();
      String utc_offset_seconds = "utc_offset_seconds = " + doc["utc_offset_seconds"].as<String>();
      String timezone = "timezone = " + doc["timezone"].as<String>();
      String timezone_abbreviation = "timezone_abbreviation = " + doc["timezone_abbreviation"].as<String>();

      String outPut = latitude + "\n" + longitude + "\n" + elevation + "\n" + utc_offset_seconds + "\n" + timezone + "\n" + timezone_abbreviation + "\n";
      Serial.println(outPut);
      displayOutput(outPut);
      http.end();

      delay(3000);
  }
  }
}