#include <Servo.h>
Servo servo;

void setup() {
  servo.attach(11);
  Serial.begin(9600);
  servo.write(0);
}

void loop() {
  int p = analogRead(A0)/3;
  Serial.println(p);
  servo.write(p);
}
