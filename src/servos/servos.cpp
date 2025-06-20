#include "servos.h"
#include "pins/pins.h"

ServoConfig servo_config_1 = {
    .axis_positions = {0, 90, 180, 270},
    .square_positions = {0, 45, 90, 135, 180, 225, 270, 315}
};

ServoConfig servo_config_2 = {
    .axis_positions = {0, 90, 180, 270},
    .square_positions = {0, 45, 90, 135, 180, 225, 270, 315}
};

ServoConfig servo_config_3 = {
    .axis_positions = {0, 90, 180, 270},
    .square_positions = {0, 45, 90, 135, 180, 225, 270, 315}
};

ServoConfig servo_config_4 = {
    .axis_positions = {0, 90, 180, 270},
    .square_positions = {0, 45, 90, 135, 180, 225, 270, 315}
};

ServoConfig servo_config_5 = {
    .axis_positions = {0, 90, 180, 270},
    .square_positions = {0, 45, 90, 135, 180, 225, 270, 315}
};

ServoConfig servo_config_6 = {
    .axis_positions = {0, 90, 180, 270},
    .square_positions = {0, 45, 90, 135, 180, 225, 270, 315}
};

ServoWrapper servo_1(servo_config_1, servo_1_pin);
ServoWrapper servo_2(servo_config_2, servo_2_pin);
ServoWrapper servo_3(servo_config_3, servo_3_pin);
ServoWrapper servo_4(servo_config_4, servo_4_pin);
ServoWrapper servo_5(servo_config_5, servo_5_pin);
ServoWrapper servo_6(servo_config_6, servo_6_pin);

void servos_setup() {
    servo_1.attach();
    servo_2.attach();
    servo_3.attach();
    servo_4.attach();
    servo_5.attach();
    servo_6.attach();

    servo_1.reset();
    servo_2.reset();
    servo_3.reset();
    servo_4.reset();
    servo_5.reset();
    servo_6.reset();
}