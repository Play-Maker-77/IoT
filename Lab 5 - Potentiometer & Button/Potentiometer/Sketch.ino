// Define the analog input pins for the three potentiometers
const int RED_POT_PIN = A1;   // Potentiometer 1 (Red) is connected to Analog Pin A1
const int GREEN_POT_PIN = A2; // Potentiometer 2 (Green) is connected to Analog Pin A2
const int BLUE_POT_PIN = A3;  // Potentiometer 3 (Blue) is connected to Analog Pin A3

// Define the digital output pins for the RGB LED
const int RED_LED_PIN = 13;
const int GREEN_LED_PIN = 12;
const int BLUE_LED_PIN = 11;

void setup() {
  // Initialize the LED pins as outputs
  pinMode(RED_LED_PIN, OUTPUT);
  pinMode(GREEN_LED_PIN, OUTPUT);
  pinMode(BLUE_LED_PIN, OUTPUT);

  // Optional: Start serial communication for debugging
  Serial.begin(9600);
  Serial.println("RGB Controller Initialized. Adjust potentiometers A1, A2, A3.");
}

void loop() {
  // 1. Read the analog values from the potentiometers (0 to 1023)
  int redValue = analogRead(RED_POT_PIN);
  int greenValue = analogRead(GREEN_POT_PIN);
  int blueValue = analogRead(BLUE_POT_PIN);

  // 2. Map the values from the 0-1023 range to the PWM 0-255 range
  // The 'map' function handles this conversion automatically.
  int mappedRed = map(redValue, 0, 1023, 0, 255);
  int mappedGreen = map(greenValue, 0, 1023, 0, 255);
  int mappedBlue = map(blueValue, 0, 1023, 0, 255);

  // 3. Apply INVERTED LOGIC for Common Anode LED
  // The Common Anode configuration means the common pin is connected to 5V (VCC).
  // To turn the LED ON, the digital pin must be set LOW (0).
  // Therefore, we invert the mapped value: (255 - mappedValue).
  int invertedRed = 255 - mappedRed;
  int invertedGreen = 255 - mappedGreen;
  int invertedBlue = 255 - mappedBlue;

  // 4. Write the inverted PWM values to the LED pins
  analogWrite(RED_LED_PIN, invertedRed);
  analogWrite(GREEN_LED_PIN, invertedGreen);
  analogWrite(BLUE_LED_PIN, invertedBlue);

  // Optional: Print values for monitoring
  
  // Serial.print("R: ");
  // Serial.print(mappedRed);
  // Serial.print(" (->PWM: ");
  // Serial.print(invertedRed);
  // Serial.print(") | G: ");
  // Serial.print(mappedGreen);
  // Serial.print(" (->PWM: ");
  // Serial.print(invertedGreen);
  // Serial.print(") | B: ");
  // Serial.print(mappedBlue);
  // Serial.print(" (->PWM: ");
  // Serial.print(invertedBlue);
  // Serial.println(")");

  // Small delay to stabilize readings and serial output
  delay(10);
}