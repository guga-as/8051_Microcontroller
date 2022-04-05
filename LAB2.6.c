#include <reg51.h>

#define CS 0x7F;

sbit chave7_aberta = P2^7;
sbit direcao_rotacao = P2^6;

void main (void)
{
	unsigned char led_aceso = 0xFF;
	unsigned short i, j;
	unsigned char numero_rotacoes;
	
	P0 = CS;
	P1 = led_aceso;
	
	while (1)
	{
		while (chave7_aberta);
		numero_rotacoes = ~P2; // "0" é chave FECHADA, "1" é chave ABERTA.
		numero_rotacoes = numero_rotacoes & 0x0F; // Apenas os 4 bits menos significativos.
		
		if (direcao_rotacao)
		{
			for (i = 0; i < numero_rotacoes; i++)
			{
				led_aceso = (led_aceso << 1) | 0x01;
				if (led_aceso == 0xFF) led_aceso = 0xFE;
				for (j = 0; j < 15000; j++);
				P1 = led_aceso;
			}
		}
		else
		{
			for (i = 0; i < numero_rotacoes; i++)
			{
				led_aceso = (led_aceso >> 1) | 0x80;
				if (led_aceso == 0xFF) led_aceso = 0x7F;
				for (j = 0; j < 15000; j++);
				P1 = led_aceso;
			}
		}
	}
}
