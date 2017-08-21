#include <XNode.h>

int ledPinOne = 14;// was anderes nehemen! LED connected to digital pin 9
int ledPinTwo = 15;
int output_pin = 0;
int output_virus_pin = 2;
int input_pin = 4;
int input_virus_pin = 5;
XNode node(input_pin, output_pin, input_virus_pin, output_virus_pin);

boolean action = false;

void setup () {
  node.init();
  pinMode(ledPinOne, OUTPUT);
  pinMode(ledPinTwo, OUTPUT);
  Serial.begin(115200);
}

void loop() {

Serial.println(node.listen());
  if(node.listen() == true && action == false){
    action = true;
    Serial.println(action);
  }

  if(action == true){

    // fade in from min to max in increments of 5 points:
    for (int fadeValue = 0 ; fadeValue <= 1023; fadeValue += 20) {
      // sets the value (range from 0 to 255):
      analogWrite(ledPinOne, fadeValue);
      analogWrite(ledPinTwo, fadeValue);
      // wait for 30 milliseconds to see the dimming effect
      delay(30);
    }

    // fade out from max to min in increments of 5 points:
    for (int fadeValue = 1023 ; fadeValue >= 0; fadeValue -= 20) {
      // sets the value (range from 0 to 255):
      analogWrite(ledPinOne, fadeValue);
      analogWrite(ledPinTwo, fadeValue);
      // wait for 30 milliseconds to see the dimming effect
      delay(30);
    }
    node.send();
    action = false; // action wird nach dem Fading zurückgesetzt
    Serial.println(action);
  }

}
