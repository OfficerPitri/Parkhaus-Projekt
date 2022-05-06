#include <Stepper.h> // Hinzufügen der Programmbibliothek.
int SPU = 2048; // Schritte pro Umdrehung.
Stepper Motor(SPU, 3,5,4,6); // Der Schrittmotor erhält die Bezeichnung "Motor" und es wird angegeben an welchen Pins der Motor angeschlossen ist.


void setup() //Hier beginnt das Setup.
{
  pinMode (13,INPUT);
Motor.setSpeed(10); // Angabe der Geschwindigkeit in Umdrehungen pro Minute.
}

void loop() {
  if (digitalRead(13)){
Motor.step(10); // Der Motor macht 2048 Schritte, das entspricht einer Umdrehung.
  }

}
