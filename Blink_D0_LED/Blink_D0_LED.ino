void setup() {
   pinMode(D0, OUTPUT);
   // Phi board v1.0(NodeMCU v1.0)의 D0 핀에는 LED가 연결되어 있음.
}

void loop() {
   digitalWrite(D0, LOW);  // LED On 
   delay(1000);
   digitalWrite(D0, HIGH); // LED Of.
   delay(3000);
}
// Phi board v1.0(NodeMCU)의 D0 핀에는 연결된 LED는 LOW 신호 공급될 때 점등(On)되는 구조
// 위 코드가 실행될 경우 D0핀에 연결된 LED는 
// 점등(On) 되어 있는 시간보다 소등(Off) 되어 있는 시간이 더 김
