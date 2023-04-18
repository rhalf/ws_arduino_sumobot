/*
   SS (stop)
   FF (forward)
   BB (backward)
   RR (right)
   LL (left)
   
   Optional
   FR (forward right)
   FL (forward left)
   BR (backward right)
   BL (backward left)
*/
const uint8_t MOTOR_A_DIR = 11, MOTOR_A_SPEED = 10, MOTOR_B_DIR = 8, MOTOR_B_SPEED = 9;
uint8_t speed = 128;

const uint8_t PIN_US_TRIG = 12, PIN_US_ECHO = 3;

uint16_t duration = 500;

void ff() {
  digitalWrite(MOTOR_A_DIR, HIGH);
  analogWrite(MOTOR_A_SPEED, speed);
  digitalWrite(MOTOR_B_DIR, HIGH);
  analogWrite(MOTOR_B_SPEED, speed);
}

void bb() {
  digitalWrite(MOTOR_A_DIR, LOW);
  analogWrite(MOTOR_A_SPEED, speed);
  digitalWrite(MOTOR_B_DIR, LOW);
  analogWrite(MOTOR_B_SPEED, speed);
}

void ss() {
  digitalWrite(MOTOR_A_DIR, LOW);
  analogWrite(MOTOR_A_SPEED, 0);
  digitalWrite(MOTOR_B_DIR, LOW);
  analogWrite(MOTOR_B_SPEED, 0);
}

void rr() {
  digitalWrite(MOTOR_A_DIR, LOW);
  analogWrite(MOTOR_A_SPEED, speed);
  digitalWrite(MOTOR_B_DIR, HIGH);
  analogWrite(MOTOR_B_SPEED, speed);
}

void ll() {
  digitalWrite(MOTOR_A_DIR, HIGH);
  analogWrite(MOTOR_A_SPEED, speed);
  digitalWrite(MOTOR_B_DIR, LOW);
  analogWrite(MOTOR_B_SPEED, speed);
}

void setup() {
  // put your setup code here, to run once:
  pinMode(MOTOR_A_DIR, OUTPUT);
  pinMode(MOTOR_A_SPEED, OUTPUT);
  pinMode(MOTOR_B_DIR, OUTPUT);
  pinMode(MOTOR_B_SPEED, OUTPUT);

  pinMode(PIN_US_TRIG, OUTPUT);
  pinMode(PIN_US_ECHO, INPUT);

  Serial.begin(9600);
}

boolean isBlocked() {
    // put your main code here, to run repeatedly:
  digitalWrite(PIN_US_TRIG, LOW);
  delayMicroseconds(2);
  digitalWrite(PIN_US_TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(PIN_US_TRIG, LOW);

  uint64_t time =  pulseIn(PIN_US_ECHO, HIGH);

  // time = microseconds * 1000000
  // 343 m/s speed of sound
  // cm
  double duration = (time / 2);
  duration = duration / 1000000;
  double distance = 343 * duration;
  distance = distance * 100;

  // cm
  Serial.println(distance);
  if (distance < 15) {
      Serial.println("Blocked : true");
      return true;
  } else {
      Serial.println("Blocked : false");
      return false;
  }
}

void rightToLeft() {
  rr();
  delay(duration);
  if (isBlocked()){
    ll();
    delay(duration);
    ll();
    delay(duration);
  }
}

void leftToRight() {
  ll();
  delay(duration);
  if (isBlocked()){
    rr();
    delay(duration);
    rr();
    delay(duration);
  }
}

void loop() {
  // put your main code here, to run repeatedly:

  if (isBlocked()) {
    
    uint8_t dir = random(0,2);
    Serial.print("dir : ");
    Serial.print(dir);
    Serial.println();
    if (dir) rightToLeft();
    else leftToRight();

  } else {
    ff();
  }
}
