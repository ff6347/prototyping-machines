#include <XNode.h>
/** Tresor **/ 
#include <Keypad_I2C.h>
#include <Keypad.h>        
#include <Wire.h>

#define I2CADDR 0x38                          // I2C Adresse vom PCF8574

const byte anzZeilen = 4;                        //Anzahl Zeilen 
const byte anzSpalten = 4;                       //Anzahl Spalten

//Hier kannst du die Symbole von deinem Keypad eintragen
char tastenLayout[anzZeilen][anzSpalten] = {
  {'1','2','3','A'}, 
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

//Hier definieren wie das Keypad mit den IO Pins vom PCF8574 verdrahtet ist.
byte zeilenPins[anzZeilen] = {0, 1, 2, 3};       //Zeilen Pins
byte spaltenPins[anzSpalten] = {4, 5, 6, 7};     //Spalten Pins

//Initialisierung von Keypad
Keypad_I2C i2cKeypad( makeKeymap(tastenLayout), zeilenPins, spaltenPins, anzZeilen, anzSpalten, I2CADDR); 

int redLed = 15;
int greenLed = 16;
int piezo = 2;

String input ="";
String password ="1234";
String clearPW ="*";
String key = "";
/** Tresor **/ 

// The Input pins need to be pullup pins
// to simplify the circuit
//
// Which pins are able to be used with an internal
// pull up resistor on the Adafruit Feather Huzzah ESP8266?
//
// There has been some confusion around.
// https://forums.adafruit.com/viewtopic.php?f=19&t=86182
// http://www.esp8266.com/viewtopic.php?f=32&t=11614
// so this is a table of the test
//
// | GPIO pin | is able to pull up? |
// | :--      | :--                 |
// | #0       | No                  |
// | #2       | Yes                 |
// | #4       | Yes                 |
// | #5       | Yes                 |
// | #12      | Yes                 |
// | #13      | Yes                 |
// | #14      | Yes                 |
// | #15      | No                  |
// | #16      | No                  |
//

int output_pin = 12;
int output_virus_pin = 3;
int input_pin = 14;
int input_virus_pin = 13;

XNode node(input_pin, output_pin, input_virus_pin, output_virus_pin);

boolean action = false;
void setup (){
  node.init();
/** Wifi Settings **/ 
//WiFi.mode(WIFI_OFF);
//    WiFi.forceSleepBegin();
//    delay(1); /

/** Tresor **/ 
 i2cKeypad.begin( );        
  Serial.begin(115200);


   pinMode(redLed, OUTPUT);
   pinMode(greenLed, OUTPUT);
   pinMode(piezo, OUTPUT);

   digitalWrite(greenLed, LOW);
   digitalWrite(redLed, HIGH);
  
   Serial.println("Setup done");
  /** Tresor **/ 
}

void loop(){
  char ausgeleseneTaste = i2cKeypad.getKey();
  key = ausgeleseneTaste;
  
  Serial.println(ausgeleseneTaste);
  if (ausgeleseneTaste != NO_KEY){
    Serial.print("Passwort: ");
  input.concat(key);
  Serial.println(input);
  }

if (input.equals(password)){
  Serial.println("Password correct");
  digitalWrite(redLed, LOW);
  digitalWrite(greenLed, HIGH);
  node.send();
   tone(piezo, 500);
  delay(300);
  noTone(piezo);
  delay(50);
  tone(piezo, 300);
  delay(200);
  noTone(piezo);
  delay(1000);
  digitalWrite(greenLed, LOW);
  digitalWrite(redLed, HIGH);
}

int lengthPW = input.length();
 if (lengthPW > 3){
  input = "";
}
 if (key == clearPW){
  input = "";
  digitalWrite(greenLed, LOW);
  digitalWrite(redLed, HIGH);
}
if (lengthPW > 3 && input != password){
   digitalWrite(redLed, LOW);
   tone(piezo, 100);
   delay(200);
   digitalWrite(redLed, HIGH);
    noTone(piezo);
  }
}
