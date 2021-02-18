#include <SoftwareSerial.h>

SoftwareSerial mySerial(12,13);

const int button = 10;
const int button2 = 11;

const int led=2; //검
const int led2=5;//파 

const int light=1;

const int trig=3;
const int echo=4;

const int trig2=8;
const int echo2=9;

int val=0;
int val2=0;

long T,T2,L, L2;


void setup() {
  mySerial.begin(9600);
  Serial.begin(9600);
//  Wire.onRequest(requestEvent);
  pinMode(button, INPUT);
  pinMode(button2, INPUT);

  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  
  pinMode(trig2, OUTPUT);
  pinMode(echo2, INPUT);

  pinMode(led, OUTPUT);
  pinMode(led2, OUTPUT);
}

void loop() {
  delay(100);

  digitalWrite(trig, LOW); delayMicroseconds(2);
  digitalWrite(trig, HIGH); delayMicroseconds(10);
  digitalWrite(trig, LOW);
  T = pulseIn(echo, HIGH);

  
  digitalWrite(trig2, LOW); delayMicroseconds(2);
  digitalWrite(trig2, HIGH); delayMicroseconds(10);
  digitalWrite(trig2, LOW);
  T2 = pulseIn(echo2, HIGH);


if(digitalRead(button) == HIGH &&digitalRead(button2) == LOW){
    mySerial.write('1');
  
  }
  else if(digitalRead(button) == LOW && digitalRead(button2) == HIGH){
    mySerial.write('2');
 
  }
else {
    mySerial.write('0');
  }
  
  
  
  val = analogRead(light);
  
  int sensor_V = map(val, 30, 700, 0, 255);
  int sensor_V2 = map(val, 0, 800, 255, 0);
  
  L = T/58.82;
  L2 = T2/58.82;

  
if(100<=val && val<=350){

   if (L2 >= 0 && L2 <= 10)
    digitalWrite(led2, HIGH);
    
   if(L >= 0 && L <= 10)//사람 있을 때  
    digitalWrite(led, HIGH);
    
  
  else if(250<val && val<=350){
    digitalWrite(led, sensor_V2);
    digitalWrite(led2, sensor_V2);
  
  }
  else{
    digitalWrite(led, sensor_V);
    digitalWrite(led2, sensor_V);
    
  }
  }
  else if(val < 100) {

  
   
    if(L>= 0 && L <= 10)//사람 있을 때  
      digitalWrite(led, HIGH);
      
    
    else{

      if(L2 >= 0 && L2 <= 10){
        digitalWrite(led2, HIGH);
      } else
        digitalWrite(led2, LOW);

      
      digitalWrite(led,LOW);
      
      
    }

  
  }

   
  Serial.print(L);
  Serial.print(", ");
  Serial.print(L2);
  Serial.print(", ");
  Serial.println(val);

}
