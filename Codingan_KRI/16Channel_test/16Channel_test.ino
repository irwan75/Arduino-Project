#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>
#include <Servo.h>

Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

//ultrasonik
//int trigPin1=6;
//int echoPin1=7;
//
//int trigPin2=8;
//int echoPin2=9;
//
//int trigPin3=10;
//int echoPin3=11;

//double minDepan = 20;
//double maxKanan = 40;
//double minKanan = 15;
//double minKiri = 15;
//double maxKiri = 15;

//int api;
//int api1;
//int api_detect;

int start = 0;
//int kiri = 0;
//int kanan = 0;

//Servo servo1;
//Servo servo2;
//Servo servo_depan;

void default_leg(){
//  servo_depan.write(90);
  //Leg1
  pwm.setPWM(0, 0, 135+30);
  pwm.setPWM(1, 0, 225+30);
  pwm.setPWM(2, 0, 200);
  //Leg2
  pwm.setPWM(3, 0, 157+30);
  pwm.setPWM(4, 0, 205+30);
  pwm.setPWM(5, 0, 166);
  //Leg3
  pwm.setPWM(6, 0, 160+25);
  pwm.setPWM(7, 0, 207+30);
  pwm.setPWM(8, 0, 250);
  //Leg4
  pwm.setPWM(9, 0, 397-30);
  pwm.setPWM(10, 0, 275-30);
  pwm.setPWM(11, 0, 240);
  //Leg5
//  servo1.write(110-10);
  pwm.setPWM(12, 0, 325-30);
  pwm.setPWM(13, 0, 135);
  //Leg6
//  servo2.write(145-8);
  pwm.setPWM(14, 0, 335-30);
  pwm.setPWM(15, 0, 220);
}

void Leg_1(){//0,1,2
  pwm.setPWM(2, 0, 250);
  delay(1000);
  pwm.setPWM(1, 0, 160);
  delay(1000);
  pwm.setPWM(2, 0, 200);
  delay(1000);
  pwm.setPWM(1, 0, 225);
  delay(1000);  
}

void Leg_2(){//3,4,5
  pwm.setPWM(5, 0, 190);
  delay(1000);
  pwm.setPWM(4, 0, 140);
  delay(1000);
  pwm.setPWM(5, 0, 140);
  delay(1000);
  pwm.setPWM(4, 0, 205);
  delay(1000);
}

void Leg_3(){//6,7,8
  pwm.setPWM(8, 0, 255);
  delay(1000);
  pwm.setPWM(7, 0, 142);
  delay(1000);
  pwm.setPWM(8, 0, 205);
  delay(1000);
  pwm.setPWM(7, 0, 207);
  delay(1000);
}

void Leg_4(){//9,10,11
  pwm.setPWM(11, 0, 190);
  delay(1000);
  pwm.setPWM(10, 0, 340);
  delay(1000);
  pwm.setPWM(11, 0, 240);
  delay(1000);
  pwm.setPWM(10, 0, 275);
  delay(1000);
}

void Leg_5(){//servo1,12,13
  pwm.setPWM(13, 0, 110);
  delay(1000);  
  pwm.setPWM(12, 0, 390);
  delay(1000);
  pwm.setPWM(13, 0, 160);
  delay(1000);
  pwm.setPWM(12, 0, 325);
  delay(1000);
}

void Leg_6(){//servo2,14,15
  pwm.setPWM(15, 0, 220);
  delay(1000);  
  pwm.setPWM(14, 0, 400);
  delay(1000);
  pwm.setPWM(15, 0, 270);
  delay(1000);
  pwm.setPWM(14, 0, 335);
  delay(1000);
}

int naik_246(int nil){
  pwm.setPWM(4, 0, 140+40);
  pwm.setPWM(10, 0, 340-40);
  pwm.setPWM(14, 0, 400-40);
  delay(nil);  
}

int maju_246(int nil){
  pwm.setPWM(5, 0, 140);
  pwm.setPWM(11, 0, 240);
  pwm.setPWM(15, 0, 270);
  delay(nil);  
}

