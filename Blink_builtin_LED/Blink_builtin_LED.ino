void setup() {
   pinMode(LED_BUILTIN, OUTPUT);
   // Phi board v1.0(NodeMCU v1.0)의 builtin(이미 {보드에}부착된) LED는
   // D4번 핀과 연결되어 있음.
}

void loop() {
   digitalWrite(LED_BUILTIN, LOW);  // LED On 
   delay(1000);
   digitalWrite(LED_BUILTIN, HIGH); // LED Of.
   delay(3000);
}
// Bulitin LED는 LOW 신호 공급될 때 점등(On)되는 구조
