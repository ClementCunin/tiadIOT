#include "Arduino.h"
#include <ESP8266WiFi.h>

#define LED_PIN 14

const char* ssid = "<wifi-ID>";
const char* password = "<wifi-password>";
WiFiServer server(80);

void setup() {
  // init LED pin
  pinMode(LED_PIN, OUTPUT);

  // init Serial
  Serial.begin(115200);

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
  // Check if a client has connected
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

  int value = LOW;
  if (request.indexOf("/LED=ON") != -1) {
    digitalWrite(LED_PIN, HIGH);
    value = HIGH;
  }
  if (request.indexOf("/LED=OFF") != -1) {
    digitalWrite(LED_PIN, LOW);
    value = LOW;
  }

  // Return the response
  client.println("HTTP/1.1 200 OK\nContent-Type: text/html\n\n<!DOCTYPE HTML>\n<html>\nLed pin is now: ");
  if(value == HIGH) {
    client.print("On");
  } else {
    client.print("Off");
  }
  client.println("<br><br>\nClick <a href=\"/LED=ON\">here</a> turn the LED on pin 2 ON<br>\nClick <a href=\"/LED=OFF\">here</a> turn the LED on pin 2 OFF<br>\n</html>");

  delay(1);
  Serial.println("Client disconnected");
  Serial.println("");
}
