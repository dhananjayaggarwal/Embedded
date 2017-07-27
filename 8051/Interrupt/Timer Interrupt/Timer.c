#include<regx51.h>
#define ledport P0
sbit ledpt = P1^4;
unsigned int count;
void main()
{
	ledpt=0;
	EA=1;		 //Enable Global Interrupt
	ET0=1;		 //Enable Timer0 Interrupt

	TMOD=0x01;		//16-bit mode for T0

	TH0=0x3c;
	TL0=0xb0;	//for 50ms delay	 

	TR0=1;		//Timer) enable		//jaise hi timer overflow hoga, uska isr call hoga
	ledport=0x00;
	while(1)
	{
	  /*while mei chalre hai hum, 50ms hue, uska isr call hua, timer ko firse fill kiya, count ++ kiya, firse overflow hua, firse count badhaya
		aise hi jaise count 20 hua, if ke andar gaye, ledport ko complement kiya aur count firse 0 kardia*/
	}


}

void time0() interrupt 1
{
	   TH0=0x3c;
		TL0=0xb0;
		count++;
		if(count>=20)	   //50ms 20 times implies one second
		{
			count=0;
			ledport=~ledport;
		}
	
}