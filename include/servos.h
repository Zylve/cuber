#pragma once

#include <ESP32Servo.h>
#include "pins.h"

struct ServoConfig {
    int axis_positions[4][4];  // [from_position][to_position]
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
        servo.write(config.axis_positions[0][0]);
        position = 0;
    }

    void turn_left() {
        int target = position < 3 ? position + 1 : 0;
        servo.write(config.axis_positions[position][target]);
        position = target;
    }

    void turn_right() {
        int target = position > 0 ? position - 1 : 3;
        servo.write(config.axis_positions[position][target]);
        position = target;
    }

    void turn_180() {
        int target = (position + 2) % 4;
        servo.write(config.axis_positions[position][target]);
        position = target;
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

extern ServoWrapper* servos[];

extern void servo_input(int id);