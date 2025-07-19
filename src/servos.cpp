#include "servos.h"
#include "pins.h"

ServoConfig servo_config_1 = {
    .axis_positions = {
        {7, 50, 85, 126},
        {7, 50, 85, 126},
        {7, 44, 85, 126},
        {7, 44, 78, 126}
    },
    .square_positions = {0, 45, 90, 135, 180, 225, 270, 315}
};

ServoConfig servo_config_2 = {
    .axis_positions = {
        {145, 14, 49, 92},
        {145, 14, 58, 103},
        {145, 14, 58, 103},
        {145, 14, 49, 92}
    },
    .square_positions = {0, 45, 90, 135, 180, 225, 270, 315}
};

ServoConfig servo_config_3 = {
    .axis_positions = {
        {125, 6, 40, 75},
        {125, 6, 45, 85},
        {125, 6, 40, 85},
        {125, 6, 38, 80}
    },
    .square_positions = {0, 45, 90, 135, 180, 225, 270, 315}
};

ServoConfig servo_config_4 = {
    .axis_positions = {
        {70, 110, 150, 27},
        {65, 110, 150, 27},
        {65, 105, 150, 27},
        {70, 110, 150, 27}
    },
    .square_positions = {0, 45, 90, 135, 180, 225, 270, 315}
};

ServoConfig servo_config_5 = {
    .axis_positions = {
        {5, 50, 93, 135},
        {5, 48, 93, 135},
        {5, 42, 93, 135},
        {5, 42, 83, 135}
    },
    .square_positions = {0, 45, 90, 135, 180, 225, 270, 315}
};

ServoConfig servo_config_6 = {
    .axis_positions = {
        {23, 65, 108, 147},
        {23, 65, 108, 147},
        {23, 60, 108, 147},
        {23, 60, 100, 147}
    },
    .square_positions = {0, 45, 90, 135, 180, 225, 270, 315}
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

void servo_input(int id) {
    if(Serial.available()) {
        String input = Serial.readStringUntil('\n');
        int angle = input.toInt();

        if(angle >= 0 && angle <= 180) {
            servos[id - 1]->servo.write(angle);
            Serial.print("Moved to: ");
            Serial.println(angle);
        } else {
            Serial.println("Invalid angle.");
        }

        while(Serial.available()) Serial.read();
    }
}