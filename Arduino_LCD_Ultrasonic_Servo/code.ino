#include <Servo.h>

#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2);

const int TRIGPIN = 8;          
const int ECHOPIN = 9;
long timer;
int jarak;

 
Servo myservo;

void setup() {
  lcd.init();
  lcd.clear();
  lcd.backlight();
  
  pinMode(ECHOPIN, INPUT);
  pinMode(TRIGPIN, OUTPUT);

  myservo.attach(7);
   
}

void loop() {
  digitalWrite(TRIGPIN, LOW);                   
  delayMicroseconds(2);
  digitalWrite(TRIGPIN, HIGH);                  
  delayMicroseconds(10);
  digitalWrite(TRIGPIN, LOW);                   

  timer = pulseIn(ECHOPIN, HIGH);
  jarak = timer/58;
  
  lcd.setCursor(0,0);
  lcd.print("Measurement");

  
  lcd.setCursor(0,1);
  lcd.print("Jarak : ");
  lcd.print(jarak);
  lcd.print(" cm");

  
  if(jarak < 100){
  	 myservo.write(180);
    delay(500);
    myservo.write(-180);
    delay(500);
  }
  
}

