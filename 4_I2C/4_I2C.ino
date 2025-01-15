#include <Wire.h>

void setup() {
  Wire.begin();
  Serial.begin(9600);
}

void loop() {
  Wire.beginTransmission(0x3C); // Alamat I2C
  Wire.write("Data I2C");
  Wire.endTransmission();
  delay(500);
}
