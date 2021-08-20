#include <Arduino.h>
#include "wifi.h"

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  WiFi.mode(WIFI_STA);
  WiFi.disconnect();
  delay(100);
  Serial.println("wifi started");
}    

void loop() {
  // put your main code here, to run repeatedly:
  int n = WiFi.scanNetworks();
  Serial.printf("found %d networks\n",n);
  if (n > 0){
    for(int i = 0; i < n; i++){
      Serial.print(i+1);
      Serial.print("  ");
      Serial.print(WiFi.SSID(i) );
      Serial.print("  ");
      Serial.print(WiFi.RSSI(i));
      Serial.println(WiFi.encryptionType(i));
    }
  }
  delay(5000);
}
