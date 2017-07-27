//objective: To Converge and diverge
//Name: Dhananjay Aggarwal
//Starting Date:2-4-17
//Cpu Board: Tico Magic
//uc: AT89S52
//Crystal:11.0592

#include <REGX51.H>

#define LedPort P0
void delay()
{
int i;
for(i=0;i<30000;i++);
}
sbit LedPwrTrans=P1^4;
int a,b;
void main()
{

LedPwrTrans=0;
a=0x80;
b=0x01;
while(1)
  {
   LedPort=~(a|b);
   a>>=1;
   b<<=1;
   delay();
   if(a==0x00&&b==0x00)
   {
   	a=0x80;
	b=0x01;
   }
  }
}


