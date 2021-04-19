#include <ESP8266WiFi.h>
#include <PubSubClient.h>

const char* ssid = "RiatechChief_2G";
const char* password = "12345678";

const char* boardName = "Phi-board9034";
char* server = "192.168.16.2"; //MQTT broker IP address

WiFiClient wifiClient; 
PubSubClient client(server, 1883, wifiClient);

void setup() {
  Serial.begin(9600);
 
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  Serial.println("\nWiFi Connected");
  Serial.print("Local IP address : ");
  Serial.println(WiFi.localIP()); 
   
  Serial.println("Connecting to broker");
  while ( !client.connect(boardName) ){ 
    Serial.print("*");
    delay(1000);
  }
  Serial.println("\nConnected to broker");
}

void loop() {}
