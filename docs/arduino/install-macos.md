Installing environment for MacOS
================================

Installing IDE
--------------

Download link: http://platformio.org/platformio-ide#

![macos platformIO](../misc/macos_platformio_dl.png)

Installing driver
-----------------

Download link: https://www.silabs.com/products/mcu/Pages/USBtoUARTBridgeVCPDrivers.aspx#mac

This driver is required to connect the board to the serial port of the computer. Follow the installation process, notice that root password may be required.

![macos driver](../misc/macos_driver_dl.png)

First application
-----------------

On the main page of the IDE, create a `New Project`.

Select the board `Adafruit HUZZAH ESP8266`, select a directory for the code and click on `Process`. This may take a while at the first launch, because the IDE has to download some drivers.

![start project](../misc/macos_start_project.png)

Connecting the board
--------------------

- In the folder `src`, create an empty application in `Main.cpp`:

```
/*
 * Empty project
 */

#include "Arduino.h"

void setup() {}

void loop() {}
```

- Connect the Adafruit mainboard throught USB.

- Compile the project: 

![compile project](../misc/macos_compile_project.png)

- Send the project to the board:

![send project](../misc/macos_send_project.png)

```
Your project is now running on the board!
```

Receiving data from the board
-----------------------------

This step is achieved by getting the serial port of the board ( ~ board console).

- Open the serial monitor interface:

![open_serial](../misc/open_serial.png)

- Configure the serial port:

![configure_serial](../misc/configure_serial.png)

You must choose the correct port, and the correct `baud rate`. For this application you can stay on 9600. Click on `Start`, you're now connected to the board.

```
If no errors occured, your setup is correct and you are ready to work.
```
