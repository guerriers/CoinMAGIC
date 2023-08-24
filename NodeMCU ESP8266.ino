void Line_Notify(String message) ;
#include <ESP8266WiFi.h>
#include <WiFiClientSecureAxTLS.h>  
// Config connect WiFi
#define WIFI_SSID "ff"
#define WIFI_PASSWORD "112233"
#define LINE_TOKEN "3M2ufrOAN9k6B91rBs9UJk7DZU7wLlBSDIZdlTWiOv1"
 void setup() {

  Serial.begin(9600);

   WiFi.mode(WIFI_STA);
  // connect to wifi.
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("connecting");

  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  Serial.println();
  Serial.print("connected: ");
  Serial.println(WiFi.localIP());
}
  
//  while (!Serial) {
//    ; // wait for serial port to connect. Needed for native USB port only
//  }

void loop() { // run over and over
  if (Serial.available()) {
      String a = Serial.readString();
      String message = "หยอดเหรียญ"+a;
      Serial.print(message);
      Line_Notify(message);
  }
}

void Line_Notify(String message) {
  axTLS::WiFiClientSecure client;

  if (!client.connect("notify-api.line.me", 443)) {
    Serial.println("connection failed");
    return;   
  }

  String req = "";
  req += "POST /api/notify HTTP/1.1\r\n";
  req += "Host: notify-api.line.me\r\n";
  req += "Authorization: Bearer " + String(LINE_TOKEN) + "\r\n";
  req += "Cache-Control: no-cache\r\n";
  req += "User-Agent: ESP8266\r\n";
  req += "Connection: close\r\n";
  req += "Content-Type: application/x-www-form-urlencoded\r\n";
  req += "Content-Length: " + String(String("message=" + message).length()) + "\r\n";
  req += "\r\n";
  req += "message=" + message;
  client.print(req);
    
  delay(20);

  // Serial.println("-------------");
  while(client.connected()) {
    String line = client.readStringUntil('\n');
    if (line == "\r") {
      break;
    }
    //Serial.println(line);
  }
  // Serial.println("-------------");
}