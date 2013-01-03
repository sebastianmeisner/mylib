/*
 ============================================================================
 Name        : rle.c
 Author      : Sebastian Meisner
 Version     :
 Copyright   : GPL2
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "rle.h"

int main(void) {
	puts("RLE Test 1.0");

	unsigned char inbuffer1[16]= {
		0,0,0,0,0,0,0,0,
		1,1,1,1,1,1,1,1
	};
	unsigned char inbuffer2[16]= {
			0,1,0,1,0,1,0,1,
			0,1,0,1,0,1,0,1
		};

	unsigned char outbuffer1[32];
	unsigned char outbuffer2[32];

	int length = 0;
	int same   = 0;
	length = rle_encode(inbuffer1, sizeof(inbuffer1), outbuffer1, sizeof(outbuffer1));
	length = rle_decode(outbuffer1, length, outbuffer2, sizeof(outbuffer2));
	same   = memcmp(inbuffer1, outbuffer2, sizeof(inbuffer1));

	length = rle_encode(inbuffer2, sizeof(inbuffer2), outbuffer1, sizeof(outbuffer1));
	length = rle_decode(outbuffer1, length, outbuffer2, sizeof(outbuffer2));
	same   = memcmp(inbuffer2, outbuffer2, sizeof(inbuffer1));

	return EXIT_SUCCESS;
}
