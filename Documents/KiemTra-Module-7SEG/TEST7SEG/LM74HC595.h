#ifndef LM74HC595_H_
#define LM74HC595_H_
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



#define   BYTENUM   2
#define BIT0                (0x0001u)
#define BIT1                (0x0002u)
#define BIT2                (0x0004u)
#define BIT3                (0x0008u)
#define BIT4                (0x0010u)
#define BIT5                (0x0020u)
#define BIT6                (0x0040u)
#define BIT7                (0x0080u)
#define BIT8                (0x0100u)
#define BIT9                (0x0200u)
#define BITA                (0x0400u)
#define BITB                (0x0800u)
#define BITC                (0x1000u)
#define BITD                (0x2000u)
#define BITE                (0x4000u)
#define BITF                (0x8000u)

int LM74HC595_buffer1;
//--------------------------------------------------------------------------------------------
// Chuyen Bit sang vi tri
//--------------------------------------------------------------------------------------------

char bit2position( int bit_const )
{
   switch( bit_const )
   {
      case BIT0:  return 0;
      case BIT1:  return 1;
      case BIT2:  return 2;
      case BIT3:  return 3;
      case BIT4:  return 4;
      case BIT5:  return 5;
      case BIT6:  return 6;
      case BIT7:  return 7;
      case BIT8:  return 8;
      case BIT9:  return 9;
      case BITA:  return 10;
      case BITB:  return 11;
      case BITC:  return 12;
      case BITD:  return 13;
      case BITE:  return 14;
      case BITF:  return 15;
      default:    return 0;
   }
}
//--------------------------------------------------------------------------------------------
// Truyen du lieu 8 bit den IC 74595
//--------------------------------------------------------------------------------------------
void Send_74595( unsigned int buffer)
{
  int i, data;
  
  data=buffer;
  
  //Dich tung bit trong bien "data" ra thanh ghi dich
  for( i = 0; i < BYTENUM*8; i++ )
  {
    if(data & BIT0)
      PORTD |= _BV(PD3);
    else
      PORTD &=~ _BV(PD3);
    
    data >>= 1;
    
    PORTD &= ~_BV(PD4);
    PORTD |= _BV(PD4);
  }
  //Xuat du lieu duoc dich ra cong xuat
  PORTD &= ~_BV(PD5);
  PORTD |= _BV(PD5);
}
//--------------------------------------------------------------------------------------------
// Truyen 4 bit den IC 74595
//--------------------------------------------------------------------------------------------
void Send4bit_74595( int bit_const, int data_4bit )
{
   char position;
   int temp = 0x000F;
   
   position = bit2position( bit_const );
   data_4bit <<= position;
   temp <<= position;
   LM74HC595_buffer1 = LM74HC595_buffer1 & (~temp);     // Xoa 4 bit bat dau tu vi tri dat
   LM74HC595_buffer1 = LM74HC595_buffer1 | data_4bit;   // Ghep gia tri trong data4 vao 4 bit cao vua xoa
   
   Send_74595(LM74HC595_buffer1);
}
//--------------------------------------------------------------------------------------------
// Truyen 8 bit den IC 74595
//--------------------------------------------------------------------------------------------
void Send8bit_74595( int bit_const, int data_8bit )
{
   char position;
   int temp = 0x00FF;
   
   position = bit2position( bit_const );
   data_8bit <<= position;
   temp <<= position;
   LM74HC595_buffer1 = LM74HC595_buffer1 & (~temp);     // Xoa 8 bit bat dau tu vi tri dat
   LM74HC595_buffer1 = LM74HC595_buffer1 | data_8bit;   // Ghep gia tri trong data8 vao 8 bit cao vua xoa
   
   Send_74595(LM74HC595_buffer1);
}
//--------------------------------------------------------------------------------------------
//-------Khoi tao IC 74595-----------//
//--------------------------------------------------------------------------------------------
void Setup_74595( void )
{
  DDRD |= _BV(DDD3)| _BV(DDD4)| _BV(DDD5);
  LM74HC595_buffer1 = 0X00FF;
  Send_74595(LM74HC595_buffer1);
}

#endif /* LM74HC595_H_ */