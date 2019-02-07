// This #include statement was automatically added by the Particle IDE.
#include "Adafruit_DHT/Adafruit_DHT.h"

// DHT parameters
#define DHTPIN D7
#define DHTTYPE DHT11

// Variables
int temperature;
int humidity;
int power = D6;

// DHT sensor
DHT dht(DHTPIN, DHTTYPE);

void setup() {
    pinMode(power, OUTPUT);
    digitalWrite(power, HIGH);

    // Start DHT sensor
    dht.begin();
}

void loop() {
    
    // Humidity measurement
    temperature = dht.getTempCelcius();
    
    // Humidity measurement
    humidity = dht.getHumidity();
    
    // Publish data
    Spark.publish("temperature", String(temperature));
    delay(2000);
    Spark.publish("humidity", String(humidity));
    delay(2000);
    
}