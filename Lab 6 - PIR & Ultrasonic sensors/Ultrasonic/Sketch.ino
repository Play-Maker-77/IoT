#define red 12
#define green 11
#define blue 10

#define echo 2
#define trigger 3

void changeColor(int r, int g, int b)
{
  analogWrite(red, 255 - r);
  analogWrite(green, 255 - g);
  analogWrite(blue, 255 - b);
}

int calculateDistance()
{
  digitalWrite(trigger, LOW);
  delayMicroseconds(2);
  digitalWrite(trigger, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigger, LOW);
  int duration = pulseIn(echo, HIGH);
  return duration * 0.034 / 2;
}

void setup() {
  // rgb led pins
  pinMode(red, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(blue, OUTPUT);

  // ultra sonic sensor pins
  pinMode(echo, INPUT);
  pinMode(trigger, OUTPUT);

}

void loop() {
  int distance = calculateDistance();

  if(distance <= 100)
  {
    changeColor(255,0,0);
  }
  else if(distance <= 200)
  {
    changeColor(255,255,0);
  }
  else
  {
    changeColor(0,255,0);
  }

  delay(100);
}
