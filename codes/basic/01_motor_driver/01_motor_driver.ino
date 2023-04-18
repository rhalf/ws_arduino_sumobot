//  ss (stop)
//  ff (forward)
//  bb (backward)
//  rr (right)
//  ll (left)
//  Optional
//  fr (forward right)
//  fl (forward left)
//  br (backward right)
//  bl (backward left)
const uint8_t 
  MA_DIR = 11, MA_SPEED = 10, 
  MB_DIR = 8, MB_SPEED = 9;
uint8_t speed = 255;
uint16_t dura = 1000;

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

  Serial.begin(9600);
  Serial.println("forward");
  ff();
  delay(dura);
  Serial.println("backward");
  bb();
  delay(dura);
  Serial.println("left");
  ll();
  delay(dura);
  Serial.println("right");
  rr();
  delay(dura);
  Serial.println("stop");
  ss();
}
void loop() {
   // put your main code here, to run repeatedly:  
}
