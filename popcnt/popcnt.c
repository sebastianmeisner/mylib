/*
 * popcnt.c
 *
 *  Created on: 25.02.2013
 *      Author: meise
 */

#include <stdio.h>
#include <stdlib.h>
#include "popcnt.h"

/**
 * @brief Counts set bits in a word, counting implementation.
 */
int popcnt_count(unsigned int x)
{
	int i;
	for ( i=0; x; x=x&(x-1), i++);
	return i;
}

/**
 * @brief Counts set bits in a word, mask implementation.
 */
int popcnt_mask(unsigned int x)
{
	static const unsigned int mask[] =
	{
			0x55555555,
			0x33333333,
			0x0f0f0f0f,
			0x00ff00ff,
			0x0000ffff
	};
	int i;
	int shift;
	for ( i=0, shift = 1; i< 5; i++, shift *= 2)
	{
		x = (x & mask[i]) + ((x>>shift) & mask[i]);
	}
	return x;
}

unsigned char hamming[256];
void sethamming()
{
	hamming[0]=0;
	hamming[1]=1;
	int i;
	for ( i=2; i<256; i++ )
	{
		if (i&1) { hamming[i]=hamming[i-1]+1;}
		else	 { hamming[i]=hamming[i>>1]; }
	}
}

int popcnt_lut(unsigned int x)
{
	unsigned char a,b,c,d;
	a=x;
	b=x>>8;
	c=x>>16;
	d=x>>24;
	return hamming[a]+hamming[b]+hamming[c]+hamming[d];
}


int popcnt_builtin(unsigned int x)
{
	return __builtin_popcount(x);
}

int main (int argc, char ** argv){
	if ( argc != 2 )
	{
		printf("No param given! Exiting...\n");
		return 1;
	}
	unsigned int x = atoi(argv[1]);
	printf("Param: %8i, in Hex: %8x\n", x, x);
	printf("popcnt_count set bits: %2i\n", popcnt_count(x));
	printf("popcnt_mask  set bits: %2i\n", popcnt_mask(x));
	sethamming();
	printf("popcnt_lut   set bits: %2i\n", popcnt_lut(x));
	printf("popcnt_builtin set bits: %2i\n", popcnt_builtin(x));
	return 0;
}
