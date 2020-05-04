#include <Wire.h>
#include <SparkFunMLX90614.h>

IRTherm therm;

void setup() {
  Serial.begin(9600);
  therm.begin();
  therm.setUnit(TEMP_C);        //selected temperature celcius
}

void loop() {
    
    if(therm.read()){             //On Success, read() will return 1, On Fail 0

    Serial.print("Object: " +String(therm.object(), 2));
    Serial.write('*');
    Serial.println("C");
    Serial.print("Ambient:  "+String(therm.ambient(), 2));
    Serial.write('*');
    Serial.println("C");
    Serial.println();
    delay(20);
      }          
}
