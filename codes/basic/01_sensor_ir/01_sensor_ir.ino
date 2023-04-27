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
  Serial.begin(9600);
}

void loop() {
  irsLeft = digitalRead(IR_PINS[0]);
  irsRight = digitalRead(IR_PINS[1]);
  irsMiddle = digitalRead(IR_PINS[2]);

  Serial.println(
    " L: " + String(irsLeft) + 
    " M:" + String(irsMiddle) + 
    " R:" String(irsRight));

  delay(250);
}