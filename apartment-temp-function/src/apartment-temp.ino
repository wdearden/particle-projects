// This #include statement was automatically added by the Particle IDE.
#include "Adafruit_DHT/Adafruit_DHT.h"

// DHT parameters
#define DHTPIN D7
#define DHTTYPE DHT22

// Variables
const int power = D6;
double tempF;
double humidity;

// DHT sensor
DHT dht(DHTPIN, DHTTYPE);

void setup() {
    pinMode(power, OUTPUT);
    digitalWrite(power, HIGH);

    // Start DHT sensor
    dht.begin();

    Particle.variable("humidity", humidity);
    Particle.variable("temperature", tempF);
}

void loop() {
    tempF = dht.getTempFarenheit();
    tempF = roundf(tempF * 100) / 100;
    delay(6000);

    humidity = dht.getHumidity();
    humidity = roundf(humidity * 10) / 10;
    delay(6000);
}
