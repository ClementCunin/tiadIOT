PlantCare
==============

Prérequis
---------

Avoir fait l'atelier "Temperature sensor".

Objectifs
---------

- Selon la température, allumer une LED verte ou rouge
- Envoyer les informations de température et d'humidité sur le site web thingspeak
- Visualiser les datas sur son mobile

A savoir
--------

Thingspeak est une plateforme libre de partage de données, il permet de collecter, afficher, analyser et automatiser des actions.
Pour communiquer avec thingspeak nous allons envoyer des informations grâce à l'API de thingspeak.

Le montage
----------

Un capteur de température et deux LEDs.

![Circuit](Circuit.png)

Le code
-------

```C
#define SERV       "api.thingspeak.com"
#define SSID       "<SSID>"
#define PASSWORD   "<password>"

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
	while(client.available()) {
		String line = client.readStringUntil('\r');
		Serial.print(line);
	}
	Serial.println();
	Serial.println("closing connection");
}
```

Les erreurs à éviter
--------------------

### Erreur de polarité: Les LEDs ne s'allument pas
Une LED a un sens, sa borne + (cathode) est la plus longue des deux pattes.
Une LED branchée à l'envers ne s'allume pas (mais n'est pas endommagée), vous pouvez essayer de la retourner.

### Erreur pas de connection wifi: Sur le terminal série je reçois des . (points)
Vérifier votre code lignes 15 et 16, le nom du réseau wifi et sont mot de passe.


### Erreur sur l'API: les données ne se mettent pas à jour sur le site
Vérifier votre code ligne 18 (l'API-KEY) qui permet d'être authentifié sur le site.
