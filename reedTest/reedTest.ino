#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define OLED_RESET     4 // Reset pin # (or -1 if sharing Arduino reset pin)
Adafruit_SSD1306 display(128, 64, &Wire, 4);

#define cSensors 2 //anzahl der sensoren und anzahl der in myPinPorts hinterlegten pins müssen übereinstimmen
int myPinPorts[]={11, 12}; //müssen immer in 2er Paaren vorkommen (wert 0 und 1 oder wert 2 und 3 bilden je ein paar
bool myPinStatus[cSensors];
bool myLastPinStatus[cSensors]={false,false}; // ={false,false}ist unnötig, kann weg
int offset;


void setup() {

   Serial.begin(9600);

  // SSD1306_SWITCHCAPVCC = generate display voltage from 3.3V internally
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("SSD1306 allocation failed"));
    for(;;); // Don't proceed, loop forever
  }
  display.clearDisplay();
  
  display.display();
  
  //-----Init-Sensoren----
  /*
  for (int i=0; i<cSensors; i++){
    pinMode(myPinPorts[i], INPUT_PULLUP);
  }
  */
  pinMode(11, INPUT_PULLUP);
  pinMode(12, INPUT_PULLUP);
  
  display.drawLine(32, 31, 96, 31, SSD1306_WHITE);
  display.display();
  

  
}

void loop() {

  left(!digitalRead(12));
  right(!digitalRead(11));
  display.display();
  

  /*
  for (int i=0; i<cSensors;i++){
    myPinStatus[i]=!digitalRead(myPinPorts[i]); //liest ports aus und speichert sie in einem Array (gegen Fehleranfälligkeit)
     Serial.print(myPinStatus[i]);
     Serial.print("<--");
     Serial.println(+myLastPinStatus[i]);
  } 
  */
  if(digitalRead(11)==true){
    Serial.print("y");
  }
  myPinStatus[0]=!digitalRead(11);
  Serial.print(digitalRead(11));
  Serial.print(myPinStatus[0]);
  myPinStatus[1]=!digitalRead(12);
  Serial.print(digitalRead(12));
  Serial.println(myPinStatus[1]);
  
  /*
  for(int i=0; i<cSensors;i++){
    Serial.println("d");
    if(myPinStatus[i]==!myLastPinStatus[i]){ //soll nur inputs bearbeiten bei denen Sich etwas verändert hat.
      Serial.println("x");
      //-------Zustandsänderung auswerten------------
      if(i%2==1){ //da sensoren gepaart vorkommen müssen sie in 2er paaren ausgelesen werden.
        offset=-1; //zum ermitteln des Vorherigen
        i++; //der Folgende wert wird in dieser Schleife mitbearbeitet und kann übersprungen werden.
      }else{
        offset=1; //zum ermitteln des Folgenden Wertes
      }

      if(myPinStatus[i]=true){
        if (myPinStatus[i+offset]=false){
          if(i%2==0){
            Serial.print("Entering right");
          }else{
            Serial.print("Entering left"); 
          }
        }
      }else{
        if (myPinStatus[i+offset]=false){
          if(i%2==0){
            Serial.print("Leaving right");
          }else{
            Serial.print("Leaving left"); 
          }
        }
      }
      
    }
  }
  */
  /*
  left(myPinStatus[1]);
  right(myPinStatus[0]);
  */
  /*
    for  (int j=0; j<cSensors; j++){
    Serial.print("Boop");
    Serial.println(myPinStatus[j]);
    myLastPinStatus[j]=myPinStatus[j];
  }//der wert von myPinStatus[j] scheint hier immer 0 zu sein
 */
  
    
    myLastPinStatus[0]=myPinStatus[0];
    myLastPinStatus[1]=myPinStatus[1];
  
}


void left(boolean an){
  
  if (an==true){
    display.drawLine(32,31,32+10,31+10,SSD1306_WHITE);
    display.drawLine(32,31,32+10,31-10,SSD1306_WHITE);
  }else{
    display.drawLine(32,31,32+10,31+10,SSD1306_BLACK);
    display.drawLine(32,31,32+10,31-10,SSD1306_BLACK);  
  }
}

void right(boolean an){
  if (an==true){
    display.drawLine(96,31,96-10,31+10,SSD1306_WHITE);
    display.drawLine(96,31,96-10,31-10,SSD1306_WHITE);
  }else{
    display.drawLine(96,31,96-10,31+10,SSD1306_BLACK);
    display.drawLine(96,31,96-10,31-10,SSD1306_BLACK);
  }
}




void testdrawrect(void) {
  display.clearDisplay();

  for(int16_t i=0; i<display.height()/2; i+=2) {
    display.drawRect(i, i, display.width()-2*i, display.height()-2*i, SSD1306_WHITE);
    display.display(); // Update screen with each newly-drawn rectangle
    delay(1);
  }
}
  
