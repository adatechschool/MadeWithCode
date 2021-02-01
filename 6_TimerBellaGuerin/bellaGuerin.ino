#include <Adafruit_CircuitPlayground.h>
bool leftButtonPressed;
bool rightButtonPressed;

void setup() {
  // put your setup code here, to run once
  Serial.begin(9600);  
  CircuitPlayground.begin();
}

void loop() {

   leftButtonPressed = CircuitPlayground.leftButton();
   rightButtonPressed = CircuitPlayground.rightButton();

  CircuitPlayground.clearPixels();

  int compteur  = 0 ;
  int decalage = 1 ;

  int nbCycles = 0 ; 


  bool needToStop = false ; 
   
  do{
    leftButtonPressed = CircuitPlayground.leftButton();
    CircuitPlayground.setPixelColor(compteur, 255,   0,   255);
    delay(1000);

    compteur = compteur + decalage ; 
  
      if (compteur > 9)
      {
        CircuitPlayground.clearPixels();
        decalage = -1 ;    
        nbCycles = nbCycles + 1 ;   
      }
      if (compteur <0)
      {
        CircuitPlayground.clearPixels();
        decalage = 1 ; 
        nbCycles = nbCycles + 1 ;   
      }

    if (leftButtonPressed == true)
    {
      needToStop = true ;
    }
    if( nbCycles > 60)
    {
      needToStop = true ;      
    }
    
    } while (needToStop == false);
  
  CircuitPlayground.setPixelColor(0, 0, 255,   0);
  CircuitPlayground.setPixelColor(1, 0, 255,   0);
  CircuitPlayground.setPixelColor(2, 0, 255,   0);
  CircuitPlayground.setPixelColor(3, 0, 255,   0);
  CircuitPlayground.setPixelColor(4, 0, 255,   0);
  CircuitPlayground.setPixelColor(5, 0, 255,   0);
  CircuitPlayground.setPixelColor(6, 0, 255,   0);
  CircuitPlayground.setPixelColor(7, 0, 255,   0);
  
      
/*  delay(1000);
  CircuitPlayground.setPixelColor(1, 128, 128,   0);
  delay(500);
  CircuitPlayground.setPixelColor(2,   0, 255,   0);
  delay(500);
  CircuitPlayground.setPixelColor(3,   0, 128, 128);
  delay(500);
  CircuitPlayground.setPixelColor(4,   0,   0, 255);
  delay(500);
  CircuitPlayground.setPixelColor(5, 0xFF0000);
  delay(500);
  CircuitPlayground.setPixelColor(6, 0x808000);
  delay(500);
  CircuitPlayground.setPixelColor(7, 0x00FF00);
  delay(500);
  CircuitPlayground.setPixelColor(8, 0x008080);
  delay(500);
  CircuitPlayground.setPixelColor(9, 0x0000FF);
// fin des 5 secondes
*/


   
}
