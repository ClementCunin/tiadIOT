Montage de la led RGB en réception (serveur)
============================================

Objectif
--------

Recevoir les informations envoyées par le controlleur client et les traiter pour faire varier les couleurs de la LED.

Montage
-------

![Montage](montageLedServer.png)

- Sur la LED, la plus grande patte est le +, la moyenne toute seule est le Rouge, l'autre moyenne le Vert, et la plus courte le Bleu.
- Ne pas oublier les résistances, une pour chaque couleur. Cela évite une éventuelle surconsommation électrique.

Le code
-------

```c
#include "Arduino.h"
#include <ESP8266WiFi.h>

#define RED_PIN   12
#define GREEN_PIN 13
#define BLUE_PIN  15

const char*       ssid = "<SSID>";
const char*       password = "<password>";
WiFiServer        server(80);

void setup() {
  // init LED pin
  pinMode(RED_PIN, OUTPUT);
  pinMode(GREEN_PIN, OUTPUT);
  pinMode(BLUE_PIN, OUTPUT);

  // Connect to WiFi, see the whole code for more infos
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
  while(!client.available()){
    delay(1);
  }

  // Read the first line of the request
  String request = client.readStringUntil('\r');
  client.flush();

  // Get associated value of each color and write it
  int index;

  if ((index = request.indexOf("R=")) != -1) {
    int r = request.substring(index + 2).toInt();
    analogWrite(RED_PIN, limit(1023-r));
  }
  if ((index = request.indexOf("G=")) != -1) {
    int g = request.substring(index + 2).toInt();
    analogWrite(GREEN_PIN, limit(1023-g));
  }
  if ((index = request.indexOf("B=")) != -1) {
    int b = request.substring(index + 2).toInt();
    analogWrite(BLUE_PIN, limit(1023-b));
  }

  // Return the response
  client.println("HTTP/1.1 200 OK\nContent-Type: text/html\n\n<!DOCTYPE HTML>\n<html>\nLed pin has changed ");
  delay(1);
  Serial.println("Client disconnected");
  Serial.println("");
}

```

- N'oubliez pas de changer les informations de connexion (SSID et password) !

Explications
------------

- On définit les PIN de la carte que nous allons utiliser et on les active en entrée
- On définit les informations de connexion ainsi que l'objet client qui va nous permettre de se connecter au serveur LED
- On définit les variables qui vont stocker les différentes valeurs de nos contrôles
- Dans le setup(), on initie la connexion au WiFi
- Ensuite, on attend qu'un client se connecte
- On parse les données qu'il nous envoie pour avoir les composantes R, G et B
- On écrit les valeurs reçues sur les PINs correspondantes
- On répond au client que tout s'est bien passé
