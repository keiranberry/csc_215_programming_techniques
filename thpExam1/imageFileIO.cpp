/** *********************************************************************
 * @file
 *
 * @brief   Functions that deal with file input and output.
 ***********************************************************************/
#include "netPBM.h"



 /** **********************************************************************
  *  @author Keiran Berry
  *
  *  @par Description
  *  Checks that the input file has opened successfully.
  *
  *  @param[in] file - The ifstream file input.
  *
  *  @param[in] fileName - The name of the file which is being checked.
  *
  *  @returns  A boolean value, whether the file has opened successfully
  *           or not.
  *
  *
  *  @par Example
  *  @verbatim
     //returns true if the file has opened successfully

     //returns false if the file has not opened

     @endverbatim
  ************************************************************************/
bool openInput(ifstream& file, string fileName)
{
    file.open(fileName);
    //open file, and if it opened successfully return true
    if (file.is_open() == true)
    {
        return true;
    }
    else
    {
        return false;
    }
}



/** **********************************************************************
 *  @author Keiran Berry
 *
 *  @par Description
 *  Checks that the input file has opened successfully in binary.
 *
 *  @param[in] file - The ifstream file input.
 *
 *  @param[in] fileName - The name of the file which is being checked.
 *
 *  @returns  A boolean value, whether the file has opened successfully
 *           or not.
 *
 *
 *  @par Example
 *  @verbatim
    //returns true if the file has opened successfully

    //returns false if the file has not opened

    @endverbatim
 ************************************************************************/
bool openInBin(ifstream& file, string fileName)
{
    file.open(fileName, ios::in | ios::binary);
    //open file in binary, if it opened successfully return true
    if (file.is_open() == true)
    {
        return true;
    }
    else
    {
        return false;
    }
}



/** **********************************************************************
 *  @author Keiran Berry
 *
 *  @par Description
 *  Checks that the output file has opened successfully.
 *
 *  @param[in] file - The ofstream file input.
 *
 *  @param[in] fileName - The name of the file which is being checked.
 *
 *  @returns  A boolean value, whether the file has opened successfully
 *           or not.
 *
 *
 *  @par Example
 *  @verbatim
    //returns true if the file has opened successfully

    //returns false if the file has not opened

    @endverbatim
 ************************************************************************/
bool openOutput(ofstream& file, string fileName)
{
    file.open(fileName);
    //open output file, and return true if opened
    if (file.is_open() == true)
    {
        return true;
    }
    else
    {
        return false;
    }

}



/** **********************************************************************
 *  @author Keiran Berry
 *
 *  @par Description
 *  Checks that the output file has opened successfully in binary.
 *
 *  @param[in] file - The ofstream file input.
 *
 *  @param[in] fileName - The name of the file which is being checked.
 *
 *  @returns  A boolean value, whether the file has opened successfully
 *           or not.
 *
 *
 *  @par Example
 *  @verbatim
    //returns true if the file has opened successfully

    //returns false if the file has not opened

    @endverbatim
 ************************************************************************/
bool openOutBin(ofstream& file, string fileName)
{
    file.open(fileName, ios::out | ios::app | ios::binary);
    //open output in binary, and return true if it opened
    if (file.is_open() == true)
    {
        return true;
    }
    else
    {
        return false;
    }

}



/** **********************************************************************
 *  @author Keiran Berry
 *
 *  @par Description
 *  Checks that the magic number provided in the input file is valid. 
 *  Since grayscale inputs are not valid, the only valid magic numbers 
 *  are P3 and P6.
 *
 *  @param[in] mn - the magic number string to be tested for validity.
 *
 *  @returns  A boolean value, whether the magic number is valid or not.
 *
 *
 *  @par Example
 *  @verbatim
    string magicNum = "P6";
    bool valid;
    valid = checkMN(magicNum);
    //result would be true
    
    magicNum = "P58";
    valid = checkMN(magicNum);
    //result would be false

    @endverbatim
 ************************************************************************/
