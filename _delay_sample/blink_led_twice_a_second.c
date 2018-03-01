#include <reg52.h>

sbit Led = P1^3;

void Delay(unsigned int t);

void main (void)
{
while (1)
	{ // blinking every second
		Led = 0;
		Delay(62500);   //  2 * 0xFFFF ==   1s 50ms
		//Delay(62500); //  2 *  62000 == ~ 1s (slightly less than a second)
		Led = 1;        //  2 *  62500 ==   1s
		//Delay(62500);
		Delay(62500);
 	}
}

void Delay (unsigned int t)
{
	// 8 asm instructions
	/*
	C:0x0816    EF       MOV      A,R7
	C:0x0817    1F       DEC      R7
	C:0x0818    7001     JNZ      C:081B
	C:0x081A    1E       DEC      R6
	C:0x081B    14       DEC      A
	C:0x081C    4E       ORL      A,R6
	C:0x081D    70F7     JNZ      Delay(C:0816)
	*/
	
	while(--t); // 8 instructions * 1 us/instuction = 8 us
	
	// 1 000 000 us = 1 s <=> 125 000 of delay cycles
	
}
