#include <reg51.h>

void c51_tmr0m2 (void);
void c51_int1 (void);

unsigned char state0 = 0x00;
unsigned char lido;

void main (void)
{
	unsigned char code mensagem[] = "Microcontrolador";
	unsigned char code *ponteiro;
	unsigned char n = 0;
	
	ponteiro = &mensagem[0];
	
	TMOD = 0x02;
	TH0 = 0x60;
	TL0 = 0x60;
	
	ET0 = 1;
	EX1 = 1;
	IT1 = 1;
	EA = 1;
	TR0 = 1;
	
	while (1)
	{
		while (state0 != 1);
		state0 = 0;
		P1 = *(ponteiro + n++);
		if (state0 == 16) state0 = 0;
	}
	
}

void c51_tmr0m2 (void) interrupt 1
{
	state0 += 1;
}

void c51_int1 (void) interrupt 2
{
	lido = P2;
	TH0 = lido;
}