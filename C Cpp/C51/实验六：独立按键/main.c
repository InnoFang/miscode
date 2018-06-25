#include "reg51.h"
typedef unsigned char u8;
typedef unsigned int u16;

sbit led = P2^0;		// D1
sbit k1=P3^1;
void delay(u16 i)
{
 	while (i--);
}
void keypros()
{
   	if (0==k1) {
		delay(1000);
		if (0==k1) {
		 	led=~led; 
		}
		while (!k1);
	}
}
void main() 
{
	while (1) 
	{
	   keypros();
	}
}