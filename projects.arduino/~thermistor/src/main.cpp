#include <Arduino.h>


#define tempPin A0
// resistance at 25 degrees C
#define THERMISTORNOMINAL 10000.0
// temp. for nominal resistance (almost always 25 C)
#define TEMPERATURENOMINAL 25
// The beta coefficient of the thermistor (usually 3000-4000)
#define BCOEFFICIENT 3100
// the value of the 'other' resistor
#define SERIESRESISTOR 10000.0  
#define NUM_SAMPLES 5

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  float sum = 0.0;
  for(int i = 0; i < NUM_SAMPLES; i++){
   sum+= analogRead(tempPin);
   delay(10);
  }
  
  float raw = sum / NUM_SAMPLES;
  float res = 1023 / raw - 1;
  res = SERIESRESISTOR / res;
  float steinhart = log(res/ THERMISTORNOMINAL ) / BCOEFFICIENT;
  float k = 1.0 / (steinhart + 1.0 / (TEMPERATURENOMINAL + 273.15));
  float c = k - 273.15;
  
  Serial.print(raw);
  Serial.print("   ");
  Serial.print(res);
  Serial.print("   ");
  Serial.print(k);
  Serial.print("   ");
  Serial.println(c);
  delay(2000);
  }