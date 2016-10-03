#include <Arduino.h>

#define PUSH_BUTTON 2

// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(115200);
  // make the pushbutton's pin an input:
  pinMode(PUSH_BUTTON, INPUT);
}

// the loop routine runs over and over again forever:
void loop() {
  // print out the state of the button:
  Serial.println(digitalRead(PUSH_BUTTON));
  delay(500);        // delay in between reads for stability
}
