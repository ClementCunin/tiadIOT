#include "Arduino.h"
#include <ESP8266WiFi.h>

#define BUT1  14
#define BUT2  12
#define BUT3  13

const char*   ssid = "WifiPartenaires";
const char*   password = "<PWD>";
const char*   ip = "<IP>";
WiFiClient    client;

unsigned int  analog_val;
unsigned int  red_val;
unsigned int  green_val;
unsigned int  blue_val;

void setup() {
  // init LED pin
  pinMode(BUT1, INPUT);
  pinMode(BUT2, INPUT);
  pinMode(BUT3, INPUT);

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
  // Read analog value and format it to fill an analogWrite call
  analog_val = analogRead(0);

  // Change color value according to associated button
  if (digitalRead(BUT1) == 1)
    red_val = analog_val;
  if (digitalRead(BUT2) == 1)
    green_val = analog_val;
  if (digitalRead(BUT3) == 1)
    blue_val = analog_val;

  // If a button have been pressed, send fresh values to the server
  if (digitalRead(BUT1) == 1
      || digitalRead(BUT2) == 1
      || digitalRead(BUT3) == 1) {
    client.connect(ip, 80);
    Serial.println("Send to server : ");
    String  str = String("GET ?R=") + String(red_val) + String("&G=")
        + String(green_val) + String("&B=") + String(blue_val);
    Serial.println(str);
    client.println(str);
  }

  delay(200);
}
