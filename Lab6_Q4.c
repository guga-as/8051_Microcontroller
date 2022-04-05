/* Programar a interface serial do 8051 para enviar os caracteres de 43h a
61h de forma cíclica, utilizando a taxa de 62,5 kbits/s. Transmitir 8 bits
de dados mais bits de paridade.

	Modificar programa anterior para que o mesmo também receba dados e
os armazene em 5 posições da memória RAM interna. Armazenar os
dados de forma cíclica (ao preencher as 5 posições, volte a preenchê-lo
com os dados recebidos). */

#include <reg51.h>

void serial (void);
	
unsigned char stateT = 0x00;
unsigned char stateR = 0x00;

void main (void)
{
	unsigned char caractere = 0x43;
	unsigned char data recebidos[5];
	unsigned char data *ponteiro;
	unsigned char n = 0;
	
	ponteiro = &recebidos[0];
	
	SCON = 0xD0; // 1101 0000B
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
		if (stateT)
		{
			stateT = 0;
			ACC = caractere++;
			TB8 = P;
			SBUF = ACC;
			if (caractere == 0x62) caractere = 0x43;
		}
		
		else if (stateR)
		{
			stateR = 0;
			*(ponteiro + n++) = SBUF;
			if (n == 5) n = 0;
		}
	}
}

void serial (void) interrupt 4
{
	if (TI)
	{
		stateT += 1;
		TI = 0;
	}
	
	else if (RI)
	{
		stateR += 1;
		RI = 0;
	}
}