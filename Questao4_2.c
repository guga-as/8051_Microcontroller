#include <reg51.h>

#define CS 0x7F;

void c51_int0 (void);
void c51_int1 (void);

unsigned char state0 = 0;
unsigned char state1 = 0;

void main(void)
{
	unsigned char code mensagem[] = "Microcontrolador";
	unsigned char *ponteiro;
	unsigned char n = 0;
	unsigned short i;
	
	P0 = CS;
	
	EX0 = 1;
	IT0 = 1;
	EX1 = 1; 
	IT1 = 1;
	
	EA = 1;
	
	ponteiro = &mensagem[0];
	
	while (1)
	{
		while (state0 != 1);
		state0 = 0;
		P1 = *(ponteiro + n++);
		for (i = 0; i < 15000; i++);
		if (n == 16) n = 0;
		
	}
}

void c51_int0 (void) interrupt 0
{
	state0 = 1;
}

void c51_int1 (void) interrupt 2
{
	EX0 = ~EX0;
	IE0 = 0;
}