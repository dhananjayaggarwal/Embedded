//Program To Display Custom Font on 16x2 LCD operated in 4 bit mode

#include<regx52.h>
#define lcdport P0

void lcd_ini();
void lcd_com(unsigned char);
void lcd_data(unsigned char);
void character();
void delay(int);

sbit rs = P2^4;
sbit en = P2^5;

void main()
{
    lcd_ini();          //Initialize The LCD
    
    character();         //Function having user generated text
	lcd_com(0x80);
	lcd_data(0);

	while(1)
	{
		lcd_com(0x81);
		delay(10000);
		lcd_data(0);
		delay(10000);
		lcd_com(0xc0);
		delay(20000);
		lcd_data(0);
		delay(20000);
	}
    
}

void lcd_ini()
{
    lcd_com(0x02);      //cursor at home
    delay(15000);
    
    lcd_com(0x28);      //function set
    delay(60);
    
    lcd_com(0x06);      //entry mode
    delay(60);
    
    lcd_com(0x0f);      //display control
    delay(60);
    
    lcd_com(0x01);      //clear display
    delay(1640);
    
}

void lcd_com(unsigned char com)
{
    rs = 0;     //command mode
	
	lcdport = com & 0xf0;
    en = 1;
    delay(100);
    en = 0;
    
    lcdport = com << 4;
    en = 1;
    delay(100);
    en = 0;
}

void lcd_data(unsigned char alp)
{
    rs = 1;     //command mode
    
    lcdport = alp & 0xf0;
    en = 1;
    delay(100);
    en = 0;
    
    lcdport = alp << 4;
    en = 1;
    delay(100);
    en = 0;
}

void character()
{
   	lcd_com(64);        //three exclamation in single line
	lcd_data(21);
    lcd_data(21);
    lcd_data(21);
    lcd_data(21);
    lcd_data(21);
    lcd_data(0);
    lcd_data(21);
    lcd_com(0xc0);
	

    
}

void delay(int t)
{
    int i;
    
    for(i=0; i<t; i++);
}