#include "bitpacking.h"

short int packThree(char high, char middle, char low)
{
	short int highMasked = 0;
	short int midMasked = 0;
	short int lowMasked = 0;
	char extractMask = 31;
	short int packOut = 0;

	highMasked = high & extractMask;
	midMasked = middle & extractMask;
	lowMasked = low & extractMask;

	packOut = packOut | highMasked;
	packOut = packOut << 5;
	packOut = packOut | midMasked;
	packOut = packOut << 5;
	packOut = packOut | lowMasked;

	return packOut;
}

void unpackThree(int codeIn, char &highOut, char &midOut, char &lowOut,
	             CHARCASE upperLower)
{
	highOut = 0;
	midOut = 0;
	lowOut = 0;
	char extractMask = 31;
	char upperMask = 64;
	char lowerMask = 96;
	short int lowMask = 0;
	short int midMask = 0;
	short int highMask = 0;

	lowMask = codeIn & extractMask;
	codeIn = codeIn >> 5;
	midMask = codeIn & extractMask;
	codeIn = codeIn >> 5;
	highMask = codeIn & extractMask;

	if (upperLower == LOWERCASE)
	{
		highOut = highOut | highMask;
		highOut = highOut | lowerMask;
		midOut = midOut | midMask;
		midOut = midOut | lowerMask;
		lowOut = lowOut | lowMask;
		lowOut = lowOut | lowerMask;
	}
	else
	{
		highOut = highOut | highMask;
		highOut = highOut | upperMask;
		midOut = midOut | midMask;
		midOut = midOut | upperMask;
		lowOut = lowOut | lowMask;
		lowOut = lowOut | upperMask;
	}

}