#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define OLED_RESET     4 // Reset pin # (or -1 if sharing Arduino reset pin)
Adafruit_SSD1306 display(128, 64, &Wire, 4);

#define anzSensoren 4
byte pinSensor[anzSensoren]={11,12,9,10};

bool pinStatus[anzSensoren];
bool lastPinStatus[anzSensoren];
byte offset;


void setup() {
  Serial.begin(9600);
  
  // SSD1306_SWITCHCAPVCC = generate display voltage from 3.3V internally
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("SSD1306 allocation failed"));
    for(;;); // Don't proceed, loop forever
  }
  display.clearDisplay();
  display.drawLine(32, 31, 96, 31, SSD1306_WHITE);
  display.display();
  
  
  for (byte i=0; i<anzSensoren; i++){
    pinMode(pinSensor[i], INPUT_PULLUP);
  pinStatus[i]=!digitalRead(pinSensor[i]);
  }
}

void loop() {
  //------Auslesen Sensoren-------
  for (byte i=0; i<anzSensoren; i++){
  lastPinStatus[i]=pinStatus[i];
  pinStatus[i]=!digitalRead(pinSensor[i]);
  }
  //------Ausgabe Sensoren--------
  left(pinStatus[0]||pinStatus[2]);
  right(pinStatus[1]||pinStatus[3]);
  display.display();
  
  /*
  Serial.print("last");
  Serial.print(lastPinStatus[2]);
  Serial.println(lastPinStatus[3]);
  Serial.print(" new");
  Serial.print(pinStatus[2]);
  Serial.println(pinStatus[3]);
  */
  //------Auswertung Sensoren------
  for(byte j=0; j<anzSensoren;j+=2){
      if(pinStatus[j]!=lastPinStatus[j]||pinStatus[j+1]!=lastPinStatus[j+1]){
      //veränderung von alt zu neu 
      if(pinStatus[j]!=lastPinStatus[j] & pinStatus[j+1]!=lastPinStatus[j+1]){ 
        Serial.println("Error");
      }else{
        //nur einer der beiden Werte hat sich verändert
  
        if(!lastPinStatus[j] & !lastPinStatus[j+1]){
          Serial.print("Auto Fährt in den Sensor: ");
          Serial.print((j/2));
          Serial.print(" : ");
          if(pinStatus[j]){
            Serial.println("links");
          }else{
            Serial.println("rechts");
          }
        }else if(!pinStatus[j]&!pinStatus[j+1]){
          Serial.print("Auto Fährt aus dem Sensor: ");
          Serial.print((j/2));
          Serial.print(" : ");
          if(lastPinStatus[j]){
            Serial.println("links");
          }else{
            Serial.println("rechts");
          }
        }else{
          Serial.println("Auto bleibt im Sensor");
        }
      }
    }else{
      //Serial.println("absolut nix");
    }
  }
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
