#include "strLib.h"

void replaceAllCString(char* cString, char* find, char* replace)
{
	char* point = nullptr;
	char* tempArray = nullptr;
	char* findEnd = nullptr;
	char* tempStart = nullptr;
	char* index = nullptr;
	char* src = nullptr;
	size_t wholeLength = 0;
	size_t findLength = 0;
	size_t pointLength = 0;
	size_t replaceLength = 0;
	size_t tempLength = 0;
	int i = 0;

	findLength = strlen(find);
	replaceLength = strlen(replace);
	wholeLength = strlen(cString);
	index = cString;
	point = strstr(cString, find);

	while (point != nullptr)
	{
		pointLength = strlen(point);
		tempLength = wholeLength - findLength;
		findEnd = point + replaceLength;
		tempStart = point + findLength;
		tempArray = new(nothrow) char[pointLength + 1];
		if (tempArray == nullptr)
		{
			cout << "Memory allocation error" << endl;
		}
		/*strcpy(tempArray, tempStart);
		strncpy(point, replace, replaceLength);
		strncpy(findEnd, tempArray, tempLength);*/
		strcpy(tempArray, tempStart);
		strcpy(point, replace);
		strcat(cString, tempArray);
		delete[] tempArray;
		src = point + replaceLength;
		point = nullptr;
		point = strstr(src, find);
	}
	point = nullptr;
	tempArray = nullptr;
	findEnd = nullptr;
	tempStart = nullptr;
	index = nullptr;
	src = nullptr;
}

void replaceAllString(string& str, string find, string replace)
{
	size_t whereFound = 0;
	size_t replaceSize = 0;
	size_t findSize = 0;
	size_t index = 0;
	whereFound = str.find(find);
	replaceSize = replace.length();
	findSize = find.length();

	while (whereFound != string::npos)
	{
		str.replace(whereFound, findSize, replace);
		index = whereFound + replaceSize;
		whereFound = str.find(find, index);
		
	}
}
