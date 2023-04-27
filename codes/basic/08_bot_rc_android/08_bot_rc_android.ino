/*
   S -> SS (stop)
   F -> FF (forward)
   B -> BB (backward)
   R -> RR (right)
   L -> LL (left)
   I -> FR (forward right)
   G -> FL (forward left)
   J -> BR (backward right)
   H -> BL (backward lef)

   0-9 -> Speed

   W -> Front Light On
   w -> Front Light Off
   U -> Back Light On
   u -> Back Light Off
   V -> Horn On
   v -> Horn Off
   X -> Hazzard On
   x -> Hazzard Off
*/
// HC-05_XXX => 1234
const uint8_t MOTOR_PINS[] = {
  11,  //motor A direction pin
  10,  //motor A speed pin
  8,   //motor B direction pin
  9    // motor b speed pin
};

uint8_t speed = 255; //255 = 100% (full speed)

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
  drive(LOW, speed, HIGH, speed);
}
void left() {
  drive(HIGH, speed, LOW, speed);
}
void setup() {
  pinMode(MOTOR_PINS[0], OUTPUT);
  pinMode(MOTOR_PINS[2], OUTPUT);
  Serial.begin(9600);
}

void loop() {
  if (Serial.available()) {
    char c = Serial.read();
    if (c == 'F') forward();
    else if (c == 'B') backward();
    else if (c == 'R') right();
    else if (c == 'L') left();
    else if (c == 'S') stop();
    else {
      if (!isDigit(c)) return;
      uint8_t v = atoi(c) + 1;
      speed = (uint8_t)(v / 10) * 255;
    }
  }
}
//HC-05_XXX