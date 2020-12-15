#include<LiquidCrystal.h>
LiquidCrystal lcd(10,9,8,7,6,5);
int incomingByte = 0;//for incoming serial data:
int relaypin1 = 13; 
int relaypin2 = 12;
int relaypin3 = 11;
void setup() {
  pinMode(relaypin1,OUTPUT);
  pinMode(relaypin2,OUTPUT);
  pinMode(relaypin3,OUTPUT);
  Serial.begin(9600);//opens serial port , sets data rate to 9600bps:
  lcd.begin(16,4);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("WELCOME");

}

void loop() {
  //send data when you only recieve data:
  if(Serial.available()>0) {
    incomingByte = Serial.read();
    if(incomingByte == 1){
      lcd.setCursor(0,1);
      lcd.print("Lamp1 IS ON");
      digitalWrite(relaypin1,HIGH);
    }
    else if (incomingByte == 2){
      lcd.setCursor(0,1);
      lcd.print("FAN IS ON");
      digitalWrite(relaypin2,HIGH);
    }
    else if (incomingByte == 3){
      lcd.setCursor(0,1);
      lcd.print("LAMP IS ON");
      digitalWrite(relaypin3,HIGH);
    }
    else
    {
      lcd.setCursor(0,1);
      lcd.print("press button");
      digitalWrite(relaypin1,LOW);
      digitalWrite(relaypin2,LOW);
      digitalWrite(relaypin3,LOW);
    }
  }
}
