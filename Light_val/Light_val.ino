const int Light = 1;
int val = 0;

void setup() {
 Serial.begin(9600);

}

void loop() {
 val = analogRead(Light);

 Serial.println(val);

}
