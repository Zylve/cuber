#pragma once

#include <ESP32Servo.h>
#include "pins.h"

struct ServoConfig {
    int axis_positions[4];
    int square_positions[8];
};

struct ServoWrapper {
    ServoConfig config;
    Servo servo;
    int position = 0;
    int servo_pin;

    ServoWrapper(ServoConfig config, int pin) : config(config), servo_pin(pin) {}


    void attach() {
        servo.attach(servo_pin);
    }

    void reset() {
        servo.write(config.axis_positions[0]);
        position = 0;
    }

    void turn_left() {
        if(position < 3) {
            position++;
        } else {
            position = 0;
        }

        servo.write(config.axis_positions[position]);
    }

    void turn_right() {
        if(position > 0) {
            position--;
        } else {
            position = 3;
        }

        servo.write(config.axis_positions[position]);
    }

    void turn_to_square(int square) {
        servo.write(config.square_positions[square]);
    }
};

extern ServoWrapper servo_1;
extern ServoWrapper servo_2;
extern ServoWrapper servo_3;
extern ServoWrapper servo_4;
extern ServoWrapper servo_5;
extern ServoWrapper servo_6;

extern void servos_setup();