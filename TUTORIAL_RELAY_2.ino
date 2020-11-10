/*
   TUTORIAL RELAY PADA ARDUINO
   PUSH BUTTON DAN RELAY
   DENGAN PENGGUNAAN DEBOUNCE

   Pinout :
   Tombol 1 -> D9

   D4 -> Led Merah

   VCC relay -> VCC
   GND relay -> GND
   IN RELAY -> SDA (atau sama dengan A4)

*/

#define TOMBOL1 9
#define merah 4
#define pinRelay A4


int statusLed = LOW;
int statusRelay = HIGH;
int statusTombolTerakhir = HIGH;
int statusTombol;

unsigned long lastDebounceTime = 0;
unsigned long debounceDelay = 50;


void setup()
{
  pinMode(TOMBOL1, INPUT); //set menjadi input
  pinMode(merah, OUTPUT);
  pinMode(pinRelay, OUTPUT); //set menjadi output
  digitalWrite(TOMBOL1, HIGH); //pull high sebagai default awal

  digitalWrite(merah, statusLed);
  digitalWrite(pinRelay, statusRelay);

}

void loop()
{
  int a = digitalRead(TOMBOL1);

  if (a != statusTombolTerakhir) {
    // reset debouncing timer
    lastDebounceTime = millis();
  }

  if ((millis() - lastDebounceTime) > debounceDelay) {
    if (a != statusTombol) {
      statusTombol = a;

      if (statusTombol == LOW) {
        statusLed = !statusLed; //kebalikan nya
        statusRelay = !statusRelay; //kebalikan nya

      }
    }
  }
  digitalWrite(merah, statusLed);
  digitalWrite(pinRelay, statusRelay);
  statusTombolTerakhir = a;
}
