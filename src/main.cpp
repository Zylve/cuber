#include <Arduino.h>
#include <ESP32Servo.h>
#include "pins.h"
#include "colours.h"
#include "servos.h"

Servo servo_one_test;

void setup() {
    Serial.begin(9600);
    pins_setup();
    Serial.println("Finished Pins");
    // servos_setup();

    sleep(5);

    servo_one_test.attach(SERVO_3_PIN);
    Serial.println("Attached");

    // servo_1.reset();
}

void loop() {
    // sensor_1.read_colour();
    // ColourRaw raw_1 = sensor_1.get_colour_raw();

    // Serial.println(String(raw_1.red) + ", " + String(raw_1.green) + ", " + String(raw_1.blue));

    sleep(1);
    servo_one_test.write(45);
    sleep(1);
    servo_one_test.write(0);
}