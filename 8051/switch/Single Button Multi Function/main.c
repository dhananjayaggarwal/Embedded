#include <REGX51.H>

#define LedPort P0
sbit PwrTrans=P1^4;
sbit R1 = P1^0;
sbit R2 = P1^1;
sbit R3 = P1^2;

sbit C1 = P1^5;


int keycheck();
void delay();
void keyaction(int);
static unsigned int keynum, key, flag;

void main()
{
PwrTrans=0;

  while(1)
	{
 	key=keycheck();
 	keyaction(key);
 
	}

}

int keycheck()
{
C1=1;
C1=0;
if(R2==0)
{
 if(flag==1)
 { flag=0;
  keynum++;
  }
}
else flag=1;
C1=1;
if(keynum==5)
 {keynum=1;
 }
return keynum;

}

void keyaction(int key)
{
switch(key)
 {
  case 1: LedPort=~0x01;
      break;
   case 2: LedPort=~0x03;
    break;
   case 3:LedPort=~0x07;
    break;
    case 4:LedPort=~0x0f;
   		break;
 }

}

