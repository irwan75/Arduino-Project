#include <SoftwareSerial.h>
SoftwareSerial SMS(9, 10);// rx(9) and tx(10)
                          // rx(9-arduino) connect to tx(gsm module)
                          // tx(10-arduino) connect to rx(gsm module)
void setup()
{
  SMS.begin(9600);       // baud rate for gsm module  
  Serial.begin(9600);    // baud rate for serial monitor 
  delay(100);
//pinMode(12, INPUT); 
}
void loop()
{
  int x=digitalRead(12);
  if (x==HIGH)
  {
    sendmessage();
    //recievemessage(); // to receive message enable receivemessage function 
                         // and "//" the sendmessage function
  }
   if (SMS.available()>0){// verify any bits which income through pins 9 and 10
   Serial.write(SMS.read());// write income data on serial monitor
 }
}

 void sendmessage()
{
  SMS.println("AT+CMGF=1"); //AT command for text mode of gsm module 
  delay(1000);  
 SMS.println("AT+CMGS=\"085756603224\"\r"); //  x is your mobile number
  delay(1000);
  SMS.println("sms send by arduino");// the text you want to send
  delay(100);
  SMS.println((char)26);// ASCII code of CTRL+Z
  delay(1000);
}
// void recievemessage()
//{
//  SMS.println("AT+CNMI=2,2,0,0,0"); // AT command to receive SMS
//  delay(1000);
// }
