#define LED_BUILTIN 4
int freq = 5000;
int ledChannel = 0;
int resolution = 8;

void setup() {
  // put your setup code here, to run once:
  ledcSetup(ledChannel, freq, resolution);
  ledcAttachPin(LED_BUILTIN, ledChannel);

}

void loop() {
  // put your main code here, to run repeatedly:
  for (int dutycycle = 0; dutycycle <= 255; dutycycle++) {
    ledcWrite(ledChannel, dutycycle);
    delay(7);
  }
  for (int dutycycle = 255; dutycycle >= 0; dutycycle--) {
    ledcWrite(ledChannel, dutycycle);
    delay(7);
  }
}
