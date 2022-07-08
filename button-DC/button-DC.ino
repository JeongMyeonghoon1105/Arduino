void setup() {
  pinMode(10, INPUT);
  pinMode(13, OUTPUT);
}

void loop() {
  if (digitalRead(10) == HIGH) {
    digitalWrite(13, 5000);
  } else {
    digitalWrite(13, LOW);
  }
}
