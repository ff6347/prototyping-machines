---
layout: default
title: "Alfredo"
author: "Nina Botthof"
author-url: "PUT ONE ONLINE PRESENSE HERE (TWITTER, INCOM, GITHUB, ETC)"
summary: "A cup, which helps to organise and automat your morning routine."
---



## Assignment



- hack a HID (human interface device)
- give a physical representation to a digital action
- test at least 5 Users
- classify your Prototype with Houde & Hills system  

The task of this prototype is to give a physical representation to a digital action. This had to be achived by a HID-Hack — the disassembling and reporposing of a human interface device e. g. a keyboard. To eveluate the prototype, usertests with at least five participants shal be made.



## Idea: Alfredo

The Idea behind Alfredo is the automatation of your daily morning routine.

- set the timer automatically when water is poored into the cup
- sends Messanges directly onto your Phone
- activates iTunes Playlist
- suggests interesting articles on Medium or other news sites
- gives information about the current weather
- gives the current treaveling time to your workingplace



The Idea behind Alfredo is the automatation of your daily morning routine. The aim was to create a cup, that does not only set a timer by itself, but helps to get off to work on time and to choose the appropriate clothing for the weather outside.
As soon as water is poored into the cup, it sets a timer for a predetermined time. When the time is over, a iMessage is sent to your Phone. Additionally Alfredo activates a certain playlist in iTunes to provide a relaxing atmosphere in the morning. While the timer is running Alfredo suggests articles from news sites to read during the brewing time. A special feature is that the articles are filtered by reading time, so you can finish reading the article until the tea is ready.
Furthermore Alfredo informs you about the traveling time to your appointed working place and notifies you when it is time to leave. To round up the experience, it also gives information about the current weather at your location by opening the weather app.
Summerising this Alfredo is a collection of timed actions triggered by the tea being brewd. These actions can be configurated according to your own habits. If the idea of Alfredo was developed further, it would include the cup, but also a service which is provided by an app to download on your phone.



## Implementation

### HID-Hack

- disassemble keyboard
- solder the contacts to mach a key on the keyboard
- assign an action to the key (KeyboardMaestro)

To build the electronic part of the cup a keyboard has been disassembled. To address certen keys from the keyboard, two contacts need to be connected and close the circuit. Therefore wires have been solderd these contacts.
To create a connection between the contacts whenever water is poored into the cup, it also needs conducting material. Two stripes of aluminium foil are sticked to the saucer and to the cup. These stripes need to reach into the cup so conductivity of the water connects the material and closes the circuit. The wires from the Keyboard are mounted onto each stripe on the saucer. 
An advantage of that construction is that the cuircuit is disconnected as soon as the cup is lifted. There is no current inside the cup while drinking.

### Code & Software

For the actions a software called Keyboard Maestro had been used. In this software it is possible to map macros to a cerain key. In this case the key + is pressed a macro group consisting of several Apple scrips for the notifications and pauses for the timing  is initiated. 
Code as listed below:

```apple script
tell application "Messages"

	set theBuddy to buddy "+491638343320" of service id "BE20AFC9-6AC7-4569-A877-A1252B7DD5F5"
-- message below (always the same)
	send "Guten Morgen! Dein Timer ist gesetzt. Hier sind ein paar interessante Arikel für die Wartezeit: medium://open/" to theBuddy

end tell

```



### Cup

- stick aluminium foil onto the cup and the saucer
- stick wire to the aluminium foil
- the circuit is colsed once the cup is filled with water
- it is opend whene the cup is liftet – no current while drinking
- script, which sends messages from Laptop to phone in determined intervals



## Usertesting

qualitiative reserch with 5 participants

To eveluate the outcome there had to be a usertestin with five participants. A qualitative research method was chosen to detect the main strenghs and weaknesses of this prototype. The participants have been invited to an open discussion with a demonstration of the prototype. To lead the discussion some questions have been predifined which should be the start of a open debate.

### Questions

- Would you buy this product?
- How did the product simplify, enhance your daily routine?
- Did you have any problems with handling the product?
- Which properties do you like about the product?
- Is there anything you disliked about it?

### Results

- 4 out of 5 would use Alfredo
- possibility to personalise the routine is very important
- need for a simple user interface on the phone
- further timer for drinking temperature proposed
- positive: think less in the morning
- push-messages better than iMessages
- wires & laptop are disturbing
- worries because of the current
- bigger cup for tea
- vintage stile is very appealing

The results of the Usertesting are positive overall.
Four of the five participants claimed that they would buy Alfredo and use it in their daily lifes. One mayour argument for the use of Alfredo was the fact that it takes over some tasks which you do not need to think of any more.
The participants also pointed out that the possibility to personalise the actions is most important for the project. Every person has their own morning routine and this should not be dictated by the service. Therefore it would be necessary to create a simple userinterface for the Phone to adjust the timing and change settings easily.
Another participant mentioned that another timer for the perfect drinking temerature could be added to enhance the userexperience.
Some also pointed out that they would prefere push messages over iMessages.

Some worries have been mentioned concerning the wires and the laptop being close to liquids. Others have not felt secure due to the combination of electricity and water — one sayed that she was scared to drink because of the current. Gladly this is not a problem becose of the construction of the cup. To avoid worries about safety the design should be reworked so one can not see any wires and foil.

Minor criticism has been mentioned about the cupsize beeing to small for tea. Therefore the vintage style of was verry appealing to the participants.



## Conclusion

- Houde & Hills system

This prototype represents the role of Alfredo in our daily lifes. Implementation and look are not redefined enough jet to suit the custemers needs. Therefore the classification in Houde & Hills system would look as followed:

After all this prototype gives a good impression of the funktion of the product. It shows the most features verry close to a planned implementation. 