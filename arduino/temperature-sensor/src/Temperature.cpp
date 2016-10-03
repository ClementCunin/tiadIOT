/*
 * Read temperature from a DHT22 sensor and send it over HTTP.
 * The serial port is the 5.
 * Don't forget to fill the SSID and PASSWORD fields.
 */

#include <DHT.h>
#include <ESP8266WiFi.h>

// sensor type
#define DHTTYPE DHT22
// sensor serial port
#define DHTPIN 5

const char* ssid = "WifiPartenaires";
const char* password = "m3nNUsSe";

// server port
WiFiServer server(80);
// sensor initialization
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);

  Serial.print("Connecting to ");
  Serial.println(ssid);

  // WIFI connection
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nWiFi connected");

  // Start the server
  server.begin();
  Serial.println("Server started");

  // Print the IP address
  Serial.print("Use this URL to connect: ");
  Serial.print("http://");
  Serial.print(WiFi.localIP());
  Serial.println("/");

  // Start the sensor
  dht.begin();
}

void loop() {
  WiFiClient client = server.available();
  // wait for a client
  if (!client) {
    return;
  }

  // client connected
  Serial.println("client connected");
  while(!client.available()){
    delay(1);
  }

  // get the humidity and temperature from the sensor
  float h = dht.readHumidity();
  float t = dht.readTemperature();

  // check for data validity and send error if values aren't valid
  if (isnan(h) || isnan(t)) {
    client.println("HTTP/1.1 200 OK\nContent-Type: text/html\n\n<!DOCTYPE HTML>\n<html>\n<p>error</p>\n</html>\n");
    return;
  }

  // convert data to string
  String sh =  String(h, 2);
  String st =  String(t, 2);

  // send the HTTP page result
  client.print(
    "HTTP/1.1 200 OK\nContent-Type: text/html\n\n<!DOCTYPE HTML>\n<html>\n<p>humidity: " +
    sh +
    "</p>\n<p>temperature: " +
    st +
    "</p>\n</html>\n"
  );
}
