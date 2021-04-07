void setup() {
   Serial.begin(9600);
   // 아두이노의 송수신 속도(예, 9600[bps])와 시리얼모니터의 소수신 속도가 일치해야함.
}

void loop() {
   Serial.println("This is a Phi board v1.0");
   delay(1000);
}
