#include <Servo.h>

Servo s;
void setup() {
  Serial.begin(9600);
  pinMode(8, INPUT);
  s.attach(7);
  s.write(0);
}

void loop() {
  if (digitalRead(8) == LOW) {
    Serial.println("On");
    s.write(90);
  } else {
    Serial.println("Off");
    s.write(0);
  }
  delay(1000);
}
