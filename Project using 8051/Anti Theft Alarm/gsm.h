#ifndef __GSM_H__
#define __GSM_H__
#include<string.h>

int k;
unsigned char str[26];
void uart_init()
{
	TMOD=0x20;
	TH1=0xfd;
	SCON=0x50;
	TR1=1;
}

void gsm_write(unsigned char ch)
{
	SBUF=ch;
	while(TI==0);
	TI=0;
}



void tx_data(unsigned char serialdata)
{
  SBUF=serialdata;
  while(TI==0);
  TI=0;
}

unsigned rx_data()
{
 while(RI==0);
 RI=0;
 return SBUF;
}

void tx_string(char *str)
{
 while(*str)
  {
  /*	if(*str=='/'&&(*str+1)=='n')
	{
		tx_data(0x0d);
		tx_data(0x0a);
		str++;
	} */
	
    tx_data(*str);
    str++;
	
  }
}

void gsm_call()
{
  tx_string("ATD+919582975127;\r");
  	delay(30000);
		delay(30000);
		
		delay(1000);

}




#endif