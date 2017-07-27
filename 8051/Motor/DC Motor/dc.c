#include<regx52.h>
sbit in1 = P3^4;
sbit in2 = P3^5;

void delay(int);

void main()
{
	
while(1)
{	 int i;
	for(i=0;i<15000;i++)
	{
	in1=0;
	in2=1;
	delay(15000-i);
	in1=1;
	in2=1;
	delay(i);
	}
	
}
}

void delay(int t)
{
	int i;
	for(i=0;i<t;i++);
}