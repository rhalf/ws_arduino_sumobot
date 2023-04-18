/*
   S -> SS (stop)
   F -> FF (forward)
   B -> BB (backward)
   R -> RR (right)
   L -> LL (left)
   tI -> FR (forward right)
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
const uint8_t 
  MA_DIR = 11, MA_SPEED = 10, 
  MB_DIR = 8, MB_SPEED = 9;
uint8_t speed = 255;

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
}

void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available()) {
    char c = Serial.read();
    if (c == 'F') ff();
    else if (c == 'B') bb();
    else if (c == 'R') rr();
    else if (c == 'L') ll();
    else if (c == 'S') ss();
    else {
      if (!isDigit(c)) return;
      uint8_t v = atoi(c) + 1;
      speed = (uint8_t)(v / 10) * 255;
    }
  }
}
//HC-05_XXX