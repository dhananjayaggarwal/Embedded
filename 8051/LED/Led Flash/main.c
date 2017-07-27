#include <REGX51.H>

#define LedPort P0

sbit LedPwrTrans=P1^4;

void delay()
{
int i;
  for(i=0;i<20000;i++);
//  for(j;j<100;j++);
}

void main()
{
LedPwrTrans = 0;

while(1)
  {
    LedPort=0xFF;
	delay();
	LedPort=0x00;
	delay();
	}
}