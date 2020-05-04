#include "TinyGPS++.h"
#include <SoftwareSerial.h>
SoftwareSerial SIM900(5, 3); 

int btnState = 0;
SoftwareSerial serial_connection(8, 9); //RX=pin 10, TX=pin 11
TinyGPSPlus gps;//This is the GPS object that will pretty much do all the grunt work with the NMEA data

//Variable penyimpanan sms 
char currentLine[500] = "";
int currentLineIndex = 0;

bool nextLineIsMessage = false;
int smsRec = 0;

void setup()
{
  Serial.begin(9600);//This opens up communications to the Serial monitor in the Arduino IDE
  serial_connection.begin(9600);//This opens up communications to the GPS
  Serial.println("GPS Start");//Just show to the monitor that the sketch has started
  pinMode(2, INPUT);

  SIM900.begin(9600);  
  SIM900.println("AT+CMGF=1");
  Serial.println("SIM800L started at 9600");
  Serial.println("Setup Complete! SIM800L is Ready!");
  SIM900.println("AT+CNMI=2,2,0,0,0");
  SIM900.println("AT");
}

void loop()
{
  while(serial_connection.available())//While there are characters to come from the GPS
  {
    gps.encode(serial_connection.read());//This feeds the serial NMEA data into the library one char at a time
  }
  if(gps.location.isUpdated())//This will pretty much be fired all the time anyway but will at least reduce it to only after a package of NMEA data comes in
  {

    btnState = digitalRead(2);
    if(btnState == 1){
      SIM900.println("AT+CMGF=1"); 
      delay(1000);
      SIM900.println("AT+CMGS=\"+6285299935661\"\r");
      delay(3000);
      SIM900.println("HELPPPPP MEEEE!!!!\nSatelite Count : "+(String(gps.satellites.value()))+"\nLatitude : "+(String(gps.location.lat(), 6))+"\nLongitude : "+(String(gps.location.lng(), 6)));
      delay(1000);
      SIM900.write((char)26);
      delay(1000);
    }
    delay(1000);
  }

  receiveSMS();
}

void receiveSMS(){ 
  //jika ada data serial terbaca
  if(SIM900.available()){
    char lastCharRead = SIM900.read();
    //baca karakter dari serial
    if(lastCharRead == '\r' || lastCharRead == '\n'){
        String lastLine = String(currentLine);
         
        //jika baris terakhir adalah +CMT, ada indikasi sms baru masuk. 
        if(lastLine.startsWith("+CMT:")){
           
          Serial.println(lastLine);
          nextLineIsMessage = true;
           
        } else if (lastLine.length() > 0) {
           
          if(nextLineIsMessage) {
            Serial.println(lastLine);
             
            //disini tempat pembacaan sms oleh sim800, kontrol sms ada disini
            if(lastLine.indexOf("Tracking") >= 0){
                smsRec = 1;
                if(smsRec == 1){
                  SIM900.println("AT+CMGF=1"); 
                  delay(1000);
                  SIM900.println("AT+CMGS=\"+6285299935661\"\r");
                  delay(3000);
                  SIM900.println("Latitude : "+(String(gps.location.lat(), 6))+"\nLongitude : "+(String(gps.location.lng(), 6)));
                  delay(1000);
                  SIM900.write((char)26);
                  delay(1000);
                }
            }
             
            nextLineIsMessage = false;
          }
           
        }
         
        //Clear char array for next line of read
        for( int i = 0; i < sizeof(currentLine);  ++i ) {
         currentLine[i] = (char)0;
        }
        currentLineIndex = 0;
    } else {
      currentLine[currentLineIndex++] = lastCharRead;
    }
  }
}
