#include "Arduino.h"
#include <ESP8266WiFi.h>

#define RED_PIN   12
#define GREEN_PIN 13
#define BLUE_PIN  15

const char*       ssid = "WifiPartenaires";
const char*       password = "m3nNUsSe";
WiFiServer        server(80);

void setup() {
  // init LED pin
  pinMode(RED_PIN, OUTPUT);
  pinMode(GREEN_PIN, OUTPUT);
  pinMode(BLUE_PIN, OUTPUT);

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

  // Start the server
  server.begin();
  Serial.println("Server started");

  // Print the IP address
  Serial.print("Use this URL to connect: ");
  Serial.print("http://");
  Serial.print(WiFi.localIP());
  Serial.println("/");

}

int limit(int num) {
  if (num > 1023)
    return (1023);
  if (num < 0)
    return (0);
}

void loop() {
  // Check if a client is connected
  WiFiClient client = server.available();
  if (!client) {
    return;
  }

  // Wait until the client sends some data
  Serial.println("new client");
  while(!client.available()){
    delay(1);
  }

  // Read the first line of the request
  String request = client.readStringUntil('\r');
  Serial.println(request);
  client.flush();

  // Get associated value of each color and write it
  int index;

  if ((index = request.indexOf("R=")) != -1) {
    int r = request.substring(index + 2).toInt();
    Serial.print("R="); Serial.println(r);
    analogWrite(RED_PIN, limit(1023-r));
  }
  if ((index = request.indexOf("G=")) != -1) {
    int g = request.substring(index + 2).toInt();
    Serial.print("G="); Serial.println(g);
    analogWrite(GREEN_PIN, limit(1023-g));
  }
  if ((index = request.indexOf("B=")) != -1) {
    int b = request.substring(index + 2).toInt();
    Serial.print("B="); Serial.println(b);
    analogWrite(BLUE_PIN, limit(1023-b));
  }

  // Return the response
  client.println("HTTP/1.1 200 OK\nContent-Type: text/html\n\n<!DOCTYPE HTML>\n<html>\nLed pin has changed ");
  delay(1);
  Serial.println("Client disconnected");
  Serial.println("");
}
