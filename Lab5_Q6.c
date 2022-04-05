#include <reg51.h>

void c51_tmr1md1 (void);

unsigned char state0 = 0x00;
unsigned char bdata dado = 0xAA;
sbit P1_0 = P1^0;
sbit dado_LSB = dado^0;

void main (void)
{
	TMOD = 0x10;
	TH1 = 0x15;
	TL1 = 0xA0;
	
	ET1 = 1;
	EA = 1;
	TR1 = 1;
	
	while (1)
	{
		while (state0 != 1);
		state0 = 0;
		P1_0 = dado_LSB;
		dado = dado >> 1;
		if (dado == 0x00) dado = 0xAA;
	}

}

void c51_tmr1md1 (void) interrupt 3
{
	state0 += 1;
	TH1 = 0x15;
	TL1 = 0xA0;
}