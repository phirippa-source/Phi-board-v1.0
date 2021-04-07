#include <SPI.h>
#include <SD.h>
#define CS_PIN  D3  // MicroSD 소켓의 Chip Selection 핀은 Phi boarad v1.0의 D3핀에 연결.

File myFile;

void setup() {
  Serial.begin(9600);
  Serial.println();
  Serial.println("Initializing SD card...");

  if ( !SD.begin(CS_PIN) ) {  // MicroSD card 초기화. 성공하면 True, 실패하면 False 리턴
    Serial.println("Initialization failed!");     // MicroSD card 소켓이 인식 실패
    Serial.println("1. Check the memory card");   // 1. Memory card의 불량 여부 조사
    Serial.println("2. reinsert the memory card");// 2. 접촉불량 - 재 삽입
    return;
  }
  Serial.println("Initialization done.");     // MicroSD card 소켓이 인식 성공
}

void loop() {
}
