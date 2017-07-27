#include<regx51.h>

#define LedPort P0
sbit PwrTrans=P1^4;
sbit R1=P1^0;
sbit R2=P1^1;
sbit R3=P1^2;
sbit R4=P1^3;
sbit C1=P1^5;
sbit C2=P1^6;
sbit C3=P1^7;

void keycheck();

void keyaction();
unsigned int keyno;
void main()
{
PwrTrans=0;
while(1)
{
keycheck();
keyaction();
}
}

void keycheck()
{
C1=1;
C2=1;
C3=1;

C1=0;
  if(R1==0)
  {
    keyno=0x07;
  }
  if(R2==0)
  {
    keyno=0x3f;
  }

C1=1;
C2=0;
    if(R1==0)
  {
    keyno=0x03;
  }
  if(R2==0)
  {
    keyno=0x1f;
   }
C2=1;
C3=0;
  if(R1==0)
  {
    keyno=0x01;
  }
  if(R2==0)
  {
    keyno=0x0f;
	}  
C3=1;
}

void keyaction()
{
LedPort=~keyno;
}

