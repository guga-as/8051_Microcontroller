// Palavra de 9 bits RECEBIDA pela interface serial - MODO 3 ASSÍNCRONO
// Gustavo Anderson Silva - 21103474
// Cristal à 11.059 MHz - 1200 bits/seg

#include <reg51.h>

void serial (void);

unsigned char stateR = 0x00;

void main (void)
{
	unsigned char xdata recebido[8];
	unsigned char xdata *ponteiro;
	unsigned char n = 0;
	
	ponteiro = &recebido[0];
	
	SCON = 0xD0; // 1101 0000B
	TMOD |= 0x20; // 0010 0000B
	TH1 = 0xE8;

	ES = 1;
	EA = 1;
	TR1 = 1;
	
	while (1)
	{
		while (stateR != 1);
		stateR = 0;
		ACC = SBUF;
		RB8 = P;
		
		if (RB8)
		{
			*(ponteiro + n++) = SBUF;
			if (n == 8) n = 0;
		}
		
		else if (RB8 == 0)
		{
			P1 = ACC;
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