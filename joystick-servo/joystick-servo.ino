#include <Servo.h>
Servo servo;

void setup() {
  servo.attach(11);
  Serial.begin(9600);
  servo.write(0);
}

void loop() {
  int x = 1023 - analogRead(A0);
  
  Serial.println(x);
  servo.write(x / 10);
}
