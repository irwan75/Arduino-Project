/*====================================================================================================== 
   Termômetro Infravermelho com MLX90614 e Arduino UNO

   WR Kits & Usina Info


   MLX90614 ------------- Arduino
   VDD ------------------ 3.3V
   VSS ------------------ GND
   SDA ------------------ SDA (A4 on older boards)
   SCL ------------------ SCL (A5 on older boards)


   Autor: Eng. Wagner Rambo
   Data: Novembro de 2016

   www.wrkits.com.br | facebook.com/wrkits | youtube.com/canalwrkits

 
======================================================================================================*/

//======================================================================================================
// --- Bibliotecas Auxiliares ---
#include <Wire.h>                //Biblioteca para I2C
#include <SparkFunMLX90614.h>    //Biblioteca SparkFunMLX90614


//======================================================================================================
// --- Objetos ---
IRTherm therm;                   //Cria um objeto para o sensor de temperatura infravermelho


 


//======================================================================================================
// --- Configurações Iniciais ---
void setup() 
{
  Serial.begin(9600);             //Inicializa comunicação serial em 9600 de baud rate
  therm.begin();                  //Inicializa sensor de temperatura infravermelho
  therm.setUnit(TEMP_C);          //Seleciona temperatura em Celsius
    
} //end setup


//======================================================================================================
// --- Loop Infinito ---
void loop() 
{
   
  
  // Call therm.read() to read object and ambient temperatures from the sensor.
  if (therm.read()) // On success, read() will return 1, on fail 0.
  {
    // Use the object() and ambient() functions to grab the object and ambient
  // temperatures.
  // They'll be floats, calculated out to the unit you set with setUnit().
    Serial.print("Object: " + String(therm.object(), 2));
    Serial.write('°'); // Degree Symbol
    Serial.println("C");
    Serial.print("Ambient: " + String(therm.ambient(), 2));
    Serial.write('°'); // Degree Symbol
    Serial.println("C");
    Serial.println();
  }
 

  delay(1500);
  
} //end setup





