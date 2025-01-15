#include <SPI.h>

const int spiSSPin = 10;

void setup() {
  pinMode(spiSSPin, OUTPUT);
  SPI.begin();
}

void loop() {
  digitalWrite(spiSSPin, LOW);
  SPI.transfer(0xFF); // Kirim data SPI
  digitalWrite(spiSSPin, HIGH);
  delay(500);
}
