#include <reg51.h>

 

unsigned char funcao (unsigned char);

 

unsigned char bdata var_1;

 

sbit var_1_1 = var_1^1;
sbit var_1_0 = var_1^0;
sbit var_2 = P0^7;
sbit var_3 = P3^4;
sbit var_4 = P3^3;

 

void main (void) {

short var_5;

unsigned char var_6 = 7;

 

var_2 = 0;
var_1 = 0x03;

while (1) {


var_3 = var_1_1;

var_4 = var_1_0;

if ( var_6 == 0) var_6 = 9;

P1 = funcao(var_6);

var_6--;

var_2 = 1;

for (var_5 = 0; var_5 <1400; var_5++);

if (var_1 == 0) var_1 = 0x03;

else var_1--;

var_2 = 0;

}

}

unsigned char funcao (unsigned char var_7) {

switch (var_7) {


case 0:   var_7 = 0x40; break;
case 1:   var_7 = 0x79; break;
case 2:   var_7 = 0x24; break;
case 3:   var_7 = 0x30; break;
case 4:   var_7 = 0x19; break;
case 5:   var_7 = 0x12; break;
case 6:   var_7 = 0x02; break;
case 7:   var_7 = 0x78; break;
case 8:   var_7 = 0x00; break;
case 9:   var_7 = 0x10; break;
case 10: var_7 = 0x08; break;
case 11: var_7 = 0x03; break;
case 12: var_7 = 0x46; break;
case 13: var_7 = 0x21; break;
case 14: var_7 = 0x06; break;
case 15: var_7 = 0x0E; break;
default:   var_7 = 0x80;
}

return var_7;

}

