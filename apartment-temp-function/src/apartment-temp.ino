// This #include statement was automatically added by the Particle IDE.
#include "Adafruit_DHT/Adafruit_DHT.h"

// DHT parameters
#define DHTPIN D7
#define DHTTYPE DHT22

// Variables
int power = D6;
int temperature;
int humidity;

// DHT sensor
DHT dht(DHTPIN, DHTTYPE);

void setup() {
    pinMode(power, OUTPUT);
    digitalWrite(power, HIGH);

    // Start DHT sensor
    dht.begin();

    Particle.function("getTemperature", getTemperature);
    Particle.function("getTemperature2", getTemperature2);
    Particle.function("getHumidity", getHumidity);
    Particle.function("getHumidity2", getHumidity2);
}

void loop() {
}

int getTemperature(String command) {
    return dht.getTempFarenheit();
}

int getTemperature2(String command) {
    return dht.getTempCelcius()*10;
}

int getHumidity(String command) {
    return dht.getHumidity();
}

int getHumidity2(String command) {
    return dht.getHumidity()*10;
}