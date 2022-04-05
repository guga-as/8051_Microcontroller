#include <reg51.h> // Diretiva ou biblioteca que contém funções e registradores presentes no 8051.

#define CS 0x7F; // Não será usado o Display de 7 segmentos, assim, a porta P0 será 0111 1111 B.

void main (void)
{
	unsigned char led_aceso = 0xFF;
	unsigned short i;
	
	P0 = CS;
	P1 = led_aceso;
	
	while (1)
	{
		while (led_aceso != 0x00)
		{
			led_aceso = led_aceso >> 1;
			for (i = 0; i < 15000; i++);
			P1 = led_aceso;
		}
		while (led_aceso != 0xFF)
		{
			led_aceso = (led_aceso << 1) | 0x01;
			for (i = 0; i < 15000; i++);
			P1 = led_aceso;
		}
	}
}