#pragma once
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <cmath>
#include <cctype>

using namespace std;

void permutations(string* items, int* p, int* used, int n, int k, int position);
bool openInput(ifstream& fileIn, string fileName);

int main(int argc, char** argv)
{
    ifstream input;
    int nIn;
    int kIn;
    string* stringsIn;
    int* pIn;
    int* usedIn;
    int i;

    if (argc != 2)
    {
        cout << "Usage: m0101.exe itemfile.txt" << endl;
        return 0;
    }

    if (openInput(input, argv[1]) == false)
    {
        cout << "Unable to open file: " << argv[1] << endl;
        return 0;
    }

    input >> nIn;
    input >> kIn;
    input.ignore(1);
    stringsIn = new(nothrow) string[nIn];
    pIn = new(nothrow) int[nIn];
    usedIn = new(nothrow) int[nIn];

    for (i = 0; i < nIn; i++)
    {
        getline(input, stringsIn[i]);
        pIn[i] = i;
        usedIn[i] = 0;
    }

    permutations(stringsIn, pIn, usedIn, nIn, kIn, 0);

    delete[]stringsIn;
    delete[]pIn;
    delete[]usedIn;
    return 0;
}

void permutations(string* items, int* p, int* used, int n, int k, int position)
{
    int i;

    if (position == k)
    {
        for (i = 0; i < k; i++)
        {
            cout << items[p[i]];
            if (i != k-1)
            {
                cout << " ";
            }
            else
            {
                cout << endl;
            }
        }
        return;
    }

    for (i = 0; i < n; i++)
    {
        if (used[i] == 0)
        {
            p[position] = i;
            used[i] = 1;
            permutations(items, p, used, n, k, position + 1);
            used[i] = 0;
        }
    }
}

bool openInput(ifstream& fileIn, string fileName)
{
    //open the input file
    fileIn.open(fileName);

    //if the input file opened, return true
    if (fileIn.is_open() == true)
    {
        return true;
    }

    //otherwise, return false
    else
    {
        return false;
    }

}
