#include <Arduino.h>
#include <ESP32Servo.h>
#include <TCS3200.h>

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

Servo servo;
int currentState = 0;
unsigned long lastDebounceTime = 0;

String colourLabels[] = { "White", "Red", "Blue", "Orange", "Green", "Yellow" };
RGBColor colourValues[] = {
    {255, 255, 255}, // White
    {255, 0, 0},     // Red
    {0, 0, 255},     // Blue
    {255, 165, 0},   // Orange
    {0, 255, 0},     // Green
    {255, 255, 0}    // Yellow
};

// TCS3200 colourSensor(S0, S1, S2, S3, OUT);

int convertAngle(int angle) {
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
    r = map(redFrequency, 40, 110, 255, 0);

    digitalWrite(S2, HIGH);
    digitalWrite(S3, HIGH);
    greenFrequency = pulseIn(sensorOut, LOW);
    g = map(greenFrequency, 70, 153, 255, 0);

    digitalWrite(S2, LOW);
    digitalWrite(S3, HIGH);
    blueFrequency = pulseIn(sensorOut, LOW);
    b = map(blueFrequency, 75, 160, 255, 0);

    float sum = r + g + b;
    if(sum == 0) sum = 1;

    float r_norm = r / sum;
    float g_norm = g / sum;
    float b_norm = b / sum;

    String color;

    if(r_norm > 0.4 && g_norm > 0.4 && b_norm > 0.4) {
        color = "White";
    } else if(r_norm > 0.5 && g_norm > 0.2 && b_norm > 0.2) {
        color = "Orange";
    } else if(g_norm > 0.5 && r_norm > 0.3 && b_norm < 0.2) {
        color = "Yellow";
    } else if(r_norm > g_norm && r_norm > b_norm) {
        color = "Red";
    } else if(g_norm > r_norm && g_norm > b_norm) {
        color = "Green";
    } else if(b_norm > r_norm && b_norm > g_norm) {
        color = "Blue";
    } else {
        color = "Unknown";
    }

    Serial.println("R: " + String(r_norm) +
        ", G: " + String(g_norm) +
        ", B: " + String(b_norm) +
        " | Color: " + color);
}