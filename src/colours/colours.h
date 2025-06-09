#pragma once

struct ColourChannelBounds {
    float min, max;
};

struct ColourThresholds {
    ColourChannelBounds red, green, blue;
};

struct ColourConfig {
    ColourThresholds white, red, green, blue, orange, yellow;
};

extern ColourConfig sensor_1;