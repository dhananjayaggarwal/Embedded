#include <REGX51.H>
#define ledport P0
sbit ledpt = P1^4;
void delay(int t);
unsigned int i,j,t;
void main()
{

	 ledpt=0;
	 EA=1;
	
	 TMOD=0x01;
	 TR0=1;
	 while(1)
	 {
	 	for(i=0;i<500;i++)
		{
		
	 	ledport=0x00;
		delay(i);
		ledport=0xff;
		delay(500-i);
	 }
	 for(i=0;i<550;i++)
		{
		
		ledport=0xff; 	
		delay(i);
		ledport=0x00;
		delay(550-i);
	 }
	 }

}


void delay(int t)
{
	for(j=0;j<t;j++)
	{
	TH0=0xff;
	TL0=0xeb;
	TR0=1;
	while(TF0==0);
	TF0=0;
	TR0=0;

	 }
}
