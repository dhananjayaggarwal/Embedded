#include <REGX52.H>

sbit buzzer = P2^7;
sbit relay1 = P2^0;
sbit relay2 = P2^1;
void delay(int t)
{
int i;
for(i=0;i<t;i++);
}

void main()
{
//buzzer=1;

relay1=1;
delay(10000);
relay2=1;
delay(10000);
while(1)
{
	
}

}
