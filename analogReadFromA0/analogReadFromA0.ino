// Phi board v1.0의 A0에는 포텐셔미터(potentiometer)가 연결되어 있음.
// Phi board v1.0의 MCU인 ESP-12E에 내장된 ADC는 10bit 분해능.

void setup() {
  Serial.begin(9600);
}

void loop() {
  Serial.println( analogRead(A0) );
  delay(500);
}

// 포텐셔미터와 기타 회로가 이상적이다라고 가정하면
// 시리얼 모니터에서 출력될 수 있 하한값은 0이며 상한값은 1023임.
// 회로의 특성에 따라 하한값과 상한값이 조금 달라 질 수 있음. 
