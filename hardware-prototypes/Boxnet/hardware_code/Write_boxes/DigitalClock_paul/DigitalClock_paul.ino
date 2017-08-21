/*
 * TimeNTP_ESP8266WiFi.ino
 * Example showing time sync to NTP time source
 *
 * This sketch uses the ESP8266WiFi library
 */
#include <XNode.h>
#include <TimeLib.h>
#include <ESP8266WiFi.h>
#include <WiFiUdp.h>
#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_PCD8544.h>

char ssid[] = "Interface Werkstatt Guest";  //  your network SSID (name)
char pass[] = "interfacelabor!";       // your network password

// char ssid[] = "FB-Design-Gäste";  //  your network SSID (name)
// char pass[] = "FBDGinternet";       // your network password

// NTP Servers:
static const char ntpServerName[] = "de.pool.ntp.org";
//static const char ntpServerName[] = "time.nist.gov";
//static const char ntpServerName[] = "time-a.timefreq.bldrdoc.gov";
//static const char ntpServerName[] = "time-b.timefreq.bldrdoc.gov";
//static const char ntpServerName[] = "time-c.timefreq.bldrdoc.gov";

const int timeZone = +2;     // Central European Time
//const int timeZone = -5;  // Eastern Standard Time (USA)
//const int timeZone = -4;  // Eastern Daylight Time (USA)
//const int timeZone = -8;  // Pacific Standard Time (USA)
//const int timeZone = -7;  // Pacific Daylight Time (USA)


WiFiUDP Udp;
unsigned int localPort = 8888;  // local port to listen for UDP packets

time_t getNtpTime();
void digitalClockDisplay();
void printDigits(int digits);
void sendNTPpacket(IPAddress &address);

/******************************************************************
ESP8266 with PCD8544 display
== Parts ==
* Adafruit Huzzah ESP8266 https://www.adafruit.com/products/2471
* Adafruit PCD8544/5110 display https://www.adafruit.com/product/338
* Adafruit USB to TTL serial cable https://www.adafruit.com/products/954
== Connection ==
USB TTL     Huzzah      Nokia 5110  Description
            ESP8266     PCD8544
            GND         GND         Ground
            3V          VCC         3.3V from Huzzah to display
            14          CLK         Output from ESP SPI clock
            13          DIN         Output from ESP SPI MOSI to display data input
            12          D/C         Output from display data/command to ESP
            #5          CS          Output from ESP to chip select/enable display
            #4          RST         Output from ESP to reset display
            15          LED         3.3V to turn backlight on, GND off
GND (blk)   GND                     Ground
5V  (red)   V+                      5V power from PC or charger
TX  (green) RX                      Serial data from IDE to ESP
RX  (white) TX                      Serial data to ESP from IDE
******************************************************************/

// Hardware SPI (faster, but must use certain hardware pins):
// SCK is LCD serial clock (SCLK) - this is pin 14 on Huzzah ESP8266
// MOSI is LCD DIN - this is pin 13 on an Huzzah ESP8266
// pin 12 - Data/Command select (D/C) on an Huzzah ESP8266
// pin 5 - LCD chip select (CS)
// pin 4 - LCD reset (RST)
Adafruit_PCD8544 display = Adafruit_PCD8544(12, 5, 4);

int output_pin = 1;
int output_virus_pin = 1;
int input_pin = 16;
int input_virus_pin = 3;

XNode node(input_pin, output_pin, input_virus_pin, output_virus_pin);

void setup()
{
  Serial.begin(115200);
  // Initialize LCD
  display.begin();
  display.setContrast(55);
  display.setTextSize(2);
  display.setTextColor(BLACK);
  display.clearDisplay();
  
 pinMode(15, OUTPUT);
 pinMode(A0, INPUT);

  // Credits
  display.println("Paul Roeder");
  display.println("- FH Potsdam");
  delay(1000);
  display.clearDisplay();

// Connect to WIFI
  
  Serial.println("TimeNTP Example");
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, pass);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  display.println("WiFi connected");
  display.display();
  delay(500);
  display.clearDisplay();
  Serial.print("IP number assigned by DHCP is ");
  Serial.println(WiFi.localIP());
  Serial.println("Starting UDP");
  Udp.begin(localPort);
  Serial.print("Local port: ");
  Serial.println(Udp.localPort());
  Serial.println("waiting for sync");
  setSyncProvider(getNtpTime);
  setSyncInterval(20000);

  display.display();
}

