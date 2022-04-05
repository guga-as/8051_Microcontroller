// Gustavo Anderson Silva - 21103474
// Timer0 - Modo 1 - Ciclos de Instrução: 16000

#include <reg51.h>

void c51_tmr0m1 (void);

unsigned char state0 = 0x00;

void main (void)
{
	unsigned char xdata vetor[] = "Gustavo";
	unsigned char xdata *ponteiro1;
	unsigned char data recebido[7];
	unsigned char data *ponteiro2;
	unsigned char n1 = 0;
	unsigned char n2 = 0;
	unsigned cont = 0;
	
	ponteiro1 = &vetor[0];
	ponteiro2 = &recebido[0];
	
	TMOD = 0x01; // 0000 0001B
	TH0 = 0xC1;
	TL0 = 0x80;
	
	ET0 = 1;
	EA = 1;
	TR0 = 1;
	
	P2 = 0x00;
	
	while (1)
	{
		while (state0 != 1);
		state0 = 0;
		*(ponteiro2 + n2++) = *(ponteiro1 + n1++);
		if (n1 == 6) n1 = 0;
		if (n2 == 6)
		{
			cont++;
			P2 = cont;
			n2 = 0;
		}
	}
	
	
}


void c51_tmr0m1 (void) interrupt 1
{
	state0 += 1;
	TH0 = 0xC1;
	TL0 = 0x80;
}