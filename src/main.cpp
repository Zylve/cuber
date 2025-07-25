#include <Arduino.h>
#include <ESP32Servo.h>
#include "pins.h"
#include "colours.h"
#include "servos.h"
#include "config.h"
#include <esp_system.h>

bool connected = false;
void solve_test();

void setup() {
    Serial.begin(9600);
    pins_setup();

    delay(1000);

    // for(int i = 0; i < 6; i++) {
    //     servos[i]->attach();
    //     servos[i]->reset();

    //     delay(1000);
    // }

    // while(!connected) {
    //     Serial.println("esp32_connect");
    //     delay(250);
    //     if(Serial.available()) {
    //         String read = Serial.readStringUntil('\n');
    //         if(read == "pc_connect") {
    //             connected = true;
    //             Serial.println("connected");
    //         }
    //     }
    // }

    if(C_SOLVE_TEST) {
        solve_test();
    }
}

void loop() {
    if(C_SERVO_INPUT) {
        servo_input(C_SERVO_INPUT_ID);
        return;
    }

    if(C_SERVO_TEST) {
        for(int i = 0; i < 6; i++) {
            servos[i]->reset();
            delay(1000);
        }

        for(int i = 0; i < 6; i++) {
            servos[i]->turn_left();
            delay(2000);
        }

        return;
    }

    sensors[0]->read_colour();
    // auto raw = sensors[1]->get_colour_raw();
    // Serial.println(String(raw.red) + " " + String(raw.green) + " " + String(raw.blue));
    // auto bounded = sensors[1]->get_colour_bounded();
    // Serial.println(String(bounded.red) + " " + String(bounded.green) + " " + String(bounded.blue));
    // auto normalized = sensors[1]->get_colour_normalized();
    // Serial.println(String(normalized.red) + " " + String(normalized.green) + " " + String(normalized.blue));
    // auto written_colour = sensors[1]->get_colour();
    // Serial.println(written_colour);
}

void solve_test() {
    String solution = "";

    while(true) {
        String solu = Serial.readStringUntil('\n');

        if(solu.substring(0, 5) == "solu:") {
            solu.replace("solu:", "");
            solu = solu + " ";
            Serial.println(solu);
            solution = solu;
            break;
        }
    }

    Serial.println("Sol parsed");

    int moves = 1;
    for(int i = 0; i < solution.length(); i++) {
        if(solution[i] == ' ') {
            moves++;
        }
    }

    String output[moves];

    int index = 0;
    int start = 0;
    for(int i = 0; i <= solution.length(); i++) {
        if(solution[i] == ' ' || i == solution.length()) {
            output[index++] = solution.substring(start, i);
            start = i + 1;
        }
    }

    Serial.println("moves parsed");

    /*
        U = 0
        D = 5
        F = 2
        B = 3
        L = 4
        R = 1
    */

    for(int i = 0; i < moves; i++) {
        Serial.println(output[i]);
        if(output[i] == "D") {
            servos[5]->turn_right();
        } else if(output[i] == "D'") {
            servos[5]->turn_left();
        } else if(output[i] == "D2") {
            servos[5]->turn_180();

        } else if(output[i] == "F") {
            servos[2]->turn_right();
        } else if(output[i] == "F'") {
            servos[2]->turn_left();
        } else if(output[i] == "F2") {
            servos[2]->turn_180();

        } else if(output[i] == "B") {
            servos[3]->turn_right();
        } else if(output[i] == "B'") {
            servos[3]->turn_left();
        } else if(output[i] == "B2") {
            servos[3]->turn_180();

        } else if(output[i] == "L") {
            servos[4]->turn_right();
        } else if(output[i] == "L'") {
            servos[4]->turn_left();
        } else if(output[i] == "L2") {
            servos[4]->turn_180();

        } else if(output[i] == "R") {
            servos[1]->turn_right();
        } else if(output[i] == "R'") {
            servos[1]->turn_left();
        } else if(output[i] == "R2") {
            servos[1]->turn_180();

        } else if(output[i] == "U") {
            servos[0]->turn_right();
        } else if(output[i] == "U'") {
            servos[0]->turn_left();
        } else if(output[i] == "U2") {
            servos[0]->turn_180();
        }

        delay(1000);
    }
}