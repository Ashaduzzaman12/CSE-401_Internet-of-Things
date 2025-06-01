const int buttonPin=3;
const int ledPin=13;
int buttonStatus=0;

void setup()
{
  pinMode(buttonPin,INPUT);
  pinMode(ledPin,OUTPUT);
}

void loop()
{
 buttonStatus=digitalRead(buttonPin);
  if(buttonStatus==HIGH){
    digitalWrite(ledPin,HIGH);
  }
  else{
    digitalWrite(ledPin,LOW);
  }
}
