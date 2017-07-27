#include<regx52.h>
#define seg_port P0
#define adcport P0


sbit add_a= P3^6;
sbit add_b= P3^7;
sbit ale= P3^2;
sbit eoc= P3^3;
sbit clock= P3^4;
sbit oe= P3^5;

sbit Unittr=P2^0;
sbit Tenstr=P2^1;
sbit Hundtr=P2^2;
sbit Thsdtr=P2^3;
unsigned char Unit=0, Tens=1, Hund=2, Thsd=3;
const unsigned char Table[]={0xc0, 0xf9, 0xa4, 0xb0, 0x99, 0x92, 0x82, 0xf8, 0x80, 0x90};
unsigned char value;

void display();
void adc_read();
void adc_init();
void delay(int);

void main()
{
	adc_init();
	EA=1;       
	ET0=1;
    TMOD = 0X01;
    TH0  = 0XFF;
    TL0  = 0X9C;
    TR0=1; 
	 
	while(1)
	{

	 adc_read();


		
	}

}

void display()
{
   seg_port = Table[Unit];
	Unittr=0;
	delay(100);
	Unittr=1;

	seg_port = Table[Tens];
	Tenstr=0;
	delay(100);
	Tenstr=1;

	seg_port = Table[Hund];
	Hundtr=0;
	delay(100);
	Hundtr=1;

	seg_port = Table[Thsd];
	Thsdtr=0;
	delay(100);
	Thsdtr=1;

}

void adc_init()
{
	ale=0;
	eoc=0;
	oe=0;
	clock=0;
	add_a=0;
	add_b=0;
}

void adc_read()
{
	  
	add_a=0;
	add_b=0;
	ale=1;
	delay(1000);
	ale=0;
	delay(1000);

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
		display();
}

void delay(int t)
{
int i;
for(i=0;i<t;i++);
}


void timer0() interrupt 1
{
	TH0  = 0XFF;
    TL0  = 0X9C;
	clock=~clock;

}