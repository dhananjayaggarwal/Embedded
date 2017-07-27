#include<reg51.h>

#define LedPort P0
sbit LedTrans=P1^4;
void delay()
{
int j;
for(j=0;j<31000;j++);
}
void main()
{
int a,b;
b=0x01;
LedTrans=0;

LedPort=0xff;
for(a=0;a<8;a++)
  {
    LedPort = LedPort << 1;
	delay();
	
  }
   for(a=0;a<8;a--)
    {
	LedPort|=b;
	b<<=1;
	delay();
    }
	 
}