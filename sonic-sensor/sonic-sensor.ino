#define TRIG 8
#define ECHO 9
#define LED 12

void setup() {
  Serial.begin(9600);
  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);
  pinMode(LED, INPUT);
}

void loop()
{
  long duration, distance;

  digitalWrite(TRIG, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG, LOW);
  
  duration = pulseIn (ECHO, HIGH);
  distance = duration * 17 / 1000;
  Serial.println(duration );
  Serial.print("\nDistance : ");
  Serial.print(distance);
  Serial.println(" cm");
  
  if (distance < 30) {
    digitalWrite(LED, HIGH);
  } else {
    digitalWrite(LED, LOW);
  }
  delay(1000);
}
