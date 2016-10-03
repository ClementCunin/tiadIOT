Installation de l'environnement pour Windows
============================================

T�l�charger l'IDE
-----------------

### Platform IO

Lien : http://platformio.org/platformio-ide

![Windows platformIO](windows_platformio_dl.png)

### Python 2.7

PlatformIO est �crit en python mais celui-ci doit-�tre install� s�par�ment.

Lien: https://www.python.org/downloads/

Attention lors de l'installation de l'installation, il faut ajouter python.exe au PATH pour que platformIO puisse le trouver sans probl�me.

![Customize python installation](windows_python_path.png)

### C-Lang 3.9.0

Lien: http://llvm.org/releases/download.html


T�l�charger le driver
---------------------

La breakboard AdaFruit Huzzah n�cessite un driver pour Windows.

Lien: https://learn.adafruit.com/adafruit-arduino-ide-setup/windows-setup


Installation du compilateur pour Huzzah
---------------------------------------

La derni�re �tape de l'installation consiste � cr�er un projet dans platformIO en selectionnant la carte Huzzah d'AdaFruit pour qu'il t�l�charge automatiquement le compilateur et ses d�pendances.

Choisir **New project**:

![Select New Project](platformIO-new-project.png)

Puis choisir **Huzzah** dans **AdaFruit**:

![Select Huzzah](platformIO-select-huzzah.png)

Et valider. 

*Note:* Le t�l�chargement peut prendre plusieurs minutes.


Next
----

Vous �tes maintenant pr�t pour l'atelier.

Il est temps de brancher votre ESP et de faire vos [premiers pas](first_step-windows.md).
