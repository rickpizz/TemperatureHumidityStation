#include "DHT.h"
#include <Servo.h>

#define DHTPIN 5

#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);
Servo servo;
float pos = 0;

void setup()
{
  Serial.begin(9600);
  servo.attach(6);

  dht.begin();
}

void loop()
{
  delay(2000);

  float h = dht.readHumidity();

  float t = dht.readTemperature();

  float f = dht.readTemperature(true);

  float hif = dht.computeHeatIndex(f, h);

  float hic = dht.computeHeatIndex(t, h, false);

  pos = t * 3.6;
  servo.write(pos);

  Serial.println(h);
}
