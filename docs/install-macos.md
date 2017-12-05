Installation de l'environnement sous MacOS
==========================================

Télécharger l'IDE
-----------------

Lien: http://platformio.org/platformio-ide#

![macos platformIO](macos_platformio_dl.png)

Télécharger le driver
---------------------

Lien: https://www.silabs.com/products/mcu/Pages/USBtoUARTBridgeVCPDrivers.aspx#mac

Le driver est nécessaire pour se connecter sur le port série de l'ESP8266. Le
processus d'installation est standard, mais le mot de passe root peut être
requis.
Une fois l'installation du driver terminé, il est nécessaire d'activer celui-ci depuis 'system preferences'/'security & privacy' , cliqué sur "autorisé" à coté de: 

``` 
"le chargement de logiciel système du développeur << Silicon Labs >> a été bloqué.
```

![macos driver](macos_driver_dl.png)


Installation du compilateur pour Huzzah
---------------------------------------

La dernière étape de l'installation consiste à créer un projet dans platformIO en selectionnant la carte Huzzah d'AdaFruit pour qu'il télécharge automatiquement le compilateur et ses dépendances.

Choisir **New project**:

![Select New Project](platformIO-new-project.png)

Puis choisir **Huzzah** dans **AdaFruit**:

![Select Huzzah](platformIO-select-huzzah.png)

Et valider. 

*Note:* Le téléchargement peut prendre plusieurs minutes.


Next
----

Vous êtes maintenant prêt pour l'atelier.

Il est temps de brancher votre ESP et de faire vos [premiers pas](first_step-macos.md).
