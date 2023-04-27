const uint8_t US_PINS[] = {
  12,  //trigger
  3    //echo
};
uint32_t time = 0;

void setup() {
  pinMode(US_PINS[0], OUTPUT);
  pinMode(US_PINS[1], INPUT);
  Serial.begin(9600);
}
void loop() {
  digitalWrite(US_PINS[0], LOW); //making sure the trigger is off.
  delayMicroseconds(2);
  digitalWrite(US_PINS[0], HIGH); //create sound
  delayMicroseconds(10);
  digitalWrite(US_PINS[0], LOW); //turn off

  time = pulseIn(US_PINS[1], HIGH); //count the time of echo.
  // time = microseconds * 1000000
  // 343 m/s speed of sound
  float dura = (time / 2);
  dura = dura / 1000000;
  // s = d/t | d = st
  float dist = 343 * dura;
  dist = dist * 100;
  // double dura = (time / 2);
  // double dist = dura / 29.15;
  Serial.print(dist);
  Serial.println(" cm");
  delay(200);
}