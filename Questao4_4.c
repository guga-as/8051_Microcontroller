#include <reg51.h>

#define CS 0x7F;

void c51_int0 (void);
void c51_int1 (void);

unsigned char state0 = 0;
unsigned char rotacao_esquerda = 0x01;

void main (void)
{
	unsigned char led_aceso = 0xFF;
	unsigned short i;
	
	EX0 = 1;
	IT0 = 1;
	EX1 = 1;
	IT1 = 1;
	EA = 1;
	
	P0 = CS;
	
	while (1)
	{
		if ((state0 == 0x01) && (rotacao_esquerda == 0x01))
		{
			state0 = 0x00;
			led_aceso = (led_aceso << 1) | 0x01;
			for (i = 0; i < 15000; i++);
			if (led_aceso == 0xFF) led_aceso = 0xFE;
			P1 = led_aceso;
		}
		else if ((state0 == 0x01) && (rotacao_esquerda == 0x00))
		{
			state0 = 0x00;
			led_aceso = (led_aceso >> 1) | 0x80;
			for (i = 0; i < 15000; i++);
			if (led_aceso == 0xFF) led_aceso = 0x7F;
			P1 = led_aceso;
		}
	}
}



void c51_int0 (void) interrupt 0
{
	state0 = ~state0 & 0x01;
}

void c51_int1 (void) interrupt 2
{
	rotacao_esquerda = ~rotacao_esquerda & 0x01;
}