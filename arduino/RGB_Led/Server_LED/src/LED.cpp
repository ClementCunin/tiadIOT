#include "Arduino.h"
#include <ESP8266WiFi.h>

#define DC_PIN    14
#define RED_PIN   12
#define GREEN_PIN 13
#define BLUE_PIN  15

const char*       ssid = "<SSID>";
const char*       password = "<password>";
WiFiServer        server(80);

void setup() {
  // init LED pin
  pinMode(DC_PIN, OUTPUT);
  pinMode(RED_PIN, OUTPUT);
  pinMode(GREEN_PIN, OUTPUT);
  pinMode(BLUE_PIN, OUTPUT);

  analogWrite(DC_PIN, 255);

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
    analogWrite(RED_PIN, request.substring(index + 2).toInt());
  }
  delay(50);
  if ((index = request.indexOf("G=")) != -1) {
    analogWrite(GREEN_PIN, request.substring(index + 2).toInt());
  }
  delay(50);
  if ((index = request.indexOf("B=")) != -1) {
    analogWrite(BLUE_PIN, request.substring(index + 2).toInt());
    }
  delay(50);

  // Return the response
  client.println("HTTP/1.1 200 OK\nContent-Type: text/html\n\n<!DOCTYPE HTML>\n<html>\nLed pin has changed ");
  delay(1);
  Serial.println("Client disconnected");
  Serial.println("");
}
