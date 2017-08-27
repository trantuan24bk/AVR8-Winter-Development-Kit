/* ==============================================================================
 *	Title:
 *		SEG7.H
 *      THU VIEN DIEU KHIEN LM74HC595
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
const unsigned char led7_CODE[10] = {0x03, 0x9F, 0x25, 0x0D, 0x99, 0x49, 0x41, 0x1F, 0x01, 0x09};
unsigned char led7_Index = 0;
unsigned char led7_Digit[4];

////////////////////////////////////////////////////////////////////////////////
//
void led7seg_Display(int num)
{
	led7_Digit[3] = (num / 1000);
	led7_Digit[2] = (num / 100) % 10;
	led7_Digit[1] = (num / 10) % 10;
	led7_Digit[0] = (num % 10);
}

void Setup_7SegLED(void)
{
  TCCR0 =(1<<CS00);                    //Chon xung clock noi cho Timer  
  TIMSK = 1<<TOIE0;
}

// Timer/Counter0 interrupt service routine
ISR(TIMER0_OVF_vect)
{
	Send8bit_74595( BIT8, 0xFF );
	switch( led7_Index )
	{
		case 0:
		Send4bit_74595( BIT4, 0x0E );
		Send8bit_74595( BIT8, led7_CODE[led7_Digit[0]] );
		led7_Index++;
		break;
		case 1:
		Send4bit_74595( BIT4, 0x0D );
		Send8bit_74595( BIT8, led7_CODE[led7_Digit[1]] );
		led7_Index++;
		break;
		case 2:
		Send4bit_74595( BIT4, 0x0B );
		Send8bit_74595( BIT8, led7_CODE[led7_Digit[2] ]);
		led7_Index++;
		break;
		case 3:
		Send4bit_74595( BIT4, 0x07 );
		Send8bit_74595( BIT8, led7_CODE[led7_Digit[3]]);
		led7_Index=0;
		break;
		default:
		break;
	}
}