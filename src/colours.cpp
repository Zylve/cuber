#include "colours.h"
#include "pins.h"

ColourConfig config_1 = {
    .white = {
        .red = {0.1, 0.35},
        .green = {0.3, 0.4},
        .blue = {0.3, 0.5}
    },
    .red = {
        .red = {0.55, 1.0},
        .green = {0.0, 0.25},
        .blue = {0.0, 0.45}
    },
    .green = {
        .red = {0.0, 0.2},
        .green = {0.55, 1.0},
        .blue = {0.0, 0.45}
    },
    .blue = {
        .red = {0.0, 0.2},
        .green = {0.0, 0.4},
        .blue = {0.6, 1.0}
    },
    .orange = {
        .red = {0.3, 0.8},
        .green = {0.0, 0.35},
        .blue = {0.2, 0.35}
    },
    .yellow = {
        .red = {0.2, 0.35},
        .green = {0.3, 0.55},
        .blue = {0.25, 0.35}
    },

    .colour_map = {
        .red = {41, 180},
        .green = {72, 255},
        .blue = {83, 311}
    }
};

ColourConfig config_2 = {
    .white = { // Uncalibrated
        .red = {0.1, 0.35},
        .green = {0.3, 0.4},
        .blue = {0.3, 0.5}
    },
    .red = { // Uncalibrated
        .red = {0.55, 1.0},
        .green = {0.0, 0.25},
        .blue = {0.0, 0.45}
    },
    .green = { // Uncalibrated
        .red = {0.0, 0.2},
        .green = {0.55, 1.0},
        .blue = {0.0, 0.45}
    },
    .blue = { // Uncalibrated
        .red = {0.0, 0.2},
        .green = {0.0, 0.4},
        .blue = {0.6, 1.0}
    },
    .orange = { // Uncalibrated
        .red = {0.3, 0.8},
        .green = {0.0, 0.35},
        .blue = {0.2, 0.35}
    },
    .yellow = { // Uncalibrated
        .red = {0.2, 0.35},
        .green = {0.3, 0.55},
        .blue = {0.25, 0.35}
    }
};

ColourConfig config_3 = {
    .white = { // Uncalibrated
        .red = {0.1, 0.35},
        .green = {0.3, 0.4},
        .blue = {0.3, 0.5}
    },
    .red = { // Uncalibrated
        .red = {0.55, 1.0},
        .green = {0.0, 0.25},
        .blue = {0.0, 0.45}
    },
    .green = { // Uncalibrated
        .red = {0.0, 0.2},
        .green = {0.55, 1.0},
        .blue = {0.0, 0.45}
    },
    .blue = { // Uncalibrated
        .red = {0.0, 0.2},
        .green = {0.0, 0.4},
        .blue = {0.6, 1.0}
    },
    .orange = { // Uncalibrated
        .red = {0.3, 0.8},
        .green = {0.0, 0.35},
        .blue = {0.2, 0.35}
    },
    .yellow = { // Uncalibrated
        .red = {0.2, 0.35},
        .green = {0.3, 0.55},
        .blue = {0.25, 0.35}
    }
};

ColourConfig config_4 = {
    .white = { // Uncalibrated
        .red = {0.1, 0.35},
        .green = {0.3, 0.4},
        .blue = {0.3, 0.5}
    },
    .red = { // Uncalibrated
        .red = {0.55, 1.0},
        .green = {0.0, 0.25},
        .blue = {0.0, 0.45}
    },
    .green = { // Uncalibrated
        .red = {0.0, 0.2},
        .green = {0.55, 1.0},
        .blue = {0.0, 0.45}
    },
    .blue = { // Uncalibrated
        .red = {0.0, 0.2},
        .green = {0.0, 0.4},
        .blue = {0.6, 1.0}
    },
    .orange = { // Uncalibrated
        .red = {0.3, 0.8},
        .green = {0.0, 0.35},
        .blue = {0.2, 0.35}
    },
    .yellow = { // Uncalibrated
        .red = {0.2, 0.35},
        .green = {0.3, 0.55},
        .blue = {0.25, 0.35}
    }
};

ColourConfig config_5 = {
    .white = { // Uncalibrated
        .red = {0.1, 0.35},
        .green = {0.3, 0.4},
        .blue = {0.3, 0.5}
    },
    .red = { // Uncalibrated
        .red = {0.55, 1.0},
        .green = {0.0, 0.25},
        .blue = {0.0, 0.45}
    },
    .green = { // Uncalibrated
        .red = {0.0, 0.2},
        .green = {0.55, 1.0},
        .blue = {0.0, 0.45}
    },
    .blue = { // Uncalibrated
        .red = {0.0, 0.2},
        .green = {0.0, 0.4},
        .blue = {0.6, 1.0}
    },
    .orange = { // Uncalibrated
        .red = {0.3, 0.8},
        .green = {0.0, 0.35},
        .blue = {0.2, 0.35}
    },
    .yellow = { // Uncalibrated
        .red = {0.2, 0.35},
        .green = {0.3, 0.55},
        .blue = {0.25, 0.35}
    }
};

ColourConfig config_6 = {
    .white = { // Uncalibrated
        .red = {0.1, 0.35},
        .green = {0.3, 0.4},
        .blue = {0.3, 0.5}
    },
    .red = { // Uncalibrated
        .red = {0.55, 1.0},
        .green = {0.0, 0.25},
        .blue = {0.0, 0.45}
    },
    .green = { // Uncalibrated
        .red = {0.0, 0.2},
        .green = {0.55, 1.0},
        .blue = {0.0, 0.45}
    },
    .blue = { // Uncalibrated
        .red = {0.0, 0.2},
        .green = {0.0, 0.4},
        .blue = {0.6, 1.0}
    },
    .orange = { // Uncalibrated
        .red = {0.3, 0.8},
        .green = {0.0, 0.35},
        .blue = {0.2, 0.35}
    },
    .yellow = { // Uncalibrated
        .red = {0.2, 0.35},
        .green = {0.3, 0.55},
        .blue = {0.25, 0.35}
    }
};

bool bounds_check(float value, float min, float max) {
    return value >= min && value <= max;
}

bool in_range(ColourNormalized colour, ColourThresholds thresholds) {
    return bounds_check(colour.red, thresholds.red.min, thresholds.red.max) &&
           bounds_check(colour.green, thresholds.green.min, thresholds.green.max) &&
           bounds_check(colour.blue, thresholds.blue.min, thresholds.blue.max);
};

String get_colour(ColourNormalized colour, ColourConfig config) {
    if(in_range(colour, config.white)) {
        return "White";
    }

    if(in_range(colour, config.orange)) {
        return "Orange";
    }

    if(in_range(colour, config.red)) {
        return "Red";
    }

    if(in_range(colour, config.green)) {
        return "Green";
    }

    if(in_range(colour, config.blue)) {
        return "Blue";
    }

    if(in_range(colour, config.yellow)) {
        return "Yellow";
    }

    return "Unknown";
}

ColourSensor sensor_1(config_1, SENSOR_1_OUT);
ColourSensor sensor_2(config_2, SENSOR_2_OUT);
ColourSensor sensor_3(config_3, SENSOR_3_OUT);
ColourSensor sensor_4(config_4, SENSOR_4_OUT);
ColourSensor sensor_5(config_5, SENSOR_5_OUT);
ColourSensor sensor_6(config_6, SENSOR_6_OUT);