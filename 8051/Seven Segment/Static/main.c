#include <REGX51.H>

#define seg_port P0

sbit Unittr = P2^0;
sbit Tenstr = P2^1;
sbit Hundtr = P2^2;
sbit Thsdtr = P2^3;

unsigned char Unit=0, Tens=1, Hund=2, Thsd=3;

unsigned char Table[]={0xc0, 0xf9, 0xa4, 0xb0, 0x99, 0x92, 0x82, 0xf8, 0x80, 0x90};
void display();

void main()
{
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