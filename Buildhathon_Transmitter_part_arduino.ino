//The number of pustbutton pin:
int buttonpinA0 = 14;
int buttonpinA1 = 15;
int buttonpinA2 = 16;
//Variable for reading pusbutton status:
int buttonState1 = 0;
int buttonState2 = 0;
int buttonState3 = 0;

void setup() {
  pinMode(buttonpinA0,INPUT);
  pinMode(buttonpinA1,INPUT);
  pinMode(buttonpinA2,INPUT);
  Serial.begin(9600);
}

void loop() {
  //read the state of the pushbutton value:
  buttonState1 = digitalRead(buttonpinA0);
  buttonState2 = digitalRead(buttonpinA1);
  buttonState3 = digitalRead(buttonpinA2);
  //check if the pushbutton is pressed:
  //if it is pressed then buttonstate is HIGH:
  if(buttonState1 == HIGH){
    Serial.write(1);
  }
  else if (buttonState2 == HIGH){
    Serial.write(2);
  }
  else if (buttonState3 == HIGH){
    Serial.write(3);
  }
  else{
    Serial.write(4);
  }

}
