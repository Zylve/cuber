#include <Arduino.h>
#include <ESP32Servo.h>

#define BUTTON_PIN 4
#define SERVO_PIN 12

#define DEBOUNCE_DELAY 200

#define GEAR_RATIO 2.5
#define OFFSET 10

Servo servo;
int currentState = 0;
unsigned long lastDebounceTime = 0;

int convertAngle(int angle) {
    return (angle + OFFSET) / GEAR_RATIO;
}

void setup() {
    servo.attach(SERVO_PIN);
    servo.write(convertAngle(0));
    pinMode(BUTTON_PIN, INPUT_PULLUP);
    Serial.begin(9600);
}

void loop() {
    unsigned long currentTime = millis();

    if(digitalRead(BUTTON_PIN) == LOW && (currentTime - lastDebounceTime > DEBOUNCE_DELAY)){
        lastDebounceTime = currentTime;
        currentState = (currentState + 1) % 4;
        int angle = currentState * 90;
        servo.write(convertAngle(angle));
    }

    Serial.println(servo.read());
}