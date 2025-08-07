# Wiring Guide
(This is currently just a reference for myself so if it doesn't make sense, that's okay.)

Colours:
- White: 0 (1)
- Red: 1 (2)
- Green: 2 (3)
- Yellow: 3 (4)
- Orange: 4 (5)
- Blue: 5 (6)

Other:
- 5V: V
- GND: G
- Servo: M
- Colour Sensor: C
- Signal: S# (S0, S1, ...)

5V:
- ESP32
- V0-0,2 (White & Green):
    - V0-0:
        - V0-0M
        - V0-0C
    - V0-2:
        - V0-2M
        - V0-2C
- V1-1,3 (Red & Blue):
    - V1-1:
        - V1-1M
        - V1-1C
    - V1-3:
        - V1-3M
        - V1-3C
- V2-4,5 (Orange & Yellow):
    - V2-4:
        - V2-4M
        - V2-4C
    - V2-5:
        - V2-5M
        - V2-5C

GND:
- ESP32
- G0-0,2 (White & Green):
    - G0-0:
        - G0-0M
        - G0-0C
    - G0-2:
        - G0-2M
        - G0-2C
- G1-1,3 (Red & Blue):
    - G1-1:
        - G1-1M
        - G1-1C
    - G1-3:
        - G1-3M
        - G1-3C
- G2-4,5 (Orange & Yellow):
    - G2-4:
        - G2-4M
        - G2-4C
    - G2-5:
        - G2-5M
        - G2-5C

Signal:
- Signal has no specific routings so we don't care about differentiating each wire.