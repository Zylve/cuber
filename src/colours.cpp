#include "colours.h"
#include "pins.h"

ColourConfig config_1 = {
    .white = { // White Face
        .red = {0.30, 0.36},
        .green = {0.31, 0.37},
        .blue = {0.31, 0.37}
    },
    .red = {
        .red = {0.48, 1.00},
        .green = {0.00, 0.25},
        .blue = {0.00, 0.20}
    },
    .green = {
        .red = {0.35, 0.46},
        .green = {0.30, 0.64},
        .blue = {0.00, 0.17}
    },
    .blue = {
        .red = {0.11, 0.42},
        .green = {0.15, 0.33},
        .blue = {0.37, 0.68}
    },
    .orange = {
        .red = {0.38, 0.58},
        .green = {0.28, 0.36},
        .blue = {0.13, 0.30}
    },
    .yellow = {
        .red = {0.33, 0.42},
        .green = {0.33, 0.42},
        .blue = {0.20, 0.29}
    },

    .colour_map = {
        .red = {2500, 38000},
        .green = {3600, 24000},
        .blue = {3400, 18000}
    }
};

ColourConfig config_2 = {
        .white = { // Red Face
        .red = {0.32, 0.38},
        .green = {0.30, 0.36},
        .blue = {0.29, 0.35}
    },
    .red = {
        .red = {0.48, 1.00},
        .green = {0.00, 0.25},
        .blue = {0.00, 0.20}
    },
    .green = {
        .red = {0.16, 0.45},
        .green = {0.55, 1.00},
        .blue = {0.00, 0.15}
    },
    .blue = {
        .red = {0.00, 0.15},
        .green = {0.00, 0.15},
        .blue = {0.70, 1.00}
    },
    .orange = {
        .red = {0.50, 0.80},
        .green = {0.24, 0.36},
        .blue = {0.00, 0.20}
    },
    .yellow = {
        .red = {0.38, 0.50},
        .green = {0.38, 0.46},
        .blue = {0.00, 0.22}
    },

    .colour_map = {
        .red = {1300, 40000},
        .green = {1900, 23000},
        .blue = {2300, 17000}
    }
};

ColourConfig config_3 = {
        .white = { // Green Face
        .red = {0.30, 0.36},
        .green = {0.31, 0.37},
        .blue = {0.31, 0.37}
    },
    .red = {
        .red = {0.48, 1.00},
        .green = {0.00, 0.25},
        .blue = {0.00, 0.25}
    },
    .green = {
        .red = {0.35, 0.48},
        .green = {0.37, 0.60},
        .blue = {0.00, 0.20}
    },
    .blue = {
        .red = {0.00, 0.39},
        .green = {0.10, 0.37},
        .blue = {0.34, 1.00}
    },
    .orange = {
        .red = {0.38, 0.50},
        .green = {0.28, 0.36},
        .blue = {0.13, 0.30}
    },
    .yellow = {
        .red = {0.33, 0.44},
        .green = {0.33, 0.44},
        .blue = {0.16, 0.29}
    },

    .colour_map = {
        .red = {1800, 55000},
        .green = {2400, 25000},
        .blue = {3000, 19000}
    }
};

ColourConfig config_4 = {
        .white = { // Blue Face; Uncalibrated
        .red = {0.32, 0.36},
        .green = {0.30, 0.36},
        .blue = {0.32, 0.37}
    },
    .red = {
        .red = {0.46, 0.62},
        .green = {0.00, 0.18},
        .blue = {0.36, 0.42}
    },
    .green = {
        .red = {0.20, 0.32},
        .green = {0.30, 0.41},
        .blue = {0.30, 0.41}
    },
    .blue = {
        .red = {0.00, 0.15},
        .green = {0.15, 0.33},
        .blue = {0.50, 1.00}
    },
    .orange = {
        .red = {0.34, 0.42},
        .green = {0.23, 0.28},
        .blue = {0.35, 0.40}
    },
    .yellow = {
        .red = {0.32, 0.34},
        .green = {0.32, 0.34},
        .blue = {0.33, 0.35}
    },

    .colour_map = {
        .red = {3600, 60000},
        .green = {4000, 50000},
        .blue = {800, 18000} // 9200
    }
};

