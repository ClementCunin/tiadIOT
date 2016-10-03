#include <Arduino.h>

#define PUSH_BUTTON 2
#define LED_PIN 16

// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  // make the pushbutton's pin an input:
  pinMode(PUSH_BUTTON, INPUT);
  pinMode(LED_PIN, OUTPUT);
}

// the loop routine runs over and over again forever:
void loop() {
  // print out the state of the button:
  if( digitalRead(PUSH_BUTTON) ) {
    Serial.println("Allumage de la led pour 3s");
    digitalWrite(LED_PIN, HIGH);
    // wait for a second
    delay(3000);
    // turn the LED off by making the voltage LOW
    digitalWrite(LED_PIN, LOW);
  } else {
    delay(100);
  }
}
