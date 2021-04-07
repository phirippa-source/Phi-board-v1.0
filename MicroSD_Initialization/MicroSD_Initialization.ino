#include <SPI.h>
#include <SD.h>
#define CS_PIN  D3  // MicroSD 소켓의 Chip Selection 핀은 Phi boarad v1.0의 D3핀에 연결.

File myFile;

void setup() {
  Serial.begin(9600);
  Serial.println();
  Serial.println("Initializing SD card...");

  if ( !SD.begin(CS_PIN) ) {  // MicroSD card 초기화. 성공하면 True, 실패하면 False 리턴
    Serial.println("Initialization failed!"); // MicroSD card 소켓 인식 실패
    return;
  }
  Serial.println("Initialization done.");     // MicroSD card 소켓 인식 성공
}

void loop() {
}
