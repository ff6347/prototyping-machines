---
layout: default
title: "Random Decision Maker"
author: "Sujing Lin"
author-url: "https://incom.org/profil/6397"
summary: "This machine could make decisions for you."
---

## Purposes
The Random Decision Maker is a prototype which rebuilt from a computer keyboard. It is a practice project from the course “Prototype Machine”. The purposes of this project are:
1) To learn the basic skills of prototyping. Included  HID hacking, rebuilding and soldering.
2) Implement new interact ways of a simple circuit. 3) Theory learning. Evaluate the purpose of a prototype with “Houde & Hills System”. Create a user test and document the feedbacks.

## Introduction
Sometimes it is easier to execute a command than to make a decision. Be urged makes someone more efficient. The decision maker is made for these reasons. It spares the user from trivial decisions, thereby helps them concentrate on their work.
This prototype is rebuilt with a circuit of computer keyboard. It generates one arbitrary option each time through mechanical method. The user needs to place a glass ball into an oblique field on the top, which is populated by a large number of pins. The ball will drop through arrays of pins and fall into one of the three exits at the lower side and trigger a treadle switch. It makes a circuit and send the signal to computer, thereby runs a preset action. The idea of the installation came from a kind of japanese gambling machine “Pachinko”. Although the falling path of a ball is arbitrarily, the probability of which exit would the ball fall into could be strongly influenced by the layout of the pins.
Normally, when somebody works alone, he will always be tempted to have a rest, even he knows that it is better to keep working. In this case, he could place a ball into the decision maker. The decision maker has three exits and two default actions. If the ball falls into the exit in middle, the user will get a price: he could take a break and the computer will open a interesting website for him. If the ball falls into the exit on sides, the computer will shout “Keep working!”, moreover nothing happens. The layout of pins makes the ball has lower probability to fall into middle.
It should be pointed out, that the decisions are non-mandatory. The final decision depends on the will of the user, whether to obey it or not. The machine just offers advises and avoids the users wasting their time because of hesitation. There was a further reason why I chose the form of Pachinko to build this prototype. Pachinko is considered as a gambling game with high risk of addictive. Most people will enjoy to watching the ball falling through pins, even who do not like gambling. The user could enjoy with this experience, regardless which result comes out at end.

## First Prototype
### Materials:
Paper
Nails (0.8 × 11mm)
Soybean
Paper tape
It is a rough prototype without circuit. It aims at testing how does the layout of the pins influences the falling path of a ball.

## Final Prototype
### Materials:
Styrofoam board
Nails (1.2 × 20mm)
Keyboard circuit
Glass ball
Carton
Paper tape
Paper
The final prototype is builded with the keyboard circuit. Under the exit there are treadle switch of the key “8”, “9” and “4”. By using the software “Keyboard Maesrto” could define these number keys as hotkeys of the actions. Key “8” and “4” are correspond to the action speak and display text “Keep Working”. Key “9” is correspond to the action “open a URL”.

## Defect
The circuit of hotkeys is too simple. It makes the actions could be trigger by normal inputting. The better way is to build circuit of multiple keys with one switch.

## Houde & Hills System
The Houde & Hills System is focusing on the purpose of the prototype. It proposed a model to define the purpose with three dimensions: role; look and feel; and implementation. The decision maker shows a method to improve the efficiency at work. However, there is still a large development space for its form and the circuit. For these reasons it is a “role” prototype.

## User test
An user test has been led to collect the user’s experience with the prototype. The following are the feedbacks from 5 users:
Would you like to use this machine?
Yes: 5, No: 0
Would you follow the result, which the machine gave to you?
Yes: 2, No: 3
Would you like to use it for make a very important decision?
Yes: 1, No: 4
Do you have fun with using this machine?
Yes: 5, No: 0
Is that meaningful of this machine?
Yes: 4, No: 1
Other feedbacks:
“I will follow the result, but I will keep to placing another ball until it comes out with the result I want.”
“I hope the users could edit preset actions by themselves.”
