#include "DHT.h"

// Define DHT pin and type
#define DHTPIN A2        // Data pin connected to D2
#define DHTTYPE DHT22   // Sensor type

// Initialize DHT sensor
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  Serial.println("DHT22 sensor test!");
  dht.begin();
}

void loop() {
  // Wait a bit between readings
  delay(2000);

  // Read humidity and temperature (Celsius)
  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature();

  // Check if any reads failed
  if (isnan(humidity) || isnan(temperature)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  Serial.print("Humidity: ");
  Serial.print(humidity);
  Serial.print(" %\t");
  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.println(" °C");
}
