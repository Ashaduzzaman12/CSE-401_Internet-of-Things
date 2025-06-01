const int regPin = A0;
const int ledPin = 13;
int sensorValue = 0;
void setup()
{
 pinMode(regPin, INPUT);
 pinMode(ledPin, OUTPUT);
}
void loop()
{
 sensorValue = analogRead(regPin);
 digitalWrite(ledPin, HIGH);
 delay(sensorValue);
 digitalWrite(ledPin, LOW);
 delay(sensorValue);
}
