#include <reg51.h>

#define CS 0x7F;

void c51_int1 (void);

unsigned char state1 = 0;
sbit direcao_rotacao = P2^0;

void main (void)
{
	unsigned char led_aceso = 0xFE;
	unsigned char numero_rotacoes, direcao_rotacao;
	unsigned short i, j;
	
	P0 = CS;
	
	EX1 = 1;
	IT1 = 1;
	EA = 1;
	
	P1 = led_aceso;
	
	while (1)
	{
		while (state1 != 1);
		direcao_rotacao = P2 & 0x01; 
		state1 = 0;
		while (state1 != 1);
		numero_rotacoes = P2;
		
		
		if (direcao_rotacao)
		{
			for (i = 0; i < numero_rotacoes; i++)
			{
				led_aceso = (led_aceso >> 1) | 0x80;
				for (j = 0; j < 15000; j++);
				if (led_aceso == 0xFF) led_aceso = 0x7F;
				P1 = led_aceso;
			}
		}
		else
		{
			for (i = 0; i < numero_rotacoes; i++)
			{
				led_aceso = (led_aceso << 1) | 0x01;
				for (j = 0; j < 15000; j++);
				if (led_aceso == 0x7F) led_aceso = 0xFE;
				P1 = led_aceso;
			}
		}
		
		state1 = 0;
	}
}	

void c51_int1 (void) interrupt 2
{
	state1 = 1;
}