void setup() {
   Serial.begin(9600);
}
byte count = 0;
void loop() {
   Serial.print("This is a Phi board v1.0 : ");
   Serial.println(count++);
   delay(100);    // 0.1초 지연
}

// byte 형 변수는 0부터 255까지 저장(표현) 가능.
// 따라서 0, 1, 2, ... 255까지 증가후 다시 0, 1, 2, ... 255까지 증가하기를 반복함.
