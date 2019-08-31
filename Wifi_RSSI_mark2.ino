//#include <SPI.h>
#include <WiFi.h>
#include <ESP8266WiFi.h>

//SSID of your network
char ssid[] = "Chozhan";
//password of your WPA Network
char pass[] = "chozhan0n";

void setup()
{
  Serial.begin(115200);
 WiFi.begin(ssid, pass);
 Serial.println("OK");

  if (WiFi.status() != WL_CONNECTED) {
    Serial.println("Couldn't get a wifi connection");
    while(true);
  }
  // if you are connected, print out info about the connection:
  else {
   // print the received signal strength:
  long rssi = WiFi.RSSI();
  Serial.print("RSSI:");
  Serial.println(rssi);
  }
}

void loop () {}
