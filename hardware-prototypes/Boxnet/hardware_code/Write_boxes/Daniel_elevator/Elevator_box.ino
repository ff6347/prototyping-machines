#include <XNode.h>
#include <Ticker.h>

/*
  Adafruit Arduino - Lesson 4. 8 LEDs and a Shift Register
  http://learn.adafruit.com/adafruit-arduino-lesson-4-eight-leds/arduino-code
  Shiftout tutorial
  http://arduino.cc/en/tutorial/ShiftOut
  PINS 1-7, 15   Q0 " Q7   Output Pins
  PIN 8  GND   Ground, Vss
  PIN 9  Q7"   Serial Out
  PIN 10   MR  Master Reclear, active low
  PIN 11   SH_CP   Shift register clock pin
  PIN 12   ST_CP   Storage register clock pin (latch pin)
  PIN 13   OE  Output enable, active low
  PIN 14   DS  Serial data input
  PIN 16   Vcc   Positive supply voltage

*/

Ticker tick;
//Pin connected to ST_CP of 74HC595
int latchPin = 14;
//Pin connected to SH_CP of 74HC595
int clockPin = 13;
////Pin connected to DS of 74HC595
int dataPin = 12;
int downLEDPin = 15;
int upLEDPin = 16;
int countingUp = false;
int counter = 10;

int output_pin = 0;
int output_virus_pin = 2;
int input_pin = 4;
int input_virus_pin = 5;
boolean action = false;

XNode node(input_pin, output_pin, input_virus_pin, output_virus_pin);

//boolean isInfected = false;
//boolean doTheCounting = true;

//| - |
//|   |
//  -
byte valsVirus [] = {
  B10011000, /*9*/
  B11010000, /*8*/
  B10000101, /*7*/
  B10110001, /*6*/
  B11000010, /*5*/
  B10101001, /*4*/
  B11010000, /*3*/
  B11010010, /*2*/
  B10111010  /*E*/
  //B10000000
  //B10000000, /* */

  //B00001001/* all leds off*/
  //B00000011
};

byte vals [] = {

  B00001000, /*9*/
  B00001000, /*9*/
  B00000000, /*8*/
  B01001101, /*7*/
  B00010000, /*6*/
  B00011000, /*5*/
  B00101100, /*4*/
  B01001000, /*3*/
  B01000010, /*2*/
  B10010010,  /*E*/
  B10010010  /*E*/
};

void setup() {
  Serial.begin(115200);
  node.init();
  pinMode(latchPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(downLEDPin, OUTPUT);
  pinMode(upLEDPin, OUTPUT);
  setSegments(vals[counter]);
  tick.attach_ms(500, change);


}
void loop() {

  if (node.listen() == true && action == false) {
    action = true;
  }

}


void change () {
  setSegments(vals[counter]);
  if (action == true) {
    if (countingUp == true ) {
      counter++;
      digitalWrite(upLEDPin, HIGH);
      digitalWrite(downLEDPin, LOW);


    } else {
      counter--;
      digitalWrite(downLEDPin, HIGH);
      digitalWrite(upLEDPin, LOW);
    }
  }

  if (counter == 10) {
    countingUp = false;
    action = false;

  } else if (counter == 0) {
    countingUp = true;
    node.send();
  }
}



void setSegments(byte val) {
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, LSBFIRST, val);
  digitalWrite(latchPin, HIGH);
}
