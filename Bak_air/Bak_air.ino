//#include <LiquidCrystal.h>
//
//LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
//byte smiley[8] = {
//  0b00000,
//  0b00000,
//  0b01010,
//  0b00000,
//  0b00000,
//  0b10001,
//  0b01110,
//  0b00000
//};

const int relay = 14;
const int buzzer = 5;

int trigPin1=13;
int echoPin1=12;

void setup() {
  pinMode(relay, OUTPUT);
  pinMode(buzzer, OUTPUT);
  Serial.begin (9600);
  pinMode(trigPin1, OUTPUT);
  pinMode(echoPin1, INPUT);

//  lcd.begin(16, 2);
  
  // create a new character
//  lcd.createChar(1, smiley);
}

void loop() {
  
//this for 1 ultrasonic{
  int duration, distance, tinggi;
  short int vlme;
  digitalWrite (trigPin1, HIGH);
  delayMicroseconds (10);
  digitalWrite (trigPin1, LOW);
  duration = pulseIn (echoPin1, HIGH);
  distance = (duration/2) / 29.2;
  tinggi = 22 - distance;
  vlme = 3.14*10*10*tinggi;
  //}
  
//  lcd.setCursor(0, 0);
//  lcd.print("Tngi Air : ");
//  lcd.print(tinggi);
//  lcd.print(" cm");
//  lcd.setCursor(0, 1);
//  // print the message at line 2
//  lcd.print("Volume : ");
//  lcd.print(vlme);
//  lcd.print(" ltr");
  
  if(tinggi >= 16){
    //Relay Mati
    digitalWrite(relay, HIGH);
  }else{
    digitalWrite(relay, LOW);
  }
  if(tinggi >= 15 && tinggi <= 18){
    digitalWrite(buzzer, HIGH); 
  }else{
    digitalWrite(buzzer, LOW); 
  }

  delay(800);
}
