const int sensorPin = A0;
const int ledPin = 9;
int lightVal;

void setup()
{
  pinMode(ledPin, OUTPUT);
  pinMode(sensorPin, OUTPUT);
  
}

void loop()
{
  lightVal = analogRead(sensorPin);
  if(lightVal<50){
    digitalWrite(ledPin,HIGH);
  }
  else{
    digitalWrite(ledPin,LOW);
  }
  
}
