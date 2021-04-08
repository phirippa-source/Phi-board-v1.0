// Adafruit SSD1306 Lib. 설치
// Phi board v1.0에서 OLED(SSD1306)의 I2C Address는 0x3C

#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128  // Phi board v1.0의 OLED(SSD1306)은 화면은 128 x 64
#define SCREEN_HEIGHT 64
#define OLED_RESET -1  
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

void setup()   {                
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {  // I2C Address : 0x3C
    Serial.println(F("OLED(SSD1306) allocation failed"));
    while(1){} // OLED 초기화에 실패했을 경우 여기서 대기.
  }
  display.clearDisplay();
 
  display.setTextColor(WHITE);    // Phi board v1.0의 OLED는 한가지 색만 지원.
  display.println("Maker's Lab.");
  display.println("Phi board v1.0");
  display.display();
}

void loop() { }
