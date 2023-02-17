#pragma once
#include <cmath>
#include <fstream>
#include <iostream>
#include <string>
#include <cctype>
#include <iomanip>
#include <vector>
#include <algorithm>

using namespace std;

/*int main(int argc, char** argv)
{
    ifstream input;
    ofstream output;
    int numValues;
    float nums;
    vector<float> v1;
    vector<float>::iterator min;
    vector<float>::iterator max;
    int i;
    int actSize;
    int j;
    int lineCount = 0;
    if (argc != 3)
    {
        cout << "Usage: m0051.exe inputfile outputfile" << endl;
        return 0;
    }
    input.open(argv[1]);
    if (input.is_open() != true)
    {
        cout << "Unable to open input file: " << argv[1] << endl;
        return 0;
    }
    output.open(argv[2]);
    if (output.is_open() != true)
    {
        cout << "Unable to open output file: " << argv[2] << endl;
        return 0;
    }
    input >> numValues;
    v1.resize(0);
    for (i = 0; i < numValues && input >> nums; i++)
    {
        v1.push_back(nums);
    }
    actSize = i;
    min = min_element(v1.begin(), v1.end());
    max = max_element(v1.begin(), v1.end());
    
    output << actSize << endl;
    output << showpoint << setprecision(3) << fixed;
    output << *min << " - " << *max << endl;
    for (j = 0; j < actSize; j++)
    {
        output << setw(15) << right << v1[j];
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
    input.close();
    output.close();
    return 0;
}*/

int main(int argc, char** argv)
{
    ifstream input;
    ofstream output;
    int numValues;
    float nums;
    vector<float> v1;
    vector<float>::iterator min;
    vector<float>::iterator max;
    vector<float>::iterator itOut;
    int i;
    int actSize;
    int lineCount = 0;
    if (argc != 3) 
    {
        cout << "Usage: m0051.exe inputfile outputfile" << endl;
        return 0;
    }
    input.open(argv[1]);
    if (input.is_open() != true)
    {
        cout << "Unable to open input file: " << argv[1] << endl;
        return 0;
    }
    output.open(argv[2]);
    if (output.is_open() != true)
    {
        cout << "Unable to open output file: " << argv[2] << endl;
        return 0;
    }
    input >> numValues;
    v1.resize(0);
    for (i = 0; i < numValues && input >> nums; i++)
    {
        v1.push_back(nums);
    }
    actSize = i;
    min = min_element(v1.begin(), v1.end());
    max = max_element(v1.begin(), v1.end());

    output << actSize << endl;
    output << showpoint << setprecision(3) << fixed;
    output << *min << " - " << *max << endl;
    for (itOut = v1.begin(); itOut != v1.end(); itOut++)
    {
        output << setw(15) << right << *itOut;
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
    input.close();
    output.close();
    return 0;
}