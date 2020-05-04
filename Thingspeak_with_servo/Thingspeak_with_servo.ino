//--------------Electronics-project-hub-------------//

//--Node-MCU--//
#include <SoftwareSerial.h>
SoftwareSerial s(12,14); // (Rx, Tx)
#include "ThingSpeak.h"
#include <ESP8266WiFi.h>
const char ssid[] = "UMI Connect";  // your network SSID (name)
const char pass[] = "umiukhuwah";   // your network password         
WiFiClient  client;

//---------Channel Details---------//
unsigned long counterChannelNumber = 900456;            // Channel ID
const char * myCounterReadAPIKey = "SCNLYRQ85474MFUR"; // Read API Key
const int FieldNumber1 = 1;  // The field you wish to read
//-------------------------------//

long statusCode;

void setup()
{
  Serial.begin(115200);
  WiFi.mode(WIFI_STA);
  ThingSpeak.begin(client);
  s.begin(9600);
}

void loop()
{
  //----------------- Network -----------------//
  if (WiFi.status() != WL_CONNECTED)
  {
    Serial.print("Connecting to ");
    Serial.print(ssid);
    Serial.println(" ....");
    while (WiFi.status() != WL_CONNECTED)
    {
      WiFi.begin(ssid, pass);
      delay(2000);
    }
    Serial.println("Connected to Wi-Fi Succesfully.");
  }
  //--------- End of Network connection--------//

  //---------------- Channel 1 ----------------//
  long temp = ThingSpeak.readLongField(counterChannelNumber, FieldNumber1, myCounterReadAPIKey);
  statusCode = ThingSpeak.getLastReadStatus();
  if (statusCode == 200)
  {
    Serial.print("Data Servo: ");
    Serial.println(temp);
    s.write(temp);
  }
  else
  {
    Serial.println("Unable to read channel / No internet connection");
  }
  delay(100);
  //-------------- End of Channel 1 -------------//
}
