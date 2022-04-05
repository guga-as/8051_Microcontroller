#include <reg51.h>

#define CS 0x7F;

void c51_int0 (void);

unsigned char state = 0;

void main (void)
{
	unsigned char cont = 0;
	unsigned short i;
	
	P0 = CS;
	
	EX0 = 1;
	IT0 = 1;
	EA = 1;
	
	while (1)
	{
		while (state == 2);
		P1 = cont++;
		for (i = 0; i < 15000; i++);	
	}
}

void c51_int0 (void) interrupt 0
{
	state = ~state & 0x02;
}