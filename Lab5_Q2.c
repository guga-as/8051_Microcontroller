#include <reg51.h>

void c51_tmr1m0 (void);

unsigned char state0 = 0x00;

void main (void)
{
	unsigned char code mensagem[] = "Microcontrolador";
	unsigned char code *ponteiro;
	unsigned char n = 0;
	
	ponteiro = &mensagem[0];
	
	TMOD = 0x00;
	TH1 = 0xEC;
	TL1 = 0x00;
	
	ET1 = 1;
	EA = 1;
	TR1 = 1;
	
	while (1)
	{
		while (state0 != 1);
		state0 = 0;
		P1 = *(ponteiro + n++);
		if (state0 == 16) state0 = 0;
	}
	
}

void c51_tmr1m0 (void) interrupt 3
{
	state0 += 1;
	TH1 = 0xEC;
	TL1 = 0x00;
}