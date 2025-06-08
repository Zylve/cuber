---
title: "Cuber"
author: "Vuk"
description: "An automatic Rubik's Cube solver"
created_at: "2024-05-17"
---

# May 15th: Started work!
Cooked up my idea and started researching the parts lying around in my kit and the school shop.

### Time today: 1 hour
### Time total: 1 hour

# May 17th:
Okay so basically I set up the platformio dev environment and got my esp32 driving an MG996R stepper motor.


https://github.com/user-attachments/assets/8cf88195-3297-4feb-9b49-cdf6550582a8

I've been wanting to create something like this for a while and I bought these components several months ago but never got around to seriously starting work on it. (And now it looks like Purdue beat me to it lol.)

Anyway I think the best way to properly begin this is to setup some goals for ***Cuber:***
- Create an automatic motorized Rubik's Cube solver.
- Have it automatically detect the initial state of the cube using colour sensors.
- Implement an algorithm like *Kociemba's* to solve the cube.
- Have an automatic scrambler to allow continuous action.
- 3D print a custom case to house components, that allows for easy access to the cube.

Wow that is a lot of goals haha.

To keep the kinematics of the cube simple, I will use a similar approach to the students at Purdue and MIT: 6 motors, one for each face of the  (no full cube rotations). To allow for access to the cube, I will allow the housing for each motor to swing out like a flower, letting me swap the cube in and out.

<img src="journal/kin.png" alt="alt text" height="360">

I got 6 TCS3200 colour sensors from my school, and the idea is that one could cover each face of the cube on the corner, and rotate the face at 30° intervals to detect all 12 stickers.

<img src="journal/colour.png" alt="alt text" height="360">

I then imported the MG996R into Fusion 360 and designed a pinion for the Rubiks cube. It will drive the cube sides by slotting into the middle piece. This is when I realized that the motor spline is to small for my 3D printer to print. Instead, I will use the injection molded pinion that came with the motors, and probably superglue the pinion to it or smt idk.

<p float="left">
    <img src="journal/2025-05-17_15-39-21.png" alt="alt text" height="360">
    <img src="journal/20250517_153258.jpg" alt="alt text" height="360">
    <img src="journal/20250517_153304.jpg" alt="alt text" height="360">
</p>

### Time today: 4 hours
### Time total: 5 hours

# May 19th:
Spent like 30 minutes today trying to make PlatformIO actually useable.

I played with my prototype pinion a bit and learned that I need to apply a ton of normal force to allow the sides to rotate.

###### No force (top) vs. force (bottom)
https://github.com/user-attachments/assets/cadc4695-f0eb-4065-a3e3-c17ea3f0df7f

https://github.com/user-attachments/assets/0a5ce550-07eb-4adf-b740-79804e6239e9

I will need to loosen my cube a lot for this, but not so much that it explodes in your face. Lubricant is also needed, I don't know what type to use though. I can buy some specialized stuff from SpeedCubeShop or just douse the cube in some machine oil from my school's shop lol.

I haven't had a lot of time these past couple days but hopefully I will have some more soon!

### Time today: 1 hour
### Time total: 6 hours


# May 23rd:
Finally got some spare time! Jumped into Fusion today and designed a prototype gearbox for the motor & pinion.

Because the version of the MG996R I have has only 180° of rotation, I need to make a step up to allow for full range of motion. I went with a 1:2.5 gear ratio via a 30T pinion and a 12T gear. Not gonna lie the MG996R has a ton of torque—I did the math from the specsheet and I could go up to like 1:8 or something.

Anyway, the 1:2.5 ratio works as all of the angles I need are whole numbers.

<!-- Image.png -->
<img src="journal/image.png" alt="alt text" height="360">

I'll be able to 3D print this over the weekend and test it out. If it works, I'll be able to attach 6 of these together to create a full robot. I'm still thinking about how to get the cube in and out though. The flower idea I mentioned early is probably too complex. I'll maybe make the top motor attached via a bolt that you can screw in and out. 

But now that we know we need a large normal force, we may have difficulty getting the cube in and out. When I have time I'll fiddle around with my pinion and see how much play there is and if it would be possible to twist the cube out. Otherwise we may need multiple motors to be unscrewable.

### Time today: 2 hours
### Time total: 8 hours

# May 24th & 25th:
Printed the gearbox. Turns out I suck at superglueing stuff together. Note to future self: sand the prints before gluing lmao.

Got it rotating and stuff. But I'm browning out the ESP32 on just a single stepper motor. Tomorrow I'll be able to take it to school and test it with an actual power supply.

https://github.com/user-attachments/assets/a11832de-1fdf-4844-b957-5d1f5c20488e

### Time this weekend: 4 hours
### Time total: 12 hours


# May 30th

So whats up. I tested the jig with a power supply and theres a couple things I learned:
- I need to make it stiffer so that the gears dont twist out.
- I suck at estimating tolerances.

For most of my testing time, the pieces of the cube were catching on each other, so I had to tighten the cube faces down. It was able to rotate the sides of the cube, but it was quite innacurate due to how much tolerance there was in the pinion and the gears.

I originally created a glue down cover for the pinion to rotate in, but my friend suggested that I make the shaft slide in and have the pinion be press fit.

### Time today: 1 hour
### Time total: 13 hours

# May 31st

Printed some tolerance tests.
- Print in place: 0.5mm
- Print out of place: 0.5mm
- Press fit: 0.3mm

Also designed a new pinion to better fit the cube. Reduced the tolerance between the pinion and the walls of the piece, and made it wrap around the corners. Not sure if the corner pieces actually do anything but maybe it increases the torque lever arm 🤷‍♂️.

<img src="journal/2025-05-31_22-02-01.png" alt="alt text" height="360">

### Time today: 3 hours
### Time total: 16 hours

# June 1st
Printed out the new gearbox and assembled it together. I need to update it a little as its too close to the face of the cube and the other sides of the cube can't actually rotate lol.

### Time today: 2 hours
### Time total: 18 hours

# June 2nd
Brought it to school and tested it out. Works much better with a lot more backlash. I can still reduce the last bit of it by adding a shaft to the pinion gear, keeping it from rocking side to side. Other than that, its pretty sweet. Something I've noticed is that for some reason the motor isn't linear. 0-90 is the same as 90-180, but 180-270 is much smaller. All stuff that can be changed in software.

https://github.com/user-attachments/assets/d39e9d64-2d36-401b-b0da-273edd4b6365

Hopefully v3 will be the final version of the gearbox. Once I confirm that works then I can start cadding the full assembly.

### Time today: 2 hours
### Time total: 20 hours

# June 6th
Spliced this power supply to power my esp32 and motors. It's 5V 10A, and each motor draws 2A maximum. Hooked it up and it works! I also looked into the specs of the jumper wires I was using and i could power up to 2 motors at a time. (22 AWG, 4A).

<img src="journal/image (1).png" alt="alt text" height="360">

### Time today: 1 hour
### Time total: 21 hours