bool checkMN(string mn)
{   //check validity of input magic nums
    //only P3 and P6 are valid input magic nums
    if (mn == "P3")
    {
        return true;
    }
    else if (mn == "P6")
    {
        return true;
    }
    else
    {
        return false;
    }
}




/** **********************************************************************
 *  @author Keiran Berry
 *
 *  @par Description
 *  Creates the final name for the output file. This is done by taking in 
 *  the magic number from the file which is to be output and the name 
 *  of the output file from the argument list. If the magic number is 
 *  one that corresponds to grayscale, then ".pgm" will be added to the 
 *  file name. Otherwise, ".ppm" will be added.
 *
 *  @param[in] mn - The magic number of the file to be output.
 *
 *  @param[in] fOut - The name of the output file from the command line.
 *
 *  @returns  A string, the final name of the output file.
 *
 *
 *  @par Example
 *  @verbatim
    string magicNum = "P3";
    string outName = "balloons";
    string final;
    final = foutName(magicNum, outName);
    //final is now "balloons.ppm"

    magicNum = "P2";
    final = fOutName(magicNum, outName);
    //final is now "balloons.pgm"

    @endverbatim
 ************************************************************************/
string fOutName(string mn, string fOut)
{   //if not grayscale output, add .ppm
    string nameOut;
    if (mn == "P3" || mn == "P6")
    {
        nameOut = fOut + ".ppm";
    }
    //if grayscale output, add .pgm
    else if (mn == "P2" || mn == "P5")
    {
        nameOut = fOut + ".pgm";
    }
    else
    {
        cout << "Invalid Magic Num In Output File" << endl;
    }
    return nameOut;
}



/** *********************************************************************
 * @author Keiran Berry
 *
 * @par Description:
 * This function takes in the image structure, the output file, and the 
 * option used from the command line. If the option is grayscale, then 
 * the redGray array is output to the file. Otherwise, all three arrays 
 * are written into the file to be used in the .ppm file. This is to be 
 * used with binary output files.
 *
 * @param[in] im - the image structure to be written from.
 * @param[in] file - the ofstream output file to be written into.
 * @param[in] optionIn - the option selected from the command line.
 *
 * @par Example:
   @verbatim
   img picture; //all areas have been filled already
   ofstream output; //output has already been opened and the header
                    //has been written
   string option = "--grayscale";
   writeFileBin(picture, output, option);
   //the redGray array will be output to the .pgm file

   option = "--flipX";
   writeFileBin(picture, output, option);
   //all three arrays will be output to the .ppm file
   @endverbatim

 ***********************************************************************/
void writeFileBin(image& im, ofstream& file, string optionIn)
{
    int i, j;
    //if option is grayscale, only output redGray array
    if (optionIn == "--grayscale")
    {
        for (i = 0; i < im.rows; i++)
        {
            for (j = 0; j < im.cols; j++)
            {
                file.write((char*)&im.redGray[i][j], sizeof(pixel));
            }
            j = 0;
        }
    }
    //if not grayscale, write each individual piece into the file
    else
    {
        for (i = 0; i < im.rows; i++)
        {
            for (j = 0; j < im.cols; j++)
            {
                file.write((char*)&im.redGray[i][j], sizeof(pixel));
                file.write((char*)&im.green[i][j], sizeof(pixel));
                file.write((char*)&im.blue[i][j], sizeof(pixel));
            }
            j = 0;
        }
    }
}



/** *********************************************************************
 * @author Keiran Berry
 *
 * @par Description:
 * This function takes in the image structure, the output file, and the
 * option used from the command line. If the option is grayscale, then
 * the redGray array is output to the file. Otherwise, all three arrays
 * are written into the file to be used in the .ppm file. This is to be
 * used with ascii output files.
 *
 * @param[in] im - the image structure to be written from.
 * @param[in] file - the ofstream output file to be written into.
 * @param[in] optionIn - the option selected from the command line.
 *
 * @par Example:
   @verbatim
   img picture; //all areas have been filled already
   ofstream output; //output has already been opened and the header
                    //has been written
   string option = "--grayscale";
   writeFileAscii(picture, output, option);
   //the redGray array will be output to the .pgm file

   option = "--flipX";
   writeFileAscii(picture, output, option);
   //all three arrays will be output to the .ppm file
   @endverbatim

 ***********************************************************************/
