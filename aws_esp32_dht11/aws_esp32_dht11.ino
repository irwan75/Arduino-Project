#include <AWS_IOT.h>
#include <WiFi.h>
#include "DHT.h"

// include your personal WiFi and AWS configuration. 
#include "config.h"
uint8_t DHTPin = 13;
#define DHTTYPE DHT11

AWS_IOT hornbill;

int status = WL_IDLE_STATUS;
int tick=0,msgCount=0,msgReceived = 0;
char payload[512];
char rcvdPayload[512];

DHT dht(DHTPin, DHTTYPE);

void mySubCallBackHandler (char *topicName, int payloadLen, char *payLoad)
{
    strncpy(rcvdPayload,payLoad,payloadLen);
    rcvdPayload[payloadLen] = 0;
    msgReceived = 1;
}



void setup() {
    Serial.begin(9600);
    dht.begin();
    while (status != WL_CONNECTED)
    {
        Serial.print("Attempting to connect to SSID: ");
        Serial.println(WIFI_SSID);
        // Connect to WPA/WPA2 network. Change this line if using open or WEP network:
        status = WiFi.begin(WIFI_SSID, WIFI_PASSWORD);

        // wait 5 seconds for connection:
        delay(5000);
    }

    Serial.println("Connected to wifi");

    if(hornbill.connect(HOST_ADDRESS, CLIENT_ID,
                aws_root_ca_pem, certificate_pem_crt, private_pem_key)== 0)
    {
        Serial.println("Connected to AWS");
        delay(1000);

        if(0 == hornbill.subscribe(TOPIC_NAME,mySubCallBackHandler))
        {
            Serial.println("Subscribe Successfull");
        }
        else
        {
            Serial.println("Subscribe Failed, Check the Thing Name and Certificates");
            while(1);
        }
    }
    else
    {
        Serial.println("AWS connection failed, Check the HOST Address");
        while(1);
    }

    delay(2000);

}

int num;

void loop() {
    //Pembacaan untuk data kelembaban
//  float humidity_1 = dht.readHumidity();
  //Pembacaan dalam format celcius (c)
//  float celcius_1 = dht.readTemperature();

//  if (isnan(humidity_1) || isnan(celcius_1)) {
//    Serial.println("Pembacaan data dari module sensor gagal!");
//    return;
//  }
    String msg = String(num)+"\"";
//    Serial.println(msg);

    if(msgReceived == 1)
    {
        msgReceived = 0;
        Serial.print("Received Message:");
        Serial.println(rcvdPayload);
    }
    if(tick >= 5)   // publish to topic every 5seconds
    {
        tick=0;
        sprintf(payload,"{\n\t \"id\" : \"%s",msg);
        if(hornbill.publish(TOPIC_NAME,payload) == 0)
        {        
            Serial.print("Publish Message:");
            Serial.println(payload);
            num++;
        }
        else
        {
            Serial.println("Publish failed");
        }
    }  
    vTaskDelay(1000 / portTICK_RATE_MS); 
    tick++;
}
