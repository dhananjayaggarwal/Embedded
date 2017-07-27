#include <REGX51.H>

#define seg_port P0

sbit Unittr = P2^0;
sbit Tenstr = P2^1;
sbit Hundtr = P2^2;
sbit Thsdtr = P2^3;

sbit R1=P1^0;
sbit R2=P1^1;
sbit R3=P1^2;
sbit R4=P1^3;
sbit C1=P1^5;
sbit C2=P1^6;
sbit C3=P1^7;

unsigned char Unit, Tens, Hund, Thsd;
unsigned int keyno, key, key1, key2, key3;

unsigned char Table[]={0xc0, 0xf9, 0xa4, 0xb0, 0x99, 0x92, 0x82, 0xf8, 0x80, 0x90};
void display();
int keycheck();
void keyaction(int);

void main()
{
 while(1)
   {
     key=keycheck();
   	 
	 keyaction(key);
	 display();
   }
}

void display()
{
  seg_port = Table[Unit];
  Unittr = 0;
  Unittr = 1;

  seg_port = Table[Tens];
  Tenstr = 0;
  Tenstr = 1;

  seg_port = Table[Hund];
  Hundtr = 0;
  Hundtr = 1;

  seg_port = Table[Thsd];
  Thsdtr = 0;
  Thsdtr = 1;

}

int keycheck()
{
C1=1;
C2=1;
C3=1;

C1=0;
  if(R1==0)
  {
    keyno=1;
  }
  if(R2==0)
  {
    keyno=2;
  }
  if(R3==0)
   keyno=3;

   if(R4==0)
    keyno=10;

C1=1;
C2=0;
    if(R1==0)
  {
    keyno=4;
  }
  if(R2==0)
  {
    keyno=5;
   }
   if(R3==0)
   keyno=6;
if(R4==0)
    keyno=11;

C2=1;
C3=0;
  if(R1==0)
  {
    keyno=7;
  }
  if(R2==0)
  {
    keyno=8;
	}
	if(R3==0)
   keyno=9; 
   if(R4==0)
    keyno=12; 
C3=1;
return keyno;

}


void keyaction(int key)
{
if(key<10)
 {
    Tens=Hund=Thsd=0;
	Unit=key;
 }
 else
 {
   Unit=key%10;
   Hund=key/10;

 }
}