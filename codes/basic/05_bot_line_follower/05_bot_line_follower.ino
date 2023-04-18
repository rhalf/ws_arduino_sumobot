const uint8_t 
MA_DIR = 11, MA_SPEED = 10, 
MB_DIR = 8, MB_SPEED = 9;
uint8_t speed = 128;

const uint8_t 
IR_LL = 7, IR_RR = 5, IR_MM = 6;
boolean onLL = false, onRR = false, onMM = false;

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

  Serial.begin(9600);
}
void loop() {
  // put your main code here, to run repeatedly:
  if (digitalRead(IR_LL) == HIGH) onLL = true;
  else onLL = false;
  if (digitalRead(IR_RR) == HIGH) onRR = true;
  else onRR = false;
  if (digitalRead(IR_MM) == HIGH) onMM = true;
  else onMM = false;

  if (!onLL && onMM && onRR) ll();
  else if (!onLL && !onMM && onRR) ll();
  else if (!onLL && onMM && !onRR) ff();
  else if (onLL && onMM && !onRR) rr();
  else if (onLL && !onMM && !onRR) rr();
  else ss();
}
