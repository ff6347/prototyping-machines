
#include <XNode.h>

int DC_MOTOR_PIN = 6;
int output_pin = 9;
int output_virus_pin = 2;
int input_pin = 12;
int input_virus_pin = 5;
boolean action = false;
int counter = 0;
int turnInterval = 100000;
XNode node(input_pin, output_pin, input_virus_pin, output_virus_pin);
void setup() {
  /* Initialize DC motor control pin as digital output */
  Serial.begin(115200);
  node.init();
  pinMode( DC_MOTOR_PIN, OUTPUT );

}

void loop() {
  if (node.listen() == true && action == false) {
    action = true;
  }
  Serial.println(counter);
  if (action == true) {
    /* Run motor */
    if (counter != 1000) {
      digitalWrite( DC_MOTOR_PIN, HIGH);
    }
    counter++;

    if (counter == turnInterval) {
      digitalWrite( DC_MOTOR_PIN, LOW);
      node.send();
      action = false;
      counter = 0;
    }
    /* Let it run for a while */
    /*delay( 2000 );
      /* Stop motor */
    /*digitalWrite( DC_MOTOR_PIN, LOW );
      /* Do nothing */
    /*while( 1 );*/
  }
}

