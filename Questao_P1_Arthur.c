#include <reg51.h>

void c51_int0 (void);

unsigned char state0 = 0;

void main (void)
{
	unsigned char vetor_de_dados[10]; 
	unsigned char *ponteiro;
	unsigned char dado_lido;
	unsigned char n;
	unsigned char cont = 0;
	
	EX0 = 1;
	IT0 = 1;
	EA = 1;	
	
	ponteiro = &vetor_de_dados[0];
	
	while (1)
	{
		while (state0 != 1);
		state0 = 0;
		dado_lido = P1;
		
		if (dado_lido <= 0x0A)
		{
			*(ponteiro + n++) = dado_lido;
			cont += 1;
		}
		
		else
		{
			dado_lido -= 5;
		}
				
		P2 = cont;
		
	}
}

void c51_int0 (void) interrupt 0
{
	state0 = ~state0 & 0x01;
}