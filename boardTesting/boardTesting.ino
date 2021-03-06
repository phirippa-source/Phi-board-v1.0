// Phi board v1.0 테스트 및 초기 코드
// 작성 일자 : 2021년 4월 16일
// 작성자 : 김성필(phirippa)
// 회사 이름(전화번호): Riatech(031-8060-7621)
#include <math.h>

// ---------- OLED(SSD1306)관련
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 
#define SCREEN_HEIGHT 64
#define OLED_RESET -1  
// ---------------------------

// ----------------- DHT11 관련
#include "DHT.h"
#define DHTPIN D4     
#define DHTTYPE DHT11

// ---------------- BH1750 관련
// #include <Wire.h>
#include <BH1750.h>
// ---------------------------

//----------------- ADS1015 관련
//#include <Wire.h>
#include <Adafruit_ADS1015.h>
//----------------------------

//----------------- LIS3DH 관련
#include "SparkFunLIS3DH.h"
//#include "Wire.h"
#include "SPI.h"
//----------------------------
//------- micorSD card 소켓 관련
//#include <SPI.h>
#include <SD.h>
#define  CS_PIN  D3
//----------------------------

// ---------------- WiFi 관련
#include <ESP8266WiFi.h>
// ---------------------------


const unsigned char phi_50x50[] PROGMEM = {
0x00, 0x00, 0x00, 0x00, 0x01, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x80, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x01, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x80, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x01, 0xff, 0xfe, 0x00, 0x00, 0x7f, 0xff, 0x80, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x01, 0xff, 0xfe, 0x00, 0x00, 0x7f, 0xff, 0x80, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x01, 0xff, 0xff, 0xf0, 0x0f, 0xff, 0xff, 0x80, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x01, 0xff, 0xff, 0xf8, 0x1f, 0xff, 0xff, 0x80, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x01, 0xff, 0xff, 0xf8, 0x1f, 0xff, 0xff, 0x80, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x01, 0xff, 0xff, 0xf8, 0x1f, 0xff, 0xff, 0x80, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x01, 0xff, 0xff, 0xf8, 0x1f, 0xff, 0xff, 0x80, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x01, 0xff, 0xff, 0xf8, 0x1f, 0xff, 0xff, 0x80, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x01, 0xff, 0xff, 0x00, 0x00, 0x7f, 0xff, 0x80, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x01, 0xff, 0xf8, 0x00, 0x00, 0x0f, 0xff, 0x80, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x01, 0xff, 0xe0, 0x78, 0x1e, 0x03, 0xff, 0x80, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x01, 0xff, 0x83, 0xf8, 0x1f, 0x81, 0xff, 0x80, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x01, 0xff, 0x07, 0xf8, 0x1f, 0xe0, 0x7f, 0x80, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x01, 0xfe, 0x1f, 0xf8, 0x1f, 0xf0, 0x3f, 0x80, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x01, 0xfc, 0x1f, 0xf8, 0x1f, 0xf8, 0x1f, 0x80, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x01, 0xf8, 0x3f, 0xf8, 0x1f, 0xfc, 0x1f, 0x80, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x01, 0xf0, 0x7f, 0xf8, 0x1f, 0xfc, 0x0f, 0x80, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x01, 0xf0, 0x7f, 0xf8, 0x1f, 0xfe, 0x0f, 0x80, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x01, 0xe0, 0x7f, 0xf8, 0x1f, 0xfe, 0x07, 0x80, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x01, 0xe0, 0x7f, 0xf8, 0x1f, 0xfe, 0x07, 0x80, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x01, 0xe0, 0xff, 0xf8, 0x1f, 0xfe, 0x07, 0x80, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x01, 0xe0, 0xff, 0xf8, 0x1f, 0xff, 0x07, 0x80, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x01, 0xe0, 0xff, 0xf8, 0x1f, 0xff, 0x07, 0x80, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x01, 0xe0, 0xff, 0xf8, 0x1f, 0xff, 0x07, 0x80, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x01, 0xe0, 0xff, 0xf8, 0x1f, 0xff, 0x07, 0x80, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x01, 0xe0, 0x7f, 0xf8, 0x1f, 0xfe, 0x07, 0x80, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x01, 0xe0, 0x7f, 0xf8, 0x1f, 0xfe, 0x07, 0x80, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x01, 0xe0, 0x7f, 0xf8, 0x1f, 0xfe, 0x0f, 0x80, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x01, 0xf0, 0x7f, 0xf8, 0x1f, 0xfe, 0x0f, 0x80, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x01, 0xf0, 0x3f, 0xf8, 0x1f, 0xfc, 0x1f, 0x80, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x01, 0xf8, 0x1f, 0xf8, 0x1f, 0xfc, 0x3f, 0x80, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x01, 0xf8, 0x1f, 0xf8, 0x1f, 0xf8, 0x3f, 0x80, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x01, 0xfc, 0x0f, 0xf8, 0x1f, 0xf0, 0x7f, 0x80, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x01, 0xfe, 0x03, 0xf8, 0x1f, 0xe1, 0xff, 0x80, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x01, 0xff, 0x81, 0xf8, 0x1f, 0x83, 0xff, 0x80, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x01, 0xff, 0xc0, 0x38, 0x1c, 0x0f, 0xff, 0x80, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x01, 0xff, 0xf8, 0x00, 0x00, 0x3f, 0xff, 0x80, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x01, 0xff, 0xff, 0x00, 0x01, 0xff, 0xff, 0x80, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x01, 0xff, 0xff, 0xf8, 0x1f, 0xff, 0xff, 0x80, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x01, 0xff, 0xff, 0xf8, 0x1f, 0xff, 0xff, 0x80, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x01, 0xff, 0xff, 0xf8, 0x1f, 0xff, 0xff, 0x80, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x01, 0xff, 0xff, 0xf8, 0x1f, 0xff, 0xff, 0x80, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x01, 0xff, 0xff, 0xf8, 0x1f, 0xff, 0xff, 0x80, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x01, 0xff, 0xff, 0xf0, 0x0f, 0xff, 0xff, 0x80, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x01, 0xff, 0xfe, 0x00, 0x00, 0x7f, 0xff, 0x80, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x01, 0xff, 0xfe, 0x00, 0x00, 0x7f, 0xff, 0x80, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x01, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x80, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x01, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x80, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};




