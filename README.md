# PIC16F887 Keypad and 7-Segment Display Circuit

This project demonstrates how to interface a keypad and a 7-segment display with a PIC16F887 microcontroller. The circuit is designed using Proteus ISIS, and the code is written in mikroC.

## Project Overview

The circuit allows you to:
- Press keys `0-9` to display the corresponding digit on the 7-segment display.
- Press `*` to display the letter `E`.
- Press `#` to display the letter `F`.

### Components Used
- **Microcontroller**: PIC16F887
- **Display**: 7-segment display (common cathode)
- **Keypad**: 4x3 matrix keypad
- **Decoder**: BCD to 7-segment decoder (if applicable)
- **Software**: Proteus ISIS for simulation, mikroC for programming

---

## Repository Structure

The repository contains the following files:
1. **Circuit Diagram**: `screen/7_seg_&_keypad.png`  
   - A visual representation of the circuit designed in Proteus ISIS.
2. **Proteus Project File**: `circuit.pdsprj`  
   - The Proteus ISIS project file for simulating the circuit.
3. **mikroC Code**: `keypad_7segment.c`  
   - The mikroC source code for the PIC16F887 microcontroller.

---

## Circuit Description

### Keypad Connections
- **Rows**: Connected to `PORTC` (RC0, RC1, RC2, RC3)
- **Columns**: Connected to `PORTC` (RC4, RC5, RC6)

### 7-Segment Display Connections
- **BCD Input**: Connected to `PORTB` (RB0, RB1, RB2, RB3)
- **Decoder**: The decoder is connected between the microcontroller and the 7-segment display.

---

## How to Use

### Simulation in Proteus ISIS
1. Open the `circuit.pdsprj` file in Proteus ISIS.
2. Load the `keypad_7segment.hex` file into the PIC16F887 microcontroller.
3. Run the simulation and interact with the keypad to see the output on the 7-segment display.

### Programming the PIC16F887
1. Open the `keypad_7segment.c` file in mikroC.
2. Compile the code to generate the `.hex` file.
3. Program the PIC16F887 microcontroller using a compatible programmer (e.g., PICkit).

