#include <Arduino.h>
#include <ESP32Servo.h>
#include "pins/pins.h"
#include "colours/colours.h"

void setup() {
    pins_setup();

    Serial.begin(9600);
}

void loop() {
    sensor_1.read_colour();
    ColourRaw raw_1 = sensor_1.get_colour_raw();

    Serial.println(String(raw_1.red) + ", " + String(raw_1.green) + ", " + String(raw_1.blue));
}