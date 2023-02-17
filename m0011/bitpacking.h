#ifndef __BITPACKING__H__
#define __BITPACKING__H__

enum CHARCASE { UPPERCASE, LOWERCASE };

short int packThree(char high, char middle, char low);

void unpackThree(int codeIn, char &highOut, char &midOut, char &lowOut,
	             CHARCASE upperLower);

#endif
