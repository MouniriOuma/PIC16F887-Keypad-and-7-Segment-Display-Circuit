// Define the connections for the keypad and 7-segment display
#define ROW_A PORTC.RC3
#define ROW_B PORTC.RC2
#define ROW_C PORTC.RC1
#define ROW_D PORTC.RC0
#define COL_1 PORTC.RC4
#define COL_2 PORTC.RC5
#define COL_3 PORTC.RC6

#define SEGMENT_PORT PORTB

// Define the BCD codes for the 7-segment display
const unsigned short SEGMENT_CODES[] = {
    0b0000, // 0
    0b0001, // 1
    0b0010, // 2
    0b0011, // 3
    0b0100, // 4
    0b0101, // 5
    0b0110, // 6
    0b0111, // 7
    0b1000, // 8
    0b1001, // 9
    0b1010, // E (for '*')
    0b1011  // F (for '#')
};

void main() {
    TRISB = 0x00; // Set PORTB as output for the 7-segment display
    TRISC = 0xF0; // Set PORTC lower nibble as output (rows) and upper nibble as input (columns)

    SEGMENT_PORT = 0x00; // Initialize the 7-segment display to off

    while (1) {
        // Scan each row
        ROW_A = 1; ROW_B = 0; ROW_C = 0; ROW_D = 0;
        if (COL_1) { SEGMENT_PORT = SEGMENT_CODES[1]; } // 1
        if (COL_2) { SEGMENT_PORT = SEGMENT_CODES[2]; } // 2
        if (COL_3) { SEGMENT_PORT = SEGMENT_CODES[3]; } // 3
        Delay_ms(10);

        ROW_A = 0; ROW_B = 1; ROW_C = 0; ROW_D = 0;
        if (COL_1) { SEGMENT_PORT = SEGMENT_CODES[4]; } // 4
        if (COL_2) { SEGMENT_PORT = SEGMENT_CODES[5]; } // 5
        if (COL_3) { SEGMENT_PORT = SEGMENT_CODES[6]; } // 6
        Delay_ms(10);

        ROW_A = 0; ROW_B = 0; ROW_C = 1; ROW_D = 0;
        if (COL_1) { SEGMENT_PORT = SEGMENT_CODES[7]; } // 7
        if (COL_2) { SEGMENT_PORT = SEGMENT_CODES[8]; } // 8
        if (COL_3) { SEGMENT_PORT = SEGMENT_CODES[9]; } // 9
        Delay_ms(10);

        ROW_A = 0; ROW_B = 0; ROW_C = 0; ROW_D = 1;
        if (COL_1) { SEGMENT_PORT = SEGMENT_CODES[10]; } // '*' for E
        if (COL_2) { SEGMENT_PORT = SEGMENT_CODES[0]; }  // 0
        if (COL_3) { SEGMENT_PORT = SEGMENT_CODES[11]; } // '#' for F
        Delay_ms(10);
    }
}