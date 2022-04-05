#include <reg51.h>

void serial (void);

unsigned char state0 = 0x00;

void main (void)
{
	unsigned char code mensagem[] = "Microcontrolador";
	unsigned char code *ponteiro;
	unsigned char n = 1;
	
	ponteiro = &mensagem[0];
	
	SCON = 0xC0; // 1100 0000B
	TMOD |= 0x20; // 0010 0000B
	TH1 = 0xFD;
	
	ES = 1;
	EA = 1;
	TR1 = 1;
	
	ACC = *ponteiro;
	TB8 = P;
	SBUF = ACC;
	
	while (1)
	{
		while (state0 != 1);
		state0 = 0;
		ACC = *(ponteiro + n++);
		TB8 = P;
		SBUF = ACC;
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