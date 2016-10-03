#include <string.h>
#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <ESP8266mDNS.h>
#include <DHT.h>
#define GREEN  13                       // LED Verte sur le PIN 13
#define RED    14                       // LED Rouge sur la PIN 14

#define DHTPIN 12                       // Capteur de temperature sur PIN 12
#define DHTTYPE DHT22                   // Type de capteur DHT22

#define SERV       "api.thingspeak.com" // Adresse de l'API
#define SSID       "******************"         // Entrez le nom de votre réseau WIFI
#define PASSWORD   "******************"         // Mot de passe de votre réseau WIFI

String API_KEY  =  "II868MY2WRS8U9IO";  // API Key pour thingspeak

DHT dht(DHTPIN, DHTTYPE);               // Démmarage du capteur

// Fonction qui nous permet de publier nos mesures.
void SendHttpGet(WiFiClient client, String url, const char* host)
{

  Serial.println("attempting connection to host: "+ String(host));
  const int httpPort = 80;
  if (!client.connect(host, httpPort)) {
    Serial.println("connection failed");
    return;
  }

  client.print(String("GET ") + url + " HTTP/1.1\r\n" +
               "Host: " + host + "\r\n" +
               "Connection: close\r\n\r\n");
  while(client.available()){
    String line = client.readStringUntil('\r');
    Serial.print(line);
  }
  Serial.println();
  Serial.println("closing connection");
}

void setup() {                            // Fonction appelée une fois pour initialiser la carte
  Serial.begin(9600);                     // Démmarage de la communication port Serie

  pinMode(GREEN, OUTPUT);                 // Configuration de la Pin de la LED verte en sortie
  pinMode(RED, OUTPUT);                   // Configuration de la Pin de la LED rouge en sortie

  digitalWrite(GREEN, HIGH);              // Allumer la LED ROUGE
  digitalWrite(RED, HIGH);                // Allumer la LED VERTE

  WiFi.begin(SSID, PASSWORD);             // Initialisation de la connection WIFI

  while (WiFi.status() != WL_CONNECTED)   // Tant que le Wifi n'es pas connecté
  {
    delay(1000);                          // Attend 1 seconde
    Serial.printf(".");                   // Affiche un point
  }
  digitalWrite(GREEN, LOW);               // Eteint la LED Verte
  digitalWrite(RED, LOW);                 // Eteint la LED ROUGE
}

void loop() {                             // Fonction principale qui vas être rappelée en boucle
  float h = dht.readHumidity();           // Lit la température et l'enregistre dans le variable 't'
  float t = dht.readTemperature();        // Lit la humidité et l'enregistre dans le variable 'h'

  if (isnan(h) || isnan(t))               // Verifie que les données sont bonnes
  {
    Serial.println("Failed to read from DHT sensor.");
    Serial.println(";-(");                // Affiche un message d'erreur sympa sur le port serie
    digitalWrite(RED, HIGH);              // Allumer les 2 LEDS pour faire comprendre qu'il y as une erreur.
    digitalWrite(GREEN, HIGH);
  }
  else
  {
    Serial.print("IP : ");                // Affiche son adresse IP sur le port Serie
    Serial.println(WiFi.localIP());
    WiFiClient client;
    Serial.print("temperature = ");
    Serial.println(t);                    // Affiche la temperature et l'humidité sur le port serie
    Serial.print("humidity = ");
    Serial.println(h);
    if (t >= 15 && t <= 19)               // Si le temperature est bonne pour une plante
    {
      digitalWrite(GREEN, HIGH);          // On allume la LED verte
      digitalWrite(RED, LOW);
      Serial.println("Temperature OK.");
    }
    else
    {
      digitalWrite(GREEN, LOW);
      digitalWrite(RED, HIGH);            // Sinon on allume la LED rouge
      Serial.println("Temperature KO.");
    }
                                          // Preparation des informations à envoyer
    String thingspeakUrl = "/update?key=" + API_KEY;
    thingspeakUrl = thingspeakUrl + "&field1=" + String(t) + "&field2=" + String(h) + "&field8=" + String(random(100));
                                          // Envoi des informations collectées
    SendHttpGet(client, thingspeakUrl, SERV);
  }
  delay(15000);                           // On attend 15 secondes avant de recommencer.
}
