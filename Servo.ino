#include<Servo.h>

Servo myservo;
int pos = 1;    

void setup() {
  myservo.attach(10);  
}
void loop() {
  
  for (pos = 0; pos <= 180; pos += 5) { 
    if(pos==80){
      delay(1500);
    }
    myservo.write(pos);              
    delay(10);                       
  }
  delay(1500);
  for (pos = 180; pos >= 0; pos -= 10) { 
    myservo.write(pos);              
    delay(10);                       
  }
  delay(1500);
}
