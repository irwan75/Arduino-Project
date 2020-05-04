void setup() {
  Serial.begin(9600);
}

void loop() {
  int sensorValue = analogRead(A0);
  float voltage = sensorValue * (5.0 / 529.069767);
  float phFix = (7.0*voltage)-16.76;
  Serial.print("Analog : "); Serial.println(sensorValue);
  Serial.print("Voltage : "); Serial.println(voltage);
  Serial.print("Ph : "); Serial.println(phFix);
  delay(500);
}
