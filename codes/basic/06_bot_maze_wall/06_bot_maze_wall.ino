const uint8_t 
  MA_DIR = 11, MA_SPEED = 10, 
  MB_DIR = 8, MB_SPEED = 9;
uint8_t speed = 200;

const uint8_t US_TRIG = 12, US_ECHO = 3;
uint16_t dura = 250;

void ff() {
  digitalWrite(MA_DIR, HIGH);
  analogWrite(MA_SPEED, speed);
  digitalWrite(MB_DIR, HIGH);
  analogWrite(MB_SPEED, speed);
}
void bb() {
  digitalWrite(MA_DIR, LOW);
  analogWrite(MA_SPEED, speed);
  digitalWrite(MB_DIR, LOW);
  analogWrite(MB_SPEED, speed);
}
void ss() {
  digitalWrite(MA_DIR, LOW);
  analogWrite(MA_SPEED, 0);
  digitalWrite(MB_DIR, LOW);
  analogWrite(MB_SPEED, 0);
}
void rr() {
  digitalWrite(MA_DIR, HIGH);
  analogWrite(MA_SPEED, speed);
  digitalWrite(MB_DIR, LOW);
  analogWrite(MB_SPEED, speed);
}
void ll() {
  digitalWrite(MA_DIR, LOW);
  analogWrite(MA_SPEED, speed);
  digitalWrite(MB_DIR, HIGH);
  analogWrite(MB_SPEED, speed);
}

void setup() {
  // put your setup code here, to run once:
  pinMode(MA_DIR, OUTPUT);
  pinMode(MA_SPEED, OUTPUT);
  pinMode(MB_DIR, OUTPUT);
  pinMode(MB_SPEED, OUTPUT);

  pinMode(US_TRIG, OUTPUT);
  pinMode(US_ECHO, INPUT);
  Serial.begin(9600);
}

boolean isBlocked() {
  digitalWrite(US_TRIG, LOW);
  delayMicroseconds(2);
  digitalWrite(US_TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(US_TRIG, LOW);
  uint64_t time =  pulseIn(US_ECHO, HIGH);
  // time = microseconds * 1000000
  // 343 m/s speed of sound
  double dura = (time / 2);
  dura = dura / 1000000;
  double dist = 343 * dura;
  dist = dist * 100;
  // cm
  if (dist < 15) return true;
  else return false;
}
void rightToLeft() {
  rr();
  delay(dura);
  if (isBlocked())
    ll(); delay(dura * 2);
}
void leftToRight() {
  ll(); delay(dura);
  if (isBlocked())
    rr(); delay(dura * 2);
}
void loop() {
  // put your main code here, to run repeatedly:
  if (isBlocked()) {
    uint8_t dir = random(0,2);
    if (dir) rightToLeft();
    else leftToRight();
  } else 
    ff();
}
