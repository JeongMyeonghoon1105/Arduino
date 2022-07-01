#define LED_1 4
#define Button_1 11

void setup()
{
  pinMode(LED_1, OUTPUT);
  pinMode(Button_1, INPUT);
}
 
void loop()
{
  if (digitalRead(Button_1) == HIGH)
  {
    digitalWrite(LED_1, HIGH);
  }
  else
  {
    digitalWrite(LED_1, LOW);
  }
}
