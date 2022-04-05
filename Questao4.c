#include <reg51.h>

#define CS 0x7F;

void c51_int0 (void);

unsigned char state = 0;

void main (void)
{
	unsigned char code mensagem[] = "Microcontrolador";
	unsigned char code *ponteiro;
	unsigned char i = 0;
	
	P0 = CS;
	ponteiro = &mensagem[0];
	
	EX0 = 1;
	IT0 = 1;
	EA = 1;
	
	while (1)
	{
		while (state != 1);
		state = 0;
		P1 = *(ponteiro + i++);
		if (i == 16) i = 0;
	}
	
}
	
void c51_int0 (void) interrupt 0
{
	state = 0x01;
}