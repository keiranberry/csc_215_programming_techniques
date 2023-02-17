/** *********************************************************************
 * @file
 *
 * @brief Takes in an image and manipulates it based on the command line 
 *        arguments.
 ***********************************************************************/

 /** ********************************************************************
 *
 * @mainpage Take Home Programming Exam 1 - Image Manipulation
 *
 * @section course_section Course Information
 *
 * @authors Keiran Berry
 *
 * @date March 5, 2022
 *
 * @par Instructor:
 *         Prof. Schrader
 *
 * @par Course:
 *         CSC 215 - Section 2 - 1:00 pm
 *
 * @par Location:
 *         Classroom - Room 329
 *
 * @section program_section Program Information
 *
 * @details This program will take in either an image, either in binary
 * or ascii format, from a .ppm file. It will then fill a structure with
 * the image's magic number, comment, columns, and rows. Following this,
 * three dynamic arrays will be allocated and filled with the image's 
 * red/gray, green, and blue information for each pixel.
 * 
 * After filling the arrays, the image can be manipulated according to 
 * command line arguments provided when the program began running. Valid
 * options for image manipulation include "--flipX", "--flipY", 
 * "--rotateCW", "--rotateCCW", "--grayscale", and "--sepia".
 * 
 * Upon completion of the image's manipulation, the final image will be 
 * output to a new file, with type (either binary or ascii) and name of
 * the file being determined by command line arguments.
 *
 * @section compile_section Compiling and Usage
 *
 * @par Compiling Instructions:
 *      None
 *
 * @par Usage:
   @verbatim
   c:\> thpExam1.exe --option --outputtype basename image.ppm
   c:\> thpExam1.exe --outputtype basename image.ppm

        option - option for image manipulation, valid options shown above.
        outputType - the type of the output file, either ascii or binary.
        basename - the output file's name, the program adds extensions.
        image.ppm - the name of the input image, extension should be included.
   @endverbatim
 *
 * @par Modifications and Development Timeline:
   @verbatim
   Date          Modification
   ------------  --------------------------------------------------------
   Feb 10, 2022  Begun work on the program 
   Mar 5, 2022   Completed work on the program
   Full list of commits and modifications available in Gitlab commit log
   @endverbatim

   Gitlab commit log, <a href = "https://gitlab.cse.sdsmt.edu/101080740/
   csc215s22programs/-/commits/master" target="_blank">
   Click Here.</a>
 *
 ***********************************************************************/
#include "netPBM.h"

 /** *********************************************************************
  * @author Keiran Berry
  *
  * @par Description:
  * This is the starting point to the program.  It will open the input 
  * file, take in its magic number, comment, columns, rows, and maximum 
  * RGB value, and then fill 3 dynamically allocated arrays with the 
  * RGB values of each pixel. These arrays will be passed into a function 
  * to manipulate the image, and then a new image file will be created 
  * with the desired changes completed.
  *
  * @param[in] argc - the number of arguments from the command prompt.
  * @param[in] argv - a 2d array of characters containing the arguments.
  *
  * @returns 0 function performed properly and output file was created.
  * @returns 0 and error message - something went wrong, see error.
  *
  * @verbatim
    see usage statement above.
    @endverbatim
  *
  ***********************************************************************/
int main(int argc, char** argv)
{
    string firstArg, secondArg, magicNum, fileIn, comm, outName, commOut,
        outNameFinal, outputType, optionUsed;
    streampos location, locationOut;
    ifstream input;
    ofstream output;
    image picture;
    picture.redGray = nullptr;
    picture.green = nullptr;
    picture.blue = nullptr;
    int maxRGB;
    //return parts of argv as strings to be used in later functions
    firstArg = argReturn(argv[1]);
    secondArg = argReturn(argv[2]);
    //check args are valid and extract needed information from them
    validArgs(input, output, argc, argv, firstArg, secondArg, fileIn, outName,
        outputType, optionUsed);

    if (openInBin(input, fileIn) == false)//if input does not open
    {
        cout << "Unable to open input file: " << fileIn << endl;
        return 0; //send statement and exit
    }

    getline(input, magicNum);//take in the magic num from the file

    if (checkMN(magicNum) == false)//if magic num is invalid
    {
        cout << "Invalid magic number in PPM file" << endl;
        input.close();
        return 0;//send statement, close input file, and exit
    }
    //determine the magic num to be used in the output file
    mnOutput(picture, outputType, optionUsed);
    //check for comments (includes multi line comments)
    while (input.peek() == '#')
    {
        if (picture.comment.size() > 0)
        {
            picture.comment = picture.comment + '\n';
        }
        getline(input, comm);
        picture.comment = picture.comment + comm;
    }
    //get columns, rows, and the 255 from the file
    input >> picture.cols;
    input >> picture.rows;
    input >> maxRGB;
    outNameFinal = fOutName(picture.magicNumber, outName);//add file extension

    if (openOutput(output, outNameFinal) == false)//if output does not open
    {
        cout << "Unable to open output file: " << outNameFinal << endl;
        return 0; // send statement and exit
    }
    fillArrays(picture, magicNum, input, output, fileIn, location);
    manipImage(picture, optionUsed);//if option used, execute the option
    //finish filling the output file
    writeHeader(picture, output, optionUsed);//write the header in the output
    //fill r, g, b arrays with information from the input file
    fileOutput(picture, input, output, locationOut, outNameFinal, optionUsed);
    //close input and output, delete dynamic array
    input.close();
    output.close();
    deleteDArray(picture);
    return 0;
}



