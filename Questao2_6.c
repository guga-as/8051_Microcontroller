#include <reg51.h>

#define CS 0x7F;

sbit chave7_aberta = P2^7;
sbit direcao_rotacao = P2^6;

void main (void)
{
	unsigned char led_aceso = 0xF7;
	unsigned char numero_rotacoes;
	unsigned short i, j;
	
	P0 = CS;
	P1 = led_aceso;
	
	while (1)
	{
		while (chave7_aberta);
		
		numero_rotacoes = ~P2;
		numero_rotacoes = numero_rotacoes & 0x0F;
		
		if (direcao_rotacao)
		{ for (i = 0; i < numero_rotacoes; i++)
			{
				led_aceso = (led_aceso << 1) | 0x01;
				for (j = 0; j < 15000; j++);
				if (led_aceso == 0xFF) led_aceso = 0xFE;
			}	
		}
		else
		{ for (i = 0; i < numero_rotacoes; i++)
			{
				led_aceso = (led_aceso >> 1) | 0x80;
				for (j = 0; j < 15000; j++);
				if (led_aceso == 0xFE) led_aceso = 0x7F;
			}
		}
		
		P1 = led_aceso;
		
		while (~chave7_aberta);
	}
}