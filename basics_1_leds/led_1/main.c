#include <reg52.h> 

void Delay(unsigned int t)
{
  while(--t);
}

void main (void)
{

while (1)
	{
		P2=0;
		Delay(20000);
		
		P2=0xFF;
		Delay(20000);
  }
}
