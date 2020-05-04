#define TRIG_PIN  7
#define ECHO_PIN  6
 
const uint8_t BATAS_BAWAH = 4;
const uint16_t BATAS_ATAS = 300;
 
 
int sonar(void);
 
void setup() 
{
  Serial.begin(9600);
  pinMode(ECHO_PIN, INPUT);
  pinMode(TRIG_PIN, OUTPUT);
}
 
void loop()
{
  int jarak = sonar();
  Serial.print("Jarak dalam satuan cm:  ");
  // Serial.println( sonar() );
  if(jarak<BATAS_BAWAH)
  {
    Serial.println("Obyek terlalu dekat");
  }
  else if(jarak>BATAS_ATAS)
  {
    Serial.println("Terlalu jauh");
  }
  else
  {
    Serial.println(jarak);
  }
 
  delay(1000);
}
 
 
int sonar(void) 
{
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);
 
  int jarak = pulseIn(ECHO_PIN, HIGH);  
  
  return (jarak = jarak / 58);
}
