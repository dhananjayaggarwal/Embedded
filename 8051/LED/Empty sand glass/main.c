//objective: To Converge and diverge
//Name: Dhananjay Aggarwal
//Starting Date:2-4-17
//Cpu Board: Tico Magic
//uc: AT89S52
//Crystal:11.0592

#include <REGX51.H>

#define LedPort P0
int a,i,j,b,c;
void delay()
{
int x;
for(x=0;x<30000;x++);
}


b=0x00;
c=0x01;
sbit LedPwrTrans=P1^4;

void main()
{
LedPwrTrans=0;
while(1)
 {
  for(i=8;i>0;i--)
   {
   a=0x80;
     for(j=0;j<i;j++)
	 {
	   LedPort=~(a|b);
	   a=a>>1;
	   delay();
	 }
	 b<<=1;
	 b=b|c;

   }
  break;
 }
 a=0x80;
 for(i=0;i<8;i++)
 {
   LedPort=a;
   a>>=1;
   a=a+0x80;
   delay();
 
 }
 while(1);
}