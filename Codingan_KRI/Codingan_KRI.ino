#include <Servo.h>

Servo kaki1_a, kaki1_b, kaki2_a, kaki2_b, kaki3_a, kaki3_b,
      kaki4_a, kaki4_b, kaki5_a, kaki5_b, kaki6_a, kaki6_b;
int servoPos = 0;


void setup() {
  kaki1_a.attach(2);
//  kaki1_b.attach(3);
//  kaki2_a.attach(4);
//  kaki2_b.attach(5);
//  kaki3_a.attach(6);
//  kaki3_b.attach(7);
//  kaki4_a.attach(8);
//  kaki4_b.attach(9);
//  kaki5_a.attach(10);
//  kaki5_b.attach(11);
//  kaki6_a.attach(12);
//  kaki6_b.attach(13);
  Serial.begin(9600);

  kaki1_a.write(0);
//  kaki1_b.write(0);
//  kaki2_a.write(0);
//  kaki2_b.write(40);
//  kaki3_a.write(0);
//  kaki3_b.write(0);
//  kaki4_a.write(0);
//  kaki4_b.write(0);
//  kaki5_a.write(0);
//  kaki5_b.write(0);
//  kaki6_a.write(0);
//  kaki6_b.write(0);
}

void loop() {
//  while(true){
//    kaki1_b.write(40);
//    kaki2_b.write(0);
//    delay(500);
//    kaki4_b.write(20);
//    kaki6_b.write(20);
//    kaki1_a.write(100);
//    kaki2_a.write(0);
//    delay(500);
//    kaki4_a.write(50);
//    kaki6_a.write(50);
//    kaki1_b.write(0);
//    kaki2_b.write(40);
//    delay(500);
//    kaki4_b.write(0);
//    kaki6_b.write(0);
//    delay(70);
    kaki1_a.write(0);
//    kaki2_a.write(10);
    delay(500);
//    kaki4_a.write(0);
//    kaki6_a.write(0);
//    delay(70);
//    boolean ganti = true;
//      while(ganti){
//        kaki2_b.write(20);
//        kaki3_b.write(20);
//        kaki5_b.write(20);
//        delay(70);
//        kaki2_a.write(50);
//        kaki3_a.write(50);
//        kaki5_a.write(50);
//        delay(70);
//        kaki2_b.write(0);
//        kaki3_b.write(0);
//        kaki5_b.write(0);
//        delay(70);
//        kaki2_a.write(0);
//        kaki3_a.write(0);
//        kaki5_a.write(0);
//        delay(70);
//        ganti = false;    
//      }
//  }
}
