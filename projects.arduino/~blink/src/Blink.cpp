/*
  Blink
  Turns on an LED on for one second, then off for one second, repeatedly.

  Most Arduinos have an on-board LED you can control. On the Uno and
  Leonardo, it is attached to digital pin 13. If you're unsure what
  pin the on-board LED is connected to on your Arduino model, check
  the documentation at http://www.arduino.cc

  This example code is in the public domain.

  modified 8 May 2014
  by Scott Fitzgerald
 */

#include <Arduino.h>

#define PULSE 250

typedef const char* const string;

class Timer
{
  private:
    unsigned long ts;
  public:  
    void reset()
    {
      ts = millis();
    } 
    int elapsedTime()
    {
     return millis() - ts; 
    }
};

Timer myTimer;
string cmds[] =
{
  "AT+NAME?",
  "AT+MAC?",
  "AT+EXIT",
};

#define nCMDS 3

// the setup function runs once when you press reset or power the board
void setup() {
  myTimer.reset();
  // initialize digital pin 13 as an output.
  pinMode(LED_BUILTIN, OUTPUT);
  //initial the Serial
  Serial.begin(115200);  
  for(int i = 0; i < nCMDS; i++){
    Serial.println(cmds[i]);
    Serial.println(Serial.read());
  }
}

int led = HIGH;
// the loop function runs over and over again forever
void loop() {
  if(myTimer.elapsedTime() > PULSE) {
    digitalWrite(LED_BUILTIN, led);   // turn the LED on (HIGH is the voltage level)
    led = led ^ HIGH;
    myTimer.reset();
  }

 
  if (Serial.available())  {
    Serial.println(Serial.read());//send what has been received
  }
}
