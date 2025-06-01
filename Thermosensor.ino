// C++ code
//
const int LM35pin=A0;
float val,data;
void setup()
{
  pinMode(LM35pin, INPUT);
  Serial.begin(9600);

}

void loop()
{
  val=analogRead(LM35pin);
  data=(val*5)/10;
  Serial.print("Temperature in celcius:");
  Serial.print(data);
  Serial.println("C");
  float fer ,kel;
  fer= (data*1.8)+32;
  kel=data+273.13;
  Serial.print("Temperature in Farenheight:");
  Serial.print(fer);
  Serial.println("F");
  Serial.print("Temperature in Kelvin:");
  Serial.print(kel);
  Serial.println("k");
  delay(1000);
}
