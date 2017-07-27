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
int x;
for(x=0;x<32000;x++);
}
sbit LedPwrTrans=P1^4;

void main()
{
int a;
LedPwrTrans=0; //Switch on the pnp transistor
a=0x00;
  while(1)
   {
	  LedPort=~a;
      a=a+0x01;
	  delay();

   }

}