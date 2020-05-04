// RemoteXY select connection mode and include library  
#define REMOTEXY_MODE__ESP8266WIFI_LIB_POINT
#include <WiFi.h> 

#include <RemoteXY.h> 

// RemoteXY connection settings  
#define REMOTEXY_WIFI_SSID "RemoteXY" 
#define REMOTEXY_WIFI_PASSWORD "12345678" 
#define REMOTEXY_SERVER_PORT 6377 


// RemoteXY configurate   
#pragma pack(push, 1) 
uint8_t RemoteXY_CONF[] = 
  { 255,0,0,33,0,83,0,8,13,1,
  67,5,15,27,34,5,2,26,11,67,
  5,15,48,37,5,2,26,11,67,5,
  16,68,36,5,2,26,11,129,0,20,
  18,26,6,17,72,117,109,105,100,105,
  116,121,0,129,0,16,40,37,6,17,
  84,101,109,112,101,114,97,116,117,114,
  101,0,129,0,19,59,31,6,17,72,
  101,97,116,32,73,110,100,101,120,0 }; 
   
// this structure defines all the variables of your control interface  
struct { 

    // output variable
  char text_1[11];  // string UTF8 end zero 
  char text_2[11];  // string UTF8 end zero 
  char text_3[11];  // string UTF8 end zero 

    // other variable
  uint8_t connect_flag;  // =1 if wire connected, else =0 

} RemoteXY; 
#pragma pack(pop) 

///////////////////////////////////////////// 
//           END RemoteXY include          // 
///////////////////////////////////////////// 


#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <DHT_U.h>

#define DHTPIN 19     // Digital pin connected to the DHT sensor 
// Feather HUZZAH ESP8266 note: use pins 3, 4, 5, 12, 13 or 14 --
// Pin 15 can work but DHT must be disconnected during program upload.

// Uncomment the type of sensor in use:
#define DHTTYPE    DHT11     // DHT 11

DHT_Unified dht(DHTPIN, DHTTYPE);

uint32_t delayMS;

String mystring;

void setup()  
{ 
  RemoteXY_Init ();  
   Serial.begin(9600);
  // Initialize device.
  dht.begin();
  Serial.println(F("DHTxx Unified Sensor Example"));
  // Print temperature sensor details.
  sensor_t sensor;
  dht.temperature().getSensor(&sensor);

  // Print humidity sensor details.
  dht.humidity().getSensor(&sensor);
  
  // Set delay between sensor readings based on sensor details.
  delayMS = sensor.min_delay / 1000;
   
  // TODO you setup code 
   
} 

void loop()  
{  
  // Delay between measurements.
  delay(delayMS);
  // Get temperature event and print its value.
  sensors_event_t event;
  dht.temperature().getEvent(&event);
  if (isnan(event.temperature)) {
    Serial.println(F("Error reading temperature!"));
  }
  
  RemoteXY_Handler (); 

  //Menampilkan Data Double/Float ke Aplikasi RemoteXY
  dtostrf(event.temperature, 0, 2, RemoteXY.text_1); // result: "1234.32"
  dtostrf(event.relative_humidity, 0, 2, RemoteXY.text_2); // result: "1234.32"
//  dtostrf(event.relative_humidity, 0, 2, RemoteXY.text_3); // result: "1234.32" 
  
  // TODO you loop code 
  //Menampilkan String di RemoteXY
// strcpy(RemoteXY.text_1, "Adaa");
//  strcpy(RemoteXY.text_2, "Keluarr");
//  strcpy(RemoteXY.text_3, "Naikkk");

}
