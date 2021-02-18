#include <Wire.h>
#define sv 9


void setup() {
 Wire.begin(sv);
 Wire.onRequest(requestEvent);
 Serial.begin(9600);

}

void loop() {
 delay(100);
 
}

void requestEvent(){
  Wire.write("hello ");
}
