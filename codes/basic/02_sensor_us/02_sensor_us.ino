const uint8_t US_TRIG = 12, US_ECHO = 3;
uint64_t time = 0;
void setup() {
  // put your setup code here, to run once:
  pinMode(US_TRIG, OUTPUT);
  pinMode(US_ECHO, INPUT);
  Serial.begin(9600);
}
void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(US_TRIG, LOW);
  delayMicroseconds(2);
  digitalWrite(US_TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(US_TRIG, LOW);

  time =  pulseIn(US_ECHO, HIGH);
  // time = microseconds * 1000000
  // 343 m/s speed of sound
  double dura = (time / 2);
  dura = dura / 1000000;
  // s = d/t | d = st
  double dist = 343 * dura;
  dist = dist * 100;
  // double dura = (time / 2);
  // double dist = dura / 29.15;
  Serial.print(dist);
  Serial.println(" cm");
  delay(200);
}