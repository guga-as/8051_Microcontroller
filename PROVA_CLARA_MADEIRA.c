#include <reg51.h>

void c51_int0 (void);
void c51_int1 (void);


unsigned char state0 = 0;
unsigned char state1 = 0;
sbit P0_7 = P0^7;

void main (void)
{
	unsigned char xdata mensagem[] = "Gustavo Silva";
	unsigned char xdata *ponteiro0;
	//unsigned char chave7_p0;
	unsigned char n;
	unsigned char cont = 0;
	
	EX0 = 1;
	IT0 = 1;
	EX1 = 1;
	IT1 = 1;
	EA = 1;
	
	ponteiro0 = &mensagem[0];
	
	while (1)
	{
		while (state1 != 0x01);
		state1 = 0;
		
		if (P0_7)
		{
			P1 = *(ponteiro0 + n++);
			if (n == 13) n = 0;
		}
		else
		{
			cont += 1;
		}
		
		if (state0 == 0x01)
		{
			state0 = 0;
			P2 = cont;
		}

	}
	
}

void c51_int0 (void) interrupt 0
{
	state0 = ~state0 & 0x01;
}

void c51_int1 (void) interrupt 2
{
	state1 = ~state1 & 0x01;
}