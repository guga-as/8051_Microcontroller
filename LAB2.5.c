#include <reg51.h>

#define CS 0x7F;

void main (void)
{
	unsigned char led_aceso = 0xFF;
	unsigned short i;
	
	P0 = CS;
	P1 = led_aceso;
	
	while (1)
	{
		led_aceso = (led_aceso >> 1) | 0x80;
		for (i = 0; i < 15000; i++);
		if (led_aceso == 0xFF) led_aceso = 0x7F;
		P1 = led_aceso;
	}
}