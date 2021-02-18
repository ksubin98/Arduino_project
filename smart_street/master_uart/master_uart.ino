#include <SoftwareSerial.h>

#include <LiquidCrystal_I2C.h>

#include <Wire.h> 
#define sv 8  

LiquidCrystal_I2C lcd(0x27,20, 4);

SoftwareSerial mySerial(12,13);


const int led = 7;
const int led_Y = 8;

byte c;

void setup() {
  Wire.begin();  
  mySerial.begin(9600); 
  Serial.begin(9600); 
//  lcd.init(); //초기화
  lcd.backlight(); //배경불켜기
  pinMode(led, OUTPUT);
  pinMode(led_Y, OUTPUT);
  
  }
  
 void loop() { 
   if(mySerial.available()>0) {
  c = mySerial.read();
  Serial.write(c);
  Serial.write("\n");
  
  
  if( c == '1' ){
    Serial.write("신고가 들어왔습니다");
    digitalWrite(led, HIGH);

  }

  else if(c == '2'){
     Serial.write("신고가 들어왔습니다");
     digitalWrite(led_Y, HIGH);

  }
  
  else {
    digitalWrite(led, LOW);
    digitalWrite(led_Y, LOW);
  }
 }
    
    Wire.requestFrom(sv, 1);
    while(Wire.available()) {
      
      byte c = Wire.read();  

      if (c == 10) {
        lcd.setCursor(0, 0); 
        lcd.print("There's a fire in Area-A of School!"); // 학교의 A구역에서 화재 발생
        digitalWrite(led, HIGH);
        
      }
      
      if (c == 20) {
      lcd.setCursor(0, 0);         // 학교의 B구역에서 화재 발생
      lcd.print("There's a fire in Area-B of School!");
      digitalWrite(led, HIGH);
        
      }
 
      if (c == 30) {
        lcd.setCursor(0, 0); 
        lcd.print("There's a fire in Area-C of School!");  // 학교의 C구역에서 화재 발생
        digitalWrite(led, HIGH);
        
      }
      

      if (c == 40) {
        lcd.setCursor(0, 0);   // 학교의 D구역에서 화재 발생
        lcd.print("There's a fire in Area-D of School!");
        digitalWrite(led, HIGH);
        
      }
      
      if (c == 50) {
        lcd.setCursor(0, 0);   // 학교의 A, B구역에서 화재 발생
        lcd.print("There's a fire in Area-A, B of School!");
        digitalWrite(led, HIGH);
        
      }

      if (c == 60) {
        lcd.setCursor(0, 0);   // 학교의 C, D구역에서 화재 발생
        lcd.print("There's a fire in Area-C, D of School!");
        digitalWrite(led, HIGH);
       
      }

      if (c == 70) {
        lcd.setCursor(0, 0);   // 학교의 A, C구역에서 화재 발생
        lcd.print("There's a fire in Area-A, C of School!");
        digitalWrite(led, HIGH);
        
      }

      if (c == 80) {
        lcd.setCursor(0, 0);   // 학교의 B, D구역에서 화재 발생
        lcd.print("There's a fire in Area-B, D of School!");
        digitalWrite(led, HIGH);
        
      }

      if (c == 90) {
        lcd.setCursor(0, 0);   // 학교에서 화재 발생
        lcd.print("There's a fire in School!");
        digitalWrite(led, HIGH);
        
      }

      if (c == 100) {
         
        digitalWrite(led, LOW);

      }
      
       
      delay(1000);
      lcd.clear();
    
    }
  }
