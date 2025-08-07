#include <Arduino.h>
#include <ESP32Servo.h>
#include "pins.h"
#include "colours.h"
#include "servos.h"
#include "config.h"
#include <esp_system.h>

bool connected = false;
void colour_routine_test();
void solve_test();

void setup() {
    Serial.begin(9600);
    pins_setup();

    delay(1000);

    for(int i = 0; i < 6; i++) {
        servos[i]->attach();
        servos[i]->reset();

        delay(1000);
    }

    if(C_MAIN) {
        while(!connected) {
            Serial.println("esp32_connect");
            delay(250);
            if(Serial.available()) {
                String read = Serial.readStringUntil('\n');
                if(read == "pc_connect") {
                    connected = true;
                    Serial.println("connected");
                }
            }
        }

        delay(1000);

        colour_routine_test();

        solve_test();

    }
}

void loop() {
    if(C_SERVO_INPUT) {
        servo_input(C_SERVO_INPUT_ID, C_SERVO_INPUT_SQUARE);
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

    // sensors[3]->read_colour();
    // auto raw = sensors[3]->get_colour_raw();
    // Serial.println(String(raw.red) + " " + String(raw.green) + " " + String(raw.blue));
    // auto bounded = sensors[5]->get_colour_bounded();
    // Serial.println(String(bounded.red) + " " + String(bounded.green) + " " + String(bounded.blue));
    // auto normalized = sensors[3]->get_colour_normalized();
    // Serial.println(String(normalized.red) + " " + String(normalized.green) + " " + String(normalized.blue));
    // auto written_colour = sensors[3]->get_colour_string();
    // Serial.println(written_colour);
    // Serial.println(written_colour  + ": " + String(normalized.red) + " " + String(normalized.green) + " " + String(normalized.blue));
    // Serial.println(written_colour + ": " + String(normalized.red) + " " + String(normalized.green) + " " + String(normalized.blue) + " | " + String(raw.red) + " " + String(raw.green) + " " + String(raw.blue));
}

void colour_routine_test() {
    // URFDLB
    String state[6][9];
    state[0][4] = "U";
    state[1][4] = "R";
    state[2][4] = "F";
    state[3][4] = "D";
    state[4][4] = "L";
    state[5][4] = "B";

    delay(1000);

    for(int i = 0; i < 5; i++) {
        if(i == 2) continue; // Skip F face because of wiring issues that I don't feel like fixing.

        for(int j = 0; j < 8; j++) {
            servos[i]->turn_to_square(j);
            delay(300);

            sensors[i]->read_colour();
            auto normalized = sensors[i]->get_colour_normalized();

            state[i][servos[i]->config.square_ids[j] - 1] = sensors[i]->get_colour_face();

            Serial.println("r:" + sensors[i]->get_colour_string() + ": " + String(normalized.red) + " " + String(normalized.green) + " " + String(normalized.blue));
        }

        Serial.println("r:");

        servos[i]->reset();
        delay(2000);
    }

    /* Offload reading of F face colours to U & R faces because I don't feel like fixing the wiring issues. */
    execute_move("R");
    execute_move("L'");
    delay(1000);

    for(int i = 1; i < 4; i++) {
        servos[0]->turn_to_square(i);
        delay(300);

        sensors[0]->read_colour();
        auto normalized = sensors[0]->get_colour_normalized();

        state[2][servos[0]->config.square_ids[i] - 1] = sensors[0]->get_colour_face();

        Serial.println("r:" + sensors[0]->get_colour_string() + ": " + String(normalized.red) + " " + String(normalized.green) + " " + String(normalized.blue));
    }

    for(int i = 5; i < 8; i++) {
        servos[0]->turn_to_square(i);
        delay(500);

        sensors[0]->read_colour();
        auto normalized = sensors[0]->get_colour_normalized();

        state[2][servos[0]->config.square_ids[i] - 1] = sensors[0]->get_colour_face();

        Serial.println("r:" + sensors[0]->get_colour_string() + ": " + String(normalized.red) + " " + String(normalized.green) + " " + String(normalized.blue));
    }

    servos[0]->reset();
    delay(1000);

    execute_move("R'");
    execute_move("L");
    delay(1000);

    execute_move("U'");
    execute_move("D");
    delay(1000);

    servos[1]->turn_to_square(0);
    delay(500);
    sensors[1]->read_colour();
    auto normalized = sensors[1]->get_colour_normalized();
    state[2][7] = sensors[1]->get_colour_face(); // Pos 8
    Serial.println("r:" + sensors[1]->get_colour_string() + ": " + String(normalized.red) + " " + String(normalized.green) + " " + String(normalized.blue));

    servos[1]->turn_to_square(4);
    delay(800);
    sensors[1]->read_colour();
    normalized = sensors[1]->get_colour_normalized();
    state[2][1] = sensors[1]->get_colour_face(); // Pos 2
    Serial.println("r:" + sensors[1]->get_colour_string() + ": " + String(normalized.red) + " " + String(normalized.green) + " " + String(normalized.blue));

    servos[1]->reset();
    delay(1000);

    execute_move("U");
    execute_move("D'");
    Serial.println("r:");
    delay(1000);

    /* Don't need to flip the state because the order is preserved when going from front to up. */

    /* Offload reading of B face colours to U & R faces because the sensor was mismanufactured and has a screwed up blue range ts pmo. */
    execute_move("R'");
    execute_move("L");
    delay(1000);

    for(int i = 1; i < 4; i++) {
        servos[0]->turn_to_square(i);
        delay(300);

        sensors[0]->read_colour();
        auto normalized = sensors[0]->get_colour_normalized();

        state[5][servos[0]->config.square_ids[i] - 1] = sensors[0]->get_colour_face();

        Serial.println("r:" + sensors[0]->get_colour_string() + ": " + String(normalized.red) + " " + String(normalized.green) + " " + String(normalized.blue));
    }

    for(int i = 5; i < 8; i++) {
        servos[0]->turn_to_square(i);
        delay(500);

        sensors[0]->read_colour();
        auto normalized = sensors[0]->get_colour_normalized();

        state[5][servos[0]->config.square_ids[i] - 1] = sensors[0]->get_colour_face();

        Serial.println("r:" + sensors[0]->get_colour_string() + ": " + String(normalized.red) + " " + String(normalized.green) + " " + String(normalized.blue));
    }

    servos[0]->reset();
    delay(1000);

    execute_move("R");
    execute_move("L'");
    delay(1000);

    execute_move("U");
    execute_move("D'");
    delay(1000);

    servos[1]->turn_to_square(0);
    delay(500);
    sensors[1]->read_colour();
    normalized = sensors[1]->get_colour_normalized();
    state[5][7] = sensors[1]->get_colour_face(); // Pos 8
    Serial.println("r:" + sensors[1]->get_colour_string() + ": " + String(normalized.red) + " " + String(normalized.green) + " " + String(normalized.blue));

    servos[1]->turn_to_square(4);
    delay(800);
    sensors[1]->read_colour();
    normalized = sensors[1]->get_colour_normalized();
    state[5][1] = sensors[1]->get_colour_face(); // Pos 2
    Serial.println("r:" + sensors[1]->get_colour_string() + ": " + String(normalized.red) + " " + String(normalized.green) + " " + String(normalized.blue));

    servos[1]->reset();
    delay(1000);

    execute_move("U'");
    execute_move("D");
    Serial.println("r:");
    delay(1000);

    String temp = "";

    temp = state[5][0];
    state[5][0] = state[5][8];
    state[5][8] = temp;

    temp = state[5][2];
    state[5][2] = state[5][6];
    state[5][6] = temp;

    temp = state[5][3];
    state[5][3] = state[5][5];
    state[5][5] = temp;

    String result = "";
    for(int i = 0; i < 6; i++) {
        for(int j = 0; j < 9; j++) {
            result += state[i][j];
        }

        result += " ";
    }

    Serial.println("state:" + result);
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
        delay(execute_move(output[i]));
    }
}