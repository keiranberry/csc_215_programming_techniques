/** *********************************************************************
 * @file
 *
 * @brief  Prototypes
 ***********************************************************************/
#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <cmath>



using namespace std;
/************************************************************************
 *             Constant Variables, defines and Enums
 ***********************************************************************/

 /** ********************************************************************
 * @brief Definition of __NETPBM__H__
 ***********************************************************************/
#ifndef __NETPBM__H__
#define __NETPBM__H__

 /** ********************************************************************
 * @brief Typedef unsigned char to "pixel"
 ***********************************************************************/
typedef unsigned char pixel;

/** ********************************************************************
* @brief Structure to be filled in with image information
***********************************************************************/
struct image
{
/** ********************************************************************
* @brief String to be filled with the image's magic number
***********************************************************************/
    string magicNumber;
/** ********************************************************************
* @brief String to be filled in with the image's comment
***********************************************************************/
    string comment;
/** ********************************************************************
* @brief Int to be filled with the image's number of rows
***********************************************************************/
    int rows;
/** ********************************************************************
* @brief Int to be filled with the image's number of columns
***********************************************************************/
    int cols;
/** ********************************************************************
* @brief 2D array of pixels to be filled with the image's red/gray data
***********************************************************************/
    pixel** redGray;
/** ********************************************************************
* @brief 2D array of pixels to be filled with the image's green data
***********************************************************************/
    pixel** green;
/** ********************************************************************
* @brief 2D array of pixels to be filled with the image's blue data
***********************************************************************/
    pixel** blue;
};

/************************************************************************
 *                         Function Prototypes
 ***********************************************************************/
//thpExam1.cpp prototypes
void usageStatement();
string argReturn(string input);
bool noOption(string argIn);
bool option(string argIn, string arg2);
//imageOperations.cpp prototypes here
void xFlip(image& im);
void yFlip(image& im);
void rotateCW(image& img);
void rotateCCW(image& img);
void grayscale(image& img);
void sepia(image& img);
void manipImage(image& img, string opUsed);
//memory.cpp prototypes here
void allocArray(image& img);
void deleteDArray(image& img);
void deleteDArrayFlip(image& img);
void allocFlipCR(image& img, pixel**& redT, pixel**& greenT, pixel**& blueT);
//imageFileIO.cpp prototypes
bool openInput(ifstream& file, string fileName);
bool openInBin(ifstream& file, string fileName);
bool openOutput(ofstream& file, string fileName);
bool openOutBin(ofstream& file, string fileName);
bool checkMN(string mn);
string fOutName(string mn, string fOut);
void writeFileBin(image& im, ofstream& file, string optionIn);
void writeFileAscii(image& im, ofstream& file, string optionIn);
void writeFileAsciiFlip(image& im, ofstream& file);
void writeHeader(image& im, ofstream& file, string optionUsed);
void mnOutput(image& img, string outType, string opUsed);
void fileOutput(image& img, ifstream& fin, ofstream& fout, streampos locOut,
    string onf, string opUsed);
void fillArrays(image& img, string magNum, ifstream& fin,
    ofstream& fout, string finName, streampos loc);
void validArgs(ifstream& fin, ofstream& fout, int numArgs, char** arguments,
    string arg1, string arg2, string& finName, string& foutName,
    string& outType, string& opUsed);

#endif
