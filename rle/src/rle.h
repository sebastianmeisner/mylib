/*
 * rle.h
 *
 *  Created on: 25.12.2012
 *      Author: meise
 */

#ifndef RLE_H_
#define RLE_H_

int rle_encode(unsigned char* inbuffer, unsigned int inlen,unsigned  char* outbuffer, unsigned int outlen);
int rle_decode(unsigned char* inbuffer, unsigned int inlen,unsigned  char* outbuffer, unsigned int outlen);
int rle_encoded_size(unsigned char* inbuffer, unsigned int inlen);
int rle_decoded_size(unsigned char* inbuffer, unsigned int inlen);


#endif /* RLE_H_ */
