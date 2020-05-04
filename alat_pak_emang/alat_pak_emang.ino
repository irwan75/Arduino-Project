#include <Wire.h>
#include <Adafruit_MLX90614.h>
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x3F,16,2);
Adafruit_MLX90614 mlx = Adafruit_MLX90614();

int const relay1 = 2;
int const relay2 = 3; 

void setup() {
  pinMode(relay1, OUTPUT);
  pinMode(relay2, OUTPUT);
  Serial.begin(9600);
  Serial.println("Adafruit MLX90614 test");  
  digitalWrite(relay1, HIGH);
  digitalWrite(relay2, HIGH);
  mlx.begin();
  lcd.init();                      // initialize the lcd 
  lcd.init();
}

void loop() {
//  Serial.print("Ambient = "); Serial.print(mlx.readAmbientTempC()); 
//  Serial.print("*C\tObject = "); Serial.print(mlx.readObjectTempC()); Serial.println("*C");

  int sensorValue = analogRead(A0);
  float voltage = sensorValue * (5.0 / 529.069767);
  float phFix = (7.0*voltage)-16.76;
//  Serial.print("Analog : "); Serial.println(sensorValue);
//  Serial.print("Voltage : "); Serial.println(voltage);
//  Serial.print("Ph : "); Serial.println(phFix);

  // Print a message to the LCD.
  lcd.backlight();
  lcd.setCursor(1,0);
  lcd.print("Suhu = "); lcd.print(mlx.readObjectTempC()); lcd.println(" *C");
  lcd.setCursor(1,1);
  lcd.print("pH = "); lcd.println(phFix);

  if(phFix<=6){
    digitalWrite(relay1, LOW);
//    Serial.println("Relay 1 Nyala");
  }else if(phFix>6){
    digitalWrite(relay1, HIGH);
//    Serial.println("Relay 1 Mati");
  }
  if(phFix>=8){
    digitalWrite(relay2, LOW);
//    Serial.println("Relay 2 Nyala");
  }else if(phFix<8){
    digitalWrite(relay2, HIGH);
//    Serial.println("Relay 2 Mati");
  }
  delay(500); 
}
