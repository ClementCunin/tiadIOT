Installing environment for Ubuntu
========================

Installing IDE
--------------

Installation link : http://platformio.org/platformio-ide#other-platforms

Connecting the mainboard
------------------------

Connect the Adafruit mainboard

Apply read and write permission for everyone on the mainboard
	-To know the USB serial, click the third from to bottom button on the
	left panel, named Serial Monitor
	-If you have multiple USB devices, you can find your mainboard by
	unplugging/plugging it and check here again
	-Go to the /dev directory and change the permissions
		-Ctrl + Alt + T (To open the Terminal)
		-sudo chmod 666 /dev/ttyUSBX (To change permission : rw-rw-rw)
		(You have to repeat these two steps everytime you unplug the mainboard)

Now you're able to upload projects to your mainboard
