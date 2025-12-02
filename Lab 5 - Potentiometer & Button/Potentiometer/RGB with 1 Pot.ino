int potPin = A0; 
int redPin = 9; 
int greenPin = 10;  
int bluePin = 11;   

void setup() {
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);

  // Turn off green & blue
  analogWrite(greenPin, 155);
  analogWrite(bluePin, 155);
}

void loop() {
  int potValue = analogRead(potPin);          // 0–1023
  int redBrightness = map(potValue, 0, 1023, 0, 255);  // 0–255

  analogWrite(redPin, redBrightness);         // Set brightness
  delay(10);
}
