#include "Arduino.h"
#include <ESP8266WiFi.h>

#define BUT1  14

const char*   ssid = "WifiPartenaires";
const char*   password = "m3nNUsSe";
const char*   ip = "192.168.56.25";
WiFiClient    client;

String        status;

void setup() {
  // init LED pin
  pinMode(BUT1, INPUT);

  // init Serial
  Serial.begin(9600);

  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);

  // WIFI connection
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");
}

void loop() {

  // If a button have been pressed, send fresh values to the server
  if (digitalRead(BUT1) == 1) {
    client.connect(ip, 80);
    status == "ON" ? status = "OFF" : status = "ON";
    Serial.println("Send to server : ");
    String  str = String("GET ?/LED=") + status;
    Serial.println(str);
    client.println(str);
  }

  delay(200);
}
