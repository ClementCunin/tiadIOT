#include "Arduino.h"

#define RED_PIN   12
#define GREEN_PIN 13
#define BLUE_PIN  15

void setup() {
  // init LED pin
  pinMode(RED_PIN, OUTPUT);
  pinMode(GREEN_PIN, OUTPUT);
  pinMode(BLUE_PIN, OUTPUT);


}

int r=0, g=0, b=0;

void loop() {
  r=(r+1)%1024;
  g=(g+2)%1024;
  b=(b-3)%1024;

  analogWrite(RED_PIN, r);
  analogWrite(GREEN_PIN, g);
  analogWrite(BLUE_PIN,b);

  delay(10);
}
