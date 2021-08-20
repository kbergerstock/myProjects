#include <Arduino.h>
#include <stepper.h>
const int steps = 64;
const int stepsPerRevolution = 2048;

Stepper stepper(steps,8,10,9,11);

void setup() {
  // put your setup code here, to run once:
  stepper.setSpeed(500);
};

void loop() {
  // put your main code here, to run repeatedly: 

  stepper.step(1024);
  int cnts[] = {1024,-512,1024,-512,1024} ;
  for (int i = 0; i < 5; i++){
    stepper.step(cnts[i]);
    delay(5);
  }

}