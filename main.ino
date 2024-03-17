#include<LiquidCrystal.h>


const int trig = 7;
const int echo = 6;

const int RS = 11, EN = 12, D4 = 2, D5 = 3, D6 = 4, D7 = 5;
LiquidCrystal lcd(RS, EN, D4, D5, D6, D7);

long trajanje = 0;
long cm =0;

void setup() {
  lcd.begin(16, 2);
  lcd.print("Started ");
  delay(1000);
  lcd.clear();
  lcd.setCursor(0,0);
  pinMode(trig, OUTPUT);
  pinMode(trig, INPUT);

}

//main part(reading from sensor and printing result)
void loop() {
  cm=0;
  trajanje=0;

  pinMode(trig, OUTPUT);
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  pinMode(echo, INPUT);
  trajanje = pulseIn(echo, HIGH);
  cm = MikroSekund_U_CM(trajanje);


  lcd.clear();


  lcd.print("Distance: ");
  lcd.setCursor(0, 1); 
  lcd.print(cm);
  lcd.print("cm");

  delay(5000);

  lcd.clear();

  delay(500);
  
}

//convert miliseconds to cm
long MikroSekund_U_CM(long microsekund) {
  return microsekund / 29 / 2;
}
