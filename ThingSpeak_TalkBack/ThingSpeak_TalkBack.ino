#include <WiFi.h>
#include <string.h>

char ssid[] = "Mate9";   // Your network SSID (name) 
char pass[] = "ed66abe688e";   // Your network password

WiFiClient  client;

int led = 2;

unsigned long myTalkBackID = 35569;
const char * myTalkBackKey = "PHRA10Y0Y8FZ7YCW";

void setup() {
  // put your setup code here, to run once:
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(115200);
  WiFi.mode(WIFI_STA);
}

void loop() {
  // put your main code here, to run repeatedly:
  //Connect or Reconnect to WiFi
  if(WiFi.status() != WL_CONNECTED){
    Serial.print("Attempting to connect to SSID: ");
    Serial.println(String(ssid));
    while(WiFi.status()!= WL_CONNECTED){
      WiFi.begin(ssid, pass);
      Serial.print(".");
      delay(5000);
    }
    Serial.println("\nConnected");
  }

  //Create the TalkBack URI
//  String tbURI = String("/talkbacks/") + String(myTalkBackID) + String("/commands/execute"); // membaca command_string di talkbacks

  String tbURI = String("/talkbacks/") + String(myTalkBackID) + String("/commands?"); //menulis command_string di talkbacks

   // Create the message body for the POST out of the values

  String postMessage =  String("api_key=") + String(myTalkBackKey); // untuk membaca data  
   
  String postMessage =  String("api_key=") + String(myTalkBackKey) + String("&command_string=nyala&position=5"); // untuk memasukkan data   

  // Make a string for any commands that might be in the queue
  String newCommand = String();

  // Make the POST to ThingSpeak
  int x = httpPOST(tbURI, postMessage, newCommand);
  client.stop();

  //Check the result
  if(x == 200){
    Serial.println("Checking Quee...");
    //Check for a command returned from talkback
    if(newCommand.length() != 0){
      Serial.print("Latest command from queue: ");
      Serial.println(newCommand);
      
      if(newCommand == "nyala"){
        digitalWrite(LED_BUILTIN, HIGH);
      }else if(newCommand == "mati"){
        digitalWrite(LED_BUILTIN, LOW);
      }
    }else{
      Serial.println(" Nothing New... ");
    }
  }else{
    Serial.println("Problem checking queu. HTTP error code " +String(x));
  }

  delay(60000);
}

int httpPOST(String uri, String postMessage, String &response){
  bool connectSuccess = false;
  connectSuccess = client.connect("api.thingspeak.com", 80);

  if(!connectSuccess){
    return -301;  
  }

  postMessage += "&header=false";

  String Headers =  String("POST ") + uri + String(" HTTP/1.1\r\n") +
                    String("Host: api.thingspeak.com\r\n") +
                    String("Content-Type: application/x-www-form-urlencoded\r\n") +
                    String("Connection: close\r\n") +
                    String("Content-Length: ") + String(postMessage.length()) +
                    String("\r\n\r\n");

  client.print(Headers);
  client.print(postMessage);

  long startWaitForResponseAt = millis();
  while(client.available() == 0 && millis() - startWaitForResponseAt < 5000){
    delay(100);    
  }

  if(client.available() == 0){       
    return -304; // Didn't get server response in time
  }

  if(!client.find(const_cast<char *>("HTTP/1.1"))){
      return -303; // Couldn't parse response (didn't find HTTP/1.1)
  }
  
  int status = client.parseInt();
  if(status != 200){
    return status;
  }

  if(!client.find(const_cast<char *>("\n\r\n"))){
    return -303;
  }

  String tempString = String(client.readString());
  response = tempString;
  
  return status;
}

