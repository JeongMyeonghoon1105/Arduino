#include "LedControl.h"

#define DIN 12
#define CS 11
#define CLK 10

LedControl lc = LedControl(DIN,CS,CLK,1);
byte x[8] = {
  B10000001,
  B01000010,
  B00100100,
  B00011000,
  B00011000,
  B00100100,
  B01000010,
  B10000001,
}

void setup()
{
  // 절전모드 해제
  lc.shutdown(0,false);
 
  // LED 밝기를 8로 지정
  lc.setIntensity(0,8);
 
  // 도트매트릭스의 LED를 초기화
  lc.clearDisplay(0);
}

void loop()
{
  for (int i = 0; i < 8; i++) {
    lc.setRow(0, i, x[i]);
  }
}
