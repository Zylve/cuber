#include <Arduino.h>
#include "pins.h"

void pins_setup() {
    pinMode(S2_1, OUTPUT);
    pinMode(S3_1, OUTPUT);
    pinMode(S2, OUTPUT);
    pinMode(S3, OUTPUT);
    
    pinMode(SENSOR_1_OUT, INPUT);
    pinMode(SENSOR_2_OUT, INPUT);
    pinMode(SENSOR_3_OUT, INPUT);
    pinMode(SENSOR_4_OUT, INPUT);
    pinMode(SENSOR_5_OUT, INPUT);
    pinMode(SENSOR_6_OUT, INPUT);

    pinMode(SERVO_1_PIN, OUTPUT);
    pinMode(SERVO_2_PIN, OUTPUT);
    pinMode(SERVO_3_PIN, OUTPUT);
    pinMode(SERVO_4_PIN, OUTPUT);
    pinMode(SERVO_5_PIN, OUTPUT);
    pinMode(SERVO_6_PIN, OUTPUT);
}