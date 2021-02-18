#include <SoftwareSerial.h>

SoftwareSerial notify(5,6);
const int button = 7;

void setup() {
  pinMode(button, INPUT);
  notify.begin(9600);
}

void loop() {
  if(digitalRead(button) == HIGH){
    notify.write("1");
    //notify.write("buzzer on");
    delay(100);
    }
  else{
    notify.write("0");
    //notify.write("buzzer off");
    delay(100);
  }


}
