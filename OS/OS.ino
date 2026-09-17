#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2);

// Pins
const int buzzer = 11;
const int ledPins[] = {6,7,8,9};

// Happy Birthday Melody
int melody[]={
392,392,440,392,523,494,
392,392,440,392,587,523,
392,392,784,659,523,494,440,
698,698,659,523,587,523
};

int noteDurations[]={
4,8,4,4,4,2,
4,8,4,4,4,2,
4,8,4,4,4,4,2,
4,8,4,4,4,2
};

void setup()
{
  lcd.init();
  lcd.backlight();

  pinMode(buzzer,OUTPUT);

  for(int i=0;i<4;i++)
    pinMode(ledPins[i],OUTPUT);
}

void loop()
{
  // Simulated Time
  int hr=11;
  int min=59;
  int sec=50;

  while(true)
  {
    lcd.clear();

    lcd.setCursor(0,0);
    lcd.print("Current Time");

    lcd.setCursor(2,1);

    if(hr<10) lcd.print("0");
    lcd.print(hr);
    lcd.print(":");

    if(min<10) lcd.print("0");
    lcd.print(min);
    lcd.print(":");

    if(sec<10) lcd.print("0");
    lcd.print(sec);

    if(hr==11)
      lcd.print(" PM");
    else
      lcd.print(" AM");

    delay(1000);

    sec++;

    if(sec>=60)
    {
      sec=0;
      min++;
    }

    if(min>=60)
    {
      min=0;
      hr=12;
    }

    if(hr==12 && min==0 && sec==0)
      break;
  }

  // Midnight
  lcd.clear();
  lcd.setCursor(2,0);
  lcd.print("12:00:00 AM");

  lcd.setCursor(0,1);
  lcd.print("Happy Birthday");

  delay(2000);

  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Happy Birthday");
  lcd.setCursor(4,1);
  lcd.print("Lokesh");

  delay(1000);

  // Melody + LEDs
  for(int i=0;i<25;i++)
  {
    int noteTime=1000/noteDurations[i];

    tone(buzzer,melody[i],noteTime);

    for(int j=0;j<4;j++)
      digitalWrite(ledPins[j],LOW);

    digitalWrite(ledPins[i%4],HIGH);

    delay(noteTime);

    noTone(buzzer);

    digitalWrite(ledPins[i%4],LOW);

    delay(60);
  }

  // Celebration Flash
  for(int k=0;k<12;k++)
  {
    for(int i=0;i<4;i++)
      digitalWrite(ledPins[i],HIGH);

    delay(150);

    for(int i=0;i<4;i++)
      digitalWrite(ledPins[i],LOW);

    delay(150);
  }

  lcd.clear();
  lcd.setCursor(1,0);
  lcd.print("Have A Great");

  lcd.setCursor(5,1);
  lcd.print("Day!");

  delay(5000);
}