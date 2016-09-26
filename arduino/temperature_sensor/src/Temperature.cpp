/*
 * Read temperature from a DHT22 sensor and write it to the serial port.
 * The serial port is the 5.
 */

#include <DHT.h>

#define DHTPIN 5
#define DHTTYPE DHT22

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  dht.begin();
}

void loop() {
  delay(2000);

  float h = dht.readHumidity();
  float t = dht.readTemperature();

  if (isnan(h) || isnan(t)) {
    Serial.println("failed to read from DHT sensor");
    return;
  }

  Serial.print("hum=");
  Serial.print(h);
  Serial.print("&temp=");
  Serial.println(t);
}
