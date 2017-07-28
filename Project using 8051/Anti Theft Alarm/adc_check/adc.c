#include<regx52.h>
#include<stdio.h>
#define adcport P1 //pin 1-17, 2-14,3-15,4-8,5-18,6-19,7-20,8-21

sbit ale = P3^4;  //14,6/22
sbit eoc = P3^5;  //15,7
sbit add_a = P3^6; //16,25
sbit add_b = P3^7;	//17,24

#define lcdport P0
sbit rs = P0^0;	   //0.0
sbit en = P0^1;	  //0.1
sbit buzzer = P2^7;


unsigned int adcvalue, adcoutput;
int adc_read();
void lcd_init();
void delay(int t);
void lcd_command(unsigned char );
void lcd_data(unsigned char);
void lcd_string(char*);
unsigned char buffer[20];
void main()
{
lcd_init();
lcd_string("WELCOME");
delay(30000);
delay(30000);

lcd_command(0x01);
delay(30000);
delay(30000);
buzzer=1;
delay(1000);
while(1)
{
	//lcd_data('1');
	//delay(30000);
//	 adcoutput=adc_read();
	//lcd_data('2');
	
	 /*  sprintf(buffer,"%d",adcoutput/20);
		lcd_command(0x01);
		lcd_string(buffer);
		 delay(30000);
		 delay(30000);
		 delay(30000);	*/

}
}
/*
int adc_read()
{
	
	
	add_a=0;
	add_b=0;
	delay(100);
	
	ale=1;
	delay(1000);
	ale=0;

	delay(1000);
	
	eoc=0;
		delay(10);
		while(eoc==1);
	
	
	  
	adcvalue=adcport;
	return(adcvalue);
}  */


 void delay(int t)
{
	int i;
	for(i=0;i<t;i++);
}
/*
void lcd_command(unsigned char comd)	  //To send commands using 4 bit bus
{
rs=0;
lcdport&=0x0f;									  //register select is low which implies command
lcdport|=(comd&0xf0);					   //Most Significant 4 bits are send to microcontroller first
en=1;									   //when enable drops from high to low, bit is transferred to controller
delay(100);
en=0;

lcdport&=0x0f;											//Nest LSB's are transferred
lcdport|=((comd<<4)&0xf0);
en=1;
delay(100);
en=0;

}

void lcd_init()			//To initialize working of lcd
{
lcd_command(0x02);		  // Cursor at home
delay(15000);

lcd_command(0x28);		 //Function Set to 4 bit data bus
delay(40);

lcd_command(0x06);		  //Entry Mode set increament/no shift
delay(40);

lcd_command(0x0f);		  //Display on,cursor displayed,blinks
delay(40);

lcd_command(0x01);		  //Clears all display and returns cursor to home(address 0)
delay(16500);
}

void lcd_data(unsigned char dat)		//To send data to lcd
{
rs=1;						//rs high implies read or write, we perform only write as we keep R/W pin grounded

lcdport&=0x0f;									  //register select is low which implies command
lcdport|=(dat&0xf0);					   //Most Significant 4 bits are send to microcontroller first
en=1;									   //when enable drops from high to low, bit is transferred to controller
delay(100);
en=0;

lcdport&=0x0f;											//Nest LSB's are transferred
lcdport|=((dat<<4)&0xf0);
en=1;
delay(100);
en=0;
}
void lcd_string(char* s)
{
 
  while(*s!='\0')
  {
    lcd_data(*s);
	s++;
  }
}
   */

