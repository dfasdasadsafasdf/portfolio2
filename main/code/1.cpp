#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x20, 16, 2);


 const int gasPin = A0;
 const int ledPin = 3;
 const int soundPin = 2;
 const int treshold = 100;
 const int tmpPin = A3;
 const int turnOffPin = 5; /// голубой
 const int manualAlarmPin = 4; /// коричн
 const int disarmedPin = 6; /// зеленка
 const int temphold = 33;
 const int OFF = 0;
 const int ARMED = 1;
 const int ALARM = 2;
 const int DISARMED = 3;
 int state = OFF;
 


void setup() {
  pinMode(gasPin, INPUT);
  pinMode(soundPin, OUTPUT);
  pinMode(ledPin, OUTPUT);
  pinMode(tmpPin, INPUT);
  pinMode(4, INPUT_PULLUP);
  pinMode(5, INPUT_PULLUP);
  pinMode(6, INPUT_PULLUP);
    
  
  Serial.begin(9600);
    lcd.init();
    lcd.backlight();
}

void loop() {
  int gas = analogRead(gasPin);
  int temp = analogRead(tmpPin);
   float voltage = temp * (5.0 / 1024.0);
   float tempC = (voltage - 0.5) * 100.0;
  
 if (digitalRead(4) == LOW) {
  state = ALARM;
  delay(200); 
}


else if (digitalRead(6) == LOW) {
  if (state == OFF) {
    state = DISARMED;      
  } else if (state == ALARM) {
    state = DISARMED;      
  } else {
    state = OFF;          
  }
  delay(200);
}


else if (digitalRead(5) == LOW) {
  if (state == ALARM) {
    state = DISARMED;     
  } else if (state == DISARMED) {
    state = ARMED;       
  } else if (state == ARMED) {
    state = DISARMED;      
  }
  delay(200);
}
  
  
  if(state == OFF) { 
    digitalWrite(ledPin, LOW);
    digitalWrite(soundPin, LOW);
   
 lcd.setCursor(0, 0);
lcd.print("SYSTEM: OFF      ");
lcd.setCursor(0, 1);
lcd.print("                ");
    }

 if (state == ARMED) {
if (tempC > temphold || gas > treshold) {
    state = ALARM;
    }
   }
  
 if (state == DISARMED) {
  digitalWrite(soundPin, LOW);
  digitalWrite(ledPin, LOW);
  if (tempC > temphold || gas > treshold) {
    lcd.setCursor(0, 0);
    lcd.print("!!!  RISK !!!   ");   
    lcd.setCursor(0, 1);
    lcd.print("Check sensors   ");

  } 
  else {
    lcd.setCursor(0, 0);
    lcd.print("TEMP: ");
    lcd.print(tempC, 1);
    lcd.print(" C    ");  
    lcd.setCursor(0, 1);
    lcd.print("GAS: ");
    lcd.print(gas);
    lcd.print("     ");    

  }
}

  
  if (state == ALARM) {
    lcd.setCursor(0,0);
    lcd.print("!!! DANGER !!!  ");
    lcd.setCursor(0, 1);
    lcd.print("Fire              ");
    digitalWrite(ledPin, HIGH);
    digitalWrite(soundPin, HIGH);
   delay(500);
    digitalWrite(ledPin, LOW);
    digitalWrite(soundPin, LOW);
  }

 
Serial.println(state);


}
    

  

