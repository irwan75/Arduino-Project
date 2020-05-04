const int pushButton = 2;

int hasil=0;

void setup() {
  // put your setup code here, to run once:
  pinMode(pushButton, INPUT);
  attachInterrupt(digitalPinToInterrupt(pushButton),counter,FALLING);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
//  hasil = digitalRead(pushButton);
  Serial.println(hasil);
}

void counter(){
  hasil = hasil+1;
}
