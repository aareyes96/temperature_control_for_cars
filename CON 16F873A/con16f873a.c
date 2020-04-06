#include <16F873A.h>
#device ADC=10

#FUSES NOWDT                    //No Watch Dog Timer
#FUSES NOBROWNOUT               //No brownout reset
#FUSES NOLVP                    //No low voltage prgming, B3(PIC16) or B5(PIC18) used for I/O

#use delay(crystal=8MHz)
#use FIXED_IO( B_outputs=PIN_B7,PIN_B6,PIN_B5,PIN_B4,PIN_B3,PIN_B2,PIN_B1,PIN_B0 )
#use FIXED_IO( C_outputs=PIN_C1,PIN_C0 )
#use rs232(baud=9600,parity=N,xmit=PIN_C6,rcv=PIN_C7,bits=8,stream=PORT1)

#include <math.h>

////////////////////////////////
#define To        298.15      //
#define Ro        15000.00    //
#define B         4500.0      //
#define serialR   5000.00     //
                              //
#include "NTC.h"              //
////////////////////////////////

////////////////////////////////
int pin = 0;                  //
int digits[10];               //
int1 flag=0;                  //
                              //
#define SEG PIN_C0            //
#define ERROR flag            //
                              //
#include "7SEG_2DIG_PB.h"     //
////////////////////////////////

int a=0;

//#define T_MAX 90
//#define T_MIN 70

#INT_TIMER1
void  TIMER1_isr(void) 
{
   SET_ADC_CHANNEL(0);
   delay_us(50);
   a = (int8)(getTempCelsius());
   
   //if( a >= T_MAX ) output_high(PIN_C1);
   //if( a <= T_MIN ) output_low (PIN_C1);
   
   if( a > 99 || a <= 0 ) 
      {
         flag = 1;
         //output_high(PIN_C1);
      }
   else flag=0;
}

void main()
{
   setup_adc_ports(AN0_AN1_AN3);
   setup_adc(ADC_CLOCK_INTERNAL);
   setup_timer_1(T1_INTERNAL|T1_DIV_BY_8);      //262 ms overflow

   
   
   enable_interrupts(INT_TIMER1);
   enable_interrupts(GLOBAL);
   
   seg_init();
   
   while(TRUE)
   {
      show(a);
   }

}