time_t prevDisplay = 0; // when the digital clock was displayed

void loop()
{
  if (timeStatus() != timeNotSet) {
    if (now() != prevDisplay) { //update the display only if time has changed
      prevDisplay = now();
    //  digitalClockDisplay();
      display.clearDisplay();
      WriteNokia();
      display.display();
      displayLED();
    }

    if ((second() % 10) == 0) 
    {
      schicken();
    }
  }
}

void WriteNokia()
{
 display.setTextSize(2);
  // digital clock display of the time
  display.print(hour());
  display.print(":");
  printDigits(minute());
  display.println();
  printDigits(second());
  display.print("sek");
  display.println();
  // display.drawLine(0, 15, 84, 15, BLACK);
  display.setTextSize(1);
  display.print(day());
  display.print(".");
  display.print(month());
  display.print(".");
  display.println(year());
}
void schicken()
{
 Serial.println(OUTPUT);
 node.send();
 display.clearDisplay();
 display.setTextSize(3);
  // digital clock display of the time
  display.println(" OUT");
  display.println(" PUT");
  display.display();
  display.clearDisplay();
}

void printDigits(int digits)
{
  // utility for digital clock display: prints preceding colon and leading 0
  if (digits < 10) {
    display.print('0'); }
  display.print(digits);
}

void displayLED() 
{
int lightLevel = analogRead(A0);
Serial.println(lightLevel);
int brightness = map(lightLevel, 0, 1024, 0, 255);
brightness = 255 - brightness;
Serial.println(brightness);
analogWrite(15, brightness);
}

/*-------- NTP code ----------*/

const int NTP_PACKET_SIZE = 48; // NTP time is in the first 48 bytes of message
byte packetBuffer[NTP_PACKET_SIZE]; //buffer to hold incoming & outgoing packets

time_t getNtpTime()
{
  IPAddress ntpServerIP; // NTP server's ip address

  while (Udp.parsePacket() > 0) ; // discard any previously received packets
  Serial.println("Transmit NTP Request");
  // get a random server from the pool
  WiFi.hostByName(ntpServerName, ntpServerIP);
  Serial.print(ntpServerName);
  Serial.print(": ");
  Serial.println(ntpServerIP);
  sendNTPpacket(ntpServerIP);
  uint32_t beginWait = millis();
  while (millis() - beginWait < 1500) {
    int size = Udp.parsePacket();
    if (size >= NTP_PACKET_SIZE) {
      Serial.println("Receive NTP Response");
      Udp.read(packetBuffer, NTP_PACKET_SIZE);  // read packet into the buffer
      unsigned long secsSince1900;
      // convert four bytes starting at location 40 to a long integer
      secsSince1900 =  (unsigned long)packetBuffer[40] << 24;
      secsSince1900 |= (unsigned long)packetBuffer[41] << 16;
      secsSince1900 |= (unsigned long)packetBuffer[42] << 8;
      secsSince1900 |= (unsigned long)packetBuffer[43];
      return secsSince1900 - 2208988800UL + timeZone * SECS_PER_HOUR;
    }
  }
  Serial.println("No NTP Response :-(");
  return 0; // return 0 if unable to get the time
}

// send an NTP request to the time server at the given address
void sendNTPpacket(IPAddress &address)
{
  // set all bytes in the buffer to 0
  memset(packetBuffer, 0, NTP_PACKET_SIZE);
  // Initialize values needed to form NTP request
  // (see URL above for details on the packets)
  packetBuffer[0] = 0b11100011;   // LI, Version, Mode
  packetBuffer[1] = 0;     // Stratum, or type of clock
  packetBuffer[2] = 6;     // Polling Interval
  packetBuffer[3] = 0xEC;  // Peer Clock Precision
  // 8 bytes of zero for Root Delay & Root Dispersion
  packetBuffer[12] = 49;
  packetBuffer[13] = 0x4E;
  packetBuffer[14] = 49;
  packetBuffer[15] = 52;
  // all NTP fields have been given values, now
  // you can send a packet requesting a timestamp:
  Udp.beginPacket(address, 123); //NTP requests are to port 123
  Udp.write(packetBuffer, NTP_PACKET_SIZE);
  Udp.endPacket();
}
