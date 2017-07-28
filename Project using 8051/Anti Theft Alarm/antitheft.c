#include<regx52.h>
#include<lcd.h>
#include<adc.h>
#include<stdio.h>
#include<gsm.h>

sbit buzz = P2^7;
sbit relay1 = P2^1;	  //pin 22
sbit relay2 = P2^0;	 //pin 21
sbit closeswitch = P2^3; //switch to off alarm
sbit ir1 = P2^4; //pin25
sbit ir2 = P2^5; //pin 26
unsigned int flag=0, i=0, flag1=0;
unsigned char buffer[10];
int j;
void detect();
void check_ir(void);
void detect1();
char ok[]="OK";

char strbuf[25];
int count=0;





void main()
{
  lcd_init();
  custom();
  lcd_string("Welcome...");
  ir2=0;
  relay1=0;
  relay2=0;
  buzz=0;
  uart_init();
  delay(30000);
  delay(30000);
  
  
 /* tx_string("AT");
	str[0]=rx_data;
	str[1]=rx_data;
	while(!strcomp(str,ok));
	str[0]='\0';
   */
  
	while(1)
	{
	   detect();
	   if(i==2000&&flag1==0)
	   {
	   i=0;
	   adc_read();
	   sprintf(buffer,"Illuminance: %d",adcvalue/5);
		lcd_command(0x01);
		lcd_string(buffer);
		for(j=0;j<20000;j++)
			{
			  check_ir();
			}

	   } 
	   if(flag==1)
	   {
	     flag=0;
		 detect1();
	   }


	   i++;
	   
	   
	}

	
}



void detect()
{
    
	if(ir2==1) //as soon as ir sensor output becomes high
	{
	//	 gsm_init();
	//	delay(1000);			  //switch everything on
		flag1=1;
		relay1=1;
		delay(1500);
		relay2=1;
		delay(1500);
	/*	if((relay1||relay2)==1)
	{	buzz=1;} */ 
		lcd_command(0x01);
		lcd_string("ALERT");
		lcd_data(0); //Three exclamations are stored on location 0 of cg ram(custom font)
		gsm_call();
	
	}
	if(closeswitch==0)	   //as soon as switch is pressed, switch off alarms/relays
	{
	      flag1=0;
		  buzz=0;
		    relay1=0;
			relay2=0;
			lcd_command(0x01);
			lcd_string("You are now safe");
			;
			for(j=0;j<30000;j++)
			{
			  check_ir();
			}
	}

}

void check_ir()
{
	if(ir2==1)
	{
	flag=1;
	}
}

void detect1()
{
	//	 gsm_init();
	//	delay(1000);			  //switch everything on
		flag1=1;
		relay1=1;
		delay(1500);
		relay2=1;
		delay(1500);
	/*	if((relay1||relay2)==1)
	{	buzz=1;} */ 
		lcd_command(0x01);
		lcd_string("ALERT");
		lcd_data(0); //Three exclamations are stored on location 0 of cg ram(custom font)
		gsm_call();
	}

