#ifndef __UART_H__
#define __UART_H__

void uart_init()
{
  TMOD=0X20;
  TH1=0XFD;
  SCON=0X50;
  TR1=1;
}



#endif