#include <reg51.h>
unsigned char funcao1 (unsigned char);
unsigned char bdata VAR_5 = 2;
sbit VAR_7 = P0^7;
sbit VAR_4 = P3^4; 
sbit VAR_3 = P3^3; 
sbit VAR_1 = VAR_5^1; 
sbit VAR_0 = VAR_5^0;
void main (void) {
unsigned char VAR_2 = 8;
unsigned short VAR_6;
    VAR_7 = 0; 
    while (1) { 
                      VAR_4 = VAR_1; 
                      VAR_3 = VAR_0; 
                      VAR_2--;
                      P1= funcao1(VAR_2); 
                       for (VAR_6 = 0; VAR_6 < 15000; VAR_6++); 
                       if (VAR_5 ==0) VAR_5 = 4; 
                      VAR_5 --; 
                       if ( VAR_2 == 0) VAR_2 = 16;
                       } 
}
unsigned char funcao1 (unsigned char VAR_8) {
switch (VAR_8) {
                             case 0: VAR_8 = 0x40; break; 
                             case 1: VAR_8 = 0x79; break; 
                             case 2:  VAR_8 = 0x24; break; 
                             case 3:  VAR_8 = 0x30; break; 
                             case 4:  VAR_8 = 0x19; break; 
                             case 5:  VAR_8 = 0x12; break; 
                             case 6:  VAR_8 = 0x02; break; 
                             case 7:  VAR_8 = 0x78; break; 
                             case 8:  VAR_8 = 0x00; break; 
                             case 9:   VAR_8 = 0x10; break; 
                             case 10: VAR_8 = 0x08; break; 
                             case 11: VAR_8 = 0x03; break; 
                             case 12: VAR_8 = 0x46; break; 
                             case 13: VAR_8 = 0x21; break; 
                             case 14: VAR_8 = 0x06; break; 
                             case 15: VAR_8 = 0x0E; break; 
                            default:    VAR_8 = 0x80; 
                       }
return VAR_8;
										 }