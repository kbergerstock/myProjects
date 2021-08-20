#include <Arduino.h>

volatile int __pulse = 500;
volatile int __cnt = 0;

ISR(TIMER2_OVF_vect){
  __cnt++;
  if (__cnt >= __pulse)
  {
    __cnt = 0;
    digitalWrite(LED_BUILTIN,digitalRead(LED_BUILTIN)^1);
  }
  TCNT2 = 5;
}

void setup() {
  // put your setup code here, to run once:
  // initialize digital pin 13 as an output.
  pinMode(LED_BUILTIN, OUTPUT);
  // initialize timer 2
  noInterrupts();
  TCCR2A = 0x00;
  TCCR2B = 0X00;
  TCNT2 = 0X05;
  // set prescaler to 64
  TCCR2B = (1<<CS11) | (1<<CS10);
  TIMSK2 = (1<<TOIE2);

  interrupts();
}

void loop() {
  // put your main code here, to run repeatedly:
}