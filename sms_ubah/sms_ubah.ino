#include <SoftwareSerial.h>
SoftwareSerial GPRS(11, 12); //11 = TX, 12 = RX
unsigned char buffer[64]; //port
int count=0;
int i = 0; //if i = 0, send SMS.
void setup() {
  GPRS.begin(9600); // the GPRS baud rate
  Serial.begin(9600); // the Serial port of Arduino baud rate.
  Serial.print("I'm ready");
  Serial.print("Hello?");
}

void loop() {
  if (GPRS.available()) {
    // if date is coming from softwareserial port ==> data is coming from GPRS shield
    while(GPRS.available()) {
      // reading data into char array
      buffer[count++]=GPRS.read();
      // writing data into array
      if(count == 64)
        break;
    }
    Serial.write(buffer,count);
    // if no data transmission ends, write buffer to hardware serial port
    clearBufferArray();
    // call clearBufferArray function to clear the stored data from the array
    count = 0; // set counter of while loop to zero
  }
  if (Serial.available())
    // if data is available on hardwareserial port ==> data is coming from PC or notebook
    GPRS.write(Serial.read()); // write it to the GPRS shield
  if(i == 0) {
    GPRS.write("AT+CMGF=1\r"); //sending SMS in text mode
    delay(1000);
    Serial.println("AT+CMGF=1\r");       
    GPRS.write("AT+CMGS=\"+6282312727830\"\r"); // phone number
    delay(1000);
    Serial.println("AT+CMGS=\"+6285756603224\"\r");       
    GPRS.write("Hello how are you?\r"); // message
    delay(1000);
    Serial.println("Hello how are you?\r"); 
    delay(1000);
    GPRS.write(0x1A);
    //send a Ctrl+Z (end of the message)
    delay(1000);
    Serial.println("SMS sent successfully");
    i++;
  }   
}

void clearBufferArray(){
  // function to clear buffer array
  for (int i=0; i<count;i++){
    buffer[i]='\0';
    // clear all index of array with command NULL
  }
}
