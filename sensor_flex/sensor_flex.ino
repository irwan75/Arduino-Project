#include<Wire.h>
#include <SoftwareSerial.h>
const int MPU_addr=0x68;  // I2C address of the MPU-6050
int16_t AcX,AcY,AcZ,Tmp,GyX,GyY,GyZ;
#include "TinyGPS++.h"
#include "SoftwareSerial.h"

SoftwareSerial serial_connection(8, 9); //RX=pin 10, TX=pin 11
TinyGPSPlus gps;//This is the GPS object that will pretty much do all the grunt work with the NMEA data
SoftwareSerial SIM900(7, 8); //Seleccionamos los pines 7 como Rx y 8 como Tx

String number[] = {{"AT+CMGS=\"+6285756603224\"\r"},{"AT+CMGS=\"+6285340472927\"\r""\r"}};
int i =0;
/*{
  //Accelorometer
  SDA - A4;
  SCL - A5;
  INT - D12;

  //Relay
  D2

  //Photoresistor
  S - A6;
  - - GND;

  //flex
  A0 sampai A3;
}*/

//const int flexpin1 = A8;
//const int flexpin2 = A9;
//const int flexpin3 = A10;
//const int flexpin4 = A11;
const int relay = 12;
//const int sensorPIR = A12;
int value;
int flexposition1;
int flexposition2;
int flexposition3;
int flexposition4;

void send_sms(){
    SIM900.println("AT+CMGF=1\r\n");
    delay(1000);
    Serial.println("SMS_Gateway Set SMS ke nomor Tujuan....");
    SIM900.println(number[i]);
    delay(1000);
    SIM900.print("test");
    delay(100);
    SIM900.println((char)26);
    delay(1000);
  
  Serial.println("SMS Terkirim");
//  i++;
}

void setup() {
  //Accelerometer Area
//  Wire.begin();
//  Wire.beginTransmission(MPU_addr);
//  Wire.write(0x6B);  // PWR_MGMT_1 register
//  Wire.write(0);     // set to zero (wakes up the MPU-6050)
//  Wire.endTransmission(true);
  //Accelerometer Area

  //GPS Area
//  serial_connection.begin(9600);//This opens up communications to the GPS
//  Serial.println("GPS Start");//Just show to the monitor that the sketch has started
  //GPS Area

send_sms();
  
  Serial.begin(9600);

  //Relay
  pinMode(relay, OUTPUT);
  digitalWrite(relay, HIGH);
  //Relay

  //Photoresistor
//  pinMode(sensorPIR, INPUT);
  //Photoresistor
}

void loop() {
  //Sensor Flex
//  flexposition1 = analogRead(flexpin1);
//  flexposition2 = analogRead(flexpin2);
//  flexposition3 = analogRead(flexpin3);
//  flexposition4 = analogRead(flexpin4);
//  value = analogRead(sensorPIR);

  //Accelerometer Area
//  Wire.beginTransmission(MPU_addr);
//  Wire.write(0x3B);  // starting with register 0x3B (ACCEL_XOUT_H)
//  Wire.endTransmission(false);
//  Wire.requestFrom(MPU_addr,14,true);  // request a total of 14 registers
//  AcX=Wire.read()<<8|Wire.read();  // 0x3B (ACCEL_XOUT_H) & 0x3C (ACCEL_XOUT_L)  
//  AcY=Wire.read()<<8|Wire.read();  // 0x3D (ACCEL_YOUT_H) & 0x3E (ACCEL_YOUT_L)
//  AcZ=Wire.read()<<8|Wire.read();  // 0x3F (ACCEL_ZOUT_H) & 0x40 (ACCEL_ZOUT_L)
//  Tmp=Wire.read()<<8|Wire.read();  // 0x41 (TEMP_OUT_H) & 0x42 (TEMP_OUT_L)
//  GyX=Wire.read()<<8|Wire.read();  // 0x43 (GYRO_XOUT_H) & 0x44 (GYRO_XOUT_L)
//  GyY=Wire.read()<<8|Wire.read();  // 0x45 (GYRO_YOUT_H) & 0x46 (GYRO_YOUT_L)
//  GyZ=Wire.read()<<8|Wire.read();  // 0x47 (GYRO_ZOUT_H) & 0x48 (GYRO_ZOUT_L)
  //Accelerometer Area


//  Serial.print("Sensor 1 : ");
//  Serial.println(flexposition1);
//  Serial.print("Sensor 2 : ");
//  Serial.println(flexposition2);
//  Serial.print("Sensor 3 : ");
//  Serial.println(flexposition3);
//  Serial.print("Sensor 4 : ");
//  Serial.println(flexposition4);
//    Serial.print ("Photoresistor : ");
//    Serial.println(value, DEC);
//  Serial.println("");
//  delay(1000);

//  Serial.print("AcX = "); Serial.print(AcX);
//  Serial.print(" | AcY = "); Serial.print(AcY);
//  Serial.print(" | AcZ = "); Serial.print(AcZ);
//  Serial.println("");
//  delay(1000);
//
//  if(flexposition1 >=10 || flexposition2 >=10 || flexposition3 >=10 || flexposition4 >=10){
//    if(AcX >= 12000 || AcX <=-10000 || AcY >= 13000 || AcY <=-13000){
//      Serial.println("Terjadi Kecelakaan");  
//      for(;i<2;){
//        send_sms();
//        }
//      }
//    }
//  else if(flexposition1 >=10 || flexposition2 >=10 || flexposition3 >=10 || flexposition4 >=10){
//    if(AcX >= 12000 || AcX <=-10000 || AcY >= 13000 || AcY <=-13000){
//      if(value >= 800){
//        Serial.println("Terjadi Kecelakaan Pada Malam Hari");
////        digitalWrite(led, HIGH);
//        delay(1000);  
//          for(;i<2;){
//            send_sms();
//          }  
//        }
//      }
//    }    
//  else if(AcX >= 14000 || AcX <=-12000 || AcY >= 15000 || AcY <=-15000){
//    Serial.println("Terjadi Kecelakaan");
//  }
//  else if(AcX >= 14000 || AcX <=-12000 || AcY >= 15000 || AcY <=-15000){
//    if(value >= 800){
//      Serial.println("Terjadi Kecelakaan Pada Malam Hari");
////      digitalWrite(led, HIGH);
//      delay(1000);  
//    }
//  }
//  delay(200);
}
