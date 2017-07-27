#include <REGX51.H>

#define seg_port P0

sbit Unittr = P2^0;
sbit Tenstr = P2^1;
sbit Hundtr = P2^2;
sbit Thsdtr = P2^3;

unsigned char Unit=0, Tens=0, Hund=0, Thsd=0;
int count=0;
unsigned char Table[]={0xc0, 0xf9, 0xa4, 0xb0, 0x99, 0x92, 0x82, 0xf8, 0x80, 0x90};
void display();
void clock();

void main()
{

EA=1;
ET0=1;
TMOD=0x01;
display();
TH0=0x4b;
TL0=0xfd;
TR0=1;

 while(1)
   {
   	 
	 display();
   }
}

void display()
{
seg_port = Table[Unit];
Unittr=0;
Unittr=1;

seg_port = Table[Tens];
Tenstr=0;
Tenstr=1;

seg_port = Table[Hund];
Hundtr=0;
Hundtr=1;

seg_port = Table[Thsd];
Thsdtr=0;
Thsdtr=1;

}

void timer_delay() interrupt 1
{

		 TH0=0x4b;
		 TL0=0xfd;
		 count++;
		 if(count>=20)
		 {
		 	count=0;
			clock();
			
		 }


}


 void clock()
 {
	Unit++;
			
			 if(Unit==10)
			{	 Unit=0;
				Tens++;
			}
			 if(Tens==6)
			{	   Tens=0;
				Hund++;
			}
			if(Hund==10)
			{
				Hund=0;
				Thsd++;
			}
			if(Thsd==6)
			{
				Thsd=0;
				Unit=0;
				Tens=0;
				Hund=0;

			}
}