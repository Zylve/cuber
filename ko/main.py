import time
import kociemba
import serial

esp32 = serial.Serial(port="COM7", baudrate=9600, timeout=0.1)

while True:
    data = esp32.readline()
    if not data:
        continue
    
    line = data.decode('utf-8', errors="ignore").strip()
    
    if line == "esp32_connect":
        esp32.write(b"pc_connect\n")
        esp32.write(b"connected\n")
        print("connected")
        break

time.sleep(1)

# U = White
# R = Red
# F = Green
# D = Yellow
# L = Orange
# B = Blue

state = ""

while True:
    data = esp32.readline()
    if not data:
        continue
    line = data.decode('utf-8', errors="ignore").strip()
    if line.startswith("state:"):
        print(line)
        state = line[6:]
        state = state.replace(" ", "")
        print("Parsed state:", state)
        break
    if line.startswith("r:"):
        print(line)


# For every "E" in the state, ask for user input
while 'E' in state:
    index = state.index('E')
    # find the position in terms of face and sticker
    faceid = index // 9
    sticker = index % 9
    faces = ["U", "R", "F", "D", "L", "B"]
    face = faces[faceid]
    position = sticker + 1
    user_input = input(f"Colour for {face}{position}: (U, R, F, D, L, B)").strip().upper()
    # replace E
    state = state[:index] + user_input + state[index+1:]

solution = kociemba.solve(state)

message = "solu:" + solution + "\n"
print("Sending solution:", message.strip())

esp32.write(message.encode())

while True:
    response = esp32.readline()
    if response:
        print("ESP32:", response.decode('utf-8', errors='ignore').strip())
        if response.decode('utf-8', errors='ignore').strip() == "esp32_finish":
            esp32.write(b"pc_finish\n")
            break
    else:
        time.sleep(0.1)