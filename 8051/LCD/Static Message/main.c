#include <REGX51.H>

sbit rs = P2^4;
sbit en = P2^5;
#define lcdport P0

void lcd_init();
void lcd_data(unsigned char dat);
void lcd_command(unsigned char comd);
void delay(int);
void lcd_string(unsigned char *s);

void main()
{
char stng[] = {"Hello,How are YuI'm Fine Thank u"};
lcd_init();
lcd_string(&stng[0]);

while(1){}


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


void lcd_command(unsigned char comd)	  //To send commands using 4 bit bus
{
rs=0;									  //register select is low which implies command

lcdport=(comd&0xf0);					   //Most Significant 4 bits are send to microcontroller first
en=1;									   //when enable drops from high to low, bit is transferred to controller
delay(1000);
en=0;
											//Nest LSB's are transferred
lcdport=(comd<<4);
en=1;
delay(1000);
en=0;

}

void lcd_data(unsigned char dat)		//To send data to lcd
{
rs=1;									//rs high implies read or write, we perform only write as we keep R/W pin grounded

lcdport=(dat&0xf0);
en=1;
delay(1000);
en=0;

lcdport=(dat<<4);
en=1;
delay(1000);
en=0;

}

void lcd_string(unsigned char *s)
{
 int i=0;
 	while(s[i]!='\0')
 	{
 		if(i==16)
		{
			lcd_command(0xc0);
		}
		lcd_data(s[i]);
		i++;
 	}
}
									   
void delay(int t)					   //To delay
{
	int i;
	for(i=0;i<t;i++);
}