#define TIME    2500
#define USER_SW   D8
#define USER_LED  D0
//#define LED_BUILTIN D4

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);
DHT dht(DHTPIN, DHTTYPE);
BH1750 lightMeter;
Adafruit_ADS1015 ads;     
LIS3DH myIMU;


void onePressUSER_SW(void) {
  while( !digitalRead(USER_SW) ) {  delay(1); }
  Serial.println("\nThe USER_SW is pressed");

  while( digitalRead(USER_SW) ) {  delay(1);  }
  Serial.println("The USER_SW is released");
}

void boardTestingHead(void){
  display.println("Maker's Lab.");
  display.println("This is a Phi board!\n");
  display.display();
  delay(2000);
}
void boardTestingDHT11(void){
  display.clearDisplay();
  display.setCursor(0, 0);
  display.println("Board Testing...\n");
  display.display();
  float h = dht.readHumidity();
  float t = dht.readTemperature();

  if (isnan(h) || isnan(t) ) {
    Serial.println("Failed to read from DHT sensor!");
    Serial.println("Press the reset button");
    while(1) {}
  }
  Serial.println("DHT11 TEST");
  Serial.print("Temp.: ");  Serial.print(t);  Serial.println(" [*C]");
  Serial.print("Humi.: ");     Serial.print(h);  Serial.println(" [%]");

  display.println("DHT11 TEST");
  display.print("Temp.: "); display.print(t);  display.println(" [*C]");
  display.print("Humi.: ");    display.print(h);  display.println(" [%]");
  
  if ( t > 40 || t < -20 || h > 80 || h < 0 ) {
    Serial.println("E - Check DHT11 Sensor");
    display.println("E - Check DHT11 Sensor");
    display.display();
    while(1){ }
  }
  Serial.println("\nDHT11 OK!");
  display.println("\nDHT11 OK!");
  display.display();
  delay(TIME);
}

