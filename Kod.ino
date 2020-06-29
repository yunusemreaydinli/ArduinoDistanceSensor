/* Writer: Yunus Emre Aydınlı
Date: 23.02.2020

Nokia 5110 pins;
1
RST  – Pin 11
CE   – Pin 12
DC   – Pin 10
DIN  – Pin 9
VCC  – Pin 8
BL   – Pin 5V
GND  – Pin GND
8
HC-SR04 pins;
GND  - Pin GND
ECHO - Pin 6
TRİG - Pin 7
VCC  - Pin 5V"
*/

#include <LCD5110_Basic.h>
#define trigPin 7
#define echoPin 6

LCD5110 myGLCD(8,9,10,11,12);
extern uint8_t SmallFont[];
extern uint8_t BigNumbers[];

void setup()
{
  myGLCD.InitLCD();
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop()
{
  myGLCD.setFont(SmallFont);
  myGLCD.print("Mesafe:", CENTER, 0);
  int sure, mesafe=0;
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(1000);
  digitalWrite(trigPin, LOW);
  sure = pulseIn(echoPin, HIGH);
  mesafe = sure/58;
  myGLCD.setFont(BigNumbers);
  myGLCD.printNumI(mesafe,CENTER,16);
  delay(450);
  myGLCD.clrScr();
}
