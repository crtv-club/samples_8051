#include <reg52.h>
#include "support.h"  // Declaration of Setup function

#define DELAY_VALUE 5000  // Set delay value once as a constant

/*
	Version with dot moving backward and forward
	with a slight delay between changing of direction.
	And at the same time the dot will speed up.
*/

// Yes, it's a global variable. They are OK for
// embedded projects. Almost OK
unsigned int current_delay;

void setup() {
	current_delay = DELAY_VALUE;  // Initialize current_delay variable
}

void feed_forward() {
	P2 = 0x01;  // Set first LED to glow up
	
	while (P2) {  // While P2 != 0
		Delay(current_delay);
		current_delay -= 10; //  decrement current delay on each iteration
		
		P2 <<= 1;  // Shift right on one bit
	}
}

void feed_backward() {
	P2 = 0x80;  // Set the last LED to glow up, 0b1000 0000 <-> 0x80
	// P2 = 0xA0;  // Gives a fun result with two moving dots
	
	while (P2) {  // While P2 != 0
		Delay(current_delay);
		current_delay -= 10; //  decrement current delay on each iteration
		
		P2 >>= 1;  // Shift left on one bit
	}
}

void loop() {
	feed_forward();
	feed_backward();
}

void main() {
	setup();  // Call setup function on start
	
	while (1) {  // Forever
		loop();  // ... execute loop body in 'loop' function
	}
}