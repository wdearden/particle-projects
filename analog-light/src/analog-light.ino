int led = D0;
bool up;
int level;
int MAX_BRIGHTNESS = 255;
int MIN_BRIGHTNESS = 0;
char brightnessStr[3];

void setup() {
	pinMode(led, OUTPUT);
  up = true;
  level = MIN_BRIGHTNESS;
}

void loop() {

  analogWrite(led, level);

  //sprintf(brightnessStr, "%d", level);
  //Particle.publish("level-reading", brightnessStr, PUBLIC);

  if (level == MIN_BRIGHTNESS) {
    up = true;
  } else if (level == MAX_BRIGHTNESS) {
    up = false;
  }

  if (up) {
    level = level + 1;
  } else {
    level = level - 1;
  }

	delay(1);

}
