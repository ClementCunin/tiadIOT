MicroPython - Installation MacOSX
=============================

[Firmware MicroPython ESP8266](http://micropython.org/resources/firmware/esp8266-20160909-v1.8.4.bin)

Installer Python :
    brew install python

---
Installer esptool :

    pip install esptool
ou

    pip2 install esptool

---
Effacer le firmware existant :

    esptool.py --port SERIAL_PORT_NAME erase_flash

---
Ecrire le firmware MicroPython sur la board :

    python esptool.py -p SERIAL_PORT_NAME --baud 460800 write_flash --flash_size=8m 0 esp8266-20160909-v1.8.4.bin

 MicroPython - Utilisation
=============================

Accéder au REPL :
---------------

    screen SERIAL_PORT_NAME 115200

Executer des scripts
---------------
Installer AMPY :

    pip install adafruit-ampy
ou

    pip2 install adafruit-ampy
ou

    sudo pip3 install adafruit-ampy

---
Définir la variable d'environnement AMPY_PORT :

    export AMPY_PORT=SERIAL_PORT_NAME

---
Les commandes Ampy :

    ampy --help

---
Désactiver l'output de debug par défaut :

(TBC)

---
Lancer un script sur la board :

    ampy run PYTHON_SCRIPT

---
Lancer un script comprenant une boucle infinie "à la Arduino" :

    ampy run --no-output PYTHON_SCRIPT

---
Charger un script sur la board pour exécution au démarrage :

    ampy put PYTHON_SCRIPT /main.py
