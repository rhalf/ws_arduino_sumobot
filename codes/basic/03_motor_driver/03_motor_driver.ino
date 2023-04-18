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
const uint8_t IR_LEFT = 11, IR_RIGHT = 10, IR_MIDDLE = 8;


uint8_t speed = 255;
uint16_t duration = 1000;

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

  Serial.begin(9600);

  Serial.println("forward");
  ff();
  delay(duration);

  Serial.println("backward");
  bb();
  delay(duration);
  
  Serial.println("left");
  ll();
  delay(duration);
  
  Serial.println("right");
  rr();
  delay(duration);
  
  Serial.println("stop");
  ss();
  delay(duration);
}

void loop() {
   // put your main code here, to run repeatedly:  
}
