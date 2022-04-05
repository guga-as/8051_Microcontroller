// Programar interface serial para 8051 para ENVIAR caracteres de 43h até 61h de forma cíclica à taxa de envio de 62.5 kBits/seg
// 9 Bits (8 bits + paridade)
// Modo 3 - Cristal oscilador de 12 MHz - SMOD = 1 

#include <reg51.h>

void serial (void);

unsigned char stateT = 0x00;

void main (void)
{
	unsigned char caractere = 0x43;
	
	SCON = 0xC0; // 1100 0000B
	PCON = 0x80; // 1000 0000B
	TMOD |= 0x20; // 0010 0000B
	TH1 = 0xFF;
	
	ES = 1;
	EA = 1;
	TR1 = 1;
	
	ACC = caractere++;
	TB8 = P;
	SBUF = ACC;
	
	while (1)
	{
		while (stateT != 1);
		stateT = 0;
		ACC = caractere++;
		TB8 = P;
		SBUF = ACC;
		if (caractere == 0x62) caractere = 0x43;
	}
	
}

void serial (void) interrupt 4
{
	if (TI)
	{
		stateT += 1;
		TI = 0;
	}
}