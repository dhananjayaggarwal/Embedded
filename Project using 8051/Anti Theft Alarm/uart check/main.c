#include<regx52.h>

void uart_init();
int stncmp(char* , char*);
unsigned char ch, flag=0, i=0, sbuff[20], check=1, rdy[]="RDY", cfun[]="+CFUN: READY", cpin[]="+CPIN: READY", call_ready[]="Call Ready";
void tx0(unsigned char);
void main()
{
uart_init();
for(i=0;i<1000;i++)
{}
tx0('O');

/*while(check){
	  check=stncmp(sbuff,"RDY");
}
while(check){
	  check=stncmp(sbuff,cfun);
}
while(check){
	  check=stncmp(sbuff,cpin);
}
while(check){
	  check=stncmp(sbuff,call_ready);
} */

tx0('K');
while(1)
{
if(flag==1)
{	flag=0;
	
}
}

}


void uart_init()
{
	TMOD=0x20;	  	// select the timer 1
	SCON=0x50;		// initilise UART
	TH1=0xfd;		// baud rate----9600
	EA=1;			// enable globel interrupt
	ES=1;
	TR1=1;			// enable timer 1
}

void serial_interupt() interrupt 4
{
  if(RI==1)
  {
  	ch=SBUF;
	RI=0;
  
  flag=1;

  if(ch!=0x0d)
	{
	sbuff[i++]=ch;
	}
	else
	{
	  sbuff[i]='\0';
	  i=0;
	}
  }
  else TI=0;
}

int strcmp(char* a, char* b)
{
while(*a++==*b++)			n
{
	if(*a=='\0')
	return 0;
	return 1;
}
}

void tx0(unsigned char x) //send data to serial port 0
{
//	EA=0;
	SBUF=x;
	while(TI==0);
	TI=0;
//	EA=1;
}