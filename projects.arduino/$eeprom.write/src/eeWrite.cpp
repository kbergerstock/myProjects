// initializes the eeprom with net IP settings

#include <Arduino.h>
#include <IPAddress.h>
#include <EEPROM.h>

void setup() {
  // put your setup code here, to run once:
  byte mac[] = {0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };
  IPAddress ip(192, 168, 1, 177);
  IPAddress dns(192, 168, 1, 1);
  IPAddress gateway(192, 168, 1, 1);
  IPAddress subnet(255, 255, 0, 0);
  byte port = 23;

  EEPROM.put(0,ip);
  EEPROM.put(4,dns);
  EEPROM.put(8,gateway);
  EEPROM.put(12,subnet);
  EEPROM.put(16,mac);
  EEPROM.put(23,port);
  
}

void loop() {
  // put your main code here, to run repeatedly:

}
