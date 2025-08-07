#include "servos.h"
#include "pins.h"
#include "colours.h"

ServoConfig servo_config_1 = {
    .axis_positions = {
        {2, 42, 78, 117},
        {2, 38, 78, 117},
        {2, 38, 78, 117},
        {2, 38, 72, 117}
    },
    .square_positions = {20, 35, 56, 71, 93, 109, 132, 149},
    .square_ids = {2, 3, 6, 9, 8, 7, 4, 1} // Different because of the net in the algorithm :/
};

ServoConfig servo_config_2 = {
    .axis_positions = {
        {14, 58, 103, 145},
        {14, 58, 103, 145},
        {14, 49, 103, 145},
        {14, 49, 92, 145}
    },
    .square_positions = {33, 52, 74, 96, 116, 140, 154, 173},
    .square_ids = {8, 7, 4, 1, 2, 3, 6, 9}
};

ServoConfig servo_config_3 = {
    .axis_positions = {
        {6, 45, 85, 125},
        {6, 45, 85, 125},
        {6, 38, 85, 125},
        {6, 40, 75, 125}
    },
    .square_positions = {24, 39, 60, 79, 102, 121, 142, 159},
    .square_ids = {8, 7, 4, 1, 2, 3, 6, 9}
};

ServoConfig servo_config_4 = {
    .axis_positions = {
        {23, 65, 108, 147},
        {23, 65, 108, 147},
        {23, 60, 108, 147},
        {23, 60, 100, 147}
    },
    .square_positions = {41, 59, 80, 99, 124, 143, 160, 178},
    .square_ids = {8, 7, 4, 1, 2, 3, 6, 9}
};

ServoConfig servo_config_5 = {
    .axis_positions = {
        {5, 50, 93, 135},
        {5, 48, 93, 135},
        {5, 39, 93, 135},
        {5, 39, 83, 135}
    },
    .square_positions = {24, 42, 63, 84, 108, 129, 148, 167},
    .square_ids = {8, 7, 4, 1, 2, 3, 6, 9}
};

ServoConfig servo_config_6 = {
    .axis_positions = {
        {27, 70, 110, 150},
        {27, 70, 110, 150},
        {27, 65, 110, 150},
        {27, 65, 105, 150}
    },
    .square_positions = {0, 22, 45, 67, 90, 112, 135, 157},
    .square_ids = {8, 7, 4, 1, 2, 3, 6, 9}
};

ServoWrapper servo_1(servo_config_1, SERVO_1_PIN);
ServoWrapper servo_2(servo_config_2, SERVO_2_PIN);
ServoWrapper servo_3(servo_config_3, SERVO_3_PIN);
ServoWrapper servo_4(servo_config_4, SERVO_4_PIN);
ServoWrapper servo_5(servo_config_5, SERVO_5_PIN);
ServoWrapper servo_6(servo_config_6, SERVO_6_PIN);

ServoWrapper* servos[] = {
    &servo_1,
    &servo_2,
    &servo_3,
    &servo_4,
    &servo_5,
    &servo_6
};

unsigned long lastColorRead = 0;
const unsigned long COLOR_READ_INTERVAL = 1000;

void servo_input(int id, bool square_input) {
    unsigned long currentMillis = millis();

    if(currentMillis - lastColorRead >= COLOR_READ_INTERVAL) {
        sensors[id]->read_colour();
        auto normalized = sensors[id]->get_colour_normalized();
        auto written_colour = sensors[id]->get_colour_string();
        Serial.println(written_colour + ": " + String(normalized.red) + " " + String(normalized.green) + " " + String(normalized.blue));
        lastColorRead = currentMillis;
    }

    if(Serial.available()) {
        String input = Serial.readStringUntil('\n');
        int angle = input.toInt();

        if(!square_input) {
            if(angle >= 0 && angle <= 180) {
                servos[id]->servo.write(angle);
                Serial.print("Moved to: ");
                Serial.println(angle);
            } else {
                Serial.println("Invalid angle.");
            }
        } else {
            if(angle >= 0 && angle < 8) {
                servos[id]->servo.write(servos[id]->config.square_positions[angle]);
                Serial.print("Moved to square: ");
                Serial.println(angle);
            } else {
                Serial.println("Invalid square index.");
            }
        }

        while(Serial.available()) Serial.read();
    }
}

int execute_move(String move) {
    if(move == "D") {
            servos[3]->turn_right();
        } else if(move == "D'") {
            servos[3]->turn_left();
        } else if(move == "D2") {
            servos[3]->turn_180();

        } else if(move == "F") {
            servos[2]->turn_right();
        } else if(move == "F'") {
            servos[2]->turn_left();
        } else if(move == "F2") {
            servos[2]->turn_180();

        } else if(move == "B") {
            servos[5]->turn_right();
        } else if(move == "B'") {
            servos[5]->turn_left();
        } else if(move == "B2") {
            servos[5]->turn_180();

        } else if(move == "L") {
            servos[4]->turn_right();
        } else if(move == "L'") {
            servos[4]->turn_left();
        } else if(move == "L2") {
            servos[4]->turn_180();

        } else if(move == "R") {
            servos[1]->turn_right();
        } else if(move == "R'") {
            servos[1]->turn_left();
        } else if(move == "R2") {
            servos[1]->turn_180();

        } else if(move == "U") {
            servos[0]->turn_right();
        } else if(move == "U'") {
            servos[0]->turn_left();
        } else if(move == "U2") {
            servos[0]->turn_180();
        }

    return 800;
}