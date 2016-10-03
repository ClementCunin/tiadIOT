Premières intéractions
===

Dans un terminal, effectuez la commande suivante :

    screen /dev/tty.SLAB_USBtoUART 115200

Un prompt ">>>" s'affiche... Bienvenue dans le **REPL** !

Vous êtes face à un interpréteur Python, et pouvez donc écrire du code et exécuter des commandes.

Pour plus de simplicité, vous pouvez **coller du texte** grâce au "Paste Mode", auquel vous accèderez grâce aux touches **Ctrl+E**.

Une fois votre texte collé, **exécutez-le** grâce aux touches **Ctrl+D**.

Vous pouvez par exemple coller le code suivant : 

    import machine
    def toggle(p):
		pin = machine.Pin(p, machine.Pin.OUT)
		pin.value(not pin.value())

La fonction **toggle(p)** est maintenant disponible. Testez-là en exécutant la commande suivante **plusieurs fois d'affilée** :

    toggle(0)

ou bien :

    toggle(2)

---
Réseau
===

Vous pouvez également connecter le microcontrolleur à un réseau grâce à une fonction comme la suivante :

    import socket
    def do_connect(essid, pw):
    	import network
    	wlan = network.WLAN(network.STA_IF)
    	wlan.active(True)
    	if not wlan.isconnected():
    	    print('connecting to network : ' + essid)
    	    wlan.connect(essid, pw)
    	    while not wlan.isconnected():
    	        pass
    	print('connected to network - ' + wlan.ifconfig()[2])
    	print('network config : ', wlan.ifconfig())

Connectez-vous ensuite comme ceci :

    do_connect('<nom du réseau>', '<mot de passe>')

Pour obtenir les détails concernant votre réseau hôte, tapez le code suivant dans le REPL :

    import network
    sta = network.WLAN(network.STA_IF)
    print(sta.ifconfig())

Une liste d'adresses IP s'affiche ; la **première** de celles-ci vous permettra d'interagir avec votre microcontrolleur via le réseau.

Pour cela, dirigez vous vers l'adresse suivante : [http://micropython.org/webrepl/](http://micropython.org/webrepl/)

Dans la boite en haute à gauche de la page, entrez l'IP notée précédemment suivie de ":8266/"

    ws://XXX.XXX.XXX.XXX:8266/

Cliquez sur "Connect". Il vous sera peut-être demandé d'établir un mot de passe. **"1234" suffira pour l'instant**. Une fois connecté.e, vous pouvez de nouveau utiliser le REPL, mais **à distance** !

Vous pouvez par exemple coder depuis un autre poste ; votre fonction toggle(p) sera encore disponible, **à condition que vous n'ayez pas redémarré le microcontrolleur** entretemps.

---
Challenge "clignotant"
===

Serez-vous capables de faire **clignoter une LED de façon continue** via le WebREPL ? 
Si vous découvrez le Python, des **exemples de code** sont disponibles dans ce répertoire, n'hésitez pas à vous en inspirer !