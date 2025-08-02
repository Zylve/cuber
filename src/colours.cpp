#include "colours.h"
#include "pins.h"

ColourConfig config_1 = {
    .white = { // White Face
        .red = {0.31, 0.34},
        .green = {0.32, 0.35},
        .blue = {0.32, 0.35}
    },
    .red = {
        .red = {0.50, 1.0},
        .green = {0.16, 0.38},
        .blue = {0.0, 0.18}
    },
    .green = {
        .red = {0.21, 0.43},
        .green = {0.45, 0.62},
        .blue = {0.11, 0.26}
    },
    .blue = {
        .red = {0.00, 0.39},
        .green = {0.32, 0.41},
        .blue = {0.50, 0.66}
    },
    .orange = {
        .red = {0.40, 0.45},
        .green = {0.32, 0.35},
        .blue = {0.21, 0.26}
    },
    .yellow = {
        .red = {0.34, 0.38},
        .green = {0.35, 0.39},
        .blue = {0.25, 0.29}
    },

    // .colour_map = {
    //     .red = {63, 327},
    //     .green = {85, 265},
    //     .blue = {79, 215}
    // }

    .colour_map = {
        .red = {480, 7000},
        .green = {690, 6400},
        .blue = {660, 4300}
    }
};

ColourConfig config_2 = {
    .white = { // Red Face, Uncalibrated
        .red = {0.29, 0.35},
        .green = {0.31, 0.38},
        .blue = {0.31, 0.38}
    },
    .red = {
        .red = {0.40, 1.0},
        .green = {0.0, 0.35},
        .blue = {0.0, 0.25}
    },
    .green = {
        .red = {0.21, 0.33},
        .green = {0.5, 0.80},
        .blue = {0.00, 0.27}
    },
    .blue = {
        .red = {0.00, 0.20},
        .green = {0.10, 0.36},
        .blue = {0.47, 1.00}
    },
    .orange = {
        .red = {0.50, 0.60},
        .green = {0.23, 0.30},
        .blue = {0.16, 0.23}
    },
    .yellow = {
        .red = {0.35, 0.40},
        .green = {0.40, 0.44},
        .blue = {0.17, 0.23}
    },

    .colour_map = {
        .red = {122, 415},
        .green = {167, 422},
        .blue = {146, 342}
    }
};

ColourConfig config_3 = {
    .white = { // Green Face, Uncalibrated
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
        .red = {63, 327},
        .green = {85, 265},
        .blue = {79, 215}
    }
};

ColourConfig config_4 = {
    .white = { // Blue Face, Uncalibrated
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
        .red = {63, 327},
        .green = {85, 265},
        .blue = {79, 215}
    }
};

ColourConfig config_5 = {
    .white = { // Orange Face, Uncalibrated
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
        .red = {63, 327},
        .green = {85, 265},
        .blue = {79, 215}
    }
};

ColourConfig config_6 = {
    .white = { // Yellow Face, Uncalibrated
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
        .red = {63, 327},
        .green = {85, 265},
        .blue = {79, 215}
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