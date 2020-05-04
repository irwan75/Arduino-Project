
#include "Sim800l.h"
#include <SoftwareSerial.h>

//SMSGSM sms;

int numdata;
boolean started=false;
char smsbuffer(160);
char n[20];

void setup() {
  Serial.begin(9600);
  Serial.println("GSM Shield testing.");

  if(gsm.begin(2400){
    Serial.println("/status=Ready");
    started=true;
  }

  //if(started){
    //if (sms.sendSMS("082312727830","Arduino SMS"))
    //Serial.println("\nSMS sent ok");
  //}
}

void loop() {
  if(started){
    if(gsm.readSMS(smsbuffer, 160, n, 20){
      Serial.println(n);
      Serial.println(smsbuffer);
    }
    delay(1000);
  }
}
