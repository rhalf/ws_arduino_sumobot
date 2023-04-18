const uint8_t 
  MA_DIR = 11, MA_SPEED = 10, 
  MB_DIR = 8, MB_SPEED = 9;
uint8_t speed = 128;

const uint8_t IR_LL = 7, IR_RR = 5, IR_MM = 6;
boolean onLL = false, onRR = false, onMM = false;

const uint8_t US_TRIG = 12, US_ECHO = 3;
const uint8_t 
  S = 0, F = 1, B = 2, R = 3, L = 4; 
uint8_t rState = S;

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
  pinMode(IR_LL, INPUT);
  pinMode(IR_RR, INPUT);
  pinMode(IR_MM, INPUT);

  pinMode(MA_DIR, OUTPUT);
  pinMode(MA_SPEED, OUTPUT);
  pinMode(MB_DIR, OUTPUT);
  pinMode(MB_SPEED, OUTPUT);

  pinMode(US_TRIG, OUTPUT);
  pinMode(US_ECHO, INPUT);
  Serial.begin(9600);
}

boolean isBlocked() {
    // put your main code here, to run repeatedly:
  digitalWrite(US_TRIG, LOW);
  delayMicroseconds(2);
  digitalWrite(US_TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(US_TRIG, LOW);

  uint64_t time =  pulseIn(US_ECHO, HIGH);
  // time = microseconds * 1000000
  // 343 m/s speed of sound
  // cm
  double dura = (time / 2);
  dura = dura / 1000000;
  double dist = 343 * dura;
  dist = dist * 100;
  // cm
  if (dist < 25 ) return true;
  else return false;
}

void loop() {
  // put your main code here, to run repeatedly:
  if (digitalRead(IR_LL) == HIGH) onLL = true;
  else onLL = false;
  if (digitalRead(IR_RR) == HIGH) onRR = true;
  else onRR = false;
  if (digitalRead(IR_MM) == HIGH) onMM = true;
  else onMM = false;

  if (isBlocked()) {
    switch(rState){
        case L:
            rr();
            delay(50);
            break;
        case R:
            ll();
            delay(50);
            break;
    }
    rState = F;
    ff();
    delay(10);
  } else if (!onLL) {
    rState = R;
    rr();
    delay(10);    
  } else if (!onRR) {
    rState = L;
    ll();
    delay(10);
  } else if (!onMM) {
    rState = B;
    bb();
    delay(400);
  } else {
    rState = F;
    ff();
  }
}