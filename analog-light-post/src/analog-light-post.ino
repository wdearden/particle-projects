int led = D0;
int photosensor = A0;
int power = A5;
bool up;
int level;
int MAX_BRIGHTNESS = 255;
int MIN_BRIGHTNESS = 0;
char brightnessStr[3];
char inputStr[3];
int brightnessvalue;

void setup() {
  pinMode(led, OUTPUT);
  pinMode(photosensor, INPUT);
  pinMode(power, OUTPUT);

  digitalWrite(power, HIGH);
  up = true;
  level = MIN_BRIGHTNESS;
}

void loop() {

  analogWrite(led, level);

  brightnessvalue = analogRead(photosensor);

  sprintf(brightnessStr, "%d", brightnessvalue);
  Particle.publish("Brightness", brightnessStr, PUBLIC);
  sprintf(inputStr, "%d", level);
  Particle.publish("InputValue", inputStr, PUBLIC);

  if (level == MIN_BRIGHTNESS) {
    up = true;
  } else if (level == MAX_BRIGHTNESS) {
    up = false;
  }

  if (up) {
    level = level + 2;
  } else {
    level = level - 2;
  }

  delay(2000);

}
