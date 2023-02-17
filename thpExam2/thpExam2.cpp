/** *********************************************************************
 * @file
 *
 * @brief demonstrates the implementation of classes and linked lists
 * to sort and display items in a specified order
 ***********************************************************************/

 /** ********************************************************************
 *
 * @mainpage Take Home Programming Exam 2 - Linked Lists/Word Frequency
 *
 * @section course_section Course Information
 *
 * @authors Keiran Berry, Nico Alvarez, Quinten Knight
 *
 * @date April 21, 2022
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
 * @details This program will take in a text file input as well as the names 
 * for two output files. Upon completion of running the program, the output 
 * files will have been created and filled in with data. One file will contain 
 * each unique word found in the text file, organized in alphabetical order, 
 * and the second will contain the statistics of the words as requested from 
 * the console. 
 * 
 * Word statistics in the second output file can either be organized by length,
 * frequency, or a combination of the two, but if no selection was made when 
 * starting the program then the file will default to being organized by 
 * frequency.
 * 
 * Upon opening the text file, each unique word will be read in and set to 
 * lowercase, as well as any punctuation from the beginning or end of the 
 * word being discarded (a hyphen in the middle of the word will stay, for 
 * example). Each of these words is inserted into a linked list, and if the 
 * word is already in the linked list then the frequency of the word will be 
 * incremented by one each time the word shows up again. After every word from 
 * the file has been read in, the output files will be created and filled in 
 * using the data from the linked list.
 *
 * @section compile_section Compiling and Usage
 *
 * @par Compiling Instructions:
 *      None
 *
 * @par Usage:
   @verbatim
   c:\> thpExam2.exe inputfile outputfile statisticsfile
   c:\> thpExam2.exe inputfile outputfile statisticsfile option

     inputfile      - the name of the file to be read in, including extension.
     outputfile     - the name of the file which will be filled alphabetically,
                      including extension.
     statisticsfile - the name of the file which will be filled with length
                      and/or frequency data, including extension.
     option         - selection for how to fill statisticsfile, with valid 
                      options being "-f", "-l", "-lf", and "-fl". If no option
                      is selected, then frequency will be the default organization.
   @endverbatim
 *
 * @par Modifications and Development Timeline:
   @verbatim
   Date          Modification
   ------------  --------------------------------------------------------
   Mar 8, 2022   Begun work on the program
   Mar 31, 2022  Completed work on the program
   Full list of commits and modifications available in Gitlab commit log
   @endverbatim

   Gitlab commit log, <a href = "https://gitlab.cse.sdsmt.edu/csc215/
   spring2022/team16/-/commits/master" target="_blank">
   Click Here.</a>
 *
 ***********************************************************************/
#define CATCH_CONFIG_RUNNER

#include "thpExam2.h"
#include "..\\catch.hpp"

/** *********************************************************************
* @brief Whether testcases will run
************************************************************************/
const bool RUNCATCH = true;

/** *************************************************************************
 * @authors Nico Alvarez, Keiran Berry, Quinten Knight
 *
 * @par Description:
 * This is the starting point to the program.  It will read in each word
 * from a text file and set each character to lowercase along with deleting
 * punctuation from the outside of the word. It will then insert the word into
 * a linked list. If the word already exists in the linked list, then
 * a frequencty counter for the word will be incremented. A Statistics file 
 * and an file containing the words in alphabetical order will be created. The
 * user can designate whether he/she wants the statistics file to contain
 * the frequency of the words, their length, or both. If no option is
 * specified, the stats file will output the frequency by default.
 *
 *
 * @param[in] argc - the number of arguments from the command prompt.
 * @param[in] argv - a 2d array of characters containing the arguments.
 *
 * @returns 0 if the program is run succesfully
 *          0 with an error message specifying what went wrong
 *
 * @verbatim
   thpExam2.exe threepigs.txt worddata.txt stats.txt -f

   //and output file will list all the words in "threepigs.txt" in
   //alphabetical order and a stats file will contain the frequency of
   //each word in the list.
   @endverbatim
 *
 ***************************************************************************/
int main( int argc, char** argv )
{
    Catch::Session session;
    int result;

    if( RUNCATCH )
    {
        result = session.run();
        if( result != 0 )
        {
            cout << "Test cases didn't pass." << endl;
            return result;
        }
    }

    ifstream fin;
    ofstream fout;
    ofstream stats;
    string temp;
    list words;

//Checking for the corect number of command line options
    if( argc != 4 && argc != 5 )
    {
        cout << "Usage: thpExam2.exe inputfile outputfile statisticFile" <<
            " [option]outputType" << endl;
        return 0;
    }
//Checking that the option used is valid if there was an option used
    if (argc == 5 && checkArg(argv[4]) == false)
    {
        cout << "Usage: thpExam2.exe inputfile outputfile statisticFile" <<
            " [option]outputType" << endl;
        return 0;
    }
//opening input and output files
    if( !openInput( fin, argv[1] ) )
    {
        cout << "Unable to open input file: " << argv[1] << endl;
        return 0;
    }
    if( !openOutput( fout, argv[2] ) )
    {
        cout << "Unable to open output file: " << argv[2] << endl;
        return 0;
    }
    if( !openOutput( stats, argv[3] ) )
    {
        cout << "Unable to open statistics file: " << argv[3] << endl;
        return 0;
    }
//reading in words from the input file and assigning them to temp,
//then passing them through checkString function and inserting them 
//into the linked list
    while( fin >> temp )
    {
        checkString( temp );
        if ( temp.length() != 0 )
            words.insert( temp );
    }
//printing the linked list to the text file for output
    words.printA( fout );
//printing the stats by specification to the output file for stats
    if( argc == 4 )
    {
        writeStatFile( "-f", stats, words );
    }
    else
    {
        writeStatFile( argv[4], stats, words );
    }
//closing files are ending the function
    closeFiles( fin, fout, stats );
    return 0;
}
