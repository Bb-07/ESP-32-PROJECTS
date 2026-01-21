#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0X27,16,2);

const int trigpin =12;
const int echopin =13;

int led1 = 15;
int led2 = 2;
int led3 = 4;
int led4 = 16;
int led5 = 17;

int buzzer = 14;

void setup() 
{
 pinMode(trigpin, OUTPUT);
 pinMode(echopin, INPUT);
 lcd.init(); 
 lcd.backlight();
 pinMode(led1, OUTPUT);
 pinMode(led2, OUTPUT);
 pinMode(led3, OUTPUT);
 pinMode(led4, OUTPUT);
 pinMode(led5, OUTPUT);
 pinMode(14, OUTPUT);
}

void loop() 
{
  digitalWrite(trigpin, LOW);
  delayMicroseconds(2);

  digitalWrite(12, HIGH);
  delayMicroseconds(10);
  digitalWrite(12,0); 
  long duration = pulseIn(echopin,1);
  int distance =(duration/2)*0.0343;

  if(distance<10)
  {
    digitalWrite(led5, HIGH);
    digitalWrite(14, HIGH);
    digitalWrite(led4,0);
    digitalWrite(led3,0);
    digitalWrite(led2,0);
    digitalWrite(led1,0);
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("water level");
    lcd.setCursor(12,0);
    lcd.print(distance);
  }

  else if(distance<30)
  {
    digitalWrite(led5, HIGH);
    digitalWrite(14,0);
    digitalWrite(led4,1);
    digitalWrite(led3,0);
    digitalWrite(led2,0);
    digitalWrite(led1,0);
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("water level");
    lcd.setCursor(12,0);
    lcd.print(distance);
  }

  else if(distance<50)
  {
    digitalWrite(led5, HIGH);
    digitalWrite(14,0);
    digitalWrite(led4,1);
    digitalWrite(led3,1);
    digitalWrite(led2,0);
    digitalWrite(led1,0);
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("water level");
    lcd.setCursor(12,0);
    lcd.print(distance);
  }

  else
  {
    digitalWrite(led5, HIGH);
    digitalWrite(14,0);
    digitalWrite(led4,1);
    digitalWrite(led3,1);
    digitalWrite(led2,1);
    digitalWrite(led1,1);
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("water level");
    lcd.setCursor(12,0);
    lcd.print(distance);
  }
  delay(500);
}
