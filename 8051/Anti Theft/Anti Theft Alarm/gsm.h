#ifndef __GSM_H__
#define __GSM_H__
int k;
unsigned char str[26];
void gsm_init()
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

void gsm_read()
{
	while(RI==0);
	str[k]=SBUF;
	RI=0;
}

void gsm_call()
{
}

#endif