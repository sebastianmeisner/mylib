/*
 * rle_test.c
 *
 *  Created on: 25.12.2012
 *      Author: meise
 */

#include <stdlib.h>
#include <limits.h>
#include <assert.h>

#include "rle.h"

int rle_encode(unsigned char* inbuffer, unsigned int inlen,unsigned  char* outbuffer, unsigned int outlen){
	unsigned char current = inbuffer[0];
	unsigned char current_cnt = 1;

	unsigned int inidx = 1;
	unsigned int outidx = 0;

	// If no output buffer given, we just count how many bytes would be needed
	if ( outbuffer == NULL ) { outlen = UINT_MAX;}

	while ( inidx < inlen && outidx < outlen-2 ){
		if ( current == inbuffer[inidx] && current_cnt != 255 ){
			current_cnt++;
			inidx++;
		} else {
			// write into outbuffer
			if ( outbuffer ) {
				outbuffer[outidx  ]= current_cnt;
				outbuffer[outidx+1] = current;
			}
			outidx+=2;

			// reset counters
			current = inbuffer[inidx];
			current_cnt = 1;
			inidx++;
		}
	}
	// Did we run out of space?
	if (inidx < inlen && outidx >= outlen-2){
		return -1;
	}

	// Write out last run. Former checks make sure we have enough space left in outbuffer.
	if ( outbuffer ) {
		outbuffer[outidx  ]= current_cnt;
		outbuffer[outidx+1] = current;
	}

	// Return length of output
	return outidx+2;

}

int rle_decode(unsigned char* inbuffer, unsigned int inlen, unsigned char* outbuffer, unsigned int outlen){

	unsigned char current;
	unsigned char current_cnt;

	unsigned int inidx = 0;
	unsigned int outidx = 0;

	// If no output buffer given, we just count how many bytes would be needed
	if ( outbuffer == NULL ) { outlen = UINT_MAX;}

	while ( inidx < inlen-1 && outidx < outlen ){
		current_cnt = inbuffer[inidx];
		current     = inbuffer[inidx+1];

		// Only count output bytes...
		if ( outbuffer == NULL){
			outidx+= current_cnt;
			continue;
		}

		// Did we run out of space?
		if ( outidx+current_cnt >= outlen){
			return -1;
		}

		for ( int i = 0; i< current_cnt; i++ ) {
			outbuffer[outidx++] = current;
		}

		inidx += 2;
	}

	// Return length of output
	return outidx;
}

int rle_encoded_size(unsigned char* inbuffer, unsigned int inlen){
	return rle_encode(inbuffer, inlen,NULL, 0);
}

int rle_decoded_size(unsigned char* inbuffer, unsigned int inlen){
	return rle_decode(inbuffer, inlen,NULL, 0);
}
