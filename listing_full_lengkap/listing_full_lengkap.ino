#include <Adafruit_Sensor.h>
#include "DHT.h"
#include <MQ2.h>
#include <SoftwareSerial.h>
SoftwareSerial SIM800L(22, 24); 

#define DHTPIN 2
int api;
int led = 13;

//Define Sensor Gas
int pinAout = A1;
int lpg_gas, co_gas, smoke_gas;
MQ2 mq2(pinAout);

#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);

  //Listing DHT11
  Serial.println("DHTxx test!");
  dht.begin();

  //Listing Sensor Api
  pinMode(A0, INPUT);

  //Listing Deteksi Led
  pinMode(led, OUTPUT);
  
  //Listing start Sensor MQ-2
  mq2.begin();

  //Listing Ready SIM800L
  SIM800L.begin(9600);  
  SIM800L.println("AT+CMGF=1");
  Serial.println("SIM800L started at 9600");
  delay(1000);
  SIM800L.println("AT+IPR=9600");
  delay(1000);
  Serial.println("Setup Complete! SIM800L is Ready!");
  SIM800L.println("AT+CNMI=2,2,0,0,0");

  //Listing Start Sim800L
  SIM800L.println("AT+CMGF=1");   
  delay(1000);
}

void Nomor1(String apiInf){
  SIM800L.println("AT+CMGF=1"); 
  delay(1000);
  SIM800L.println("AT+CMSS=\"+6285298231608\"\r");
  delay(2000);
  SIM800L.println(apiInf);
  delay(100);
  SIM800L.println((char)26);
  delay(1000);
}

void Nomor2(String apiInf){
  SIM800L.println("AT+CMGF=1");   
  delay(1000);
  SIM800L.println("AT+CMSS=\"+6285756603224\"\r");
  delay(2000);
  SIM800L.println(apiInf);
  delay(100);
  SIM800L.println((char)26);
  delay(1000);  
}

void Nomor3(String apiInf){
  SIM800L.println("AT+CMGF=1"); 
  delay(1000);
  SIM800L.println("AT+CMSS=\"+6281242370123\"\r");
  delay(2000);
  SIM800L.println(apiInf);
  delay(100);
  SIM800L.println((char)26);
  delay(1000);
}

void Nomor4(String apiInf){
  SIM800L.println("AT+CMGF=1"); 
  delay(1000);
  SIM800L.println("AT+CMGS=\"+62895800148010\"\r");
  delay(2000);
  SIM800L.println(apiInf);
  delay(100);
  SIM800L.println((char)26);
  delay(1000);
}

void Api(){
  api = analogRead(A0);
  Serial.println(api);
  delay(100);
}

void loop() {
  delay(2000);

  float h = dht.readHumidity();
  // Read temperature as Celsius (the default)
  float t = dht.readTemperature();
  // Read temperature as Fahrenheit (isFahrenheit = true)
  float f = dht.readTemperature(true);

  // Check if any reads failed and exit early (to try again).
  if (isnan(h) || isnan(t) || isnan(f)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  // Compute heat index in Fahrenheit (the default)
  float hif = dht.computeHeatIndex(f, h);
  // Compute heat index in Celsius (isFahreheit = false)
  float hic = dht.computeHeatIndex(t, h, false);

  Serial.print("Humidity: ");
  Serial.print(h);
  Serial.print(" %\t");
  Serial.print("Temperature: ");
  Serial.print(t);
  Serial.print(" *C ");
  Serial.print(f);
  Serial.print(" *F\t");
  Serial.print("Heat index: ");
  Serial.print(hic);
  Serial.print(" *C ");
  Serial.print(hif);
  Serial.println(" *F");

  Api();
  delay(1000);

    //Listing Sensor Asap
  float* values= mq2.read(true); //jika diset "false" tidak akan dimunculkan di serial monitor
  
  lpg_gas = mq2.readLPG();
  co_gas = mq2.readCO();
  smoke_gas = mq2.readSmoke();
  delay(1000);

  if(api<400 && (lpg_gas <=3 || co_gas <=3 || smoke_gas <= 3)){
    Nomor1("Api Terdeteksi \n Asap Terdeteksi \n Humidity : ");
    delay(5000);
    Nomor2("Api Terdeteksi \n Asap Terdeteksi \n Humidity : ");
    delay(5000);
    Nomor3("Api Terdeteksi \n Asap Terdeteksi \n Humidity : ");
    delay(5000);
    Nomor4("Api Terdeteksi \n Asap Terdeteksi \n Humidity : ");
    delay(5000); 
  }
  
  else if(api<400){
    Nomor1("Api Terdeteksi");
    delay(5000);
    Nomor2("Api Terdeteksi");
    delay(5000);
    Nomor3("Api Terdeteksi");
    delay(5000);
    Nomor4("Api Terdeteksi");
    delay(5000);
  }

  else if(lpg_gas <= 3 || co_gas <=3 || smoke_gas <= 3){
    Nomor1("Asap Terdeteksi");
    delay(5000);
    Nomor2("Asap Terdeteksi");
    delay(5000);
    Nomor3("Asap Terdeteksi");
    delay(5000);
    Nomor4("Asap Terdeteksi");
    delay(5000);
  }

  digitalWrite(led, HIGH);   // turn the LED on (HIGH is the voltage level)
}
