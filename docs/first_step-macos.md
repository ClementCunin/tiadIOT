First step on MacOS
===================

First application
-----------------

On the main page of the IDE, create a `New Project`.

Select the board `Adafruit HUZZAH ESP8266`, select a directory for the code and click on `Process`. This may take a while at the first launch, because the IDE has to download some drivers.

![start project](macos_start_project.png)

Connecting the board
--------------------

1) In the folder `src`, create an empty application in `Main.cpp`:

```
/*
 * Empty project
 */

#include "Arduino.h"

void setup() {}

void loop() {}
```

2) Connect the Adafruit mainboard throught USB.

3) Compile the project:

![compile project](macos_compile_project.png)

4) Send the project to the board:

![send project](macos_send_project.png)

```
Your project is now running on the board!
```

Receiving data from the board
-----------------------------

This step is achieved by getting the serial port of the board ( ~ board console).

- Open the serial monitor interface:

![open_serial](open_serial.png)

- Configure the serial port:

![configure_serial](configure_serial.png)

You must choose the correct port, and the correct `baud rate`. For this application you can stay on 9600. Click on `Start`, you're now connected to the board.

```
If no errors occured, your setup is correct and you are ready to work.
```
