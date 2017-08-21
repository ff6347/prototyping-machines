#include <XNode.h>
#include <TimedAction.h>
#include <Servo.h>


//GLOBALS
const int servoPin = 0; // Pin für die steuerung des Servos
bool increment = true; // true, wenn Winkel des Servos erhöht werden soll
short pos = 0; // aktueller Winkel des Servos
const int ledPin = 12; // Pin für die LED
int ledState = LOW; // LED standardmäßig ausgeschalted
int randomAngle = random(90);
int LEDrandom = random(100);
bool virus = false;

int i = 0;

int output_pin = 14;
int output_virus_pin = 2;
int input_pin = 4;
int input_virus_pin = 5;

XNode node(input_pin, output_pin, input_virus_pin, output_virus_pin);
Servo myservo;

//FUNCTIONS

// schaltet LED ein/aus
void ledBlink() {
  // ist LED ein oder aus – kehrt wert um
  if (ledState == LOW) {
    ledState = HIGH;
  } else {
    ledState = LOW;
  }

  // Versetzt LED in den aktuellen Status
  digitalWrite(ledPin, ledState);
}

//timers – müssen NACH den Funktionen kommen
TimedAction ledThread = TimedAction(500, ledBlink);

void setup() {
  pinMode(ledPin, OUTPUT); // deklariert ledpin als output
  Serial.begin(115200); // definiert datenfrequetz – nur für Serial Monitor
  node.init();

  node.setInterval(50);
}

void loop() {

  if (/*node.virusDetect()*/ virus == true) {
    myservo.attach(0); // Servo wird aktiviert
    myservo.write(randomAngle);
    delay(30);
    randomAngle = random(90);
    LEDrandom = random(100);

    if (LEDrandom < 50) {
      digitalWrite(ledPin, LOW);
    }

    else {
      digitalWrite(ledPin, HIGH);
    }

  }
  else {

    ledThread.check();

    myservo.attach(0); // Servo wird aktiviert

    for (pos = 0; pos <= 90; pos++) { // geht von 0 bis 90 Grad durch

      // prüften wann aktionen durchgeführt werden sollen, auch wärend der Schleife
      ledThread.check();

      myservo.write(pos); // Servo nimmt position aus Variable 'pos' ein
      Serial.println(pos);
      delay(15); // pause damit Servo Zeit hat die Position einzunehmen

      if (pos == 90) {
        node.send();
        Serial.println("senden");
      }

    }

    myservo.detach(); //deaktiviert Servo – braucht weniger Strom
    digitalWrite(0, LOW);

    for (i = 0; i <= 5000; i++) {
      ledThread.check();
      delay(1);
    }

    myservo.attach(0); // Servo wird aktiviert


    for (pos = 90; pos >= 0; pos--) { // geht von 0 bis 90 Grad durch
      // prüften wann Aktionen durchgeführt werden sollen, auch während der Schleife

      ledThread.check();

    myservo.write(pos); // Servo nimmt position aus Variable 'pos' ein
      Serial.println(pos);
      delay(15); // Pause damit Servo Zeit hat die Position einzunehmen

    }
    myservo.detach(); //deaktiviert Servo – braucht weniger Strom
    digitalWrite(0, LOW);

    for (i = 0; i <= 5000; i++) {
      ledThread.check();
      delay(1);
    }

  }
}
