/* RECEBA palavra de 9 bits (8 bits  + bits de paridade) c/ baud rate variável, interrupção serial */
// Gustavo Anderson Silva - 21103474
// Cristal de 11.059 MHz e baud rate de 1200 bits/seg - Timer1 - Modo 3

#include <reg51.h>

void serial (void);

unsigned char stateR = 0x00;

void main (void)
{
	unsigned char xdata recebidos[8];
	unsigned char xdata *ponteiro;
	unsigned char n = 0;
	
	
	ponteiro = &recebidos[0];
	
	SCON = 0xD0; // 1101 0000B
	PCON = 0x00; // 0000 0000B -> SMOD = 0
	TMOD |= 0x20; // 0010 0000B
	TH1 = 0xE8;
	
	ES = 1;
	EA = 1;
	TR1 = 1;
	
	P1 = 0x00; // 1111 1111 - 0000 0000b
	
	while (1)
	{
		while (stateR != 1); 
		stateR = 0;
		ACC = SBUF;
		RB8 = P;
		
		if (RB8 == 1)
		{
			*(ponteiro + n++) = SBUF; 
			if (n == 8) n = 0; 
		}
		
		else if (RB8 == 0)
		{
			P1 = SBUF;
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