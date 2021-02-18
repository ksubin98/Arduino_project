const int led=5;
const int button = 3;
const int button2 = 4;

void setup() {
//  Wire.begin(sv);
  Serial.begin(9600);
 // Wire.onRequest(requestEvent);
  pinMode(button, INPUT);
  pinMode(button2, INPUT);
  pinMode(led, OUTPUT);

}

void loop() {
 if(digitalRead(button) || digitalRead(button2) ==HIGH){
  digitalWrite(led, HIGH);
 }
 else
  digitalWrite(led,LOW);
}
  
