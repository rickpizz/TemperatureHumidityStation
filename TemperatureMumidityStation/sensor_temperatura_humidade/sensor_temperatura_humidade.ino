#include "RHT.h"
#include <Servo.h>

#define RHTPIN 5

#define RHTTYPE RHT1

RHT dht(RHTPIN, RHTTYPE);
Servo servo;
float pos = 0;

void setup()
{
  Serial.begin(9600);
  servo.attach(6);

  rht.begin();
}

void loop()
{
  delay(2000);

  float h = rht.readHumidity();

  float t = rht.readTemperature();

  float f = rht.readTemperature(true);

  float hif = rht.computeHeatIndex(f, h);

  float hic = rht.computeHeatIndex(t, h, false);

  pos = t * 3.6;
  servo.write(pos);

  Serial.println(h);
}
