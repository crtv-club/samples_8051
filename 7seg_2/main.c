#include <reg52.h>
#include "support.h"

#define SEGMENTS P2
#define POSITIONS P1

// Just light every segment one by one

#define DELAY_VALUE 50000  // Set delay value once as a constant

void setup() {
	SEGMENTS = 0xFF;
	POSITIONS = 0x00;
}

void loop() {
	SEGMENTS = 0x01;  // Set first LED to glow up
	
	while (SEGMENTS) {  // While P2 != 0
		Delay(DELAY_VALUE);
		
		SEGMENTS <<= 1;  // Shift right on one bit
	}
}

void main() {
	setup();
	
	while (1) {
		loop();
	}
}