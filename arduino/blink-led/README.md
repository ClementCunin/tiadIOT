Mon premier montage
===================

Objectifs
---------

- Faire un premier montage sur la breadboard
- Découvrir la programmation d'un arduino

A savoir
--------

L'ESP8266 peut être programmé de la même manière qu'un arduino, c'est ce que nous alons faire ici avec un premier programme basic. La documentation lié à arduino étant très importante sur internet, il est générallement très facile de trouver des codes d'exemple pour la majorité des montages simple.

Concrétement, un programme arduino est un programme en C/C++ qui importe "Arduino.h" et qui se compose de deux fonctions:

- **setup()** qui sera exécuté une fois au démarrage du micro-controlleur. C'est à dire, lors de sa mise sous tention ou d'un reset.
- **loop()** qui sera appelé en boucle une fois la fonction **setup()** terminé.

L'ESP8266 dispose de plusieurs entrée/sorties (aussi appelé GPIO) numéroté que l'on va pouvoir programmé. Les fonctions utiles:

- **pinMode( <pin-number>, OUTPUT )** permet d'indiquer que l'on souhaite utilisé ce port en sortie. En général on utilise cette fonction dans le **setup()**.
- **digitalWrite( <pin-number>, HIGH/LOW)** permet d'indiquer si on souhaite avoir un niveau logique haut (+3V) ou bas (0V) sur la sortie correspondante.

Le montage
----------

Une led et sa résistance, branché sur la sortie 16.

![Screenshot1](screen1.png)

Le code
-------
	#include "Arduino.h"
	
	#define LED_PIN 16
	
	void setup() {
	  // initialize LED digital pin as an output.
	  pinMode(LED_PIN, OUTPUT);
	}
	void loop() {
	  // turn the LED on (HIGH is the voltage level)
	  digitalWrite(LED_PIN, HIGH);
	  // wait for a second
	  delay(1000);
	  // turn the LED off by making the voltage LOW
	  digitalWrite(LED_PIN, LOW);
	   // wait for a second
	  delay(1000);
	}


Les erreurs à éviter
-------------------

### Erreur de polarité: La LED ne s'allume pas
Une LED a un sens, sa borne + (cathode) est la plus longue des deux pattes.
Une LED branché à l'envers ne s'allume pas (mais n'est pas endommagé), vous pouvez essayer de la retourner.