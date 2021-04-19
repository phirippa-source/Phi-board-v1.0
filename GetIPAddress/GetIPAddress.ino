#include <ESP8266WiFi.h>
const char* ssid = "RiatechChief_2G";
const char* password = "12345678";
void setup() {
  Serial.begin(9600);
 
  //공유기에 접속하겠다는 안내글 출력
  Serial.print("\nConnecting to ");
  Serial.println(ssid);

  // 해당 공유기에 접속을 시도
  WiFi.begin(ssid, password);
  
  // Phi 보드의 WiFi 상태를 조사함
  // Phi 보드의 WiFi 장치가 공유기에 접속되지 않았다면
  // 지속적으로 WiFi 상태를 조사해서 접속되면 while 루프를 빠져 나감
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  Serial.println("\nWiFi Connected");
  
  // 공유기로부터 할당 받은 "(사설)IP 주소" 출력
  // 시리얼 출력된 IP address는 공유기로부터 할당받은 Phi 보드의 IP 주소임.
  Serial.print("Local IP address : ");
  Serial.println(WiFi.localIP());
 }

void loop() {
}
