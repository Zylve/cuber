#include "servos.h"
#include "pins.h"
#include "colours.h"

ServoConfig servo_config_1 = {
    .axis_positions = {
        {7, 50, 85, 126},
        {7, 50, 85, 126},
        {7, 44, 85, 126},
        {7, 44, 78, 126}
    },
    .square_positions = {25, 42, 61, 79, 99, 119, 140, 157},
    .square_ids = {2, 3, 6, 9, 8, 7, 4, 1} // Different because of the net in the algorithm :/
};

ServoConfig servo_config_2 = {
    .axis_positions = {
        {14, 58, 103, 145},
        {14, 58, 103, 145},
        {14, 49, 103, 145},
        {14, 49, 92, 145}
    },
    .square_positions = {33, 52, 74, 96, 118, 140, 154, 173},
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
        {27, 70, 110, 150},
        {27, 70, 110, 150},
        {27, 65, 110, 150},
        {27, 65, 105, 150}
    },
    .square_positions = {0, 22, 45, 67, 90, 112, 135, 157},
    .square_ids = {8, 7, 4, 1, 2, 3, 6, 9}
};

ServoConfig servo_config_5 = {
    .axis_positions = {
        {5, 50, 93, 135},
        {5, 48, 93, 135},
        {5, 42, 93, 135},
        {5, 42, 83, 135}
    },
    .square_positions = {0, 22, 45, 67, 90, 112, 135, 157},
    .square_ids = {8, 7, 4, 1, 2, 3, 6, 9}
};

ServoConfig servo_config_6 = {
    .axis_positions = {
        {23, 65, 108, 147},
        {23, 65, 108, 147},
        {23, 60, 108, 147},
        {23, 60, 100, 147}
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