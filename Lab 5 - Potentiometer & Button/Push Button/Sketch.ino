int buttonPin = A0;
int ledPin = 13;

void setup() {
  pinMode(buttonPin, INPUT);   // button input
  pinMode(ledPin, OUTPUT);     // LED output
}

void loop() {
  int buttonState = analogRead(buttonPin);

  if (buttonState == LOW) {
    digitalWrite(ledPin, HIGH);   // LED ON when pressed
  } 
  else {
    digitalWrite(ledPin, LOW);    // LED OFF when released
  }
  delay(100);
}
