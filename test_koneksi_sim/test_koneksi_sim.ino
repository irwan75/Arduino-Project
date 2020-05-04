#include "SoftwareSerial.h"

SoftwareSerial SMS_Gateway(22, 24);
char tempChar = "";

String number[] = {{"AT+CMGS=\"+6285756603224"},{"AT+CMGS=\"+6282293082293"}};

void setup() {
  Serial.begin(19200);
  Serial.println("Program Mencoba Koneksi ke SIM800L SMS Gateway");
  SMS_Gateway.begin(19200);

  for(int i = 0; i<10;i++){
    Serial.print("=====");
    delay(500);
  }
  Serial.println();
  Serial.println("Koneksi dimulai");

  Serial.println("Setup Format SMS ke ASCII");
  SMS_Gateway.println("AT+CMGF=1\r\n");
  delay(1000);

  Serial.println("SMS_Gateway Set SMS ke nomor Tujuan....");
  for(int i = 0; i < 2 ; i++){
    SMS_Gateway.println("");
    delay(1000);
    SMS_Gateway.print("test");
    SMS_Gateway.println((char)26);
    delay(1000);
  }
  
  Serial.println("SMS Terkirim");
  
}

void loop() {
  // put your main code here, to run repeatedly:

}
