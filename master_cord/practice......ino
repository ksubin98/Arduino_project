#include <SoftwareSerial.h>
#include <LiquidCrystal_I2C.h>
#include <Wire.h>

LiquidCrystal_I2C lcd(0x27, 20, 4);
SoftwareSerial mySerial(12, 13);
byte c; // data from uart
byte b; // data from i2c


#define sv 8
const int led = 7;


unsigned long lcd_timer = 0;
bool lcd_flag = false;


unsigned long req_timer = 0;

void setup()
{
  Wire.begin();
  mySerial.begin(9600);
  Serial.begin(9600);
  
  lcd.begin();         //초기화
  lcd.backlight();    //배경불켜기
  
  pinMode(led, OUTPUT);

  lcd_timer = millis();
}

void loop(){

  if (mySerial.available()){

    Serial.println("debug serial");
    
    c = mySerial.read();
    Serial.write(c);
    Serial.write("\n");

    if (c == '1'){
      Serial.println("신고가 들어왔습니다");
      digitalWrite(led, HIGH);
      lcd.setCursor(0, 0);
      lcd.print("Report from streetlight 1!");
    }
    else if (c == '2'){
      Serial.println("신고가 들어왔습니다");
      digitalWrite(led, HIGH);
      lcd.setCursor(0, 0);
      lcd.print("Report from streetlight 2!");
    }
    else{
      digitalWrite(led, LOW);
    
    }

    lcd_timer = millis();
    lcd_flag = true;
  }


  if(millis() - req_timer > 2000){
    Serial.println("debug request data");

    lcd.clear();
    req_timer = millis();
    Wire.requestFrom(sv, 1);  // data request function
  }

  
  // while(Wire.available()) {
  if (Wire.available()){

    Serial.println("debug I2C");
    
    // byte c = Wire.read();  
    b = Wire.read();

    if (b == 10){
      lcd.setCursor(0, 0);
      lcd.print("There's a fire in Area-A of School!"); // 학교의 A구역에서 화재 발생
      digitalWrite(led, HIGH);
    }
    else if (b == 20){
      lcd.setCursor(0, 0); // 학교의 B구역에서 화재 발생
      lcd.print("There's a fire in Area-B of School!");
      digitalWrite(led, HIGH);
    }
    else if (b == 30){
      lcd.setCursor(0, 0);
      lcd.print("There's a fire in Area-C of School!"); // 학교의 C구역에서 화재 발생
      digitalWrite(led, HIGH);
    }
    else if (b == 40){
      lcd.setCursor(0, 0); // 학교의 D구역에서 화재 발생
      lcd.print("There's a fire in Area-D of School!");
      digitalWrite(led, HIGH);
    }
    else if (b == 50){
      lcd.setCursor(0, 0); // 학교의 A, B구역에서 화재 발생
      lcd.print("There's a fire in Area-A, B of School!");
      digitalWrite(led, HIGH);
    }
    else if (b == 60){
      lcd.setCursor(0, 0); // 학교의 C, D구역에서 화재 발생
      lcd.print("There's a fire in Area-C, D of School!");
      digitalWrite(led, HIGH);
    }
    else if (b == 70){
      lcd.setCursor(0, 0); // 학교의 A, C구역에서 화재 발생
      lcd.print("There's a fire in Area-A, C of School!");
      digitalWrite(led, HIGH);
    }
    else if (b == 80){
      lcd.setCursor(0, 0); // 학교의 B, D구역에서 화재 발생
      lcd.print("There's a fire in Area-B, D of School!");
      digitalWrite(led, HIGH);
    }
    else if (b == 90){
      lcd.setCursor(0, 0); // 학교에서 화재 발생
      lcd.print("There's a fire in School!");
      digitalWrite(led, HIGH);
    }
    else if (b == 100){
      digitalWrite(led, LOW);
    }
    lcd_timer = millis();
    lcd_flag = true;
    
    // delay(1000);
    // lcd.clear();
  }
}
