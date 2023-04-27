const uint8_t MOTOR_PINS[] = {
  11,  //motor A direction pin
  10,  //motor A speed pin
  8,   //motor B direction pin
  9    // motor b speed pin
};

uint8_t speed = 150;  //128 = 50% (full speed)

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
  drive(LOW, speed , HIGH, speed);
}

const uint8_t IR_PINS[] = {
  7,  //ir left pin
  5,  //ir right pin
  6   //ir middle pin
};

bool irsLeft = false, irsRight = false, irsMiddle = false;

void setup() {
  pinMode(IR_PINS[0], INPUT);
  pinMode(IR_PINS[1], INPUT);
  pinMode(IR_PINS[2], INPUT);

  pinMode(MOTOR_PINS[0], OUTPUT);
  pinMode(MOTOR_PINS[2], OUTPUT);
}
void loop() {
  irsLeft = digitalRead(IR_PINS[0]);
  irsRight = digitalRead(IR_PINS[1]);
  irsMiddle = digitalRead(IR_PINS[2]);

  if (!irsLeft && irsMiddle && irsRight) left();
  else if (!irsLeft && !irsMiddle && irsRight) left();
  else if (!irsLeft && irsMiddle && !irsRight) forward();
  else if (irsLeft && irsMiddle && !irsRight) right();
  else if (irsLeft && !irsMiddle && !irsRight) right();
  else stop();
}
