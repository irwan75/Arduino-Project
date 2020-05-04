#include <GSM.h> 

#define PINNUMBER "" // Nomor PIN kartu SIM (jika ada)

GSM gsmAccess;
GSM_SMS sms;

void setup() {
  Serial.begin(9600);
  Serial.println("SMS Messages Sender by Cronyos.com");
  boolean notConnected = true;

    while (notConnected) {
    if (gsmAccess.begin(PINNUMBER) == GSM_READY) {
      notConnected = false;
    } else {
      Serial.println("Gagal Mengakses Kartu SIM");
      delay(1000);
    }
  }

  Serial.println("Kartu SIM terAkses");
   Serial.println("Mengirim SMS...");
// kirim SIM
  sms.beginSMS("085728775753"); // Nomor Tujuan
  sms.print("SMS Cinta dari Cronyos.com");
  sms.endSMS();
  Serial.println("SMS Terkirim !!!");
}

void loop() {

}
