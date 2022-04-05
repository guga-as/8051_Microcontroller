#include <reg51.h>

void c51_tmr0m1 (void);

unsigned char state0 = 0x00;

void main (void)
{
	unsigned char code mensagem[] = "Microcontrolador";
	unsigned char code *ponteiro;
	unsigned char n = 0;
	
	ponteiro = &mensagem[0];
	
	TMOD = 0x01;
	TH0 = 0xFF;
	TL0 = 0x9C;
	
	ET0 = 1;
	EA = 1;
	TR0 = 1;
	
	while (1)
	{
		while (state0 != 1);
		state0 = 0;
		P1 = *(ponteiro + n++);
		if (n == 16) n = 0;
		
	}
}

void c51_tmr0m1 (void) interrupt 1
{
	state0 += 1;
	TH0 = 0xFF;
	TL0 = 0x9C;
}