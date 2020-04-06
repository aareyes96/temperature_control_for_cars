
/*////////////////////////////////////////
//   #define To -> 298.15?K            //
//   #define Ro -> R nominal del ntc     //
//   #define B  -> Constante del metal   //
//   #define serialR -> R en serie      //
////////////////////////////////////////*/   

#include <math.h>

   float getTempCelsius(void)
   {
      //Variables
      float Vx    =0;
      float Rx    =0;
      float temp  =0;  
      float y     =0;
      //Leer y calcular caida de voltaje
      Vx = read_adc();
      Vx = Vx*(5.00/1024.00) ;
      
      //Calcular resistencia del ntc
      Rx = ( Vx * serialR ) / ( 5.00 - Vx ) ; 
      
      //formula para calcular temp con NTC
      y = log(Rx/Ro);
      y = (1.00/To) + (y *(1.00/B));
      temp = 1.00/y;
      
      //De kelvins a Celcius
      temp = temp - 273.15;
      
      return temp;
   }
   
