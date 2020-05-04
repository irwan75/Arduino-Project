#include <Servo.h>

Servo servo;

int api;
int api_detect;

void fix(){
  int detect1 =digitalRead(3);
  delay(10);
  int detect2 =digitalRead(4);
  delay(10);
  Serial.println(detect1);
  Serial.println(detect2);
  if(detect2==0){
    for(int i=0 ;i<=180;i++){
      api = analogRead(A0);  
      servo.write(i);
      delay(20);
      if(api<=150){
        Serial.println("Terdeteksi Api");
        api_detect = 1;
        if(api_detect == 1){
          servo.write(90);    
        }
      }
    }
    for(int i=180; i>=0;i--){
      api = analogRead(A0);  
      servo.write(i);
      delay(20);
      if(api<=150){
        Serial.println("Terdeteksi Api");
        api_detect = 1;
        if(api_detect == 1){
          servo.write(90);    
        }
      }
    }
  }
  delay(300);  
}

void setup() {
  Serial.begin(9600);
//  pinMode(3, INPUT);
//  pinMode(4, INPUT);
  pinMode (A0, INPUT);
  pinMode(2, OUTPUT);
//  servo.attach(25);  
}

void loop() {
  api = analogRead(A0);
  Serial.println(api);
  delay(500);
} 
