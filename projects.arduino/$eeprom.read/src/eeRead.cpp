/*
 * EEPROM Read
 *
 * Reads the value of each byte of the EEPROM and prints it
 * to the computer.
 * This example code is in the public domain.
 */

#include<Arduino.h>
#include <EEPROM.h>

// start reading from the first byte (address 0) of the EEPROM
int address = 0;
byte value;

void setup() {
  // initialize serial and wait for port to open:
  Serial.begin(115200);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }
    int i,j;
    for(i = 0; i < 4; i++) {
      for(j = 0; j < 8; j++)
      {
        Serial.print(value, HEX);
        Serial.print(" ");
        value = EEPROM.read(address);
        address++;
        }
    Serial.println("");
  }
}

void loop() {

}
