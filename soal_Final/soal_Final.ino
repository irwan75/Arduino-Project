void setup() {
  //LED
  pinMode(    ,OUTPUT);
  pinMode(    ,OUTPUT);

  //Seven Segment
  for(int b=2;b<=9;b++){
    pinMode(    ,OUTPUT);
  }
}

void loop() {
  //LED
  digitalWrite(    ,HIGH);
  digitalWrite(    ,HIGH);

  //OnOff dan Kedap Kedip
  onOff_kedap();

  //Angka 7
  digitalWrite(     ,LOW);
  digitalWrite(     ,HIGH);
  digitalWrite(     ,LOW);
  digitalWrite(     ,HIGH);
  digitalWrite(     ,LOW);
  digitalWrite(     ,HIGH);
  digitalWrite(     ,HIGH);
  digitalWrite(     ,LOW);

  //Loading Seven Segment
  loading();
}

void loading(){
  for(int c=   ;c<=9;c++){
    digitalWrite(     ,HIGH);
    delay(50);
  }for(int c=2;c<=   ;c++){
    digitalWrite(     ,LOW);
    delay(50);
  }
}

void onOff_kedap(){
  for(int i=0;i<   ;i++){
    digitalWrite(    ,HIGH);
    digitalWrite(    ,HIGH);
    delay(     );
    digitalWrite(    ,LOW);
    digitalWrite(    ,LOW);
    delay(     );
  }for(int a=   ;a<10;a++){
    digitalWrite(   ,HIGH);
    delay(     );
    digitalWrite(   ,LOW);
    digitalWrite(   ,HIGH);
    delay(     );
    digitalWrite(   , LOW);
  }
}
