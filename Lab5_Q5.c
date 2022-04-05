#include <reg51.h>

void c51_tmr0m2 (void);
void c51_tmr1m0 (void);

unsigned char state0 = 0x00;
sbit P2_3 = P2^3;

void main (void)
{
	unsigned char code mensagem[] = "Microcontrolador";
	unsigned char code *ponteiro;
	unsigned char n = 0;
	
	ponteiro = &mensagem[0];
	
	TMOD = 0x02;
	TH0 = 0x60;
	TL0 = 0x60;
	TH1 = 0xE2;
	
	ET0 = 1;
	ET1 = 1;
	EA = 1;
	TR0 = 1;
	TR1 = 1;
	
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

void c51_tmr1m0 (void) interrupt 3
{
	P2_3 = 1;
	TH1 = 0xE2;
}