#include "SR04.h"
#define TRIG_PIN 12
#define ECHO_PIN 11

#define RED_LED 5
#define YELLOW_LED 6
#define GREEN_LED 7
#define NO_DISTANCE 0

SR04 sr04 = SR04(ECHO_PIN,TRIG_PIN);
long distance;

void setup() {
   Serial.begin(9600);
   delay(1000);
   pinMode(RED_LED, OUTPUT);
   pinMode(YELLOW_LED, OUTPUT);
   pinMode(GREEN_LED, OUTPUT);
}

void loop() {
   distance = sr04.Distance();
   
   if (distance < 20) {
    lightSignal(RED_LED);
   } else if(distance < 40) {
    lightSignal(YELLOW_LED);
   } else if (distance < 60) {
    lightSignal(GREEN_LED);
   } else {
    lightSignal(NO_DISTANCE);
   }
}

void lightSignal(int led){
  digitalWrite(RED_LED, LOW);
  digitalWrite(YELLOW_LED, LOW);
  digitalWrite(GREEN_LED, LOW);
  if (led != NO_DISTANCE) digitalWrite(led, HIGH);
}
