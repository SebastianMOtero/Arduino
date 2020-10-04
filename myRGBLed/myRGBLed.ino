// Define Pins
#define BLUE 3
#define GREEN 5
#define RED 6
#define delayTime 1000

void setup(){
  pinMode(RED, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(BLUE, OUTPUT);
  digitalWrite(RED, HIGH);
  digitalWrite(GREEN, LOW);
  digitalWrite(BLUE, LOW);
}
 
int rainbowColorsRGB[7][3] = {
  {255, 0, 0},   //red
  {150, 20, 0},  //orange
  {255, 150, 0}, //yellow
  {0, 255, 0},   //green
  {0, 255, 255}, //cyan
  {0, 0, 255},   //blue
  {75, 0, 130}   //violet
};
  
void loop(){
  for(int i = 0; i < 7; i ++) {
    analogWrite(RED, rainbowColorsRGB[i][0]);
    analogWrite(GREEN, rainbowColorsRGB[i][1]);
    analogWrite(BLUE, rainbowColorsRGB[i][2]);
    delay(delayTime);
  }
}
