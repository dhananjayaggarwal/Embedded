#include<reg51.h>

#define LedPort P0
sbit LedPwrTrans=P1^4;
delay();
void main()
{
LedPwrTrans=0;

while(1)
 {LedPort=0x0F;
  delay();
  LedPort=0xF0;
  delay();
  }
}
delay()
{  
int i;
for(i=0; i<32700; i++);
}