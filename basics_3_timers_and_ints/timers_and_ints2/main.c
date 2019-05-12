#include <reg52.h>

#define TICKS 50000
#define PRESCALER 10

const unsigned int PRELOAD = 65536 - TICKS;

void enable_interrupts();
void setup_timer();
void start_timer();
void stop_timer();
void delay(int t);

void handle_t0_int() interrupt 1 {
	// counter of overflows, used for prescaling
	static unsigned char of_counter = 0;
	
	// timer is still counting!!!!
	
	// if you need to start over...
	// stop timer
	stop_timer();
	
	// set reload value
	TL0 = PRELOAD;  // write low 8 bits and strip the rest
	TH0 = PRELOAD >> 8;  // write hight 8 bits
	
	// resume timer
	start_timer();
	
	of_counter += 1;
	
	if (of_counter >= PRESCALER) {
		P1 = ~P1;
		of_counter = 0;
	}
}

void main() {
	unsigned char buf;
	
	// setup block
	setup_timer();
	enable_interrupts();
	start_timer();
	
	// to light up digits on 7-segment display
	// in the used connection, is not so relevant for this project
	P0 = 0x00;

	while(1) {
		// do some work as usual...
		// or do nothing (empty loop)
		/*
		for(buf = 0x01; buf <= 0x08; buf <<= 1) {
			P0 = buf;
			delay(62500);
		}
		*/
	}
}

void enable_interrupts() {
	ET0 = 1;  // unmask timer 0's interrupt
	EA = 1;  // globally enable interrupts
}

void start_timer() {
	TR0 = 1;
}

void stop_timer() {
	TR0 = 0;
}

void setup_timer() {
	// setup parameters for TIMER0
	// don't touch parameters for TIMER1, disable gating,
	// count internal clock pulses, configure as 16-bit timer
  // (timer mode 1)
	
	// GATE1, C/T1#, M11, M01, GATE0, C/T0#, M10, M00
	//  DNT ,  DNT , DNT, DNT,   0  ,   0  ,  0 ,  1
	// "DNT" means "Do Not Touch" here
	TMOD = (TMOD & 0xF0) | (0x01);
}


void delay(int t) {
	while(t--);
}
