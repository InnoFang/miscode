#include "reg51.h"
typedef unsigned char u8;
typedef unsigned int u16;

sbit led1 = P2^0;		// D1
sbit led2 = P2^1;		// D2
sbit led3 = P2^2;		// D3
sbit led4 = P2^3;		// D4

sbit k1=P3^1;
sbit k2=P3^0;
sbit k3=P3^2;
sbit k4=P3^3;

void delay(u16 i)
{
 	while (i--);
}
void keypros()
{
   	if (0==k1) {
		delay(1000);
		if (0==k1) {
		 	led1=~led1; 
		}
		while (!k1);
	}
	if (0==k2) {
		delay(1000);
		if (0==k2) {
		 	led2=~led2; 
		}
		while (!k2);
	}
	if (0==k3) {
		delay(1000);
		if (0==k3) {
		 	led3=~led3; 
		}
		while (!k3);
	}
	if (0==k4) {
		delay(1000);
		if (0==k4) {
		 	led4=~led4; 
		}
		while (!k4);
	}
}
void main() 
{
	while (1) 
	{
	   keypros();
	}
}