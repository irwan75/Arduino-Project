int trigPin1=2;
int echoPin1=3;

int trigPin2=4;
int echoPin2=5;

int trigPin3=6;
int echoPin3=7;

int trigPin4=8;
int echoPin4=9;

int trigPin5=10;
int echoPin5=11;

double maxDepan = 15;
double maxKanan = 15;
double minKiri = 10;
double maxKiri = 10;

void forward(){
  Serial.println("Maju Teruss!!");
  delay(200);
}

void turnLeft(){
  Serial.println("Hadap Kiri!!");
  delay(200);
}

void turnRight(){
  Serial.println("Hadap Kanan!!");
  delay(200);
}

void setup() {
  Serial.begin(9600);
  
  pinMode(trigPin1, OUTPUT);
  pinMode(echoPin1, INPUT);
  pinMode(trigPin2, OUTPUT);
  pinMode(echoPin2, INPUT);
  pinMode(trigPin3, OUTPUT);
  pinMode(echoPin3, INPUT);
  pinMode(trigPin4, OUTPUT);
  pinMode(echoPin4, INPUT);
  pinMode(trigPin5, OUTPUT);
  pinMode(echoPin5, INPUT);
}

void loop() {
//Ultrasonic_1
int duration1, distance1;
digitalWrite(trigPin1, HIGH);
delay(10);
digitalWrite(trigPin1, LOW);
duration1 = pulseIn (echoPin1, HIGH);
distance1 = (duration1/2) / 29.1;

Serial.print("Ultrasonic 1 : ");
Serial.print(distance1);
Serial.print("cm\n");
delay(500);


//Ultrasonic_2
int duration2, distance2;
digitalWrite(trigPin2, HIGH);
delay(10);
digitalWrite(trigPin2, LOW);
duration2 = pulseIn (echoPin2, HIGH);
distance2 = (duration2/2) / 29.1;

//Serial.print("Ultrasonic 2 : ");
//Serial.print(distance2);
//Serial.print("cm\n");
//delay(500);


//Ultrasonic_3
int duration3, distance3;
digitalWrite(trigPin3, HIGH);
delay(10);
digitalWrite(trigPin3, LOW);
duration3 = pulseIn (echoPin3, HIGH);
distance3 = (duration3/2) / 29.1;

//Serial.print("Ultrasonic 3 : ");
//Serial.print(distance3);
//Serial.print("cm\n");
//delay(500);


//Ultrasonic_4
int duration4, distance4;
digitalWrite(trigPin4, HIGH);
delay(10);
digitalWrite(trigPin4, LOW);
duration4 = pulseIn (echoPin4, HIGH);
distance4 = (duration4/2) / 29.1;

Serial.print("Ultrasonic 4 : ");
Serial.print(distance4);
Serial.print("cm\n");
delay(500);


//Ultrasonic_5
int duration5, distance5;
digitalWrite(trigPin5, HIGH);
delay(10);
digitalWrite(trigPin5, LOW);
duration5 = pulseIn (echoPin5, HIGH);
distance5 = (duration5/2) / 29.1;

Serial.print("Ultrasonic 5 : ");
Serial.print(distance5);
Serial.print("cm\n");
delay(500);

//Wall Follower Kanan
if(distance4<maxDepan && distance1>=15){
  forward();
}else if(distance4>12 && distance1>=15){
  Serial.println("Kiri-kiri Sedikit");
}
else if(distance4>maxDepan && distance5<10){
  Serial.println("Kanan-kanan Sedikit");
}else if(distance1<maxDepan && distance4<maxKanan && distance5>=15){
  turnLeft();
}else if(distance5>=15 && distance1>=15 && distance4>=15){
  turnRight();
}

}