void writeFileAscii(image& im, ofstream& file, string optionIn)
{
    int i, j;
    int current;
    //if grayscale, only output redGray array
    if (optionIn == "--grayscale")
    {
        for (i = 0; i < im.rows; i++)
        {
            for (j = 0; j < im.cols; j++)
            {
                current = im.redGray[i][j];
                file << current << endl;
            }
            j = 0;
        }
    }
    //otherwise, output each piece of each array into the file
    else
    {
        for (i = 0; i < im.rows; i++)
        {
            for (j = 0; j < im.cols; j++)
            {
                current = im.redGray[i][j];
                file << current << endl;
                current = im.green[i][j];
                file << current << endl;
                current = im.blue[i][j];
                file << current << endl;
            }
            j = 0;
        }
    }

}



/** *********************************************************************
 * @author Keiran Berry
 *
 * @par Description:
 * This function takes in the image structure, the output file, and the
 * option used from the command line. All three arrays are written into 
 * the .ppm file. This is to be used if the rows and columns of the 
 * arrays have been previously flipped and the output file is ascii. 
 * Since the only options that can trigger this rotation are flipCW and 
 * flipCCW, there is no need to check for a grayscale output here.
 *
 * @param[in] im - the image structure to be written from.
 * @param[in] file - the ofstream output file to be written into.
 *
 * @par Example:
   @verbatim
   img picture; //all areas have been filled already
   ofstream output; //output has already been opened and the header
                    //has been written
   writeFileAsciiFlip(picture, output);
   //all three arrays will be output to the .ppm file
   @endverbatim

 ***********************************************************************/
void writeFileAsciiFlip(image& im, ofstream& file)
{
    int i, j;
    int current;
    //write each piece of the arrays into the file
    //columns and rows are flipped for this one
    for (i = 0; i < im.cols; i++)
    {
        for (j = 0; j < im.rows; j++)
        {
            current = im.redGray[i][j];
            file << current << endl;
            current = im.green[i][j];
            file << current << endl;
            current = im.blue[i][j];
            file << current << endl;
        }
        j = 0;
    }
}



/** *********************************************************************
 * @author Keiran Berry
 *
 * @par Description:
 * This function takes in the image structure, the output file, and the
 * option used from the command line. This function will write the 
 * header into the output file. This means that the magic number, 
 * comment, rows, columns, and "255" will be written into the output 
 * file. A whitespace is output to the file after the "255" in order 
 * to avoid issues with being off by one in binary outputs.
 *
 * @param[in] im - the image structure to be written from.
 * @param[in] file - the ofstream output file to be written into.
 * @param[in] optionUsed - the option selected from the command line.
 *
 * @par Example:
   @verbatim
   img picture; //all areas have been filled already
   ofstream output; //output has already been opened and the header
                    //has been written
   string option = "--flipX";
   writeHeader(picture, output, option);
   //the header will be written into the file
   @endverbatim

 ***********************************************************************/
void writeHeader(image& im, ofstream& file, string optionUsed)
{
    //write the file header
    //magic number first
    file << im.magicNumber << endl;
    //comment next
    file << im.comment << endl;
    file << im.cols << " " << im.rows << endl;
    //this will always be 255, so just output 255
    //with a whitespace to not mess up binary
    file << 255 << " ";
}



