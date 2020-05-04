#include <MQ2.h>
 
int pinAout = A3;
int lpg_gas, co_gas, smoke_gas;
 
MQ2 mq2(pinAout);
 
void setup(){
//Set serial monitor pada baut 9600
  Serial.begin(9600);
  mq2.begin();
}
 
void loop(){
  
  /*Pembacaan ketiga gas sekaligus dalam satuan PPM
  * No.1 = Gas LPG
  * no.2 = Gas CO
  * n0.3 = Gas SMOKE
  */
  
  float* values= mq2.read(true); //jika diset "false" tidak akan dimunculkan di serial monitor
  
  lpg_gas = mq2.readLPG();
  co_gas = mq2.readCO();
  smoke_gas = mq2.readSmoke();
  
  delay(1000);
}
 
