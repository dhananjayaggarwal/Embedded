#include<regx52.h>
#define segport P0
#define adcport P0

sbit add_a=P3^6;
sbit add_b=P3^7;
sbit ale=P3^2;
sbit st=P3^2;
sbit eoc=P3^3;
sbit clock=P3^4;
sbit oe=P3^5;

sbit unittr=P2^0;
sbit tenstr=P2^1;
sbit hundtr=P2^2;
sbit thsdtr=P2^3;

unsigned char Unit=0, Tens=0, Hund=0, Thsd=0;
unsigned char Table[]={0xc0, 0xf9, 0xa4, 0xb0, 0x99, 0x92, 0x82, 0xf8, 0x80, 0x90};
unsigned char value, flag, count=0;

void adc_init();
void adc_read();
void display();
void delay(int);

void main()
{

	EA=1;
	ET0=1;
	TMOD = 0x01;
	TH0= 0xff;
	TL0= 0x9c;
	TR0=1;
	
	while(1)
	{
	
		if(flag==1)
		{
		flag=0;

			adc_read();
		}
		display();
	}
}

void delay(int t)
{
int i;
for(i=0; i<t; i++)
{}
}



void adc_read()
{
	add_a=0;
	add_b=0;
	ale=1;
	delay(50);
	st=1;
	delay(50);
	ale=0;
	st=0;

	while(eoc==1);
	while(eoc==0);

	adcport=0xff;



	oe=1;
	value=adcport;
	oe=0;

	

	Unit=value%10;
	value=value/10;
	Tens=value%10;
	value=value/10;
	Hund=value%10;
	value=value/10;
	Thsd=value%10;

	

}



void display()
{
	segport = Table[Unit];
	unittr=0;
	delay(100);
	unittr=1;

	segport = Table[Tens];
	tenstr=0;
	delay(100);
	tenstr=1;

	segport = Table[Hund];
	hundtr=0;
	delay(100);
	hundtr=1;

	segport = Table[Thsd];
	thsdtr=0;
	delay(100);
	thsdtr=1;

}

void timer0() interrupt 1
{
	TH0=0xff;
	TL0=0x9c;
	clock=~clock;
	
	count++;
	if(count==150)
	{
		count=0;
		flag=1;
	}
}