#include <WiFi.h>

//SSID of your network
char ssid[] = "Chozhan";
//password of your WPA Network
char pass[] = "chozhan0n";

#include "BluetoothSerial.h"
BluetoothSerial ESP_BT;
String value = "";
int i_value, tot, avg;

void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid, pass);
  Serial.println("Wifi paired");
  ESP_BT.begin("Bluetooth Begin");
//  if (WiFi.status() != WL_CONNECTED) {
//    Serial.println("Couldn't get a wifi connection");
//    while (true);
//  }
  Serial.println("Bluetooth Device is Ready to Pair");
}

void loop() {
  long rssi = WiFi.RSSI();
  Serial.print("RSSI:");
  Serial.println(rssi);
  if (ESP_BT.available())  {
    for (int i = 0; i < 10; i++) {
      ESP_BT.readStringUntil('\n');
      value = ESP_BT.readStringUntil('\n');
      //      Serial.println(value);
      i_value = value.toInt();  
      //      Serial.println(i_value);
      tot = tot + i_value;
    }
  }
  Serial.print("Total : ");
  Serial.println(tot);
  avg = tot / 10;
  Serial.print("Average : ");
  Serial.println(avg);
  delay(1000);
  value = "";
  i_value = 0;
  tot = 0;
  avg = 0;
}
