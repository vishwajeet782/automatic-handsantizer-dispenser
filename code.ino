# include "LiquidCrystal.h"  //lcd libary  



                                 
LiquidCrystal lcd(2, 3, 4, 5, 6, 7);   //LCD object Parameters: (rs, enable, d4, d5, d6, d7)
const int trigPin = 12; //trig pin connection 
const int echoPin = 11;  //echopin connection 
long duration;
int distanceCm;
float liquid;
const int WATERPUMP=13;
                                                                                                            
void setup() {      // setup perameter
lcd.begin(16,2);
pinMode(13,OUTPUT);                                                 
pinMode(trigPin, OUTPUT);
pinMode(echoPin, INPUT);
lcd.setCursor(0,0);
lcd.print("  Distance    ");
lcd.setCursor(0,1);
lcd.print("  Measurement  ");
delay(2000);
lcd.clear();
lcd.setCursor(0,0);
lcd.print("    WASH HANDS   ");
lcd.setCursor(0,1);
lcd.print("    STAY SAFE  ");
delay(2000);
lcd.clear();
}

void loop() {   
  if (Serial.available()) 
  {
    int speed = Serial.parseInt(); 
    if (speed >= 0 && speed <= 255)
    {
      analogWrite(WATERPUMP, speed);
    }
  }
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
duration = pulseIn(echoPin, HIGH);
distanceCm= duration*0.034/2;                                                                                 


if(distanceCm >= 20){
digitalWrite(13, LOW);lcd.setCursor(0,0);                                                 
lcd.print("Distance Measur.");
delay(10);
lcd.setCursor(0,1);
lcd.print("Distance:");
lcd.print(distanceCm);
lcd.print(" Cm ");
delay(1000);
lcd.clear();
lcd.print("Hands too far");
delay(2000);
}
else {
digitalWrite(13, HIGH);lcd.setCursor(0,0);                                                 
lcd.print("Distance Measur.");
delay(10);
lcd.setCursor(0,1);
lcd.print("Distance:");
lcd.print(distanceCm);
lcd.print(" Cm ");
delay(1000);
lcd.clear();
lcd.print("Dispensing ");
delay(2000);

}


}