/** *********************************************************************
 * @author Keiran Berry
 *
 * @par Description:
 * This function takes in the output type and option from the image 
 * structure. The option is used to tell whether the output will be a 
 * grayscale image, since that changes the magic number necessary for 
 * the output file.
 *
 * @param[in] img - the image structure to be written into.
 * @param[in] outType - which type the output file will be.
 * @param[in] opUsed - the option selected from the command line.
 *
 * @par Example:
   @verbatim
   img picture;
   string type = "--binary";
   string option = "--flipX";
   mnOutput(picture, type, option);
   //"P6" will be added to the image structure

   type = "--ascii";
   option = "--grayscale";
   mnOutput(picture, type, option);
   //"P2" will be added to the image structure
   @endverbatim

 ***********************************************************************/
void mnOutput(image& img, string outType, string opUsed)
{
    //add magic number to structure based on 
    //the output type and whether it is 
    //to be grayscale
    if (outType == "--binary")
    {
        if (opUsed == "--grayscale")
        {
            img.magicNumber = "P5";
        }
        else
        {
            img.magicNumber = "P6";
        }
    }
    else if (outType == "--ascii")
    {
        if (opUsed == "--grayscale")
        {
            img.magicNumber = "P2";
        }
        else
        {
            img.magicNumber = "P3";
        }
    }
}



/** *********************************************************************
 * @author Keiran Berry
 *
 * @par Description:
 * This function calls the writeFile functions for ascii or binary. If 
 * the output is to be ascii, then writeFileAscii is called. If the 
 * output is to be binary, then a pointer is called to the current 
 * location in the output file after writing the header. The output 
 * file is then opened in binary, then writeFileBin is called in 
 * order to write the output to the file starting where the pointer 
 * left off. The magic number in the structure is used to determine 
 * the output type.
 *
 * @param[in] img - the image structure to be written from.
 * @param[in] fin - the ifstream input file.
 * @param[in] fout - the ofstream output file.
 * @param[in] locOut - the current location in the output file.
 * @param[in] onf - the final output name of the file.
 * @param[in] opUsed - the option given from the command line.
 *
 * @par Example:
   @verbatim
   img picture; //picture.magicNumber = "P6"
   ifstream input;
   ofstream output;
   streampos locO;
   string outNameFinal = "balloons.ppm";
   string op = "--flipY";
   fileOutput(picture, input, output, locO, outNameFinal, op);
   //locOut will be set to the location of the end of the header, then
   //the output will be closed, opened in binary, and then writeFileBin 
   //will be called
   @endverbatim

 ***********************************************************************/
void fileOutput(image& img, ifstream& fin, ofstream& fout, streampos locOut,
    string onf, string opUsed)
{
    if (img.magicNumber == "P5" || img.magicNumber == "P6")
    {
        //find where we currently are in the file
        locOut = fout.tellp();
        fout.close(); //close the file
        if (openOutBin(fout, onf) == false) //open file in bin
        {
            cout << "Unable to open output file: " << onf << endl;
            exit(0);
        }
        fout.seekp(locOut);//go to where you were
        writeFileBin(img, fout, opUsed);
    }
    else if (img.magicNumber == "P2" || img.magicNumber == "P3")
    {
        writeFileAscii(img, fout, opUsed);
    }
}



/** *********************************************************************
 * @author Keiran Berry
 *
 * @par Description:
 * This function fills the arrays in the image structure with information 
 * from the file. The type of input is determined by the string magNum. 
 * If the input is binary, then a pointer is set to the end of the header 
 * that has already been read in and then the file will be reopened in 
 * binary. Next, the information will be read into the arrays. If the 
 * input is ascii, then the arrays are directly filled from the file.
 *
 * @param[in] img - the image structure to be written from.
 * @param[in] magNum - the magic number from the input file.
 * @param[in] fin - the ifstream input file.
 * @param[in] fout - the ofstream output file.
 * @param[in] finName - the name of the input file.
 * @param[in] loc - the current location in the output file.
 *
 * @par Example:
   @verbatim
   img picture; //arrays have already been allocated
   string mNumber = "P6";
   ifstream input;
   ofstream output;
   string inName = "balloonsA.ppm";
   streampos location;
   fillArrays(picture, mNumber, input, output, inName, location);
   //location will be set to the location in the input file, then the 
   //file will be opened in binary and fill the arrays with information 
   //starting at location
   @endverbatim

 ***********************************************************************/
