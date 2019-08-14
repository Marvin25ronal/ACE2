#include <ESP8266WiFi.h>
#include "ESP8266HTTPClient.h"
const char* ssid="Familion Martinez";
const char* password="Marvin25";


void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(2,OUTPUT);
  Serial.print("Wifi connecting to ");
  Serial.println( ssid );

  WiFi.begin(ssid,password);

  Serial.println();
  Serial.print("Connecting");

  while( WiFi.status() != WL_CONNECTED ){
      delay(500);
      Serial.print(".");        
  }
   Serial.println();

  Serial.println("Wifi Connected Success!");
  Serial.print("NodeMCU IP Address : ");
  Serial.println(WiFi.localIP() );
}


void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(2,HIGH);
  Serial.println("hola0");
  prueba();
  delay(5000);
}
void prueba(){
  if(WiFi.status()==WL_CONNECTED){
    HTTPClient http;
    Serial.print("[HTTP] begin..\n");
 //  http.begin("http://api.thingspeak.com/channels/309236/feeds/last.txt"); //HTTP
    http.begin("https://www.google.com", "9ba996f2c2eb712b55920dcebf39532761a7b8bd"); //HTTPS
    Serial.println("[HTTP] GET ...");
    int httpCode=http.GET();
    if (httpCode > 0) {
      Serial.printf("[HTTP] GET... code: %d\n", httpCode);
      if (httpCode == HTTP_CODE_OK) {
        String payload = http.getString();
        Serial.println(payload);
        Serial.print("ok");
      }
    } else {
      Serial.printf("[HTTP] GET... failed, error: %s\n", http.errorToString(httpCode).c_str());
    }
    http.end();
  }else {
    Serial.print("Error al enviar");
  }
}
