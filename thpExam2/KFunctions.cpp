/** **************************************************************************
 * @file
 *
 * @brief  Keiran's Functions
 ****************************************************************************/
#include "thpExam2.h"



 /** **********************************************************************
  *  @author Keiran Berry
  *
  *  @par Description
  *  Returns the size of a linked list. This is accomplished by stepping 
  *  through each node starting at headptr and incrementing temp by one 
  *  until temp-> next is nullptr. A counter is incremented as temp 
  *  steps through and the final count of nodes is returned at the end.
  *
  *  @returns  An int value, the size of the linked list.
  *
  *
  *  @par Example
  *  @verbatim
     list.insert(1);
     list.insert(2);
     list.insert(3);
     int listSize;

     listSize = list.size();


     //listSize is now 3

     @endverbatim
  ************************************************************************/
int list::size()
{
    node* temp = nullptr;
    temp = headptr;//initialize temp to the beginning
    int count;

    //if headptr is nullptr, then the list is empty
    if (headptr == nullptr)
    {
        return 0;
    }

    //as long as we are not at the end of the list, increment temp and count
    for (count = 1; temp->next != nullptr; count++)
    {
        temp = temp->next;
    }

    return count;
}



/** **********************************************************************
 *  @author Keiran Berry
 *
 *  @par Description
 *  Increments the whatever is passed in by one. This is used to increment 
 *  the frequency of a word by one each time the word is found in the 
 *  input file.
 *
 *  @param[in] currentFreq - the current frequency of the word found.
 *
 *  @returns  An int value, the new current frequency of the word.
 *
 *
 *  @par Example
 *  @verbatim
    int current = 5;
    int newCurrent;
    newCurrent = incrementFreq(current);
    
    //newCurrent is now 6

    @endverbatim
 ************************************************************************/
int list::incrementFreq(int currentFreq)
{
    currentFreq++;
    return currentFreq;
}



/** **********************************************************************
 *  @author Keiran Berry
 *
 *  @par Description
 *  Takes in the desired output type from the console and directs the
 *  program to the correct function/functions to write the files
 *  depending upon what output has been requested.
 *
 *  @param[in] outputType - The type of output which will be written
 *            to the stats file.
 *  @param[in] outputFile - The ostream output file which is to be
 *            written into.
 *  @param[in] baseList - The linked list which is being written to
 *            the file, containing the information for words from the
 *            input file.
 *
 *  @par Example
 *  @verbatim
    string outType = "-f";
    ostream output;
    //baseList class has been declared and linked list has been filled
    //in with word information

    writeStatFile(outType, output, baseList);
    //baseList.printF(output) will be called

    outType = "-lf";

    writeStatFile(outType, output, baseList);
    //baseList.printL(output) will be called
    //baseList.printF(output) will be called

    @endverbatim
 ************************************************************************/
void writeStatFile(string outputType, ostream& outputFile, list& baseList)
{
    if (outputType == "-l")
    {
        //call printL function
        baseList.printL(outputFile);
    }

    else if (outputType == "-f")
    {
        //call printF function
        baseList.printF(outputFile);

    }

    else if (outputType == "-lf")
    {
        //call printL function
        baseList.printL(outputFile);
        //seek to where it ended if we need to

        //call printF function
        baseList.printF(outputFile);
    }

    else if (outputType == "-fl")
    {
        //call printF function
        baseList.printF(outputFile);
        //seek to where it ended if we need to

        //call printL function
        baseList.printL(outputFile);
    }
}



/** **********************************************************************
 *  @author Keiran Berry
 *
 *  @par Description
 *  Checks that the input file has opened successfully.
 *
 *  @param[in] fileIn - The ifstream file input.
 *
 *  @param[in] fileName - The name of the file which is being checked.
 *
 *  @returns  A boolean value, whether the file has opened successfully
 *           or not.
 *
 *
 *  @par Example
 *  @verbatim
    //returns true if the input file has opened successfully

    //returns false if the file has not opened

    @endverbatim
 ************************************************************************/
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



/** **********************************************************************
 *  @author Keiran Berry
 *
 *  @par Description
 *  Checks that the output file has opened successfully.
 *
 *  @param[in] fileOut - The ofstream file output.
 *
 *  @param[in] fileName - The name of the file which is being checked.
 *
 *  @returns  A boolean value, whether the file has opened successfully
 *           or not.
 *
 *
 *  @par Example
 *  @verbatim
    //returns true if the output file has opened successfully

    //returns false if the file has not opened

    @endverbatim
 ************************************************************************/
bool openOutput(ofstream& fileOut, string fileName)
{
    //open the output file
    fileOut.open(fileName);

    //if the output file opened, return true
    if (fileOut.is_open() == true)
    {
        return true;
    }

    //otherwise, return false
    else
    {
        return false;
    }

}



/** **********************************************************************
 *  @author Keiran Berry
 *
 *  @par Description
 *  Checks that the argument provided from the command line for how to
 *  output the information to the output file is a valid option. This
 *  function is only called if there was an option provided, as
 *  otherwise it would just default to outputting by frequency.
 *
 *  @param[in] argIn - the argument to be tested for validity.
 *
 *  @returns  A boolean value, whether the option is valid or not.
 *
 *
 *  @par Example
 *  @verbatim
    string option = "-f";
    bool valid;
    valid = checkArg(option);
    //result would be true

    option = "-inv";
    valid = checkArg(option);
    //result would be false

    @endverbatim
 ************************************************************************/
bool checkArg(string argIn)
{
    if (argIn == "-f")
    {
        return true;
    }

    else if (argIn == "-l")
    {
        return true;
    }

    else if (argIn == "-lf")
    {
        return true;
    }

    else if (argIn == "-fl")
    {
        return true;
    }

    else
    {
        return false;
    }
}