void fillArrays(image& img, string magNum, ifstream& fin,
    ofstream& fout, string finName, streampos loc)
{
    int i, j;
    pixel currPix;
    int current;
    if (magNum == "P6")
    {
        loc = fin.tellg();       //if binary, open in binary, skip newline
        fin.close();             //then fill arrays
        openInBin(fin, finName);
        fin.seekg(loc);
        fin.ignore(1);
        allocArray(img);
        for (i = 0; i < img.rows; i++)
        {
            for (j = 0; j < img.cols; j++)
            {
                fin.read((char*)&img.redGray[i][j], sizeof(pixel));
                fin.read((char*)&img.green[i][j], sizeof(pixel));
                fin.read((char*)&img.blue[i][j], sizeof(pixel));
            }
            j = 0;
        }
    }
    else
    {
        allocArray(img);                    //if ascii, fill arrays like normal
        for (i = 0; i < img.rows; i++)
        {
            for (j = 0; j < img.cols; j++)
            {
                fin >> current;
                currPix = current;
                img.redGray[i][j] = currPix;
                fin >> current;
                currPix = current;
                img.green[i][j] = currPix;
                fin >> current;
                currPix = current;
                img.blue[i][j] = currPix;
            }
            j = 0;
        }
    }
}



/** *********************************************************************
 * @author Keiran Berry
 *
 * @par Description:
 * This function checks that the arguments from the command line are 
 * valid. If not, then a usage statement will be sent to the console. 
 * While checking the arguments, strings will be filled with the command 
 * line arguments to be used in various later functions.
 *
 * @param[in] fin - the ifstream input file.
 * @param[in] fout - the ofstream output file.
 * @param[in] numArgs - the argc from main.
 * @param[in] arguments - the argv from main.
 * @param[in] arg1 - the first argument from argv.
 * @param[in] arg2 - the second argument from argv.
 * @param[in] finName - the name of the input file.
 * @param[in] foutName - the name of the output file.
 * @param[in] outType - the type of file which is to be output.
 * @param[in] opUsed - the option for manipulation from the command line.
 *
 * @par Example:
   @verbatim
   ifstream input;
   ofstream output;
   int argc;
   char** argv;
   string firstArg;
   string secondArg;
   string nameIn;
   string nameOut;
   string type;
   string option;
   //command line: thpExam1.exe --flipX --ascii balloons balloonsA.ppm
   validArgs(input, output, argc, argv, firstArg, secondArg, nameIn, 
             nameOut, type, option);
   //since arguments are valid, nothing will output to console
   //nameIn is now "balloonsA.ppm"
   //nameOut is now "balloons"
   //type is now "--ascii"
   //option is now "--flipX"
   @endverbatim

 ***********************************************************************/
void validArgs(ifstream& fin, ofstream& fout, int numArgs, char** arguments,
    string arg1, string arg2, string& finName, string& foutName,
    string& outType, string& opUsed)
{
    bool isArgValid;
    if (numArgs == 4)
    {
        isArgValid = noOption(arg1);
        if (isArgValid != true)
        {
            usageStatement();//if arguments are invalid, send usage statement
            exit(0);
        }
        finName = arguments[3];//with no option the file name is in spot 3
        foutName = arguments[2];
        outType = arguments[1];

    }
    if (numArgs == 5)
    {
        isArgValid = option(arg1, arg2);
        if (isArgValid != true)
        {
            usageStatement();//invalid arguments, send usage statement
            exit(0);
        }
        finName = arguments[4];//with an option the file name is in slot 4
        foutName = arguments[3];
        outType = arguments[2];
        opUsed = arguments[1];
    }
    if (numArgs != 4 && numArgs != 5)//wrong num of arguments, send usage
    {
        usageStatement();
        exit(0);
    }
}