void boardTestingBH1750(void){
  display.clearDisplay();
  display.setCursor(0, 0);
  display.println("Board Testing...\n");
  display.display();
  float lux = lightMeter.readLightLevel();
  
  Serial.println("BH1750 TEST"); Serial.print("Light: ");  Serial.print(lux);  Serial.println(" [lx]");
  display.println("BH1750 TEST"); display.print("Light: "); display.print(lux); display.println(" [lx]");

  if (0 > lux && lux > 5000) {
    Serial.println("E - Check BH1750 Sensor");
    display.println("E - Check BH1750 Sensor");
    display.display();
    while(1){ }
  }
  Serial.println("\nBH1750 OK!");
  display.println("\nBH1750 OK!");
  display.display();
  delay(TIME);
}


void boardTestingADS1015(void){
  display.clearDisplay();
  display.setCursor(0, 0);
  display.println("Board Testing...\n");
  display.display();
  
  int16_t adc0 = ads.readADC_SingleEnded(0);
  Serial.println("ADS1015 TEST");
  Serial.print("AIN0 : "); Serial.println(adc0);
  display.println("ADS1015 TEST");
  display.print("AIN0 : "); display.println(adc0);
  display.display();
  
  if ( adc0 < 0 || adc0 > 10) {
    Serial.println("E - Check ADS1015");
    Serial.println("Unconnect to AIN0 input jack, press the reset button");
    display.println("E - Check ADS1015");
    display.println("Unconnect to AIN0 input jack, press the reset button");    
    while(1){ }
  }
  Serial.println("\nADS1015 OK!");
  display.println("\nADS1015 OK!");
  display.display();
  delay(TIME);
}
void boardTestingLIS3DH(void){
  byte count = 0;

  while(true) {
    display.clearDisplay();
    display.setCursor(0, 0);
    display.println("Board Testing...\n");
    display.display();

    float xacc = myIMU.readFloatAccelX();
    float yacc = myIMU.readFloatAccelY();
    float zacc = myIMU.readFloatAccelZ();
    count++;
    Serial.println("LIS3DH TEST");
    Serial.print("X=");   Serial.println(xacc, 4);
    Serial.print("Y=");   Serial.println(yacc, 4);
    Serial.print("Z=");   Serial.println(zacc, 4);
    
    display.println("LIS3DH TEST");
    display.print("X=");  display.println(xacc, 4);
    display.print("Y=");  display.println(yacc, 4);
    display.print("Z=");  display.println(zacc, 4);
    display.display();
    delay(TIME);
  
    if ( abs_p(xacc) > 0.02 || abs_p(yacc) > 0.02 || abs_p(zacc) < 0.96) { // 수평으로 놓여 있지 않은 경우, 또는 에러 발생 시에 수행.
      Serial.println("E - Check LIS3DH");
      Serial.println("Put the board somewhere flat.\nPress the USER_SW!");
  
      display.clearDisplay();
      display.setCursor(0, 0);
      display.println("Board testing...\n");
      display.println("E - Check LIS3DH");
      Serial.print("Count : "); Serial.println(count);
      
      if(count < 3) {
        display.println("Put the board somewhere flat.\nPress the USER_SW!");   
        display.display();
        onePressUSER_SW();
      } else {
        display.clearDisplay();
        display.setCursor(0, 0);
        display.println("Board testing...\n");
        display.println("E - Check LIS3DH");
        display.println("Press the RESET button!");   
        display.display();
        while(1) { delay(1); };  // 리셋될 때까지 무한히 대기.
      }
    } else { // 수평으로 놓여 있거나 에러 없을 경우 무한 루프에서 벗어남.
      break;
    }
  }
  Serial.println("\nLIS3DH OK!");
  display.println("\nLIS3DH OK!");
  display.display();
  delay(TIME);
}
void boardTestingMicroSD(void){
  Serial.println("MICROSD TEST");
  display.clearDisplay();
  display.setCursor(0, 0);
  display.println("Board Testing...\n");
  display.println("MICROSD TEST");
  display.display();

  if ( !SD.begin(CS_PIN) ) {
    display.clearDisplay();
    Serial.println("MICROSD - Warning!");
    Serial.println("1. Insert(reinsert) a memory card. If you don't use a microsd card now, Ignore this warning");
    Serial.println("To next Check, Press USER_SW");
    
    display.clearDisplay();
    display.setCursor(0, 0);
    display.println("Board Testing...\n");
    display.println("MICROSD - Warning!");
    display.println("Insert(reinsert) a microsd. If you don't use a microsd, Ignore this warning.");
    display.println("Press USER_SW!");
    display.display(); 
    onePressUSER_SW();
  } else {
    Serial.println("\nMicroSD Card OK");
    display.println("\nMicroSD Card OK");
    display.display();
    delay(TIME);
  }
}

