#define rightback 9
#define leftback 6
#define rightfront 5
#define leftfront 3
#define TRIG 10
#define ECHO 11

long duration;
long distance;

void setup()
{
  pinMode(rightfront, OUTPUT);
  pinMode(leftfront, OUTPUT);
  pinMode(rightback, OUTPUT);
  pinMode(leftback, OUTPUT);
  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);
  Serial.begin(9600);
}

void loop()
{
  digitalWrite(TRIG, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG, LOW);
  duration = pulseIn(ECHO, HIGH);
  distance = duration * 17 / 1000;
  Serial.print("\nDistance : ");
  Serial.print(distance);
  
  if (distance < 70)
  {
    digitalWrite(rightfront, LOW);
    digitalWrite(leftfront, LOW);
    digitalWrite(rightback, HIGH);
    digitalWrite(leftback, HIGH);
  }
  else
  {
    digitalWrite(rightback, LOW);
    digitalWrite(leftback, LOW);
    digitalWrite(rightfront, HIGH);
    digitalWrite(leftfront, HIGH);
  }
  delay(1000);
//  analogWrite(rightfront, spd);
//  analogWrite(leftfront, spd);
}
