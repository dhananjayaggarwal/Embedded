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

void rotate();
void converge();
void sandGlass();
void binaryCounter();
void swap();
void blink();
void delay();

unsigned int keyno;
unsigned char rri=0,rra = 0x80;
int a,b;

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
    keyno=3;
  }
   if(R2==0)
  {
    keyno=6;
  }

  C1=1;
  C2=0;
    if(R1==0)
  {
    keyno=2;
  }
  if(R2==0)
  {
    keyno=5;
   }
  C2=1;
  C3=0;
  if(R1==0)
  {
    keyno=1;
  }
  if(R2==0)
  {
    keyno=4;
	} 
  if(R3==0)
  {
   keyno=7;
  } 
  C3=1;
}

void keyaction()
{
 
 switch(keyno)
  {
  	case 1:{ blink();
	       break;
		   }
    case 2: { swap();
	        break;
			}
	case 3: { rotate();
			break; }
	case 4:{ converge();
			 break; }
	case 5: { sandGlass();
			 break; }
	case 6: { binaryCounter();
			   break; }
  
  
  }
}

void blink()
{
LedPort=0x00;
delay();
LedPort=0xff;
delay();

}

void swap()
{
LedPort=0x0f;
delay();
LedPort=0xf0;
delay();
}

void converge()
{
int i;
a=0x80;
b=0x01;
for(i=0;i<8;i++)
  {
   LedPort=~(a|b);
   a>>=1;
   b<<=1;
   keycheck();
   if(keyno!=4)
   break;
   delay();
   
  }
}

void rotate()
{
//for(i=0;i<8;i++)
if(rri<8)
 {
    LedPort=~rra;
	rra=rra>>1;
	rri++;
	if(rri==8)
	{rri=0;
	rra = 0x80;
	}
	  delay();
}
}

void delay()
{  
int j;

for(j=0; j<30000; j++);
keycheck();

}

void sandGlass()
{
int i,c,j;
b=0x00;
c=0x01;

 
  for(i=8;i>0;i--)
   {
   a=0x80;
     for(j=0;j<i;j++)
	 {
	   LedPort=~(a|b);
	   a=a>>1;
	   delay();
	 }
	 b<<=1;
	 b=b|c;

   }
 
}

void binaryCounter()
{
	 b=0x01;
   LedPort=0xff;
for(a=0;a<8;a++)
  {
    LedPort = LedPort << 1;
	delay();
	
  }
   
}
