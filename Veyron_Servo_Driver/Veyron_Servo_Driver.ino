void setup() {
  Serial.begin(115200);//Set the baudrate to 115200 A:1  B:1
  delay(100);//wait for baudrate setting finished
}

void loop() {
  Serial.print("#4 P750");// Channel 5 will move to 750us within 500ms
  delay(5);               //wait for first comand transmission done, if you send
  // a long command, you'd better extend it
  Serial.print("\r");    // send Carriage Return <CR>
  delay(1000);            //wait for servo go to the set position
  Serial.print("#4 P2200");// Channel 5 will move to 2200us within 500ms
  delay(5);
  Serial.print("\r");
  delay(1000);
}
