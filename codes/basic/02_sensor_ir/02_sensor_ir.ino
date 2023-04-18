const uint8_t 
IR_LL = 7, IR_RR = 5, IR_MM = 6;
boolean onLL = false, onRR = false, onMM = false;
void setup() {
  // put your setup code here, to run once:
  pinMode(IR_LL, INPUT);
  pinMode(IR_RR, INPUT);
  pinMode(IR_MM, INPUT);
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

  Serial.print("Left : ");
  Serial.print(onLL);
  Serial.print(" ");
  Serial.print("Middle : ");
  Serial.print(onMM);
  Serial.print(" ");
  Serial.print("Right : ");
  Serial.print(onRR);
  Serial.println();
  delay(200);
}