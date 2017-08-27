/* ==============================================================================
 *	Title:
 *		TEST lED 7 DOAN VOI IC 74HC595 DEM TU 0 DEN 9
 *
 *	Description:
 *		SER   <------------------------>  PD3
 *		SRCLK <------------------------>  PD4
 *		RCLK  <------------------------>  PD5
 *
 *  Created on: 
 * 		8/1/2015
 *
 *  Author: 
 *		Vnelektronics Co.Ltd 
 *		Website: http:://vnelek.vn
 *    	Email: support@vnelek.vn
 *    	776 Ton Duc Thang, Lien Chieu, Da Nang
 *
 * 	Compiler:
 * 			Atmel Studio 6.2 version 
 * ==============================================================================*/

#include <avr/io.h>				
#include <util/delay.h>
#include <avr/interrupt.h>
 
unsigned int counter=0;

#include "LM74HC595.h"
#include "LED7SEG.h"

int main( void )
{ 
  unsigned int num=0;
  //Khoi tao IC 74HC595 va led 7 doan
  Setup_74595();
  Setup_7SegLED();
  
  sei();                               // Khoi tao ngat toan cuc
  while(1)
  {
	  led7seg_Display(num++);    
	  if(num>9)
	  num=0;
	  _delay_ms(10);
  }
}
