#include "BluetoothSerial.h"
BluetoothSerial ESP_BT;
String value = "";
int i_value, tot, avg;

void setup() {
  Serial.begin(115200);
  ESP_BT.begin("Follow Me Robot Mark-2");
  Serial.println("Bluetooth Device is Ready to Pair");
}

void loop() {
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
