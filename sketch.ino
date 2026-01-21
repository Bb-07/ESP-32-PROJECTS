#include <ESP32Servo.h>
#include <LiquidCrystal_I2C.h>
Servo myservo;
LiquidCrystal_I2C lcd(0x27,16,2);

const int pirpin =13;
const int servopin = 19;

void setup() 
{
 pinMode(pirpin, INPUT);
 Serial.begin(115200);
 myservo.attach(servopin);
 myservo.write(0);
 lcd.init();
 lcd.backlight();
}

void loop() 
{
  int pirvalue = digitalRead(pirpin);
  Serial.println(pirvalue);

  if(pirvalue=HIGH)
  {
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("PIR value");
    lcd.setCursor(12,0);
    lcd.print(pirvalue);
    lcd.setCursor(0,1);
    lcd.print("SERVO ON 180");
    myservo.write(180);
    delay(2000);
  }

  else
  {
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("PIR Value");
    lcd.setCursor(12,0);
    lcd.print(pirvalue);
    lcd.setCursor(0,1);
    lcd.print("SERVO ON 0");
    myservo.write(0);

  }
delay(500);
}
