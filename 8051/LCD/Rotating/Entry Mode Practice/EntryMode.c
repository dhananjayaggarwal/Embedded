#include <REGX51.H>
#define lcdport P0
sbit rs = P2^4;
sbit en = P2^5;
sbit R1=P1^0;
sbit R2=P1^1;
sbit R3=P1^2;
sbit R4=P1^3;
sbit C1=P1^5;
sbit C2=P1^6;
sbit C3=P1^7;



void lcd_init();
void lcd_data(unsigned char dat);
void lcd_command(unsigned char comd);
void delay(int);
void lcd_string(unsigned char *s);

void display(char *p);


void main()
{
  unsigned char i, j=0xcf;

lcd_init();



//delay(30000);
//lcd_command(0x07);
//delay(30000);

	for(i=0x80;i<0x8f;i++)
	{

	lcd_command(0x06);
	lcd_command(0x01);
	lcd_command(i);
	display("hello");
	delay(20000);
//	lcd_command(0x1c); //Right Display Shift
	
	lcd_command(0x04);

//	 delay(20000);

		lcd_command(j); //Left Shift
		
		
		display("uoYerAwoH");
		delay(20000);
		j--;
		
	 }
	}

 		 //"allan si ehs seY"






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
											//Next LSB's are transferred
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


									   
void delay(int t)					   //To delay
{
	int i;
	for(i=0;i<t;i++);
}

void display(char *p)
{
	while(*p!='\0')
	{
		lcd_data(*p);
		p++;
		
	}


}