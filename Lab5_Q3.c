#include <reg51.h>

void c51_tmr0m2 (void);

unsigned state0 = 0x00;

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
	EA = 1;
	TR0 = 1;
	
	while (1)
	{
		while (state0 != 4);
		state0 = 0;
		P1 = *(ponteiro + n++);
		if (n == 16) n = 0;
	}
	
	
}

void c51_tmr0m2 (void) interrupt 1
{
	state0 += 1;
}