#include <reg51.h>

#define CS 0x7F;

void c51_int0 (void);
void c51_int1 (void);

unsigned char state0 = 0;
unsigned char state1 = 0;

void main (void)
{
	unsigned char code mensagem[] = "Microcontrolador";
	unsigned char code *ponteiro0;
	unsigned char recebido[8];
	unsigned char *ponteiro1;
	unsigned char n0 = 0;
	unsigned char n1 = 0;
	
	P0 = CS;
	
	ponteiro0 = &mensagem[0];
	ponteiro1 = &recebido[0];
	
	EX0 = 1;
	IT0 = 1;
	EX1 = 1;
	IT1 = 1;
	EA = 1;
	
	while (1)
	{
		if (state0 == 0x01)
		{
			state0 = 0;
			P1 = *(ponteiro0 + n0++);
			if (n0 == 16) n0 = 0;
		}
		
		if (state1 == 0x01)
		{
			state1 = 0;
			*(ponteiro1 + n1++) = P1;
			if (n1 == 8) n1 = 0;
		}	
	}
}

void c51_int0 (void) interrupt 0
{
	state0 = ~state0 & 0x01;
}

void c51_int1 (void) interrupt 2
{
	state1 = ~state1 & 0x01;
}