#include <GSM.h>

#define PINNUMBER "" // Nomor PIN kartu SIM (jika ada)


GSM gsmAccess;
GSM_SMS sms;

char senderNumber[20]; // array untuk menampung teks pesan

void setup() {
  Serial.begin(9600);
  Serial.println("SMS Messages Receiver");
  boolean notConnected = true;

  // Start GSM connection
  while (notConnected) {
    if (gsmAccess.begin(PINNUMBER) == GSM_READY) {
      notConnected = false;
    } else {
       Serial.println("Gagal Mengakses Kartu SIM");
      delay(1000);
    }
  }

 Serial.println("Kartu SIM terAkses");
  Serial.println("Menunggu SMS...");
}

void loop() {
  char c;

  
  if (sms.available()) { // Jika ada SMS Masuk
    Serial.println("SMS Masuk dari:");

    sms.remoteNumber(senderNumber, 20); // menampung nomor pengirim
    Serial.println(senderNumber); // print nomor pengirim

     while (c = sms.read()) { // print isi SMS
      Serial.print(c);
    }

       
    sms.flush(); // Hapus SMS dari Memori
    Serial.println("SMS terhapus");
  }

  delay(1000);

}
