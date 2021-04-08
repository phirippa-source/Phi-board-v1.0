#include "SparkFunLIS3DH.h"
#include "Wire.h"
#include "SPI.h"

LIS3DH myIMU; 
// Phi board v1.0에 부착된 LIS3DH의 I2C Address는 0x19

void setup() {
  Serial.begin(9600);
  myIMU.begin();
}

void loop()
{
  Serial.print(myIMU.readFloatAccelX(), 4); Serial.print(" ");
  Serial.print(myIMU.readFloatAccelY(), 4); Serial.print(" ");
  Serial.println(myIMU.readFloatAccelZ(), 4);
  delay(40); // f = 1/40 x 1000 = 25[Hz]
}
