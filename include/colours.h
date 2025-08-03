#pragma once

#include <Arduino.h>
#include <string>
#include "pins.h"

using namespace std;

struct ColourRaw {
    int red, green, blue;

    ColourRaw(int r, int g, int b) : red(r), green(g), blue(b) {}
};

struct ColourBounded {
    int red, green, blue;

    ColourBounded(int r, int g, int b) : red(r), green(g), blue(b) {}
};

struct ColourNormalized {
    float red, green, blue;

    ColourNormalized(float r, float g, float b) : red(r), green(g), blue(b) {}

    ColourNormalized(ColourBounded bounded) {
        float sum = bounded.red + bounded.green + bounded.blue;

        if(sum == 0) sum = 1;

        red = static_cast<float>(bounded.red) / sum;
        green = static_cast<float>(bounded.green) / sum;
        blue = static_cast<float>(bounded.blue) / sum;
    }
};

struct ColourChannelMapBound {
    int min, max;
};

struct ColourMap {
    ColourChannelMapBound red, green, blue;
};

struct ColourChannelThreshold {
    float min, max;
};

struct ColourThresholds {
    ColourChannelThreshold red, green, blue;
};

struct ColourConfig {
    ColourThresholds white, red, green, blue, orange, yellow;
    ColourMap colour_map;
};

String get_colour_string(ColourNormalized colour, ColourConfig config);
int get_colour(ColourNormalized colour, ColourConfig config);
String get_colour_face(ColourNormalized colour, ColourConfig config);

struct ColourSensor {
    ColourConfig config;
    int sensor_out;

    ColourSensor(ColourConfig config, int sensor_out) : config(config), sensor_out(sensor_out) {}

    ColourRaw colour_raw = ColourRaw(0, 0, 0);
    ColourBounded colour_bounded = ColourBounded(0, 0, 0);
    ColourNormalized colour_normalized = ColourNormalized(0.0f, 0.0f, 0.0f);

    ColourRaw get_colour_raw() {
        return colour_raw;
    }

    ColourBounded get_colour_bounded() {
        return colour_bounded;
    }

    ColourNormalized get_colour_normalized() {
        return colour_normalized;
    }

    void read_colour() {
        int redFrequency = 0;
        int greenFrequency = 0;
        int blueFrequency = 0;

        digitalWrite(S2, LOW);
        digitalWrite(S3, LOW);
        digitalWrite(S2_1, LOW);
        digitalWrite(S3_1, LOW);
        redFrequency = pulseIn(sensor_out, LOW);

        digitalWrite(S2, HIGH);
        digitalWrite(S3, HIGH);
        digitalWrite(S2_1, HIGH);
        digitalWrite(S3_1, HIGH);
        greenFrequency = pulseIn(sensor_out, LOW);

        digitalWrite(S2, LOW);
        digitalWrite(S3, HIGH);
        digitalWrite(S2_1, LOW);
        digitalWrite(S3_1, HIGH);
        blueFrequency = pulseIn(sensor_out, LOW);

        colour_raw = ColourRaw(redFrequency, greenFrequency, blueFrequency);

        colour_bounded = ColourBounded(
            constrain(map(redFrequency, config.colour_map.red.min, config.colour_map.red.max, 255, 0), 0, 255),
            constrain(map(greenFrequency, config.colour_map.green.min, config.colour_map.green.max, 255, 0), 0, 255),
            constrain(map(blueFrequency, config.colour_map.blue.min, config.colour_map.blue.max, 255, 0), 0, 255)
        );

        colour_normalized = ColourNormalized(colour_bounded);
    }

    String get_colour_string() {
        ColourNormalized colour = get_colour_normalized();
        return ::get_colour_string(colour, config);
    }

    int get_colour() {
        ColourNormalized colour = get_colour_normalized();
        return ::get_colour(colour, config);
    }

    String get_colour_face() {
        ColourNormalized colour = get_colour_normalized();
        return ::get_colour_face(colour, config);
    }
};

extern ColourSensor sensor_1;
extern ColourSensor sensor_2;
extern ColourSensor sensor_3;
extern ColourSensor sensor_4;
extern ColourSensor sensor_5;
extern ColourSensor sensor_6;

extern ColourSensor* sensors[];