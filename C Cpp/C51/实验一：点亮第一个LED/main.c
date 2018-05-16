#include "reg51.h"

sbit led = P2^0;

void main() 
{
	while (1) 
	{
	   led = 0;
	}
}