#include <Servo.h>

int potPin = 12;
int servoPin = 14;
Servo servo;

void setup()
{
  servo.attach(servoPin);
}

void loop()
{
  int reading = analogRead(potPin);     // 0 to 1023
  int angle = reading / 6;              // 0 to 180-ish
  servo.write(angle);
}
