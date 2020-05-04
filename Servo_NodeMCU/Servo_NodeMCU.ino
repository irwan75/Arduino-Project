#define LED_BUILTIN 13
int freq = 100;
int ledChannel = 1;
int resolution = 8;

void setup() {
  // put your setup code here, to run once:
  ledcSetup(ledChannel, freq, resolution);
  ledcAttachPin(LED_BUILTIN, ledChannel);

}

void loop() {
  // put your main code here, to run repeatedly:
  for (int dutycycle = 0; dutycycle <= 180; dutycycle++) {
    ledcWrite(ledChannel, dutycycle);
    delay(7);
  }
  for (int dutycycle = 180; dutycycle >= 0; dutycycle--) {
    ledcWrite(ledChannel, dutycycle);
    delay(7);
  }
//  ledcWrite(ledChannel, 180);
//  delay(1000);
//  ledcWrite(ledChannel, 0);
//  delay(1000);
}
