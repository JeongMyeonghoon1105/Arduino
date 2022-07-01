void setup() {
  Serial.begin(9600);
}
 
void loop() {
  int x = analogRead(A0);
  int y = analogRead(A1);
  Serial.print("X 좌표 : ");
  Serial.print(x);
  Serial.print("\t");
  Serial.print("Y 좌표 : ");
  Serial.println(1023 - y);
  delay(200);
}
