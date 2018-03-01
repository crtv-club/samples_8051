#include <reg52.h>
#include "support.h"

#define SEGMENTS P2
#define POSITIONS P1

// Just light everything up

void setup() {
	SEGMENTS = 0xFF;
	POSITIONS = 0x00;
}

void loop() {
	// Nothing is here yet
}

void main() {
	setup();
	
	while (1) {
		loop();
	}
}