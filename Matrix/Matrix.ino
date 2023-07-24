#include "LedControl.h"

#define DIN 12
#define CS 11
#define CLK 10

LedControl lc = LedControl(12,11,10,1);

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
  // 도트매트릭스의 LED를 첫번째 부터 1개씩 차례대로 켜줍니다.
 for (int row=0; row<8; row++)
  {
    for (int col=0; col<8; col++)
    {
      lc.setLed(0,col,row,true);
      delay(25);
    }
  }
 
  // 도트매트릭스의 LED를 첫번째 부터 1개씩 차례대로 꺼줍니다.
 for (int row=0; row<8; row++)
  {
    for (int col=0; col<8; col++)
    {
      lc.setLed(0,col,row,false);
      delay(25);
    }
  }
}
