#include <Arduino.h>
#include "pins.h"

void pins_setup() {
    pinMode(S0, OUTPUT);
    pinMode(S1, OUTPUT);
    pinMode(S2, OUTPUT);
    pinMode(S3, OUTPUT);

    pinMode(sensor_1_out, INPUT);
    pinMode(sensor_2_out, INPUT);
    pinMode(sensor_3_out, INPUT);
    pinMode(sensor_4_out, INPUT);
    pinMode(sensor_5_out, INPUT);
    pinMode(sensor_6_out, INPUT);

    digitalWrite(S0, HIGH);
    digitalWrite(S1, LOW);
}