#include <REGX52.H>
#define ledport P0
#define adcport P0

sbit ledpwrtr= P1^4;
sbit add_a= P3^6;
sbit add_b= P3^7;
sbit ale= P3^2;
sbit eoc= P3^3;
sbit clock= P3^4;
sbit oe= P3^5;
void adc_init();
void delay();
void main()
{
adc_init();
ledpwrtr=0;
while(1)
{
	clock=1;
	add_a=0;
	add_b=0;
	clock=0;
	ale=1;
	clock=1;
	delay();
	clock=0;
	ale=0;
	clock=1;
	delay();
	while(eoc==1)
	{
		clock=0;
		clock=1;
	}
	while(eoc==0)
	{
		clock=0; 
		clock=1;
	} 
	adcport=0xff;
	clock=0;
	oe=1;
	clock=1;
	ledport=~adcport;
	oe=0;
	clock=0;


}

}

void adc_init()
{
	ale=0;
	oe=0;
	eoc=0;

}
void delay()
{
int i;
for(i=0;i<1000;i++);
}