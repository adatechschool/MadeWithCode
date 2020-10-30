#include <Adafruit_CircuitPlayground.h>
void led() {
 /* for(int i=0;i<3;i++)
  {
    CircuitPlayground.playTone(500, 100);
    CircuitPlayground.setPixelColor(0, 255,   255,   255);
    CircuitPlayground.setPixelColor(2, 255,   255,   255);
    CircuitPlayground.setPixelColor(4, 255,   255,   255);
    CircuitPlayground.setPixelColor(6, 255,   255,   255);
    CircuitPlayground.setPixelColor(8, 255,   255,   255);
    delay(1000);
  }
*/

  Serial.print("je suis dans led");
  Serial.println();
  
    CircuitPlayground.setPixelColor(0, 255,   255,   255);
    delay(500);
    CircuitPlayground.setPixelColor(1, 255,   0,   0);
    delay(500);
    CircuitPlayground.setPixelColor(2, 0,   random(125, 255),   random(0, 125));
    delay(500);
    CircuitPlayground.setPixelColor(3, random(0, 255),   random(0, 255),   random(0, 255));
    delay(500);
    CircuitPlayground.setPixelColor(4, random(0, 255),   random(0, 255),   random(0, 255));
    delay(500);
    CircuitPlayground.setPixelColor(5, random(0, 255),   random(0, 255),   random(0, 255));
    delay(500);
    CircuitPlayground.setPixelColor(6, random(0, 255),   random(0, 255),   random(0, 255));
    delay(500);
    CircuitPlayground.setPixelColor(7, random(0, 255),   random(0, 255),   random(0, 255));
    delay(500);
    CircuitPlayground.setPixelColor(8, random(0, 255),   random(0, 255),   random(0, 255));
    delay(500);
    CircuitPlayground.setPixelColor(9, random(0, 255),   random(0, 255),   random(0, 255));
    delay(500);
    CircuitPlayground.clearPixels();
    CircuitPlayground.playTone(500, 100);

   Serial.print("je suis à la fin de led");
  Serial.println();
  }
bool leftButtonPressed;
bool rightButtonPressed;
bool timerLance = false;
long interval = 15000; 
long previousMillis = 0;

void setup() {
  // put your setup code here, to run once
  Serial.begin(9600);  
  CircuitPlayground.begin();
}

void loop() {
    unsigned long currentMillis = millis();   
     
    if(currentMillis - previousMillis > interval && timerLance == true) {
       led(); 
       timerLance = false ; 
       interval = interval + 1000;
    }

   leftButtonPressed = CircuitPlayground.leftButton();
   rightButtonPressed = CircuitPlayground.rightButton();
   
 if (leftButtonPressed) {
      
   // lancer timer
   Serial.print("Je lance un timer");
     Serial.println();

      previousMillis = currentMillis ; 
      timerLance = true ;
      delay(1000);
      interval = interval - 1000;
      Serial.print(interval, DEC);
      Serial.print("Interval");
      Serial.println();
   }  

   if (rightButtonPressed){
      Serial.print("le timer s'arrete");
      Serial.println();
      timerLance = false;
      delay(1000);
     } 
   
}
