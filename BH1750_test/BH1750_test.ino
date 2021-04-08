// 아래 예제 코드는 
// BH1750 lib. by Christopher Laws 버전 1.1.4를 설치.
// 아두이노 IDE의 주 메뉴에서 '파일/예제/BH1750/BH1750test"와 동일(유사)


#include <Wire.h>
#include <BH1750.h>

BH1750 lightMeter;
// Phi board v1.0에 부착된 BH1750의 I2C Address는 0x23

void setup(){
  Serial.begin(9600);
  Wire.begin();
  lightMeter.begin();
  Serial.println(F("BH1750 Test begin"));
}

void loop() {
  float lux = lightMeter.readLightLevel();
  Serial.print("Light: ");
  Serial.print(lux);
  Serial.println("[lx]");
  delay(1000);
}
