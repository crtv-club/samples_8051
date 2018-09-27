#include <reg52.h>
#include "support.h"

#define SEGMENTS P2
#define POSITIONS P1

// FIXME

#define SEG_A  0x20  // 0b0010 0000
#define SEG_B  0x80  // 0b1000 0000
#define SEG_C  0x08  // 0b0000 1000
#define SEG_D  0x02  // 0b0000 0010
#define SEG_E  0x01  // 0b0000 0001
#define SEG_F  0x40  // 0b0100 0000
#define SEG_G  0x10  // 0b0001 0000
#define SEG_DP 0x04  // 0b0000 0100

const unsigned short NUMBER_CODES[] = {
	SEG_A | SEG_B | SEG_C | SEG_D | SEG_E | SEG_F,  // 0
	SEG_B | SEG_C,  // 1
	SEG_A | SEG_B | SEG_G | SEG_E | SEG_D,  // 2
	SEG_A | SEG_B | SEG_G | SEG_C | SEG_D,  // 3
	SEG_F | SEG_G | SEG_B | SEG_C,  // 4
	SEG_A | SEG_F | SEG_G | SEG_C | SEG_D,  // 5
	SEG_A | SEG_F | SEG_G | SEG_E | SEG_D | SEG_C,  // 6
	SEG_A | SEG_B | SEG_C,  // 7
	0xFF & ~(SEG_DP),  // 8
	SEG_A | SEG_F | SEG_G | SEG_B | SEG_C | SEG_D  // 9
};

#define DELAY_VALUE 50000  // Set delay value once as a constant

void setup() {
	SEGMENTS = 0xFF;
	POSITIONS = 0x00;
}

void loop() {
	short int i;
	
	for (i = 0; i < 10; i++) {
		SEGMENTS = NUMBER_CODES[i];
		Delay(DELAY_VALUE);
	}
}

void main() {
	setup();
	
	while (1) {
		loop();
	}
}