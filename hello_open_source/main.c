#include <8052.h>

void delay(unsigned int t) {
   while (t--);
}

void main(void) {
   while (1) {
       P0 = 0xFF;
       delay(10000);
       P0 = 0x00;
       delay(10000);
   }
}