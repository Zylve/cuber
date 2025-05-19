#include <Arduino.h>
#include <ESP32Servo.h>

Servo servo;

void setup() {
    servo.attach(12);
}

void loop() {
    for(int pos = 0; pos <= 180; pos++){
        servo.write(pos);
        delay(15);
    }

    for(int pos = 180; pos >= 0; pos--){
        servo.write(pos);
        delay(15);
    }
}