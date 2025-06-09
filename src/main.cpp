#include <Arduino.h>
#include <ESP32Servo.h>
#include "colours/colours.h"

#define BUTTON_PIN 4
#define SERVO_PIN 12

#define S0 26
#define S1 27
#define S2 32
#define S3 33
#define sensorOut 25

#define DEBOUNCE_DELAY 200

#define GEAR_RATIO 2.5
#define OFFSET 10

#define YELLOW_MIN_R   0.4
#define YELLOW_MIN_G   0.4
#define YELLOW_MAX_B   0.15

#define ORANGE_MIN_R   0.6
#define ORANGE_MAX_G   0.4
#define ORANGE_MAX_B   0.15

#define WHITE_MIN      0.30
#define WHITE_MAX      0.37
#define WHITE_TOLERANCE 0.07

Servo servo;
int currentState = 0;
unsigned long lastDebounceTime = 0;

String get_colour(float, float, float, ColourConfig config = sensor_1);

int convert_angle(int angle) {
    return (angle + OFFSET) / GEAR_RATIO;
}

// void setup() {
//     // servo.attach(SERVO_PIN);
//     // servo.write(convertAngle(0));
//     // pinMode(BUTTON_PIN, INPUT_PULLUP);
//     // pinMode(18, OUTPUT);
//     Serial.begin(9600);
//     colourSensor.begin();
//     colourSensor.frequency_scaling(TCS3200_OFREQ_20P);

//     Serial.println("Cal light");
//     colourSensor.calibrate_light();
//     Serial.println("Done light");
//     delay(2000);
//     Serial.println("Cal dark");
//     colourSensor.calibrate_dark();  
//     Serial.println("Done dark");
//     delay(2000);

//     // RGBColor whiteBalance = {125, 70, 80};
//     // RGBColor whiteBalance = colourSensor.read_rgb_color();
//     // colourSensor.white_balance(whiteBalance);
// }

// void loop() {
//     // unsigned long currentTime = millis();

//     // if(digitalRead(BUTTON_PIN) == LOW && (currentTime - lastDebounceTime > DEBOUNCE_DELAY)){
//     //     lastDebounceTime = currentTime;
//     //     currentState = (currentState + 1) % 4;
//     //     int angle = currentState * 90;
//     //     servo.write(convertAngle(angle));
//     // }

//     // Serial.println(servo.read());

//     // Serial.println(colourSensor.nearest_color(colourLabels, colourValues, 6));
//     Serial.println("R: " + String(colourSensor.read_rgb_color().red) + 
//                    ", G: " + String(colourSensor.read_rgb_color().green) + 
//                    ", B: " + String(colourSensor.read_rgb_color().blue));
// }


int redFrequency = 0;
int greenFrequency = 0;
int blueFrequency = 0;

int r = 0;
int g = 0;
int b = 0;

void setup() {
    // Setting the outputs
    pinMode(S0, OUTPUT);
    pinMode(S1, OUTPUT);
    pinMode(S2, OUTPUT);
    pinMode(S3, OUTPUT);

    // Setting the sensorOut as an input
    pinMode(sensorOut, INPUT);

    // Setting frequency scaling to 20%
    digitalWrite(S0, HIGH);
    digitalWrite(S1, LOW);

    // Begins serial communication
    Serial.begin(9600);
}

void loop() {
    digitalWrite(S2, LOW);
    digitalWrite(S3, LOW);
    redFrequency = pulseIn(sensorOut, LOW);
    r = constrain(map(redFrequency, 41, 180, 255, 0), 0, 255);

    digitalWrite(S2, HIGH);
    digitalWrite(S3, HIGH);
    greenFrequency = pulseIn(sensorOut, LOW);
    g = constrain(map(greenFrequency, 72, 255, 255, 0), 0, 255);

    digitalWrite(S2, LOW);
    digitalWrite(S3, HIGH);
    blueFrequency = pulseIn(sensorOut, LOW);
    b = constrain(map(blueFrequency, 83, 311, 255, 0), 0, 255);

    float sum = r + g + b;
    if(sum == 0) sum = 1;

    float r_norm = r / sum;
    float g_norm = g / sum;
    float b_norm = b / sum;

    String colour = get_colour(r_norm, g_norm, b_norm);




    Serial.println("R: " + String(r_norm) +
        ", G: " + String(g_norm) +
        ", B: " + String(b_norm)
        + " - Colour: " + colour);

}

String get_colour(float r, float g, float b, ColourConfig config) {
    auto bounds_check = [](float value, float min, float max) {
        return value >= min && value <= max;
        };

    auto in_range = [&](float r, float g, float b, ColourThresholds thresholds) {
        return bounds_check(r, thresholds.red.min, thresholds.red.max) &&
            bounds_check(g, thresholds.green.min, thresholds.green.max) &&
            bounds_check(b, thresholds.blue.min, thresholds.blue.max);
        };

    if(in_range(r, g, b, config.white)) {
        return "White";
    }

    if(in_range(r, g, b, config.orange)) {
        return "Orange";
    }

    if(in_range(r, g, b, config.red)) {
        return "Red";
    }

    if(in_range(r, g, b, config.green)) {
        return "Green";
    }

    if(in_range(r, g, b, config.blue)) {
        return "Blue";
    }

    if(in_range(r, g, b, config.yellow)) {
        return "Yellow";
    }

    return "Unknown";
}