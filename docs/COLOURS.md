```
             |************|
             |*U1**U2**U3*|
             |************|
             |*U4**U5**U6*|
             |************|
             |*U7**U8**U9*|
             |************|
 ************|************|************|************
 *L1**L2**L3*|*F1**F2**F3*|*R1**R2**R3*|*B1**B2**B3*
 ************|************|************|************
 *L4**L5**L6*|*F4**F5**F6*|*R4**R5**R6*|*B4**B5**B6*
 ************|************|************|************
 *L7**L8**L9*|*F7**F8**F9*|*R7**R8**R9*|*B7**B8**B9*
 ************|************|************|************
             |************|
             |*D1**D2**D3*|
             |************|
             |*D4**D5**D6*|
             |************|
             |*D7**D8**D9*|
             |************|

UUUUUUUUURRRRRRRRRFFFFFFFFFDDDDDDDDDLLLLLLLLLBBBBBBBBB
```


Wiring & Code IDs:
- White: 0 (1)
- Red: 1 (2)
- Green: 2 (3)
- Yellow: 3 (4)
- Orange: 4 (5)
- Blue: 5 (6)

- U: Up
- R: Right
- F: Front
- D: Down
- L: Left
- B: Back

Actual Positions:
- U: White
- R: Red
- F: Green
- D: Yellow
- L: Orange
- B: Blue

Will Sense Colours in the order of:
- U & D
- R & L
- F & B

U: 2, 3, 6, 9, 8, 7, 4, 1 (why did i design this shit reversed!? [it's not actually my fault its just the way this algorithm does the net])
D: 8, 7, 4, 1, 2, 3, 6, 9

R: 8, 7, 4, 1, 2, 3, 6, 9
L: 8, 7, 4, 1, 2, 3, 6, 9

F: 8, 7, 4, 1, 2, 3, 6, 9
B: 8, 7, 4, 1, 2, 3, 6, 9