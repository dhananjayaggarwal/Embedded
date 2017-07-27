#include <REGX51.H>
#include<string.h>
sbit rs = P2^4;
sbit en = P2^5;
#define lcdport P0
sbit R1=P1^0;
sbit R2=P1^1;
sbit R3=P1^2;
sbit R4=P1^3;
sbit C1=P1^5;
sbit C2=P1^6;
sbit C3=P1^7;

char keycheck();	//It returns a character which is send to lcd data

unsigned char keyno, key, flag;	 //because character need to be shown
unsigned int i=0;
unsigned char input[10];
void lcd_init();
void lcd_data(unsigned char dat);
void lcd_command(unsigned char comd);
void delay(int);
void lcd_string(unsigned char *s);
void keyaction(char key);
void passcheck(char);

void main()
{

lcd_init();
i=0;

while(1){

	key=keycheck();			 //Call to return which key was pressed
	keyaction(key);	 //Send keypressed to data
	 passcheck(key);   //agar * dabaya to check karo entered data is matched to password or not

}
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


									   
void delay(int t)					   //To delay
{
	int i;
	for(i=0;i<t;i++);
}

char keycheck()
{
  C1=1;
  C2=1;
  C3=1;
   keyno='n';		//agar koi key press ni ki humne to 
  C1=0;
   if(R1==0)
  {
    keyno='3';
  }
   if(R2==0)
  {
    keyno='6';
  }
	if(R3==0)
	{
		keyno='9';
	}
   if(R4==0)
   {
   	keyno='#';
   }

  C1=1;
  C2=0;
    if(R1==0)
  {
    keyno='2';
  }
  if(R2==0)
  {
    keyno='5';
   }

   	if(R3==0)
	{
		keyno='8';
	}
   if(R4==0)
   {
   	keyno='0';
   }
  C2=1;
  C3=0;
  if(R1==0)
  {
    keyno='1';
  }
  if(R2==0)
  {
    keyno='4';
	} 
  if(R3==0)
  {
   keyno='7';
  } 
  	
   if(R4==0)
   {
   	keyno='*';
   }
  C3=1;

  return keyno;
}

void keyaction(char key)	//PERFORM action according to key pressed
{
  if(keyno=='n')
  flag=1;

  	else if(flag==1)
  	{
  		flag=0;

		if(i<5)						   //since our password length is 5, so 5 baar loop chalaya taaki 5 key press lele
		{
			lcd_data(key);	 //Send keypressed to data
			input[i]=key;	 //String mei key store key
			i++;
			input[i]='\0';	 //string mei key aane ke baad last element should be null
		}
 	 }
}

void passcheck(char check)
{  if(check=='*')			  //agar * key press key tabhi ye function chalga, i.e. it acts as enter
	{
	char pass[] = {"18793"};   //our password

	char access[] = {"ACCESS GRANTED"};	
	char denied[] = {"ACCESS DENIED"};
	 int result;
	 result = strcmp(pass, input);	  //compare two strings

	 if(result==0)					   //agar strings are same
	 {
	 	lcd_command(0x01);
		lcd_command(0x0c);
	 	lcd_string(&access[0]);			 //access granted ko data line par bhejne ke lie
	}		
	else
	{
	 lcd_command(0x01);
	 lcd_command(0x0c);
	 lcd_string(&denied[0]);
	 
	}
	}
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
