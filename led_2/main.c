#include <reg52.h>
#include "support.h"  // Declaration of Setup function

#define DELAY_VALUE 50000  // Set delay value once as a constant

void setup() {
	// Nothing is here for now
}

void loop() {
	P2 = 0x01;  // Set first LED to glow up
	
	while (P2) {  // While P2 != 0
		Delay(DELAY_VALUE);
		
		P2 <<= 1;  // Shift right on one bit
	}
}

void main() {
	setup();  // Call setup function on start
	
	while (1) {  // Forever
		loop();  // ... execute loop body in 'loop' function
	}
}