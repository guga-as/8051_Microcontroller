// Programa que RECEBE palavra de 9 bits pela interface serial
// Gustavo Anderson Silva - 21103474
// Baud Rate: 4800 bits/seg
// Cristal de 11.059 MHz


#include <reg51.h>

void serial (void);

unsigned char stateR = 0x00;

void main (void)
{
	unsigned char data recebidos[8];
	unsigned char data *ponteiro;
	unsigned char n = 0;
	
	
	ponteiro = &recebidos[0];
	
	SCON = 0xD0; // Modo 3 com baud variável - 1101 0000B
	PCON = 0x00; // 0000 0000B
	TMOD |= 0x20; // Timer 1 MODO 2 - 0010 0000B
	TH1 = 0xFA;
	
	ES = 1;
	EA = 1;
	TR1 = 1;
	
	while (1)
	{
		while (stateR != 1);
		stateR = 0;
		ACC = SBUF;
		RB8 = P;
		
		if (RB8 == 0)
		{
			*(ponteiro + n++) = SBUF;
			if (n == 8) n = 0;
		}
		
		else if (RB8 == 1)
		{
			P2 = ACC;
		}
	}
}

void serial (void) interrupt 4
{
	if (RI)
	{
		stateR += 1;
		RI = 0;
	}
}