/* Fazer um programa para TRANSMITIR pela interface serial os valores de 41H a
61H de forma cíclica. Devem ser transmitidos 8 bits de dados à taxa de 19,2
kbits por segundo. O programa deve também receber dados, armazenando os
valores recebidos em 10 posições da memória externa. Após completar o
preenchimento destas 10 posições de memória, voltar a preenchê-las com os
dados recebidos a partir da primeira posição. */


#include <reg51.h>

void serial (void);

unsigned char stateT = 0x00;
unsigned char stateR = 0x00;

void main (void)
{
	unsigned char caractere = 0x41;
	unsigned char xdata recebidos[10];
	unsigned char xdata *ponteiro;
	unsigned char n = 0;
	
	ponteiro = &recebidos[0];
	
	SCON = 0x50; // 0101 0000B
	PCON = 0x80; // 1000 0000B
	TMOD |= 0x20; // 0010 0000B
	TH1 = 0xFD;
	
	ES = 1;
	EA = 1;
	TR1 = 1;
	
	SBUF = caractere++;
	
	while (1)
	{
		if (stateT)
		{
			stateT = 0;
			SBUF = caractere++;
			if (caractere == 0x62) caractere = 0x41;
		}
		
		else if (stateR)
		{
			stateR = 0;
			*(ponteiro + n++) = SBUF;
			if (n == 10) n = 0;
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