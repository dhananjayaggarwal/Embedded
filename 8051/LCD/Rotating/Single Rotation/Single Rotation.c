#include <REGX51.H>

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
void lcd_init();
void lcd_data(unsigned char dat);
void lcd_command(unsigned char comd);
void delay(int);
void lcd_string(unsigned char *s);
void keyaction(char key);

const unsigned char text[]={"ECE"};
const unsigned char textm[]={"Electronics"}; 
void main()
{

 unsigned char i,j,k, loc2=0xc0, loc1=0x80;
                                    
 lcd_init();
 while(1){                          
 for(i=0;text[i]!='\0';i++)
 {  
         lcd_command(loc1);

		  loc1++;
 		lcd_data(text[i]);              
	 
   }
   for(i=0;i<40;i++)
   {
   lcd_command(loc2+i);
  for(j=0;textm[j]!='\0';j++)
  {
  		
		  lcd_data(textm[j]);
		
  }
  lcd_command(0x01);
  for(k=0;text[k]!='\0';k++)
 {  
       
 		lcd_data(text[k]);              
	 
   }
 }
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

/*char keycheck()
{
  C1=1;
  C2=1;
  C3=1;
   keyno='n';
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

void keyaction(char key)
{
  if(keyno=='n')
  flag=1;

  	else if(flag==1)
  	{
  		flag=0;

		lcd_command(0x01);
		lcd_data(key);	 //Send keypressed to data


 	 }
}

  */ 

