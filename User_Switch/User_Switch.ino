#define USER_LED  D0
#define USER_SW   D8

void setup() {
   pinMode(USER_LED, OUTPUT); // USER_LED(D0)핀에는 LED가 부논리로 연결되어 있음(LOW 출력 --> LED On).
   pinMode(USER_SW, INPUT);   // USER_SW(D8)핀에는 User Switch가 연결되어 있음(normal open 타입)
}                             // User Switch를 누르면 USER_SW(D8)핀은 HIGH 상태로 변경.
                              // User Switch를 누르지 않으면 USER_SW(D8)핀의 상태는 LOW.

void loop() {
   int userSwitch = digitalRead(USER_SW);
   digitalWrite(USER_LED, userSwitch);  // USER_LED(D0) 핀이 LOW 출력일 때 User LED On!
}                                       // USER_LED(D0) 핀이 HIGH 출력일 때 User LED Off.
