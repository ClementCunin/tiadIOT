Premiers pas avec l'ESP8266 sous Linux
======================================

Connecter le micro controleur
------------------------

Connectez le micro controleur (MC) � votre ordinateur

Appliquer les permissions de lecture et d'�criture pour tout le monde sur le MC
- Pour savoir quel est le le port USB utilis�, cliquez sur le bouton Serial Monitor,
sur le panneau lat�ral gauche, troisi�me en partant du bas
- Si vous avez plusieurs p�riph�riques USB connect�s, vous pouvez trouver le MC
en le branchant/d�branchant, et en v�rifiant lequel est parti de la liste entre
temps
- Allez dans le r�pertoire /dev et changez les permissions
 - Ctrl + Alt + T (Ouvrir le terminal)
 - sudo chmod 666 /dev/ttyUSBX (Pour changer les permissions : rw-rw-rw,
o� X est le num�ro de port utilis�)
 - N.B. Vous devez effectuer cette commande � chaque fois que vous rebranchez
votre MC

Maintenant vous pouvez t�l�verser (upload) votre projet !