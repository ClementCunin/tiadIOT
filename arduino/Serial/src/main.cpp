#include "Arduino.h"

int i=0;
setup() {
	Serial.begin(115200);
	Serial.println("Program start");
}

loop() {
	Serial.print("Hello world. Uptime :");
	Serial.print(++i);
	Serial.println(" seconds.");
	delay(1000);
}