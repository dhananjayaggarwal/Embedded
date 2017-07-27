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

int keycheck();	//It returns a character which is send to lcd data

unsigned char  keych;	 //because character need to be shown
void lcd_init();
void lcd_data(unsigned char dat);
void lcd_command(unsigned char comd);
void delay(int);
void lcd_string(unsigned char *s);
void keyaction(int);
  unsigned int keyno, key, flag=1;
void num_of_press(int);	
//int counter(int);
int prev=100, count=0, count1=0;
void print_it(int key);
void key1();
void key2();
void key3();
void key4();
void key5();
void key6();
void key7();
void key8();
void key9();
void key10();
void key11();
void key12();



void main()
{

lcd_init();


while(1){

	key=keycheck();			 //Call to return which key was pressed
	keyaction(key);

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

int keycheck()
{
	flag=1;
  C1=1;
  C2=1;
  C3=1;
   keyno=100;
  C1=0;
   if(R1==0)
  {
  	keyno=1;
	delay(10000);
    
  }
   if(R2==0)
  {
    keyno=4;
  }
	if(R3==0)
	{
		keyno=7;
	}
   if(R4==0)
   {
   	keyno=10;
   }

  C1=1;
  C2=0;
    if(R1==0)
  {
    keyno=2;
	delay(10000);

  }
  if(R2==0)
  {
    keyno=5;
   }

   	if(R3==0)
	{
		keyno=8;
	}
   if(R4==0)
   {
   	keyno=11;
   }
  C2=1;
  C3=0;
  if(R1==0)
  {
    keyno=3;
  }
  if(R2==0)
  {
    keyno=6;
	} 
  if(R3==0)
  {
   keyno=9;
  } 
  	
   if(R4==0)
   {
   	keyno=12;
   }
  C3=1;

  return keyno;
}

void keyaction(int key)
{

	
	if(key==100){
		flag=1;	 }
	else if(flag==1)
	{
		flag=0;
		num_of_press(key);
	}	
}


void num_of_press(int key)
{
	if(key!=100){
	if(prev==key)
	{
		 count++;
		 lcd_command(0x10);
		 print_it(key);
	}
	 else if(prev!=key)
	 {
	 	count=0;
		print_it(key);
		prev=key;
	 }
}
}

void print_it(int key)
{
	switch(key)
	{
		case 1: key1();
				break;
		case 2: key2();
				break;
		case 3: key3();
				break;
		case 4: key4();
				break;
		case 5: key5();
				break;
		case 6: key6();
				break;
		case 7: key7();
				break;
		case 8: key8();
				break;
		case 9: key9();
				break;
		case 10: key10();
				break;
		case 11: key11();
				break;
		case 12: key12();
				break;																																					
	default: return;
	
	}
}
void key1()
{
	if(count==0)
	lcd_data('1');
	 
}

void key2()
{
	count1=count%4;
	if(count1==0)
	lcd_data('A');
	else if(count1==1)
	lcd_data('B');
	else if(count1==2)
	lcd_data('C');
	else if(count1==3)
	lcd_data('2'); 
	
	 
}
 
void key3()
{
	count1=count%4;
	if(count1==0)
	lcd_data('D');
	else if(count1==1)
	lcd_data('E');
	else if(count1==2)
	lcd_data('F');
	else if(count1==3)
	lcd_data('3'); 
	
	 
}

void key4()
{
	count1=count%4;
	if(count1==0)
	lcd_data('G');
	else if(count1==1)
	lcd_data('H');
	else if(count1==2)
	lcd_data('I');
	else if(count1==3)
	lcd_data('4'); 
	
	 
}

void key5()
{
	count1=count%4;
	if(count1==0)
	lcd_data('J');
	else if(count1==1)
	lcd_data('K');
	else if(count1==2)
	lcd_data('L');
	else if(count1==3)
	lcd_data('5'); 
	
	 
}

void key6()
{
	count1=count%4;
	if(count1==0)
	lcd_data('M');
	else if(count1==1)
	lcd_data('N');
	else if(count1==2)
	lcd_data('O');
	else if(count1==3)
	lcd_data('6'); 
	
	 
}

void key7()
{
	count1=count%5;
	if(count1==0)
	lcd_data('P');
	else if(count1==1)
	lcd_data('Q');
	else if(count1==2)
	lcd_data('R');
	else if(count1==3)
	lcd_data('S');
	else if(count1==5)
	lcd_data('7'); 
	
	 
}

void key8()
{
	count1=count%4;
	if(count1==0)
	lcd_data('T');
	else if(count1==1)
	lcd_data('U');
	else if(count1==2)
	lcd_data('V');
	else if(count1==3)
	lcd_data('8'); 
	
}

void key9()
{
	count1=count%5;
	if(count1==0)
	lcd_data('W');
	else if(count1==1)
	lcd_data('X');
	else if(count1==2)
	lcd_data('Y');
	else if(count1==3)
	lcd_data('Z');
	else if(count1==5)
	lcd_data('9'); 
}

void key10()
{

	if(count==0);
	lcd_data('*');
}

void key11()
{
	if(count==0)
	lcd_data(' ');
	else if(count==1)
	lcd_data('0');
}
void key12()
{
	
		
}