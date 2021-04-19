// Phi board v1.0
// 작성자 : 김성필
// 작성 일자 : 2021-04-19

// Phi board v1.0의 USER_SW는 D8에 연결되어 있음.
#define USER_SW D8
// Pull down 형태로 USER_SW 회로가 구성되어 있어
// 스위치를 누르지 않을 경우 USER_SW가 연결된 D8 핀은 LOW 상태
// 스위치를 누르면 USER_SW가 연결된 D8 핀은 HIGH 상태가 됨

void setup() {
  Serial.begin(9600);
  pinMode(USER_SW, INPUT);
}
void onePressUSER_SW(void) {
  while( !digitalRead(USER_SW) ) {  // 스위치가 눌리지 않았을 때 
    delay(1);                       // digitalRead(USER_SW)의 반환 값은 LOW, 0
  }                                 // 따라서 !digitatRead(USER_SW)의 반환 값은 HIGH, 1
                                    // 스위치가 눌리지 않았다면 무한히 대기함.
  Serial.println("\nThe USER_SW is pressed");

  while( digitalRead(USER_SW) ) {
    delay(1);
  }
  Serial.println("The USER_SW is released");
}

void loop() {
  onePressUSER_SW();
}