void boardTestingWiFi(void) {
  Serial.println("WiFi TEST");
  display.clearDisplay();
  display.setCursor(0, 0);
  display.println("Board Testing...\n");
  display.println("WiFi TEST");
  display.display();
  
  int numOfSsid = WiFi.scanNetworks( );   // 주변에 있는 무선 공유기를 조사, 개수를 알려줌.
  if ( numOfSsid == -1 ) {                // 주변에 공유기가 없을 때.
    Serial.println("Couldn't get a wifi connection\nCheck the ESP-12E\nPress a USER_SW to next");
    display.println("Couldn't get a wifi connection\nCheck the ESP-12E\nPress a USER_SW to next");
    display.display();
    onePressUSER_SW();
  } else {                                // 주변에 공유기가 있을 때.
    Serial.print("number of available networks:");
    Serial.println(numOfSsid);
    for( int i = 0; i < numOfSsid; i++) {
      Serial.print(i); Serial.print(") "); Serial.print( WiFi.SSID(i) ); Serial.print("\tSignal: "); 
      Serial.print( WiFi.RSSI(i) );  Serial.println("[dBm]");  
    }
    //보드의 OLED에는 (화면이 작아서) 하나의 공유기 정보만 출력
    display.print( WiFi.SSID(0) ); display.print(":"); display.print(WiFi.RSSI(0));display.println("[dBm]");
  }
  Serial.println("\nWiFi OK!");
  display.println("\nWiFi OK!");
  display.display();
  delay(TIME);
}
float abs_p(float value) {
  if (value < 0) {
    return -1*value;
  } else {
    return value;
  }
}

void displayLog(void) {
  display.clearDisplay();
  display.drawBitmap(0,0, phi_50x50, 128, 64, WHITE);//http://javl.github.io/image2cpp/
  display.setCursor(20,52);
  
  display.println("Phi board v1.0");
  display.display(); 
}
void setup() {
  Serial.begin(9600);
  pinMode(USER_SW, INPUT);
  pinMode(USER_LED, OUTPUT);
      
  dht.begin();
  Wire.begin();
  lightMeter.begin();
  ads.begin();
  myIMU.begin();
  
  // Serial 모니터에(만) 출력
  Serial.println(F("\nPhi board v1.0 Testing"));
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { 
    Serial.println(F("OLED(SSD1306) allocation failed")); 
    Serial.println(F("board Test is quited. Failed!")); 
    return;
  }
  delay(2000); //the OLED has enough time to initialize before writing text
  
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);  // white font and black background
  
  boardTestingHead();
  boardTestingDHT11();
  boardTestingBH1750();
  boardTestingADS1015();
  boardTestingLIS3DH();
  boardTestingMicroSD();
  boardTestingWiFi();
  displayLog();
  Serial.println("See the logo at OLED dispaly on the board");
  pinMode(LED_BUILTIN, OUTPUT); // LED_BUILTIN(D4)는 DHT11과 같이 연결되어 있기 때문에 
                                // D4핀은 DHT11과 IO 기능을 동시에 사용할 수 없음.
}

void loop() {
  Serial.print("A0: ");Serial.println( analogRead(A0) );
  
  digitalWrite(LED_BUILTIN, HIGH);
  digitalWrite(USER_LED, HIGH);
  delay(200);
  digitalWrite(LED_BUILTIN, LOW);
  digitalWrite(USER_LED, LOW);
  delay(800);
}
