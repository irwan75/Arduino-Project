#include <SoftwareSerial.h>
SoftwareSerial SIM900(7, 8); 
int a=1;
 
void setup() {
  Serial.begin(9600);
  SIM900.begin(9600);  
  SIM900.println("AT+CMGF=1");
  Serial.println("SIM800L started at 9600");
  delay(1000);
  Serial.println("Setup Complete! SIM800L is Ready!");
  SIM900.println("AT+CNMI=2,2,0,0,0");
  SIM900.println("AT");
 
  SIM900.println("AT+CMGF=1"); 
  delay(1000);  
  //SIM900.println("AT+CMGS=\"+6281244244250");
  //delay(20000);
  SIM900.println("AT+CMGS=\"+6281242600582\"\r");
  delay(1000);
//  if(a=1){
    SIM900.println("Api Terdeteksi");
    delay(100);
//    a++;
//    if(a=2){
//      SIM900.println(" dan Asap Terdeteksi");
//      delay(100);
//      a++;
//      if(a=3){
//        SIM900.println("Masukkk");
//        delay(100);
//      }  
//    }
//  }  
  SIM900.println((char)26);
  delay(1000);
  Serial.println("Pengiriman SMS Berhasil!");
  delay(1000);
  
  SendSMS();
  delay(5000);
  SendSMS1();
  delay(5000);
  SendSMS2();
  delay(5000);
  
}
 
void loop() {
  
}

void SendSMS(){
  SIM900.println("AT+CMGF=1"); 
  delay(1000);
  SIM900.println("AT+CMGS=\"+6285756603224\"\r");
  delay(2000);
  SIM900.println("Api Terdeteksi");
  delay(100);  
}

void SendSMS1(){
  SIM900.println("AT+CMGF=1"); 
  delay(1000);
  SIM900.println("AT+CMGS=\"+6285298231608\"\r");
  delay(2000);
  SIM900.println("Api Terdeteksi");
  delay(100);
}

void SendSMS2(){
  SIM900.println("AT+CMGF=1"); 
  delay(1000);
  SIM900.println("AT+CMGS=\"+62895800148010\"\r");
  delay(2000);
  SIM900.println("Api Terdeteksi");
  delay(100);
}
