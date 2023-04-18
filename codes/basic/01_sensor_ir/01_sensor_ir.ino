const uint8_t IR_LEFT = 7, IR_RIGHT = 5, IR_MIDDLE = 6;
boolean irsLeft = false, irsRight = false, irsMiddle = false;

void setup() {
  // put your setup code here, to run once:
  pinMode(IR_LEFT, INPUT);
  pinMode(IR_RIGHT, INPUT);
  pinMode(IR_MIDDLE, INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (digitalRead(IR_LEFT) == HIGH) irsLeft = true;
  else irsLeft = false;

  if (digitalRead(IR_RIGHT) == HIGH) irsRight = true;
  else irsRight = false;

  if (digitalRead(IR_MIDDLE) == HIGH) irsMiddle = true;
  else irsMiddle = false;

  Serial.print("Left : ");
  Serial.print(irsLeft);
  Serial.print(" ");
  Serial.print("Middle : ");
  Serial.print(irsMiddle);
  Serial.print(" ");
  Serial.print("Right : ");
  Serial.print(irsRight);
  Serial.println();
  
  delay(250);
}