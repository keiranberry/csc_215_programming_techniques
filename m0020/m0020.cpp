#pragma once
#include <cmath>
#include <fstream>
#include <iostream>
#include <string>
#include <cctype>
#include <iomanip>

using namespace std;

bool openInput(ifstream& file, string fileName);
bool openOutput(ofstream& file, string fileName);
float* findMinimum(float arrayIn[], int arrayInSize);
float* findMaximum(float arrayIn[], int arrayInSize);

int main(int argc, char **argv)
{
    ifstream input;
    ofstream output;
    float *array = nullptr;
    int arraySize;
    float nums;
    int i = 0;
    int newSize;
    float* minPoint = nullptr;
    float* maxPoint = nullptr;
    int j = 0;
    int lineCount = 0;


	if (argc != 3)
	{
		cout << "Usage: m0020.exe inputfile outputfile" << endl;
		return 0;
	}
    if (openInput(input, argv[1]) == false)
    {
        cout << "Unable to open input file: " << argv[1] << endl;
        return 0;
    }
    if (openOutput(output, argv[2]) == false)
    {
        cout << "Unable to open output file: " << argv[2] << endl;
        return 0;
    }
    input >> arraySize;
    array = new (nothrow) float[arraySize];
    if (array == nullptr)
    {
        cout << "Unable to allocate memory" << endl;
    }
    for(i=0; input >> nums && i<arraySize; i++)
    {
        array[i] = nums;
    }
    newSize = i;
    minPoint = findMinimum(array, newSize);
    maxPoint = findMaximum(array, newSize);

    output << newSize << endl;
    output << showpoint << setprecision(3) << fixed;
    output << *minPoint << " - " << *maxPoint << endl;
    for (j = 0; j < newSize; j++)
    {
        output << setw(15) << right << array[j];
        lineCount++;
        if (lineCount == 5)
        {
            output << endl;
            lineCount = 0;
        }
    }
    if (lineCount != 0)
    {
        output << endl;
    }
    delete[]array;
    minPoint = nullptr;
    maxPoint = nullptr;
    delete minPoint;
    delete maxPoint;
    input.close();
    output.close();
	return 0;
}

bool openInput(ifstream& file, string fileName)
{
    file.open(fileName);

    if (file.is_open() == true)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool openOutput(ofstream& file, string fileName)
{
    file.open(fileName);

    if (file.is_open() == true)
    {
        return true;
    }
    else
    {
        return false;
    }

}

float* findMinimum(float arrayIn[], int arrayInSize)
{
    int i = 0;
    float* minimum = nullptr;
    int min = 0;
    for (i = 0; i < arrayInSize; i++)
    {
        if (arrayIn[i] < arrayIn[min])
        {
            min = i;
        }
    }
    minimum = &arrayIn[min];
    return minimum;
}

float* findMaximum(float arrayIn[], int arrayInSize)
{
    int i = 0;
    float* maximum = nullptr;
    int max = 0;
    for (i = 0; i < arrayInSize; i++)
    {
        if (arrayIn[i] > arrayIn[max])
        {
            max = i;
        }
    }
    maximum = &arrayIn[max];
    return maximum;
}
