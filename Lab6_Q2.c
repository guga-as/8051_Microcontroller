#include <reg51.h>

void serial (void);

//unsigned char state0 = 0x00;
unsigned char stateR = 0x00;

void main (void)
{
	//unsigned char code mensagem[] = "Microcontrolador";
	//unsigned char code *ponteiro;
	unsigned char data recebido[5];
	unsigned char data *ponteiro2;
	//unsigned char n = 0;
	unsigned char n2 = 0;
	
	ponteiro2 = &recebido[0];
	
	SCON = 0x50; // 0101 0000B
	TMOD |= 0x20; // 0010 0000B
	TH1 = 0xFD;
	
	ES = 1;
	EA = 1;
	TR1 = 1;
	
	*ponteiro2 = SBUF;
	
	while (1)
	{
		while (stateR != 1);
		stateR = 0;
		*(ponteiro2 + n2++) = SBUF;
		if (n2 == 5) n2 = 0;
	}
	
}

void serial (void) interrupt 4
{
	if (TI)
	{
		//state0 += 1;
		TI = 0;
	}
	else if (RI)
	{
		stateR += 1;
		RI = 0;
	}
}