/** **************************************************************************
 * @file
 *
 * @brief  Prototypes
 ****************************************************************************/
#pragma once

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

#ifndef __thpExam2__H__
#define __thpExam2__H__

/*****************************************************************************
*                     Class Prototype
*****************************************************************************/
/**
 * @brief Class definition for a linked list
*/
class list
{
public:
    list ( );
    ~list ( );

    //List Manipulation
    bool insert ( string word );
    int incrementFreq ( int currentFreq );

    //List Information
    bool isEmpty ( );
    int size ( );

    int freqAt ( int pos );
    string wordAt ( int pos );

    void getF ( vector<int>& freqList );
    void getL ( vector<int>& lengList );

    //Print Functions
    void printA ( ostream& out );
    void printF ( ostream& out );
    void printL ( ostream& out );

private:
/**
 * @brief Structure containing the infomation for each note in a linked list
*/
    struct node
    {
        string word;   /**< The word to be stored in the linked list */
        int frequency; /**< The amount of times a word has been added */
        node* next;    /**< The address of the next node in the list*/
    };
    node* headptr;     /**< The address of the first node in the list*/

    node* findF ( int freq, node* ptr );
    node* findL ( int freq, node* ptr );
};

/*****************************************************************************
*                     Function Prototypes
*****************************************************************************/
bool openInput(ifstream& fileIn, string fileName);
bool openOutput(ofstream& fileOut, string fileName);
void closeFiles( ifstream& fin, ofstream& fout, ofstream& stats );
void checkString( string& word );
void writeStatFile(string outputType, ostream& outputFile, list& baseList);
bool checkArg( string argIn );

#endif