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
    Particle.function("getHumidity", getHumidity);
}

void loop() {   
    // Temperature measurement
    temperature = dht.getTempCelcius();
    
    // Humidity measurement
    humidity = dht.getHumidity();

    Particle.variable("temperature", temperature);
    Particle.variable("humidity", humidity); 
}

int getTemperature(String command) {
    return dht.getTempCelcius();
}

int getHumidity(String command) {
    return dht.getHumidity();
}