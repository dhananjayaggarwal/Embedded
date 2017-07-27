#include<reg51.h>

#define LedPort P0
sbit LedPwrTrans=P1^4;
int a;
//int b;


void delay();
void main()
{
LedPwrTrans=0;
a = 0x80;
//b = 0x80;
while(1)
 {
    LedPort=~a;
	a=a>>1;
//	a+=b;
	  delay();
	 
 } 
}
void delay()
{  
int j;
for(j=0; j<30000; j++);
}