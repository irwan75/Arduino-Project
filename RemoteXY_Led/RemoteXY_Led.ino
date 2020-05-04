/* 
   -- New project -- 
    
   This source code of graphical user interface  
   has been generated automatically by RemoteXY editor. 
   To compile this code using RemoteXY library 2.3.5 or later version  
   download by link http://remotexy.com/en/library/ 
   To connect using RemoteXY mobile app by link http://remotexy.com/en/download/                    
     - for ANDROID 4.3.1 or later version; 
     - for iOS 1.3.5 or later version; 
     
   This source code is free software; you can redistribute it and/or 
   modify it under the terms of the GNU Lesser General Public 
   License as published by the Free Software Foundation; either 
   version 2.1 of the License, or (at your option) any later version.     
*/ 

////////////////////////////////////////////// 
//        RemoteXY include library          // 
////////////////////////////////////////////// 

// RemoteXY select connection mode and include library  
#define REMOTEXY_MODE__ESP8266WIFI_LIB_POINT
#if defined(ESP8266)
#include <ESP8266WiFi.h> 
#else
#include <WiFi.h>
#endif

#include <RemoteXY.h> 

// RemoteXY connection settings  
#define REMOTEXY_WIFI_SSID "RemoteXY" 
#define REMOTEXY_WIFI_PASSWORD "12345678" 
#define REMOTEXY_SERVER_PORT 6377 


// RemoteXY configurate   
#pragma pack(push, 1) 
uint8_t RemoteXY_CONF[] = 
  { 255,1,0,0,0,11,0,8,13,0,
  4,0,9,22,7,18,2,26 }; 
   
// this structure defines all the variables of your control interface  
struct { 

    // input variable
  int8_t slider_1; // =0..100 slider position 

    // other variable
  uint8_t connect_flag;  // =1 if wire connected, else =0 

} RemoteXY; 
#pragma pack(pop) 

///////////////////////////////////////////// 
//           END RemoteXY include          // 
///////////////////////////////////////////// 

int led = 4;
int freq = 5000;
int ledChannel = 0;
int resolution = 8;

void setup()  
{ 
  Serial.begin(9600);
  RemoteXY_Init ();  
   ledcSetup(ledChannel, freq, resolution);
  ledcAttachPin(led, ledChannel);
   
  // TODO you setup code 
   
} 

void loop()  
{  
  RemoteXY_Handler (); 
  Serial.println((RemoteXY.slider_1));
//   digitalWrite(led, (RemoteXY.slider_1));
  ledcWrite(ledChannel, (RemoteXY.slider_1));
   
  // TODO you loop code 
  // use the RemoteXY structure for data transfer 


}
