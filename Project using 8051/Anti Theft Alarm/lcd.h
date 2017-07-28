#ifndef __LCD_H__
#define __LCD_H__

#define lcdport P0
sbit rs = P0^0;	   //0.0
sbit en = P0^1;	  //0.1


void delay(int t)
{
	int i;
	for(i=0;i<t;i++);
}

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

/*void lcd_number(unsigned char num)
{
	unsigned char num1;
	num1=num;
	lcd_data((num1/1000)+0x30);
	num1=num1%1000;
	
	lcd_data((num1/100)+0x30);
	num1=num1%100;
	
	lcd_data((num1/10)+0x30);
	lcd_data((num1%10)+0x30);

}

void lcd_goto(char row, char col)
{
 char pos;
  if(row<2)
   {
     pos=0x80 | (row<<6);

	 if(col<16)
	 pos=pos+col;
	 lcd_command(pos);
   }
}*/

int strcomp(char *a, char*b)
{
	while(*a==*b)
	{
	  if(*a=='\0')
	  return 0;
	  a++;
	  b++;
	}
	return(*a-*b);
} 

void custom()
{
lcd_command(64);        //three exclamation in single line
	lcd_data(21);
    lcd_data(21);
    lcd_data(21);
    lcd_data(21);
    lcd_data(21);
    lcd_data(0);
    lcd_data(21);
    
	lcd_command(0x80);
 

}

#endif