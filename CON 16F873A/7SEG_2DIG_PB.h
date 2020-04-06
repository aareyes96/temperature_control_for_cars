/*////////////////////////////
//							//
// 7-Segmento de 2 digitos	//
// por el puerto B 			//
// *-> pin es el punto 		//
// decimal. hay que ponerlo	//
// aparte de esta biblioteca//
//							//
// DECLARAR:				//
// int digits[10];			//
// int pin = 0;				//
// #define SEG PIN_X#		//
// #define ERROR flag#		//
////////////////////////////*/

void seg_init(void)
	{	  	
	  
	  digits[0] = 0b00111111;
      digits[1] = 0b00000110;
      digits[2] = 0b01011011;
      digits[3] = 0b01001111;
      digits[4] = 0b01100110;
      digits[5] = 0b01101101;
      digits[6] = 0b01111101;
      digits[7] = 0b00000111;
      digits[8] = 0b01111111;
      digits[9] = 0b01100111;
	}
void show( int num ){
    
     if ( num < 10 )
     {
         output_b( 0 | pin );
         output_low( SEG );
         output_b( digits [ num ] | pin );
         delay_ms( 10 );
         output_b( 0 | pin );
         output_high( SEG );;
         output_b( digits [ 0 ] | pin );
         delay_ms( 10 );
      }
	  
     if ( num >= 10 && num <= 99 )
     {
         output_b( 0 | pin );
         output_low( SEG );
         output_b( digits [ num%10 ] | pin );
         delay_ms( 10 );
         output_b( 0 | pin);
         output_high( SEG );
         output_b( digits [ num/10 ] | pin );
         delay_ms( 10 );
      }
	  
	  if ( num > 99 )
	 {
		 output_b( 0 | pin );
         output_low( SEG );
         output_b( 0b01000000 | pin );
         delay_ms( 10 );
         output_b( 0 | pin);
         output_high( SEG );
         output_b( 0b01000000 | pin );
         delay_ms( 10 );
	 }
	 
	 if ( ERROR )
	 {
		 output_b( 0 | pin );
         output_low( SEG );
         output_b( 0b01000000 | pin );
         delay_ms( 200 );
         output_b( 0 | pin);
         output_high( SEG );
         output_b( 0b01000000 | pin );
         delay_ms( 200 );
	 }
}