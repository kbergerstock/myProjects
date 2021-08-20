#include <Arduino.h>

#define LED_PIN 2

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

void setup() {
  // put your setup code here, to run oh
  pinMode(LED_PIN,OUTPUT);
  digitalWrite(LED_PIN, HIGH);
  myTimer.reset();
}

void loop() {
  // put your main code here, to run repeatedly:
  if(myTimer.elapsedTime() >= 500)
    {
        myTimer.reset();
        digitalWrite(LED_PIN, digitalRead(LED_PIN) ^ 1);
    }
}