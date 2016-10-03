Installation de l'environnement pour Windows
============================================

Télécharger l'IDE
-----------------

### Platform IO

Lien : http://platformio.org/platformio-ide

![Windows platformIO](windows_platformio_dl.png)

### Python 2.7

PlatformIO est écrit en python mais celui-ci doit-être installé séparément.

Lien: https://www.python.org/downloads/

Attention lors de l'installation de l'installation, il faut ajouter python.exe au PATH pour que platformIO puisse le trouver sans problème.

![Customize python installation](windows_python_path.png)

### C-Lang 3.9.0

Lien: http://llvm.org/releases/download.html


Télécharger le driver
---------------------

La breakboard AdaFruit Huzzah nécessite un driver pour Windows.

Lien: https://learn.adafruit.com/adafruit-arduino-ide-setup/windows-setup


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

Il est temps de brancher votre ESP et de faire vos [premiers pas](first_step-windows.md).
