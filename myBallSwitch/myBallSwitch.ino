#define ledPin 13

void setup(){ 
  pinMode(ledPin, OUTPUT);
  pinMode(2, INPUT);
  digitalWrite(2, HIGH);
} 

void loop() 
{ 
  digitalRead(2) == HIGH ? digitalWrite(ledPin, LOW) : digitalWrite(ledPin, HIGH);
}
