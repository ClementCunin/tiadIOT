Premiers pas avec l'ESP8266 sous Linux
======================================

Connecter le micro controleur
------------------------

Connectez le micro controleur (MC) à votre ordinateur

Appliquer les permissions de lecture et d'écriture pour tout le monde sur le MC
- Pour savoir quel est le le port USB utilisé, cliquez sur le bouton Serial Monitor,
sur le panneau latéral gauche, troisième en partant du bas
- Si vous avez plusieurs périphériques USB connectés, vous pouvez trouver le MC
en le branchant/débranchant, et en vérifiant lequel est parti de la liste entre
temps
- Allez dans le répertoire /dev et changez les permissions
 - Ctrl + Alt + T (Ouvrir le terminal)
 - sudo chmod 666 /dev/ttyUSBX (Pour changer les permissions : rw-rw-rw,
où X est le numéro de port utilisé)
 - N.B. Vous devez effectuer cette commande à chaque fois que vous rebranchez
votre MC

Maintenant vous pouvez téléverser (upload) votre projet !