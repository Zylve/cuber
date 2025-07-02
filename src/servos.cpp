#include "servos.h"
#include "pins.h"

ServoConfig servo_config_1 = {
    .axis_positions = {0, 90, 180, 270},
    .square_positions = {0, 45, 90, 135, 180, 225, 270, 315}
};

ServoConfig servo_config_2 = {
    .axis_positions = {15, 55, 100, 145},
    .square_positions = {0, 45, 90, 135, 180, 225, 270, 315}
};

ServoConfig servo_config_3 = {
    .axis_positions = {5, 41, 79, 125},
    .square_positions = {0, 45, 90, 135, 180, 225, 270, 315}
};

ServoConfig servo_config_4 = {
    .axis_positions = {30, 66, 108, 150},
    .square_positions = {0, 45, 90, 135, 180, 225, 270, 315}
};

ServoConfig servo_config_5 = {
    .axis_positions = {8, 47, 88, 133},
    .square_positions = {0, 45, 90, 135, 180, 225, 270, 315}
};

ServoConfig servo_config_6 = {
    .axis_positions = {26, 62, 105, 145},
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