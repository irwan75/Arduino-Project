/* www.nyebarilmu.com */
//mengirim sms menggunakan ATCommand
 
#include <SoftwareSerial.h>
SoftwareSerial SIM800L(2, 3); // RX | TX
// Connect the TX to Arduino pin 2 RX. 
// Connect the RX to Arduino pin 3 TX. 
void setup() {
   //menggunakan baut komunikasi 9600 pada serial monitor
    Serial.begin(9600);
    while(!Serial);
    Serial.println("Arduino with Module GSM is ready");
 
    //menggunakan baut komunikasi 9600 antara module gsm dengan arduino
    SIM800L.begin(9600);  
    Serial.println("Module dimulai pada serial komunikasi 9600");
    delay(1000);//waktu jeda 1 detik
    Serial.println("SIM800L SIAP DIGUNAKAN!");
   
  Serial.println("Set format SMS ke ASCII"); //menset format SMS
  SIM800L.write("AT+CMGF=1\r\n"); //Prosedur penulisan oleh module sim800l
  delay(1000); //waktu jeda 1 detik
 
  Serial.println("SIM800 Set SMS ke Nomor Tujuan");
  //silahkan ganti no hp nya menjadi no hp ANDA
  SIM800L.write("AT+CMGS=\"085647156889\"\r\n");
  delay(1000);
   
  Serial.println("Module mengirimkan SMS ke no tujuan");
  //isi SMS yang ditujukan ke no hp diatas
  SIM800L.write("Testing SMS via SIM800 loh!"); 
  delay(1000);
   
  Serial.println("Ketik pada keyboard Ctrl+Z atau ESC > keluar menu ini");
  SIM800L.write((char)26);
  delay(1000);
     
  Serial.println("SMS Selesai Dikirim!");
}
 
void loop() {
}
