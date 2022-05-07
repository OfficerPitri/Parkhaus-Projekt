//----libaries----
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

//----Display(s)-anlegen--
#define OLED_RESET     4 // Reset pin # (or -1 if sharing Arduino reset pin)
Adafruit_SSD1306 display(128, 64, &Wire, 4); //display anlegen


//-----------Straßen-Schienen-Layout-Einstellungen-------------

#define anzRichtungssensoren 2 
const byte richtungsSensor [anzRichtungssensoren] [4]={ //rechtungssensoren werden als zwei reedSensoren mit anliegenden Straßen angelegt
  {11, 09},    //PIN 0 (Reedsensor)
  {12, 10},    //PIN 1 (Reedsensor)
  {00, 01},    //StraßenId vor PIN 0 (für später implementierte Straßenlogik)
  {01, 02},    //StraßenId nach PIN 1 --> Straßen sollen später Speichern, welche Autos(AutoID) in welcher reihung auf einer Straße stehen
}//Beispiel --> Straße00 -- <RichtungsSensor0> -- Straße01 -- <RichtungsSensor1> -- Straße02
//aussagen über positionswechsel von Autos können getroffen werden
//an einem Straßenabschnitt können mehrere Sensoren mit verknüpften Straßen hängen, Jeder Sensor hat AUSSCHLIEßLICH 2 anliegende Straßen

//----laufzeitspeicher----
bool pinStatus[anzRichtungssensoren*2]; //aktuelle Zustände der ReedSensoren
bool lastPinStatus[anzRichtungssensoren*2];//vorherige Zustände der ReedSensoren



void setup() {
  Serial.begin(9600); //Starten eines Kommunikationsprotokolls
  //------------Display-überprüfen------------
  
  // SSD1306_SWITCHCAPVCC = generate display voltage from 3.3V internally
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("SSD1306 allocation failed"));
    for(;;); // Don't proceed, loop forever
  }

  //----------Display-in-Ausgangslage---------
  display.clearDisplay();
  display.drawLine(32, 31, 96, 31, SSD1306_WHITE);
  display.display();  
  
  //einmaliges auslesen aller Zeilen um die Funktionsweise des Folgenden Codes zu garantieren
  //Anfangszustände, bei denen Autos auf der Strecke sind stellen ein Problem dar (nicht track bar)
  for (byte i=0; i<anzRichtungssensoren*2; i+=2){
    pinMode(richtungsSensor[i][0], INPUT_PULLUP);
  pinStatus[i]=!digitalRead(richtungsSensor[i][0]); //werte werden zur besseren verarbeitbarkeit in ein array gespeichert
  pinMode(richtungsSensor[i][1], INPUT_PULLUP);     //(so können sich die zustände während einem Durchlauf nicht veränden)
  pinStatus[i+1]=!digitalRead(richtungsSensor[i][1]); 
  }                                        
}//ende Setup

void loop() {//main Programm
  //------Auslesen Sensoren-------
  for (byte i=0; i<anzRichtungssensoren*2; i+=2){
  lastPinStatus[i]=pinStatus[i];
  pinStatus[i]=!digitalRead(richtungsSensor[i][0]);
  lastPinStatus[i+1]=pinStatus[i+1];
  pinStatus[i+1]=!digitalRead(richtungsSensor[i][1]);
  }
  
  //------Auswertung Sensoren------
  //vergleicht den aktuellen und vorherigen Zustand aller sensoren
  //tiefere überprüfung, nur wenn sich etwas verändert hat
  //haben sich beide sensoren gleichzeitig verändert liegt ein fehler vor. (z.B. Auto zu schnell/auslesen zu langsam, auto hineingesetzt oder herausgehoben)
  //sind beide Pins aus und es hat sich etwas verändert, verlässt das Auto den Sensor
  //waren vorher beide Pins aus, und einer hat sich verändert, betritt das auto den sensor
  //hat sich etwas verändert und keins der vorher genannten szenarien tritt ein, so bewegt sich das Auto im sensor
  //(Sensoren werden so verbaut dass an beiden pins gleichzeitig ein Signal anliegen kann)
  
  for(byte j=0; j<anzRichtungssensoren*2;j+=2){
      if(pinStatus[j]!=lastPinStatus[j]||pinStatus[j+1]!=lastPinStatus[j+1]){
      //veränderung von alt zu neu 
      if(pinStatus[j]!=lastPinStatus[j] & pinStatus[j+1]!=lastPinStatus[j+1]){ 
        Serial.println("Error");
      }else{
        //nur einer der beiden Werte hat sich verändert
  
        if(!lastPinStatus[j] & !lastPinStatus[j+1]){//vorher waren beide auf LOW (und einer ist jetzt HIGH)
          Serial.print("Auto Fährt in den Sensor: ");
          Serial.print((j/2)); //Nummer des Sensors wird aus Position im array berechnet
          Serial.print(" : ");
          if(pinStatus[j]){//prüfen ob das Auto auf dem linken oder rechten Sensor Steht
            Serial.println("links");
          }else{
            Serial.println("rechts");
          }
        }else if(!pinStatus[j]&!pinStatus[j+1]){ //aktuell sind beide auf LOW (und vorher war einer HIGH)
          Serial.print("Auto Fährt aus dem Sensor: ");
          Serial.print((j/2));
          Serial.print(" : ");
          if(lastPinStatus[j]){//prüfen auf welchem der beiden Sensoren das Auto vorher stand
            Serial.println("links");
          }else{
            Serial.println("rechts");
          }
        }
      }
    }
  }
}


void left(boolean an){
  
  if (an==true){//linke Pfeilspitze zeichen
    display.drawLine(32,31,32+10,31+10,SSD1306_WHITE); //koordinaten (x1, y1, x2, y2, farbe) 
    display.drawLine(32,31,32+10,31-10,SSD1306_WHITE);//farbe kann nur SSD1306_WHITE oder SSD1306_BLACK sein
    display.drawLine(32,31,32+10,31+10,SSD1306_BLACK);
    display.drawLine(32,31,32+10,31-10,SSD1306_BLACK);  
  }
}

void right(boolean an){
  if (an==true){//rechte Pfeilspitze zeichen
    display.drawLine(96,31,96-10,31+10,SSD1306_WHITE);
    display.drawLine(96,31,96-10,31-10,SSD1306_WHITE);
  }else{//rechte Pfeilspitze übermalen/"ausschalten"
    display.drawLine(96,31,96-10,31+10,SSD1306_BLACK);
    display.drawLine(96,31,96-10,31-10,SSD1306_BLACK);
  }
}
