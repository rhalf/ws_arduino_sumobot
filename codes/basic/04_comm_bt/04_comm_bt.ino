#include <SoftwareSerial.h>
SoftwareSerial bluetooth(2,3); // RX, TX

void setup () {
    bluetooth.begin(9600);
    Serial.begin(9600);
    Serial.println("Enter data :");
}

void loop() {
    while (bluetooth.available()) {
        Serial.write(bluetooth.read());
    }

    while (Serial.available()) {
        bluetooth.write(Serial.read());
    }
}