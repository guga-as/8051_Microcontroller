#include <reg51.h>

#define CS 0x7F;

void c51_int1 (void);

sbit direcao_rotacao = P2^6; // Pino 6 da P2 é declarado como bit de rotação: "0" p/ esquerda, "1" p/ direita.
unsigned char state1 = 0;

void main (void)
{
	unsigned char led_aceso = 0xFF;
	unsigned char direcao_rotacao;
	unsigned char numero_rotacoes = 0x00; 
	unsigned short i, j;
	
	EX1 = 1;
	IT1 = 1;
	EA = 1;
	
	P0 = CS;
	P1 = led_aceso;
	
	while (1)
	{
		while (state1 != 1);
		state1 = 0;
		direcao_rotacao = ~P2 & 0x40;
		while (state1 != 1);
		state1 = 0;
		numero_rotacoes = ~P2;
		
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
				if (led_aceso == 0xFF) led_aceso = 0xFE;
				P1 = led_aceso;
			}
		}
	}
}

void c51_int1 (void) interrupt 2
{
	state1 = ~state1 & 0x01;
}