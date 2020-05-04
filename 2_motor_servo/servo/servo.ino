#include <Servo.h>
Servo servo1;
Servo servo2;
int pos=10;
int dos=24;
int angka;

void setup() {
  servo1.attach(9);
  servo2.attach(3);
}

void loop() {
  for(angka=0;angka<=1;angka++){
    for(pos = 10;pos<175;pos+=1){
      servo1.write(pos);
      delay(2);
    }
    for(pos = 175;pos>=10;pos-=1){
      servo1.write(pos);
      delay(9);
    }
  }

  for (angka=0;angka<=3;angka++){
    for(dos = 12; dos<170;dos+=1){
      servo2.write(dos);
      delay(2);
    }
    for(dos = 170;dos>=12;dos-=1){
      servo2.write(dos);
      delay(9);
    }
  }
}
