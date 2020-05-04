#include <Servo.h>
Servo servo1;
Servo servo2;
int pos = 0;
int dos = 0;

void setup() {
  servo1.attach(9);
  servo2.attach(3);
}

void loop() {
 for(pos = 20; pos < 200; pos += 1){
  servo1.write(pos);
  delay(0);                  
 } 
 for(pos = 200; pos>=20; pos-=1){
  servo1.write(pos);               
  delay(0);                        
 }
 
 for(dos = 0;pos<200;pos+=1){
  servo2.write(dos);
  delay(0); 
 }
 for(dos = 200;pos>=1;pos-=1){
  servo2.write(dos);
  delay(0);
 }
}
