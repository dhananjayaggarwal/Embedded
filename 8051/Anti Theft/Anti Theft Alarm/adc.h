#ifndef __ADC_H__
#define __ADC_H__

#define adcport P1 //pin 1-17, 2-14,3-15,4-8,5-18,6-19,7-20,8-21

sbit ale = P3^4;  //14,6/22
sbit eoc = P3^5;  //15,7
sbit add_a = P3^6; //16,25
sbit add_b = P3^7;	//17,24

unsigned int adcvalue;
void check_ir(void);
unsigned int adc_read()
{
	
	
	add_a=0;
	add_b=0;
	delay(100);
	check_ir();
	ale=1;
	delay(1000);
	ale=0;
	check_ir();
	delay(1000);
	check_ir();
	eoc=0;
		delay(10);
		while(eoc==1);
	
	
	  
	adcvalue=adcport;
	return(adcvalue);
}


#endif