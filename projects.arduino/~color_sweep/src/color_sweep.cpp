#include "Arduino.h"

// color drivers pin definitions
#define BLUE  3
#define GREEN 5
#define RED   6

// module to display all colors
void color_sweep(){
  int r,g,b;
  for(b = 0; b < 256; b++) {
    analogWrite(BLUE,b);
    for(g = 0; g < 256; g++){
      analogWrite(GREEN,g);
      for(r = 0; r < 256; r++){
        analogWrite(RED,r);
        delay(10);
      }
    }
  }
}

void setup() {
  // put your setup code here, to run once:
  pinMode(RED,OUTPUT);
  pinMode(GREEN,OUTPUT);
  pinMode(BLUE,OUTPUT);
  digitalWrite(RED,LOW);
  digitalWrite(GREEN,LOW);
  digitalWrite(BLUE,LOW);

  }

void loop() {
 // put your main code here, to run repeatedly:
  color_sweep();
}
