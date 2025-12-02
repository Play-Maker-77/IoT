// 1. Define the pins
const int redPin = 9;
const int greenPin = 10;
const int bluePin = 11;
const int buzzerPin = 8;

void setup() {
  // 2. Set the LED pins as outputs
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  // The buzzer pin is often set as OUTPUT, but tone() handles it.
  pinMode(buzzerPin, OUTPUT); 
}

// Helper function to set the RGB color
// Values from 0 (off) to 255 (full brightness)
void setRgbColor(int r, int g, int b) {
  // Since we assumed Common Anode (COM to 5V), 
  // lower analogWrite value means *more* brightness.
  // 0 = ON (full brightness), 255 = OFF.
  analogWrite(redPin, 255 - r);
  analogWrite(greenPin, 255 - g);
  analogWrite(bluePin, 255 - b);
}

void loop() {
  // -----------------
  // 1. Red color with a high pitch tone
  // -----------------
  setRgbColor(255, 0, 0); // Full Red
  // Play a 1000 Hz tone for 500 milliseconds (0.5 seconds)
  tone(buzzerPin, 1000, 500); 
  delay(1000); // Wait 1 second (tone will stop after 0.5s)
  
  // -----------------
  // 2. Green color with a lower pitch tone
  // -----------------
  setRgbColor(0, 255, 0); // Full Green
  // Play a 500 Hz tone for 500 milliseconds
  tone(buzzerPin, 500, 500); 
  delay(1000);

  // -----------------
  // 3. Blue color with no tone
  // -----------------
  setRgbColor(0, 0, 255); // Full Blue
  noTone(buzzerPin); // Stop any playing tone
  delay(1000);

  // -----------------
  // 4. White color (all colors on) and an intermittent beep
  // -----------------
  setRgbColor(255, 255, 255); 
  tone(buzzerPin, 2000); // Start a 2000 Hz tone, don't set a duration
  delay(200); // Wait 200ms
  noTone(buzzerPin); // Stop the tone
  delay(800); // Wait 800ms (1 second total for the cycle)
}