int turun_246(int nil){
  pwm.setPWM(4, 0, 205+30);
  pwm.setPWM(10, 0, 275-30);
  pwm.setPWM(14, 0, 335-30);
  delay(nil);  
}

int naik_135(int nil){
  pwm.setPWM(1, 0, 160+40);
  pwm.setPWM(7, 0, 142+40);
  pwm.setPWM(12, 0, 390-40);
  delay(nil);  
}

int maju_135(int nil){
  pwm.setPWM(2, 0, 200);
  pwm.setPWM(8, 0, 205);
  pwm.setPWM(13, 0, 160);
  delay(nil);
}

int belakang_246(int nil){
    pwm.setPWM(5, 0, 190);
    pwm.setPWM(11, 0, 190);
    pwm.setPWM(15, 0, 220);
    delay(nil);  
}

int turun_135(int nil){
  pwm.setPWM(1, 0, 225+30);
  pwm.setPWM(7, 0, 207+30);
  pwm.setPWM(12, 0, 325-30);
  delay(nil);  
}

int belakang_135(int nil){
  pwm.setPWM(2, 0, 250);
  pwm.setPWM(8, 0, 255);
  pwm.setPWM(13, 0, 110);    
  delay(nil);
}

void maju(){
  if(start=0){
    naik_246(100);
    start++;    
  }
    maju_246(100);
    turun_246(3);
    naik_135(100);
    maju_135(3);
    belakang_246(100);
    turun_135(3);  
    naik_246(100);
    belakang_135(3);
}

void hadap_kanan(){
//  naik_246(100);
    //belakang 2 maju 4,6
    pwm.setPWM(5, 0, 190);
    pwm.setPWM(11, 0, 240);
    pwm.setPWM(15, 0, 270);
    delay(100);
    turun_246(3);
    naik_135(100);
    //maju 2 belakang 4,6
    pwm.setPWM(5, 0, 140);
    pwm.setPWM(11, 0, 190);
    pwm.setPWM(15, 0, 220);
    //belakang 1,3 maju 5
    pwm.setPWM(2, 0, 250);
    pwm.setPWM(8, 0, 255);
    pwm.setPWM(13, 0, 160);
    delay(100);
    turun_135(3);
    naik_246(100);
    //maju 1,3 belakang 5
    pwm.setPWM(2, 0, 200);
    pwm.setPWM(8, 0, 205);
    pwm.setPWM(13, 0, 110);    
}

void hadap_kiri(){
//    naik_246(2000);  
    //maju 2 belakang 4,6
    pwm.setPWM(5, 0, 140);
    pwm.setPWM(11, 0, 190);
    pwm.setPWM(15, 0, 220);
    delay(100);
    turun_246(3);    
    naik_135(100);
    //belakang 2 maju 4,6
    pwm.setPWM(5, 0, 190);
    pwm.setPWM(11, 0, 240);
    pwm.setPWM(15, 0, 270);
    //belakang 5 maju 1,3
    pwm.setPWM(13, 0, 110);
    pwm.setPWM(2, 0, 200);
    pwm.setPWM(8, 0, 205);
    delay(100);
    turun_135(3);
    naik_246(100);
    //belakang 1,3 maju 5
    pwm.setPWM(2, 0, 250);
    pwm.setPWM(8, 0, 255);
    pwm.setPWM(13, 0, 160);
}

void mundur(){
  naik_246(1000);
  while(true){
    belakang_246(1000);
    turun_246(5);
    naik_135(1000);
    maju_246(5);
    belakang_135(1000);
    turun_135(5);
    naik_246(2000);
    maju_135(5);  
  }
}

