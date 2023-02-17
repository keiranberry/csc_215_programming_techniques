/** **************************************************************************
 * @file
 *
 * @brief  Nico's Functions
 ****************************************************************************/
#include "thpExam2.h"


 /** **********************************************************************
  *  @author Nicolas AD. Alvarez
  *
  *  @par Description
  *  Creates a linked list
  *
  *  @par Example
  *  @verbatim

     list words;
     //an empty list is created, and headptr is initialized to nullptr

     @endverbatim
  ************************************************************************/
list::list()
{
//setting headptr to nullptr
    headptr = nullptr;
}


/** **********************************************************************
  *  @author Nicolas AD. Alvarez
  *
  *  @par Description
  *  deletes a linked list
  *
  *  @par Example
  *  @verbatim

     list words;
     //an empty list is created, and headptr is initialized to nullptr

     @endverbatim
  ************************************************************************/
list::~list()
{
    node* temp;
//while-loop deletes nodes until headptr equals nullptr
    while( headptr != nullptr )
    {
        temp = headptr;
        headptr = temp->next;
        delete temp;
    }
}


/** *************************************************************************
 * @author Nicolas AD. Alvarez
 *
 * @par Description:
 * Checks is a linked list is empty and returns a bool
 *
 *
 * @returns a boolean value, true if the linked list is empty and false if
 * it isn't
 *
 * @verbatim
 * list words;
 * bool empty;
 * 
   list.insert("hello");
   empty = words.isEmpty();   //empty will be set to false

   @endverbatim
 *
 ***************************************************************************/
bool list::isEmpty()
{
//if headptr points to nullptr then the list is empty
    if( headptr == nullptr )
    {
        return true;
    }
    return false;
}


/** *************************************************************************
 * @author Nicolas AD. Alvarez
 *
 * @par Description:
 * Removes the punctuation from the beginning and the end of a word and
 * sets all characters to lowercase
 *
 *
 * @param[in] word a string to be used for the function
 *
 * @verbatim
 * string word = "..."Yes!!
 *
   checkString( word )  //word will be set to "yes"

   @endverbatim
 *
 ***************************************************************************/
void checkString( string &word )
{
//declaring variables
    int size = int( word.size() );
    int i;
    //while loop deletes a character from the beginning of the string as long
    //as it is a punctuation
    while( word.length() != 0 && ispunct( word[0] ) != 0 )
    {
        word.erase( 0, 1 );
        size -= 1;
    }
    //while loop deletes a character from the end of the string as long
    //as it is a punctuation
    while( word.length() != 0 && ispunct( word[size - 1] ) != 0 )
    {
        word.erase( ( size - 1 ), 1 );
        size -= 1;
    }
    //for loop sets every charater in the string to lowercase
    if( word.length() != 0 )
    {
        for( i = 0; i < size; i++ )
        {
            word[i] = tolower( word[i] );
        }
    }

    return;
}


/** **********************************************************************
 *  @author Nicolas AD. Alvarez
 *
 *  @par Description
 *  Closes files.
 *
 *  @param[in] fin the input file to be closed.
 *  @param[in] fout the output file to be closed.
 *  @param[in] stats the statistics file to be closed.
 *
 *
 *  @par Example
 *  @verbatim

    fin.open( "..." ) 
    fout.open( "..." )
    stats.open( "..." )

    cleanup( fin, fout, stats )
    //the files close

    @endverbatim
 ************************************************************************/
void closeFiles( ifstream& fin, ofstream& fout, ofstream& stats )
{
    //closing the input and output files
    fin.close();
    fout.close();
    stats.close();
}