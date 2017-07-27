---
layout: default
title: "Box-Net
author: "Paul Röder, Sujing Lin, Daniel Boubet, Nina Botthof"
author-url: "PUT ONE ONLINE PRESENSE HERE (TWITTER, INCOM, GITHUB, ETC)"
summary: "An indefinitely expandable, distributed network of connected boxes."
---



## Initial Concept

The first draft of the projekt was a game, which explaines the daingers of Bot-Networks invaiding connected IOT-Devices. As the everyday life becomes more technical and every device is connected to the internet, security issues are more harmful than ever before. The game Box-Net wants to illustrate the perils of Bots being passed from one device to another and the damage they bring about.  
Box-Net consists of multiple small boxes, each representing one IOT-Device in a network. These Boxes can be pluged together to illustrate the interconnectivity of such devices. But there are viruses that can be passed through and flaw the boxes funktionality. The funktionality of the boxes can only be restored by keeping the firmware up to date via a Patch-Button. Main Goal is it to connect as much boxes as possible while keeping them uninfected.



## Revised Concept

Due to time shortage the intitial concept had to be revised in order to be finished on Werkschau.  
The idea of Box-Net was cut down to the essentials: an interconnected system. It still features the boxes each representing one device e. g. the lamp. These boxes can be connected to eachother and react on a signal that is being passed through. This way the players can explore the different combinations an how the boxes react.  
To keep the network as simple as possible there are only two classes: sending; and recieving boxes. The sending boxes are always switched on and output a signal, they can not recieve any signals. Recieving boxes on the other hand can only react to incomming signals an only execute an action when they have input.  


## Construction

For the hardware compound of the boxes the adafruit feather huzzah has been used. Main factor for that decision was the built in Ion-Lithium-Battery-Plug.  
The outer construction of the boxes was made out of a very strong cardboard. It is very light compared to MDF or acrylic glass and additionally cheaper than any other comparable material.  


## Boxes

### Surveillance Box

This box represents a security system. Especially surveillance cameras are knowen to be very vulnerable to bot attacs.  
Inside the box there is a camera dummy with a built in motor and LED.

In the initial concept there where two kinds of funktionallity: normal and infected. 

#### Normal

The camera pivots in regular intervals from left to right and back. The LED is switched on and off simultaneously. It can initiate a signal and is switched on from the beginning.

#### Infected

The camera and the LED act unpredictable and unregularily.



#### Implementation

##### Construction

On one edge of the box is a cut out window. The camera is located inside the box and points out of the window.  
The camera is, like the box, constructed out of cardboard. To give a more realistic impression, there is a lens from an old web cam and a red LED on the front. It also has a rack to hold the camera in position. A motor is mounted inside the rack, right under the camera, to controll the cameras movement.



##### Code

One main issue of this box was to move the motor and switch the LED on and off simultaniously. Normally there can only one action be executed at a time. To avoid this problem timed action library has been used. It helps coordinate multiple actions by defining intervals.



```c
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
```

