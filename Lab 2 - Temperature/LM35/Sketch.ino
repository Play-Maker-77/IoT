const int lm35Pin = A0;  // Signal pin connected to A0

void setup() {
  Serial.begin(9600);
  Serial.println("LM35 Temperature Sensor Test");
}

void loop() {
  int sensorValue = analogRead(lm35Pin);     // Read analog value (0–1023)
  float voltage = sensorValue * (5.0 / 1023.0);  // Convert to volts
  float temperatureC = voltage * 100.0;          // 10 mV per °C → multiply by 100

  Serial.print("Voltage: ");
  Serial.print(voltage);
  Serial.print(" V\t");

  Serial.print("Temperature: ");
  Serial.print(temperatureC);
  Serial.println(" °C");

  delay(1000); // 1 second between readings
}
