
/*
 * Created by K. Suwatchai (Mobizt)
 * 
 * Email: k_suwatchai@hotmail.com
 * 
 * Github: https://github.com/mobizt
 * 
 * Copyright (c) 2019 mobizt
 * 
 * This example is for FirebaseESP8266 Arduino library v 2.6.0 and later
 *
*/


//FirebaseESP8266.h must be included before ESP8266WiFi.h
#include "FirebaseESP8266.h"
#include <ESP8266WiFi.h>

#define FIREBASE_HOST "https://node-mcu-iot-cc9b7.firebaseio.com/"
#define FIREBASE_AUTH "osMh2S47kCevIFLzr7l00DRkQgnpiCjPoJwHUjrZ"
#define WIFI_SSID "Mate9"
#define WIFI_PASSWORD "ed66abe688e"

//Define FirebaseESP8266 data object
FirebaseData firebaseData;

void printResult(FirebaseData &data);

String bio[] = {"Aldi","Fairuz","Titik","Malona","Digi","Talent"};

void setup()
{

  Serial.begin(115200);

  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("Connecting to Wi-Fi");
  while (WiFi.status() != WL_CONNECTED)
  {
    Serial.print(".");
    delay(300);
  }
  Serial.println();
  Serial.print("Connected with IP: ");
  Serial.println(WiFi.localIP());
  Serial.println();

  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
  Firebase.reconnectWiFi(true);

  //Set database read timeout to 1 minute (max 15 minutes)
  Firebase.setReadTimeout(firebaseData, 1000 * 60);
  //tiny, small, medium, large and unlimited.
  //Size and its write timeout e.g. tiny (1s), small (10s), medium (30s) and large (60s).
  Firebase.setwriteSizeLimit(firebaseData, "tiny");
  
  /*
  This option allows get and delete functions (PUT and DELETE HTTP requests) works for device connected behind the
  Firewall that allows only GET and POST requests.
  
  Firebase.enableClassicRequest(firebaseData, true);
  */

  String path = "/Biodata";
 
  Serial.println("------------------------------------");
  Serial.println("Set double test...");

  for (uint8_t i = 0; i < 6; i++)
  {
    //Also can use Firebase.set instead of Firebase.setDouble
    if (Firebase.setString(firebaseData, path + "/Data" + (i+0), bio[i]))
    {
      Serial.println("PASSED");
      Serial.println("PATH: " + firebaseData.dataPath());
      Serial.println("TYPE: " + firebaseData.dataType());
      Serial.println("ETag: " + firebaseData.ETag());
      Serial.print("VALUE: ");
      printResult(firebaseData);
      Serial.println("------------------------------------");
      Serial.println();
    }
    else
    {
      Serial.println("FAILED");
      Serial.println("REASON: " + firebaseData.errorReason());
      Serial.println("------------------------------------");
      Serial.println();
    }
  }
}

void printResult(FirebaseData &data)
{
//    if (data.dataType() == "double")
//        printf("%.9lf\n", data.doubleData());
    if(data.dataType() == "string")
        Serial.println(data.stringData());
}

void loop()
{
}
