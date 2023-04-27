const uint8_t MOTOR_PINS[] = {
  11,  //motor A direction pin
  10,  //motor A speed pin
  8,   //motor B direction pin
  9    // motor b speed pin
};

uint8_t speed = 255; //255 = 100% (full speed)
uint16_t dura = 1000; // 1000 milliseconds = 1 second

void drive(uint8_t maDir, uint8_t maSpeed, uint8_t mbDir, uint8_t mbSpeed) {
  digitalWrite(MOTOR_PINS[0], maDir);
  analogWrite(MOTOR_PINS[1], maSpeed);
  digitalWrite(MOTOR_PINS[2], mbDir);
  analogWrite(MOTOR_PINS[3], mbSpeed);
}
void forward() {
  drive(HIGH, speed, HIGH, speed);
}
void backward() {
  drive(LOW, speed, LOW, speed);
}
void stop() {
  drive(LOW, 0, LOW, 0);
}
void right() {
  drive(HIGH, speed, LOW, speed);
}
void left() {
  drive(LOW, speed, HIGH, speed);
}
void setup() {
  pinMode(MOTOR_PINS[0], OUTPUT);
  pinMode(MOTOR_PINS[2], OUTPUT);

  forward();
  delay(dura);

  backward();
  delay(dura);

  left();
  delay(dura);

  right();
  delay(dura);

  stop();
}
void loop() {}
