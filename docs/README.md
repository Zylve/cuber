# Documentation

## Notes
All colours in this project have an ID associated with it. Here are the mappings:
| Colour | ID (0-index) | ID (1-index) | Face |
|:------:|:------------:|:------------:|:----:|
| White  | 0            | 1            | U    |
| Red    | 1            | 2            | R    |
| Green  | 2            | 3            | F    |
| Yellow | 3            | 4            | D    |
| Orange | 4            | 5            | L    |
| Blue   | 5            | 6            | B    |

## Hardware
All parts of Cuber were printed in PLA with standard Cura and supports enabled.

The pinion that grabs the cube and the gear were attached to the shaft via press-fit and super glue. The gear attached directly to the servo was aligned using physical guides in the print and super glued.

The colour sensors are attached to the gearbox via 4-40 bolts hardware. This can be done via super glue as well.

The gearboxes are attached to the main nets via 1/4-20 hardware.

## Electronics
<img src="../journal/image copy 10.png">
Cuber was wired using the following schematic. To prevent larges amounts of current going through the ESP32, you must distribute power directly from the wall. I used wagos to do this, but you can choose a different method. You can view my distribution [here](./Wiring%20Guide.md).

The S0 & S1 pins on the colour sensors are wired to their secondary set of VCC and GND pins. The S2 & S3 connections are distributed from a single ESP32 pin. All other signal wires are point-to-point to the ESP32.

Note that there exists a separate point-to-point connection for the colour sensor on the up face (S2_1, S3_1). This is because I ran out of wagos.

## Software
### Building & Uploading
Clone the repository.
```bash
git clone https://github.com/Zylve/cuber.git
cd cuber
```

Prepare the platformio project
```bash
pio run
```

To upload the code to the ESP32, connect via USB
```bash
pio run -t upload
```

Setup the python environment
```bash
cd ko
python -m venv .
./bin/pip install pyserial # linux/mac
./Scripts/pip install pyserial # windows
```

### Setting up the code.
Set the correct pins in `include/pins.h`.

#### Servo Calibration
Disable the C_MAIN flag, enable the C_SERVO_INPUT flag and set the servo ID in `include/config.h`. Connect via serial monitor and you will be able to prompt the servo to turn between 0 and 180 degrees. In `src/servos.cpp` you will have to set the correct angles.

```cpp
// Servo 1
ServoConfig servo_config_1 = {
    .axis_positions = {
        {2, 42, 78, 117},
        {2, 38, 78, 117},
        {2, 38, 78, 117},
        {2, 38, 72, 117}
    },
    .square_positions = {20, 35, 56, 71, 93, 109, 132, 149},
    .square_ids = {2, 3, 6, 9, 8, 7, 4, 1} // Different because of the net in the algorithm :/
};
```

The `.axis_positions` is the angle each servo needs to drive to to reach a certain position. The array is in the format of `[from][to]`. Setting the values properly will allow for faster turns as the servo will not undershoot due to friction.

The `.square_positions` is the angle each servo needs to drive to for the colour sensor to point towards each square on the cube. To calibrate, test each angle in order from `.axis_positions[0][0]`, and find the angle that causes the servo to stop such that the dark point of the colour sensor tube is in the middle of the square.

`.square_ids` is the ID of the square mapped to the `.square_positions` array. Note that this is different for the first servo because of how the kociemba library takes input.

#### Colour Sensor Calibration
Set the appropriate values in `src/colours.cpp` for each sensor.

```cpp
ColourConfig config_1 = { // White face sensor
    .white = { // White colour
        .red = {0.30, 0.37},
        .green = {0.30, 0.37},
        .blue = {0.30, 0.37}
    },
    .red = { // Red colour
        .red = {0.48, 1.00},
        .green = {0.00, 0.25},
        .blue = {0.00, 0.20}
    },
    // ...

    .colour_map = {
        .red = {2500, 38000},
        .green = {3600, 24000},
        .blue = {3400, 18000}
    }
};
```

You will have to take the raw readings from the sensors via `sensors[i]->get_colour_raw()`. Rotate each colour on the cube through the sensor and mark down the minimum and maximum values for each colour channel. Set these values as your `.colour_map`.

With the `.colour_map` set, take the normalized readings via `sensors[i]->get_colour_normalized()`. Rotate each colour through various positions and set the proper bands for each channel in each colour.

Note that this will take a lot of trial and error. It took me over 20 hours to get it right. It is still not perfect but I am honestly tired of calibrating the sensors.

Reset the flags in `include/config.h` to enable the main program again.

#### Python Solver
Set the correct serial port in `ko/main.py`
```python
esp32 = serial.Serial(port="COM7", baudrate=9600, timeout=0.1)
```

### Usage

#### Solving
Connect Cuber to wall power and connect the ESP32 via USB to your computer. Upload the program with the main flag enabled.

On a system with port access, run the python script
```bash
./bin/python main.py # linux/mac
./Scripts/python main.py # windows
```
Once connected, Cuber will start reading the faces of the cube. Once it is finished, it will prompt you to enter the colours for any squares that it failed to read. It will display the location (U2, R5, etc) and prompt for the colour (U, R, F, D, L, B). Read through the [notes](#notes) and the [Colour Routine](./Colour%20Routine.md) file for information on that.

After all the colours are entered, it will run the kociemba algorithm, will start running the solution while displaying the moves on the serial monitor.

#### Scrambling
Disconnect Cuber from wall power. Manually scramble the cube. Take note that once connected to power the servos will zero to their starting positions.