const int pwmPin = 9;

void setup() {
  pinMode(pwmPin, OUTPUT);
}

void loop() {5
  digitalWrite(pwmPin, HIGH);
  delayMicroseconds(1000); // 50% dari periode 2ms
  digitalWrite(pwmPin, LOW);
  delayMicroseconds(1000);
}
