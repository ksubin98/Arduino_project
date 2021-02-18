#include <Wire.h>
#define sv 9

const int led = 7;

void setup() {
  Wire.begin();
  Serial.begin(9600);
  pinMode(led, OUTPUT);
  

}

void loop() {
  Wire.requestFrom(sv,6);

 while(Wire.available()){
    char c = Wire.read();
    if(c=='1' || c == '2'){
      digitalWrite(led, HIGH);
    }
  }
  delay(500);

}
