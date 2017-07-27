#include<regx52.h>
#include<lcd.h>
#include<adc.h>
#include<stdio.h>
#include<gsm.h>
#include<uart.h>
sbit buzz = P2^7;
sbit relay1 = P2^1;	  //pin 22
sbit relay2 = P2^0;	 //pin 21
sbit closeswitch = P2^3; //switch to off alarm
sbit ir1 = P2^4; //pin25
sbit ir2 = P2^5; //pin 26
unsigned int flag=1, i;
unsigned char buffer[10];
void detect();
void check_ir(void);
char ok[]="OK";

char strbuf[25];
int count=0;
void main()
{
  lcd_init();
  custom();
  lcd_string("Welcome...");
  uart_init();
  ir2=0;
  relay1=0;
  relay2=0;
  buzz=0;
 /* tx_string("AT");
	str[0]=rx_data;
	str[1]=rx_data;
	while(!strcomp(str,ok));
	str[0]='\0';
   */
  
	while(1)
	{
	   detect();
	   
	   adc_read();
	   sprintf(buffer,"%d",adcvalue);
	   
	   if(flag==1)
	   {
	     flag=0;
		 detect();
	   }
	  
	   
	   
	}

	
}

/*void buzzer()
	{
		if(adc_output>=88)
		{
		  buzz=1;
		  relay1=1;
		  relay2=1;
		  lcd_string("Danger");	
		} else if(adc_output<88)
		{	buzz=0;
		    relay1=0;
			relay2=0;							]
		 }

		lcd_string(buffer);
	}*/

void detect()
{
	if(ir2==1) //as soon as ir sensor output becomes high
	{
	//	buzz=1;	
	//	delay(1000);			  //switch everything on
		relay1=1;
		delay(1500);
		relay2=1;
		delay(1500);
		lcd_command(0x01);
		lcd_string("ALERT");
		lcd_data(0); //Three exclamations are stored on location 0 of cg ram
		gsm_call();
	}
	if(closeswitch==0)	   //as soon as switch is pressed, switch off alarms/relays
	{
		  buzz=0;
		    relay1=0;
			relay2=0;
			lcd_command(0x01);
			lcd_string("You are now safe");
	}

}

void check_ir()
{
	if(ir2==1)
	{
	flag=1;
	}
}