#include <Arduino.h>
#include <ESP32Servo.h>
#include "pins.h"
#include "colours.h"
#include "servos.h"


void setup() {
    Serial.begin(9600);
    pins_setup();
    servos_setup();

    delay(1000);

    servo_1.reset();
}

void loop() {
}