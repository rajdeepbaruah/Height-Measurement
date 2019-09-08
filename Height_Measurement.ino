
/*        CODE IS WRITTEN BY RAJDEEP BARUAH                                                       */
/*        For working of this code correctly the ultrasonic sensor must be above 350cm            */




#include<LiquidCrystal.h>

LiquidCrystal lcd(A5,A4,A3,A2,A1,A0);

float distance,duration;
float height,h=350;                   //  Change the value of h with the height the ultrasonic sensor 

void setup() {
  
  pinMode(2,OUTPUT);               //  Ultrasonic sensor Trigger Pin  
  pinMode(3,INPUT);                //  Ultrasonic sensor Echo Pin
 
  lcd.begin(16,2);
  lcd.clear();
  lcd.setCursor(4,0);
  lcd.print(" Height is : ");
  
  analogWrite(9,50);              //  Backlight Contrast of LCD
  analogWrite(3,20);              //  Frontlight Contrast of LCD
}

void dist() {
  
  digitalWrite(2, LOW);
  delayMicroseconds(2);

  digitalWrite(2,HIGH);
  delayMicroseconds(10);
  digitalWrite(2, LOW);

  duration = pulseIn(3,HIGH);
  distance = duration*0.034/2;

  Serial.println(distance);
  delay(500);
  

}

void loop()
{
    dist();
    height=h-distance;

    lcd.setCursor(7,1);
    lcd.print(height);
    
}
