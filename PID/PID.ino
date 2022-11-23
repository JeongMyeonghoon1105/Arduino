#include <Servo.h>
Servo servo;

//  PID 상수 정의
double kp = 0.005;
double ki = 0.002;
double kd = 0.001;
 
unsigned long currentTime, previousTime;
double elapsedTime;
double error;
double lastError;
double input, output, setPoint;
double cumError, rateError;
 
void setup(){
  Serial.begin(9600);
  servo.attach(11);
  setPoint = 72;     // setPoint 변수 초기화
  servo.write(0);
  delay(1000);
}    
 
void loop(){
  input = servo.read();     // 서보모터 각도 읽기
  output = computePID(input);
  Serial.println(output);
  delay(500);
  servo.write(output);     // PID 제어값으로 모터 제어
}

// PID 제어값 계산 함수
double computePID(double inp){     
  currentTime = millis();    // 현재 시간 가져오기
  elapsedTime = (double)(currentTime - previousTime);   // 마지막 실행 이후 흐른 시간 계산
  error = setPoint - inp;     // 현재 오차 계산
  cumError += error * elapsedTime;     // 적분 계산
  rateError = (error - lastError)/elapsedTime;   // 미분 계산

  double out = (kp * error) + (ki * cumError) + (kd * rateError);    // PID 제어값 계산             

  lastError = error;     // 현재 에러를 저장
  previousTime = currentTime;    // 현재 시간 저장

  return out;     // 제어 결과 반환
}
