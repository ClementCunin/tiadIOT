#include "Arduino.h"

#define DC_PIN    14
#define RED_PIN   12
#define GREEN_PIN 13
#define BLUE_PIN  15
#define BUT1      0
#define BUT2      16
#define BUT3      5

unsigned int      analog_val;

void setup() {
  // Init serial for some debugs
  Serial.begin(9600);
  // Init pin mode
  pinMode(DC_PIN, OUTPUT);
  pinMode(RED_PIN, OUTPUT);
  pinMode(GREEN_PIN, OUTPUT);
  pinMode(BLUE_PIN, OUTPUT);
  pinMode(BUT1, INPUT);
  pinMode(BUT2, INPUT);
  pinMode(BUT3, INPUT);

  // Set the DC pin sending voltage
  analogWrite(DC_PIN, 255);

}

void loop() {

  // Get the potentiometer value and divide it to fit analogWrite range
  analog_val = analogRead(0) / 4;

  // Write the value if the assigned button is pressed
  if (digitalRead(BUT1) == 1)
    analogWrite(RED_PIN, analog_val);

  if (digitalRead(BUT2) == 1)
    analogWrite(GREEN_PIN, analog_val);

  if (digitalRead(BUT3) == 1)
    analogWrite(BLUE_PIN, analog_val);

  delay(100);

}