void setup() {
  Serial.begin(9600);
  pwm.begin();
  pwm.setPWMFreq(60);

//  servo1.attach(26);
//  servo2.attach(27);
//  servo_depan.attach(25);

//  pinMode(3, INPUT);
//  pinMode(4, INPUT);
//  pinMode (A0, INPUT);
//  pinMode(A1, INPUT);

//Ultrasonic
//  pinMode(trigPin1, OUTPUT);
//  pinMode(echoPin1, INPUT);
//  pinMode(trigPin2, OUTPUT);
//  pinMode(echoPin2, INPUT);
//  pinMode(trigPin3, OUTPUT);
//  pinMode(echoPin3, INPUT);
//Ultrasonic

  default_leg();
}

void loop() {
//  //(servoenum, 0, pulselen)
//  //servoenum = servo yang bergerak
//  //pulselen = sudut perputaran servo
//
//  int detect1 =digitalRead(3);
//  int detect2 =digitalRead(4);
//
////maju();
////hadap_kiri();
////hadap_kanan();
////mundur();
//
////Ultrasonic_1
//int duration1, distance1;
//digitalWrite(trigPin1, HIGH);
//delay(10);
//digitalWrite(trigPin1, LOW);
//duration1 = pulseIn (echoPin1, HIGH);
//distance1 = (duration1/2) / 29.1;
//
////Serial.print("Ultrasonic 1 : ");
////Serial.print(distance1);
////Serial.print("cm\n");
////delay(500);
//
//
////Ultrasonic 2
//int duration2, distance2;
//digitalWrite(trigPin2, HIGH);
//delay(10);
//digitalWrite(trigPin2, LOW);
//duration2 = pulseIn (echoPin2, HIGH);
//distance2 = (duration2/2) / 29.1;
//
////Serial.print("Ultrasonic 2 : ");
////Serial.print(distance2);
////Serial.print("cm\n");
////delay(500);
//
//
////Ultrasonic_3
//int duration3, distance3;
//digitalWrite(trigPin3, HIGH);
//delay(10);
//digitalWrite(trigPin3, LOW);
//duration3 = pulseIn (echoPin3, HIGH);
//distance3 = (duration3/2) / 29.1;
//
////Serial.print("Ultrasonic 3 : ");
////Serial.print(distance3);
////Serial.print("cm\n");
////delay(500);
////Serial.println("");
//
//api1 = analogRead(A1);
//
////Wall Follower Kanan
//if(detect1==0){
//  for(int a=0;a<=5;a++){
//    maju();
//    Serial.println("Maju Berkondisi");
//  }delay(1000);
//    for(int i=0 ;i<=180;i++){
//      api = analogRead(A0);  
//      servo_depan.write(i);
//      delay(20);
//      if(api<=150){
//        Serial.println("Terdeteksi Api");
//        api_detect =1;
//      }
//    }
//    for(int i=180; i>=0;i--){
//      api = analogRead(A0);  
//      servo_depan.write(i);
//      delay(20);
//      if(api<=150){
//        Serial.println("Terdeteksi Api");
//        api_detect = 1;
//      }
//    }delay(1000);
//    if(api_detect==1){
//      servo_depan.write(90);  
//    }else if(api_detect==0){
//      delay(500);
//      for(int a=0;a<=10;a++){
//         hadap_kanan();
//        Serial.println("hadap kanan");  
//      }
//    }
//}else if(api_detect == 1){
//  api = analogRead(A0);  
//  maju();
//  Serial.println("Maju Api");
//  if(distance1<15){
//    api_detect++;
//  }else if(api<60){
//    default_leg();
//    delay(20000);
//  }
//}else if(distance1>minDepan && distance3>=minKanan && distance3<=maxKanan){
//  maju();
//  Serial.println("maju");
//}else if(distance1<minDepan && distance3>=minKanan && distance3<=maxKanan){
//  delay(500);
//  if(kiri=0){
//    default_leg();
//    naik_246(100);
//    kiri++;  
//  }
//  hadap_kiri();
//  Serial.println("hadap kiri");
//}else if(distance1>minDepan && distance3>=maxKanan && distance2>=maxKiri){
//  delay(500);
//  if(kanan=0){
//    default_leg();
//    naik_246(100);
//    kanan++;  
//  }
//  hadap_kanan();
//  Serial.println("hadap kanan"); 
//}
}
