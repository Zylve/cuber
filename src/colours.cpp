#include "colours.h"
#include "pins.h"

ColourConfig config_1 = {
    .white = {
        .red = {0.30, 0.35},
        .green = {0.31, 0.37},
        .blue = {0.31, 0.37}
    },
    .red = {
        .red = {0.50, 1.0},
        .green = {0.0, 0.18},
        .blue = {0.0, 0.18}
    },
    .green = {
        .red = {0.25, 0.33},
        .green = {0.5, 0.80},
        .blue = {0.00, 0.27}
    },
    .blue = {
        .red = {0.00, 0.25},
        .green = {0.05, 0.30},
        .blue = {0.50, 0.95}
    },
    .orange = {
        .red = {0.42, 0.55},
        .green = {0.25, 0.32},
        .blue = {0.17, 0.23}
    },
    .yellow = {
        .red = {0.34, 0.39},
        .green = {0.37, 0.43},
        .blue = {0.17, 0.24}
    },

    .colour_map = {
        .red = {63, 327},
        .green = {85, 265},
        .blue = {79, 215}
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

ColourSensor* sensors[] = {
    &sensor_1,
    &sensor_2,
    &sensor_3,
    &sensor_4,
    &sensor_5,
    &sensor_6
};