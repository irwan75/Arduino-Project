#include<Wire.h>
#include <SoftwareSerial.h>

SoftwareSerial SIM900(7, 8); //Seleccionamos los pines 7 como Rx y 8 como Tx

String number[] = {{"AT+CMGS=\"+6285756603224\"\r"},{"AT+CMGS=\"+6285340472927\"\r"\r"}};

const int MPU_addr=0x68;  // I2C address of the MPU-6050
int16_t AcX,AcY,AcZ,Tmp,GyX,GyY,GyZ;
//byte led [] = {3,4,5,7,8,9,10};
void setup(){
  Wire.begin();
  Wire.beginTransmission(MPU_addr);
  Wire.write(0x6B);  // PWR_MGMT_1 register
  Wire.write(0);     // set to zero (wakes up the MPU-6050)
  Wire.endTransmission(true);
  SIM900.begin(9600);
  Serial.begin(9600);

  SIM900.println("AT+CMGF=1\r\n");
  delay(1000);
   Serial.println("SMS_Gateway Set SMS ke nomor Tujuan....");
  for(int i = 0; i < 2 ; i++){
    SIM900.println(number[i]);
    delay(1000);
    SIM900.print("test");
    delay(100);
    SIM900.println((char)26);
    delay(1000);
  }
  
  Serial.println("SMS Terkirim");

//  FLEX
//  pinMode (10, OUTPUT);
//  pinMode (9, OUTPUT);
//  pinMode (8, OUTPUT);
//  pinMode (7, OUTPUT);
//  pinMode (5, OUTPUT);
//  pinMode (4, OUTPUT);
//  pinMode (3, OUTPUT);
}
void loop(){
  Wire.beginTransmission(MPU_addr);
  Wire.write(0x3B);  // starting with register 0x3B (ACCEL_XOUT_H)
  Wire.endTransmission(false);
  Wire.requestFrom(MPU_addr,14,true);  // request a total of 14 registers
  AcX=Wire.read()<<8|Wire.read();  // 0x3B (ACCEL_XOUT_H) & 0x3C (ACCEL_XOUT_L)  
  AcY=Wire.read()<<8|Wire.read();  // 0x3D (ACCEL_YOUT_H) & 0x3E (ACCEL_YOUT_L)
  AcZ=Wire.read()<<8|Wire.read();  // 0x3F (ACCEL_ZOUT_H) & 0x40 (ACCEL_ZOUT_L)
  Tmp=Wire.read()<<8|Wire.read();  // 0x41 (TEMP_OUT_H) & 0x42 (TEMP_OUT_L)
  GyX=Wire.read()<<8|Wire.read();  // 0x43 (GYRO_XOUT_H) & 0x44 (GYRO_XOUT_L)
  GyY=Wire.read()<<8|Wire.read();  // 0x45 (GYRO_YOUT_H) & 0x46 (GYRO_YOUT_L)
  GyZ=Wire.read()<<8|Wire.read();  // 0x47 (GYRO_ZOUT_H) & 0x48 (GYRO_ZOUT_L)
  Serial.print("AcX = "); Serial.print(AcX);
  Serial.print(" | AcY = "); Serial.print(AcY);
  Serial.print(" | AcZ = "); Serial.print(AcZ);
//  Serial.print(" | GyX = "); Serial.print(GyX);
//  Serial.print(" | GyY = "); Serial.print(GyY);
//  Serial.print(" | GyZ = "); Serial.print(GyZ);
  Serial.print(" | Tmp = "); Serial.println(Tmp/340.00+36.53);  //equation for temperature in degrees C from datasheet
//  Serial.print(" | GyX = "); Serial.print(GyX);
//  Serial.print(" | GyY = "); Serial.print(GyY);
//  Serial.print(" | GyZ = "); Serial.println(GyZ);
//if (AcY < 4056 && AcY > 3356){
//  digitalWrite(led[0], 0);
//  digitalWrite(led[1], 0);
//  digitalWrite(led[2], 0);
//  digitalWrite(led[3], 0);
//  digitalWrite(led[4], 0);
//  digitalWrite(led[5], 0);
//  digitalWrite(led[6], 1);
//}
//else if (AcY < 3006 && AcY > 2356){
//  digitalWrite(led[0], 0);
//  digitalWrite(led[1], 0);
//  digitalWrite(led[2], 0);
//  digitalWrite(led[3], 0);
//  digitalWrite(led[4], 0);
//  digitalWrite(led[5], 1);
//  digitalWrite(led[6], 0);
//}
//else if (AcY < 1756 && AcY > 356){
//  digitalWrite(led[0], 0);
//  digitalWrite(led[1], 0);
//  digitalWrite(led[2], 0);
//  digitalWrite(led[3], 0);
//  digitalWrite(led[4], 1);
//  digitalWrite(led[5], 0);
//  digitalWrite(led[6], 0);
//}
//else if (AcY < 356 && AcY > -1062){
//  digitalWrite(led[0], 0);
//  digitalWrite(led[1], 0);
//  digitalWrite(led[2], 0);
//  digitalWrite(led[3], 1);
//  digitalWrite(led[4], 0);
//  digitalWrite(led[5], 0);
//  digitalWrite(led[6], 0);
//}
//else if (AcY < -1062 && AcY > -1268){
//  digitalWrite(led[0], 0);
//  digitalWrite(led[1], 0);
//  digitalWrite(led[2], 0);
//  digitalWrite(led[3], 1);
//  digitalWrite(led[4], 0);
//  digitalWrite(led[5], 0);
//  digitalWrite(led[6], 0);
//}
//else if (AcY < -1268 && AcY > -2824){
//  digitalWrite(led[0], 0);
//  digitalWrite(led[1], 0);
//  digitalWrite(led[2], 1);
//  digitalWrite(led[3], 0);
//  digitalWrite(led[4], 0);
//  digitalWrite(led[5], 0);
//  digitalWrite(led[6], 0);
//}
//else if (AcY < -2824 && AcY > -3824){
//  digitalWrite(led[0], 0);
//  digitalWrite(led[1], 1);
//  digitalWrite(led[2], 0);
//  digitalWrite(led[3], 0);
//  digitalWrite(led[4], 0);
//  digitalWrite(led[5], 0);
//  digitalWrite(led[6], 0);
//}
//else if (AcY < -3824 && AcY > -4824){
//  digitalWrite(led[0], 1);
//  digitalWrite(led[1], 0);
//  digitalWrite(led[2], 0);
//  digitalWrite(led[3], 0);
//  digitalWrite(led[4], 0);
//  digitalWrite(led[5], 0);
//  digitalWrite(led[6], 0);
//}

  delay(1000);
}
