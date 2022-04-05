#include <reg51.h>

void serial (void);

unsigned char state0 = 0x00;

void main (void)
{
	unsigned char code mensagem[] = "Microcontrolador";
	unsigned char code *ponteiro;
	unsigned char n = 0;
	
	ponteiro = &mensagem[0];
	
	SCON = 0x40;
	TMOD |= 0x20;
	TH1 = 0xFD;
	
	ES = 1;
	EA = 1;
	TR1 = 1;
	
	SBUF = *ponteiro;
	
	while (1)
	{
		while (state0 != 1);
		state0 = 0;
		SBUF = *(ponteiro + n++);
		if (n == 16) n = 0;
	}
}

void serial (void) interrupt 4
{
	if (TI)
	{
		state0 += 1;
		TI = 0;
	}
}