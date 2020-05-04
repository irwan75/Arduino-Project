#include <SoftwareSerial.h>
SoftwareSerial s(13,2); // (Rx, Tx)

int data;

void setup() {
  s.begin(9600);
  Serial.begin(9600);
  Serial.println("Mulai...");
}
 
void loop() {
//  s.write("s");
  if (s.available()>0)
  { Serial.println("Connect Node");
    data=s.read();
    Serial.println(data);
  }else{
    Serial.println("Terputus...");
  }
  delay(2000);
}