/** *********************************************************************
 * @author Keiran Berry
 *
 * @par Description:
 * Outputs a usage statement to the console if the incorrect number of 
 * arguments has been provided, or there is otherwise an issue with the 
 * arguments which have been input.
 *
 * @par Example:
   @verbatim
   Input: thpExam1.exe --flipX --ascii balloonOut BalloonsA.ppm
   Output: nothing

   Input: thpExam1.exe thisisanincorrectnumberofarguments
   Output: Usage: thpExam1.exe --outputtype basename image.ppm 
   Or: thpExam1.exe option --outputType basename image.ppm
   @endverbatim
 ***********************************************************************/
void usageStatement()
{//usage statement to output to console if needed
    cout << "Usage: thpExam1.exe --outputtype "
        "basename image.ppm" << endl;
    cout << "   Or: thpExam1.exe option --outputtype "
        "basename image.ppm" << endl;
    cout << "Valid options: '--flipX' '--flipY' '--rotateCW' "
        "'--rotateCCW' '--grayscale' '--sepia'" << endl;
}



/** *********************************************************************
 * @author Keiran Berry
 *
 * @par Description:
 * Returns strings from argv to be used in main, does not mess with them 
 * whatsoever. Only returns a string in order for the argument to be 
 * assigned to a variable.
 *
 * @param[in, out] input - the string from argv to be processed.
 *
 * @returns input, the string which was passed in.
 * @par Example:
   @verbatim
   string outputType;
   argv[2] = "--binary";
   outputType = argReturn(argv[2]);
   //outputType now contains "--binary"
   @endverbatim
 ***********************************************************************/
string argReturn(string input) //returns the argv to be used in main
{
    return input;
}



/** *********************************************************************
 * @author Keiran Berry
 *
 * @par Description:
 * Checks that the argument provided for the output type is valid. This
 * function will only be used if there is no option provided for the 
 * program to use to manipulate the image. In other words, the image is 
 * being passed into the function solely to be output as binary or ascii.
 *
 * @param[in] argIn - the string argument which will be checked.
 *
 * @returns true or false, whether the argument is valid or not.
 * @par Example:
   @verbatim
   string input = "--binary";
   bool valid;
   valid = noOption(input);
   //valid would be true
   input = "binary";
   valid = noOption(input);
   //valid would be false
   @endverbatim
 ***********************************************************************/
bool noOption(string argIn)
{//checks that args are valid if there is no option chosen
    if (argIn == "--binary" || argIn == "--ascii")
    {
        return true;
    }
    else
    {
        return false;
    }
}



/** *********************************************************************
 * @author Keiran Berry
 *
 * @par Description:
 * Checks that the arguments provided for the option and output type are 
 * valid. This function will be used if an option has been selected for 
 * use. In other words, this function will be used if there is some 
 * manipulation to be done to the image.
 *
 * @param[in] argIn - the option argument which will be checked.
 * @param[in] arg2 -  the output type argument which will be checked.
 *
 * @returns true or false, whether the arguments are valid or not.
 * @par Example:
   @verbatim
   string input = "--flipX";
   string input2 = "--binary";
   bool valid;
   valid = option(input, input2);
   //valid would be true
   input = "--invalidoption";
   input2 = "--invalidoutputtype";
   valid = option(input, input2);
   //valid would be false
   @endverbatim
 ***********************************************************************/
bool option(string argIn, string arg2)
{//checks that arguments are valid if there is an option chosen
    bool valid = false;
    if (argIn == "--flipX")
    {
        valid = true;
    }
    else if (argIn == "--flipY")
    {
        valid = true;
    }
    else if (argIn == "--rotateCW")
    {
        valid = true;
    }
    else if (argIn == "--rotateCCW")
    {
        valid = true;
    }
    else if (argIn == "--grayscale")
    {
        valid = true;
    }
    else if (argIn == "--sepia")
    {
        valid = true;
    }
    else
    {
        valid = false;;
    }
    if (valid == true)
    {
        if (arg2 == "--binary" || arg2 == "--ascii")
        {
            return valid;
        }
        else
        {
            valid = false;
        }
    }
    return valid;
}