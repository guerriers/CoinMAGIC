#include <LiquidCrystal_I2C.h>
#include <Wire.h> 
LiquidCrystal_I2C lcd(0x27, 16, 2);
int test1b;
int test5b;
int test10b;
int b10 = 0;
int b5 = 0;
int b1 = 0;
int total = 0;
int total10 = 0;
int total5 = 0;
int total1 = 0;
//int t10 = 10;
//int t5 = 5;
//int t1 = 1;

void setup() {
Serial.begin(9600);
pinMode(A2,INPUT);
pinMode(A1,INPUT);
pinMode(A0,INPUT);
pinMode(2,INPUT);
pinMode(13,OUTPUT);
pinMode(12,OUTPUT);
pinMode(11,OUTPUT);
digitalWrite(11,LOW);
digitalWrite(12,LOW);
digitalWrite(13,LOW);
lcd.begin ();
lcd.setCursor(0, 0);
lcd.print("Savings");
lcd.setCursor(0, 1);
lcd.print("^ ^");
lcd.backlight();
delay(2000);
lcd.clear();
lcd.setCursor(0, 0);
lcd.print("^ ^");
lcd.setCursor(0, 1);
lcd.print("TOTAL : ");
lcd.setCursor(7, 1);
lcd.print(total);
}

void loop() {
  test1b = analogRead(A2);
  test5b = analogRead(A0);
  test10b= analogRead(A1);
  
//Serial.println(test1b);
//Serial.println(test5b);
//Serial.println(test10b);
//Serial.println(total);
  if(test10b > 100){
    b10 = 1;
    }
  if(test5b > 100){
    b5 = 1;
    }
  if(test1b >110 ){
    b1 = 1;
    }

    
  if(b10 == 1){
    digitalWrite(11,HIGH);
    delay(100);
    digitalWrite(11,LOW);
    b10 = 0;
    b5= 0;
    b1 = 0;
    total10 = total10 + 10;
    total = total + 10;
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("COIN10:");
    lcd.setCursor(7,0);
    lcd.print(total10);
    lcd.setCursor(0, 1);
    lcd.print("TOTAL : ");
    lcd.setCursor(7, 1);
    lcd.print(total);
    Serial.println(10);
    delay(200);
    }
    
    if(b5 == 1){
    digitalWrite(12,HIGH);
    delay(100);
    digitalWrite(12,LOW);
    b10 = 0;
    b5= 0;
    b1 = 0;
    total5 = total5 + 5;
    total = total + 5;
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("COIN5 :");
    lcd.setCursor(7,0);
    lcd.print(total5);
    lcd.setCursor(0, 1);
    lcd.print("TOTAL : ");
    lcd.setCursor(7, 1);
    lcd.print(total);
    Serial.println(5);
    delay(200);
    
    }
    if(b1 == 1  ){
    digitalWrite(13,HIGH);
    delay(100);
    digitalWrite(13,LOW);
    b10 = 0;
    b5= 0;
    b1 = 0;
    total1 = total1 + 1;
    total = total + 1;
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("COIN1 :");
    lcd.setCursor(7,0);
    lcd.print(total1);
    lcd.setCursor(0, 1);
    lcd.print("TOTAL : ");
    lcd.setCursor(7, 1);
    lcd.print(total);
    Serial.println(1);
    delay(200);
    
    }
}