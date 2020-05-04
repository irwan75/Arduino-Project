int trigPin1=10;
int echoPin1=11;

void setup() {
  Serial.begin (9600);
  pinMode(trigPin1, OUTPUT);
  pinMode(echoPin1, INPUT);
}

void loop() {
  //this for 1 ultrasonic{
  int duration, distance;
  digitalWrite (trigPin1, HIGH);
  delayMicroseconds (10);
  digitalWrite (trigPin1, LOW);
  duration = pulseIn (echoPin1, HIGH);
  distance = (duration/2) / 29.2;

      Serial.print(distance);   
      Serial.print("cm");
      Serial.println();
      delay(1000);
  //}
}
