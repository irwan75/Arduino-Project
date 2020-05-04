// ---------- Tes Uji Coba SIM800L Modul dengan Arduino ---------- //
// --------------- Dibuat Oleh : M. Nofgi Y.P.U. ----------------- //
// --------------- www.nofgipiston.wordpress.com ----------------- //

#include 

SoftwareSerial SIM800L(7, 8); // RX,TX

void setup()
{
 // setting baud rate serial monitor
 Serial.begin(9600);
 while (!Serial);

// setting baud rate sim 800l
 Serial.println("Inisialisasi modul SIM800L");
 SIM800L.begin(115200);
 delay(1000);

// ------------------ Mulai Mengirim SMS ------------------- //

Serial.println("Tes Uji Coba Kirim SMS...");

// setting ke mode teks untuk pengiriman sms
 SIM800L.write("AT+CMGF=1\r\n");
 delay(1000);

// setting nomor tujuan
 SIM800L.write("AT+CMGS=\"089999999917\"\r\n"); // no tujuan sms
 delay(1000);

// setting isi teks sms
 SIM800L.write("Mencoba Mengirim SMS"); // teks isi sms
 delay(1000);

// mengirim char ctrl+z/esc untuk keluar dari menu sms
 SIM800L.write((char)26); // CTRL-Z
 delay(1000);

Serial.println("SMS Telah dikirim!");
}

void loop()
{
}
