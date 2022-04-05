// Gustavo Anderson Silva - 21103474
// Timer 0 - Modo 1 - 16000 Ciclos de Instrução

#include <reg51.h>

void c51_tmr0m1 (void);

unsigned char state0 = 0x00;
sbit P1_6 = P1^6;

void main (void)
{
	unsigned char numero_rotacoes;
	unsigned char i;
	
	TMOD = 0x01; // 0000 0001B
	TH0 = 0xC1;
	TL0 = 0x80;
	
	ET0 = 1;
	EA = 1;
	TR0 = 1;
	
	P2 = 0x01;
	
	while (1)
	{
		while (state0 != 1);
		state0 = 0;
		
		numero_rotacoes = P1 & 0x0F;
		
		if (P1_6 == 1)
		{
			for (i = 0; i < numero_rotacoes; i++)
			{
				P2 = P2 << 0x01;
				if (P2 == 0x00) P2 = 0x01;
			}
		}
		
		else if (P1_6 == 0)
		{
			P2 = P2;
		}
		
	}
	
}

void c51_tmr0m1 (void) interrupt 1
{
	state0 += 1;
	TH0 = 0xC1;
	TL0 = 0x80;
}