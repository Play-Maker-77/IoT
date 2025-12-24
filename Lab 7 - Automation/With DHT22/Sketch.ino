#include "DHT.h"
#include <Servo.h>

// Pin Definitions
#define DHTPIN A2     
#define DHTTYPE DHT22 
#define SERVO_PIN 9

// Initialize components
DHT dht(DHTPIN, DHTTYPE);
Servo myServo;

int pos = 0;    // Variable to store servo position
bool movingForward = true;

void setup() {
  Serial.begin(9600);
  dht.begin();
  myServo.attach(SERVO_PIN);
  
  // Start the servo at 0 degrees
  myServo.write(0);
}

void loop() {
  // Read temperature as Celsius
  float temp = dht.readTemperature();

  // Check if reading failed
  if (isnan(temp)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  Serial.print("Temperature: ");
  Serial.print(temp);
  Serial.println("°C");

  // Logic: Move if temp > 40, stop if temp <= 40
  if (temp > 40) {
    sweepServo();
  } else {
    // Optional: Reset to 0 position when stopped
    myServo.write(0); 
  }

  delay(20); // Small delay for stability
}

// Function to handle continuous sweeping motion
void sweepServo() {
  if (movingForward) {
    pos += 2; // Adjust speed by changing this increment
    if (pos >= 180) movingForward = false;
  } else {
    pos -= 2;
    if (pos <= 0) movingForward = true;
  }
  myServo.write(pos);
}