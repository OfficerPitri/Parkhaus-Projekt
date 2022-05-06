#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define OLED_RESET     4 // Reset pin # (or -1 if sharing Arduino reset pin)
Adafruit_SSD1306 display(128, 64, &Wire, 4);

#define anzSensoren 2
byte pinSensor[anzSensoren]={11,12};

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
  
  pinMode(11, INPUT_PULLUP);
  pinMode(12, INPUT_PULLUP);

  
  for (byte i=0; i<anzSensoren; i++){
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
  left(pinStatus[0]);
  right(pinStatus[1]);
  display.display();
  
  /*
  Serial.print("last");
  Serial.print(lastPinStatus[0]);
  Serial.println(lastPinStatus[1]);
  Serial.print(" new");
  Serial.print(pinStatus[0]);
  Serial.println(pinStatus[1]);
  */
  //------Auswertung Sensoren------

      if(pinStatus[0]!=lastPinStatus[0]||pinStatus[1]!=lastPinStatus[1]){
      //veränderung von alt zu neu 
      if(pinStatus[0]!=lastPinStatus[0] & pinStatus[1]!=lastPinStatus[1]){ 
        Serial.println("Error");
      }else{
        //nur einer der beiden Werte hat sich verändert
  
        if(!lastPinStatus[0] & !lastPinStatus[1]){
          Serial.print("Auto Fährt in den Sensor: ");
          if(pinStatus[0]){
            Serial.println("links");
          }else{
            Serial.println("rechts");
          }
        }else if(!pinStatus[0]&!pinStatus[1]){
          Serial.print("Auto Fährt aus dem Sensor: ");
          if(lastPinStatus[0]){
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
