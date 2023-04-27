const uint8_t MOTOR_PINS[] = {
  11,  //motor A direction pin
  10,  //motor A speed pin
  8,   //motor B direction pin
  9    // motor b speed pin
};

uint8_t speed = 255;  //255 = 100% (full speed)
uint16_t dura = 200;  // 1000 milliseconds = 1 second

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

const uint8_t US_PINS[] = {
  12,  //trigger
  3    //echo
};

void setup() {
  pinMode(MOTOR_PINS[0], OUTPUT);
  pinMode(MOTOR_PINS[2], OUTPUT);

  pinMode(US_PINS[0], OUTPUT);
  pinMode(US_PINS[1], INPUT);
}

bool isBlocked() {
  digitalWrite(US_PINS[0], LOW);
  delayMicroseconds(2);
  digitalWrite(US_PINS[0], HIGH);
  delayMicroseconds(10);
  digitalWrite(US_PINS[0], LOW);

  uint32_t time = pulseIn(US_PINS[1], HIGH);
  // time = microseconds * 1000000
  // 343 m/s speed of sound
  float dura = (time / 2);
  dura = dura / 1000000;
  float dist = 343 * dura;
  dist = dist * 100;
  // cm
  if (dist < 15) return true;
  else return false;
}

void rightToLeft() {
  right();
  delay(dura);
  if (isBlocked()) {
    left();
    delay(dura * 2);
  }
}
void leftToRight() {
  left();
  delay(dura);
  if (isBlocked()) {
    right();
    delay(dura * 2);
  }
}
void loop() {
  if (isBlocked()) {
    uint8_t direction = random(0, 2);
    if (direction) rightToLeft();
    else leftToRight();
  } else {
    forward();
  }
}
