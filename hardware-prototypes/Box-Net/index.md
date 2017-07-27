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

#### Implementation

##### Construction

##### Code

