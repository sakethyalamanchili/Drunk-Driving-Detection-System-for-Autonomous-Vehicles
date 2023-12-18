#include <LiquidCrystal.h>
LiquidCrystal lcd(6,7,8,9,10,11);
  
int redled = 2;
int greenled = 3;
int buzzer = 4;
int sensor = A0;
int sensorThresh = 400; //threshold value for drunk
int motor = 5;

void setup()
{
pinMode(redled, OUTPUT);
pinMode(greenled,OUTPUT);
pinMode(buzzer,OUTPUT);
pinMode(sensor,INPUT);
pinMode(motor,OUTPUT);
Serial.begin(9600);
lcd.begin(16,2);
}

void loop()
{
  int analogValue = analogRead(sensor);//value read by gas sensor
  Serial.print(analogValue);
  Serial.println( );
  
  if(analogValue>sensorThresh)//condition if drunk
  {
    digitalWrite(redled,LOW);
    digitalWrite(greenled,HIGH);
    digitalWrite(buzzer,HIGH);
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("ALCOHOL DETECTED.");
    delay(1000);
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("ALERT!");
    delay(500);
    lcd.setCursor(0,1);
    lcd.print("STOPPING CAR...  ");
    delay(1000);
    lcd.clear();
    digitalWrite(motor,LOW);
    delay(5000);
  }
  else//condition if safe
  {
    digitalWrite(greenled,LOW);
    digitalWrite(redled,HIGH);
    digitalWrite(motor,HIGH);
    digitalWrite(buzzer,LOW);
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("SAFE");
    delay(1000);
    lcd.clear();
    delay(1000);
  }  
     
}