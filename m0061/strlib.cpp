#include "strlib.h"

//functions here

int recCStrCmp(char str1[], char str2[], int pos) //version 1
{
    int whatReturns = 0;
    if (str1[pos] == '\0' || str2[pos] == '\0')
    {
        whatReturns = str1[pos] - str2[pos];
        return whatReturns;
    }
    if (isalpha(str1[pos]) && isalpha(str2[pos]))
    {
        whatReturns = toupper(str1[pos]) - toupper(str2[pos]);
    }
    else
    {
        whatReturns = str1[pos] - str2[pos];
    }
    if (whatReturns == 0)
    {
        pos = pos + 1;
        whatReturns = recCStrCmp(str1, str2, pos);
    }
    return whatReturns;
}

int recCStrCmp(char* str1, char* str2) //version 2
{
    int whatReturns = 0;
    if (*str1 == '\0' || *str2 == '\0')
    {
        whatReturns = *str1 - *str2;
        return whatReturns;
    }
    if (isalpha(*str1) && isalpha(*str2))
    {
        whatReturns = toupper(*str1) - toupper(*str2);
    }
    else
    {
        whatReturns = *str1 - *str2;
    }
    if (whatReturns == 0)
    {
        str1++;
        str2++;
        whatReturns = recCStrCmp(str1, str2);
    }
    str1 = nullptr;
    str2 = nullptr;
    return whatReturns;
}