ColourConfig config_5 = {
        .white = { // Orange Face; Uncalibrated
        .red = {0.30, 0.36},
        .green = {0.31, 0.37},
        .blue = {0.31, 0.37}
    },
    .red = {
        .red = {0.48, 1.00},
        .green = {0.00, 0.25},
        .blue = {0.00, 0.20}
    },
    .green = {
        .red = {0.35, 0.46},
        .green = {0.30, 0.64},
        .blue = {0.00, 0.17}
    },
    .blue = {
        .red = {0.11, 0.42},
        .green = {0.15, 0.33},
        .blue = {0.37, 0.68}
    },
    .orange = {
        .red = {0.38, 0.58},
        .green = {0.28, 0.36},
        .blue = {0.13, 0.30}
    },
    .yellow = {
        .red = {0.33, 0.42},
        .green = {0.33, 0.42},
        .blue = {0.20, 0.29}
    },

    .colour_map = {
        .red = {2500, 38000},
        .green = {3600, 24000},
        .blue = {3400, 18000}
    }
};

ColourConfig config_6 = {
        .white = { // Yellow Face; Uncalibrated
        .red = {0.30, 0.36},
        .green = {0.31, 0.37},
        .blue = {0.31, 0.37}
    },
    .red = {
        .red = {0.48, 1.00},
        .green = {0.00, 0.25},
        .blue = {0.00, 0.20}
    },
    .green = {
        .red = {0.35, 0.46},
        .green = {0.30, 0.64},
        .blue = {0.00, 0.17}
    },
    .blue = {
        .red = {0.11, 0.42},
        .green = {0.15, 0.33},
        .blue = {0.37, 0.68}
    },
    .orange = {
        .red = {0.38, 0.58},
        .green = {0.28, 0.36},
        .blue = {0.13, 0.30}
    },
    .yellow = {
        .red = {0.33, 0.42},
        .green = {0.33, 0.42},
        .blue = {0.20, 0.29}
    },

    .colour_map = {
        .red = {2500, 38000},
        .green = {3600, 24000},
        .blue = {3400, 18000}
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

String get_colour_string(ColourNormalized colour, ColourConfig config) {
    if(in_range(colour, config.white)) {
        return "White";
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

    if(in_range(colour, config.orange)) {
        return "Orange";
    }

    if(in_range(colour, config.yellow)) {
        return "Yellow";
    }

    return "Unknown";
}

int get_colour(ColourNormalized colour, ColourConfig config) {
    // Wiring & Code IDs:
    // - White: 0 (1)
    // - Red: 1 (2)
    // - Green: 2 (3)
    // - Blue: 3 (4)
    // - Orange: 4 (5)
    // - Yellow: 5 (6)

    if(in_range(colour, config.white)) {
        return 0;
    }

    if(in_range(colour, config.red)) {
        return 1;
    }

    if(in_range(colour, config.green)) {
        return 2;
    }

    if(in_range(colour, config.blue)) {
        return 3;
    }

    if(in_range(colour, config.orange)) {
        return 4;
    }

    if(in_range(colour, config.yellow)) {
        return 5;
    }

    return -1;
}

String get_colour_face(ColourNormalized colour, ColourConfig config) {
    //     Actual Positions:
    // - U: White
    // - R: Red
    // - F: Green
    // - D: Yellow
    // - L: Orange
    // - B: Blue

    if(in_range(colour, config.white)) {
        return "U";
    }

    if(in_range(colour, config.red)) {
        return "R";
    }

    if(in_range(colour, config.green)) {
        return "F";
    }

    if(in_range(colour, config.blue)) {
        return "B";
    }

    if(in_range(colour, config.orange)) {
        return "L";
    }

    if(in_range(colour, config.yellow)) {
        return "D";
    }

    return "E";
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