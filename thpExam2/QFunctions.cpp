/** **************************************************************************
 * @file
 * 
 * @brief Quinten's Functions
 ****************************************************************************/

#include "thpExam2.h"

/** ***************************************************************************
 * @author Knight, Quinten David R.
 * 
 * @par Description
 * Inserts passed in string into list, checking that the list is in
 * alphabetical order. If string is already in list then the corresponding
 * frequency is incremented
 *
 * @param[in]   ins - string to be added to list
 * 
 * @returns  true if inserted successfully, false if memory allocation error
 *
 * @par Example
 * @verbatim
   list tempList;
   string ins = "This is a string";
   
   if ( !tempList.insert ( ins ) )
   {
       return -1;
   }

   @endverbatim
 *****************************************************************************/
bool list::insert ( string ins )
{
    //Defining Variables
    node* cur = headptr;
    node* last = nullptr;

    //Allocate node and check that successful
    node *temp = new (nothrow) node;
    if ( temp == nullptr )
        return false;

    //Set up new node
    temp->word = ins;
    temp->frequency = 1;
    temp->next = nullptr;

    //If list is empty
    if ( headptr == nullptr )
    {
        //Set headptr to node and return true
        headptr = temp;
        return true;
    }

    //Traverses until current pointer is no longer less than ins, or to end
    while ( cur != nullptr && ins > cur->word )
    {
        last = cur;
        cur = cur->next;
    }

    //If this word is already in the list
    if ( cur != nullptr && cur->word == ins )
    {
        //Increment frequency of word and return true
        cur->frequency = incrementFreq ( cur->frequency );

        return true;
    }

    //If still at the beginning of the list (less than headptr)
    if ( last == nullptr )
    {
        //Insert node at the beginning
        temp->next = cur;
        headptr = temp;

        return true;
    }
    
    //Insert temp structure
    temp->next = cur;
    last->next = temp;

    return true;
}


/** ***************************************************************************
 * @author Knight, Quinten David R.
 *
 * @par Description
 * Outputs list to specified stream in alphabetical order, outputting a banner
 * for each letter that matches words in the list
 *
 * @param[in, out]   output - stream to output list to
 *
 *
 * @par Example
 * @verbatim
   list tempList;
   string ins = "This is a string";
   
   tempList.insert ( ins );

   tempList.printA ( cout );

   @endverbatim
 *****************************************************************************/
void list::printA ( ostream& output )
{
    //Defining variables
    node* tempptr = headptr;
    char ch = 'a';
    int i = 0;
    
    //While not at the end of the list
    while ( tempptr != nullptr )
    {
        //Set ch equal to the first letter
        ch = tempptr->word.at ( 0 );

        //Output banner
        output << setw ( 80 ) << setfill ( '*' ) << "" << endl;
        output << "* words starting with " << tempptr->word.at(0) << endl;
        output << setw ( 80 ) << "" << setfill ( ' ' ) << endl;

        //While the word matches the character and not at the end of list
        while ( tempptr != nullptr && tempptr->word.at ( 0 ) == ch )
        {
            //Output three words per line while the word matches ch
            for ( i = 0; tempptr != nullptr && i < 3 
                && tempptr->word.at ( 0 ) == ch; ++i )
            {
                output << setw(26) << left << tempptr->word;
                tempptr = tempptr->next;
            }

            //Output newline
            output << endl;
        }

        //Output newline
        output << endl;
    }
}


/** ***************************************************************************
 * @author Knight, Quinten David R.
 *
 * @par Description
 * Outputs list to specified stream in order from most frequent to least, 
 * outputting a banner for each frequency that matches words in the list
 *
 * @param[in, out]   output - stream to output list to
 *
 *
 * @par Example
 * @verbatim
   list tempList;
   string ins = "This is a string";

   tempList.insert ( ins );

   tempList.printF ( cout );

   @endverbatim
 *****************************************************************************/
void list::printF ( ostream& output )
{
    //Defining variables
    node* tempptr = headptr;
    vector <int> freqList;
    vector <int>::iterator it;
    string tempWord;
    int i = 0;

    //Fill vector with frequencies
    getF ( freqList );

    //Set iterator to the begining
    it = freqList.begin ( );

    //While not at the end of the vector
    while ( it != freqList.end ( ) )
    {
        //Output the header
        output << setw ( 80 ) << setfill ( '*' ) << "" << endl;
        output << "* Frequency  " << *it << endl;
        output << setw ( 80 ) << "" << setfill ( ' ' ) << endl;

        //Find the first word that matches the frequency
        tempptr = findF ( *it, tempptr );

        //While not at the end of the list
        while ( tempptr != nullptr )
        {
            //Output 3 words per line while not at the end of file
            for ( i = 0; tempptr != nullptr && i < 3; ++i )
            {
                //Output word
                output << setw(26) << left << tempptr->word;

                //Find next match
                tempptr = findF ( *it, tempptr->next );
            }

            //Output newline
            output << endl;
        }

        //Output newline
        output << endl;

        //Reset tempptr and increment iterator
        tempptr = headptr;
        ++it;
    }
}


/** ***************************************************************************
 * @author Knight, Quinten David R.
 *
 * @par Description
 * Fills passed in vector with frequency of words in list in order from most
 * frequent to least
 *
 * @param[in, out]   freqList - vector to write list of word frequencies to
 *
 *
 * @par Example
 * @verbatim
   list tempList;
   string ins = "This is a string";
   vector<int> freqList;

   tempList.insert ( ins );

   tempList.getL ( freqList );

   @endverbatim
 *****************************************************************************/
void list::getF ( vector<int>& freqList )
{
    //Defining variables
    node* tempptr = headptr;
    int i = 0;
    vector<int>::iterator it = freqList.begin ( );

    //If vector is empty, insert first item
    if ( freqList.empty ( ) )
    {
        freqList.push_back ( tempptr->frequency );
    }

    //Loop to the end of the linked list
    while ( tempptr != nullptr )
    {
        //If frequency is not already in list
        if ( tempptr != nullptr && !count ( freqList.begin ( ),
            freqList.end ( ), tempptr->frequency ) )
        {
            //Input frequency
            freqList.push_back ( tempptr->frequency );
        }

        //Increment tempptr
        tempptr = tempptr->next;
    }

    //Sort in decreasing order
    sort ( freqList.rbegin ( ), freqList.rend ( ) );
    freqList.shrink_to_fit ( );
}


/** ***************************************************************************
 * @author Knight, Quinten David R.
 *
 * @par Description
 * Searches through list, starting at startPtr and returns the location of the
 * first node that matches the specified frequency
 *
 * @param[in]       freq - frequency to look for in nodes
 * @param[in]   startPtr - node to start at
 *
 * @returns  memory location of found node, nullptr if no match found
 *
 * @par Example
 * @verbatim

   @endverbatim
 *****************************************************************************/
list::node* list::findF ( int freq, node* startPtr )
{
    //While ptr not at the end of list
    while ( startPtr != nullptr )
    {
        //If word frequecy matches freq
        if ( startPtr->frequency == freq )
        {
            //Return address
            return startPtr;
        }

        //Increment pointer
        startPtr = startPtr->next;
    }

    //If not found return nullptr
    return nullptr;
}


/** ***************************************************************************
 * @author Knight, Quinten David R.
 *
 * @par Description
 * Outputs list to specified stream in order from longest word to shortest,
 * outputting a banner for each length that matches words in the list
 *
 * @param[in, out]   output - stream to output list to
 *
 *
 * @par Example
 * @verbatim
   list tempList;
   string ins = "This is a string";

   tempList.insert ( ins );

   tempList.printL ( cout );

   @endverbatim
 *****************************************************************************/
void list::printL ( ostream& output )
{
    //Defining variables
    node* tempptr = headptr;
    vector<int> lengthList;
    vector<int>::iterator it;
    int i = 0;

    //Fill vector with lengths
    getL ( lengthList );

    //Set iterator to begining
    it = lengthList.begin ( );

    //While the iterator is not at the end of the list
    while ( it != lengthList.end ( ) )
    {
        //Output the header
        output << setw ( 80 ) << setfill ( '*' ) << "" << endl;
        output << "* length of  " << *it << endl;
        output << setw ( 80 ) << "" << setfill(' ') << endl;

        //Find location of next length match
        tempptr = findL ( *it, tempptr );

        //While not at the end of the linked list
        while ( tempptr != nullptr )
        {
            //Allow 3 words per line
            for ( i = 0; tempptr != nullptr && i < 3; ++i )
            {
                //Output word
                output << setw ( 26 ) << left << tempptr->word;

                //Find next match
                tempptr = findL ( *it, tempptr->next );
            }

            //Output newline
            output << endl;
        }

        //Output newline
        output << endl;

        //Reset tempptr
        tempptr = headptr;

        //Increment iterator
        ++it;
    }
}


/** ***************************************************************************
 * @author Knight, Quinten David R.
 *
 * @par Description
 * Fills passed in vector with lengths of words in list in order from longest
 * to shortest length
 *
 * @param[in, out]   lengList - vector to write list of word lengths to
 *
 *
 * @par Example
 * @verbatim
   list tempList;
   string ins = "This is a string";
   vector<int> lengList;

   tempList.insert ( ins );

   tempList.getL ( lengList );

   @endverbatim
 *****************************************************************************/
void list::getL ( vector<int>& lengList )
{
    //Defining variables
    node* tempptr = headptr;
    int i = 0;
    vector<int>::iterator it = lengList.begin ( );

    //If vector is empty, insert first item
    if ( lengList.empty ( ) )
    {
        lengList.push_back ( int(tempptr->word.length ( )) );
    }

    //Loop to the end of the linked list
    while ( tempptr != nullptr )
    {
        //If frequency is not already in list
        if ( tempptr != nullptr && !count ( lengList.begin ( ),
            lengList.end ( ), tempptr->word.length ( ) ) )
        {
            //Input frequency
            lengList.push_back ( int( tempptr->word.length ( ) ) );
        }

        //Increment pointer
        tempptr = tempptr->next;
    }

    //Sort in decreasing order
    sort ( lengList.rbegin ( ), lengList.rend ( ) );
    lengList.shrink_to_fit ( );
}


/** ***************************************************************************
 * @author Knight, Quinten David R.
 *
 * @par Description
 * Searches through list, starting at startPtr and returns the location of the
 * first node that matches the specified word length
 *
 * @param[in]       leng - word length to look for in nodes
 * @param[in]   startPtr - node to start at
 *
 * @returns  memory location of found node, nullptr if no match found
 *
 * @par Example
 * @verbatim

   @endverbatim
 *****************************************************************************/

list::node* list::findL ( int leng, node* startPtr )
{
    //While not at the end of the list
    while ( startPtr != nullptr )
    {
        //If word length matches leng
        if ( startPtr->word.length ( ) == leng )
        {
            //Return address to node
            return startPtr;
        }

        //Increment pointer
        startPtr = startPtr->next;
    }

    //If not found return nullptr
    return nullptr;
}


/** ***************************************************************************
 * @author Knight, Quinten David R.
 *
 * @par Description
 * Passes in position and walks through list until getting to selected position,
 * returning the address of word at position
 *
 * @param[in]       pos - which node position to walk to
 *
 * @returns   string of word at position, returns nothing if overstepped
 *
 * @par Example
 * @verbatim

   @endverbatim
 *****************************************************************************/

string list::wordAt ( int pos )
{
    //Define variables
    int i = 0;
    node* tempptr = headptr;

    //Increment until at position
    for ( i = 0; tempptr != nullptr && i < pos; ++i )
    {
        tempptr = tempptr->next;
    }

    //If at the end of the list, return null
    if ( tempptr == nullptr )
    {
        return "";
    }

    //Return address of word
    return tempptr->word;
}

/** ***************************************************************************
 * @author Knight, Quinten David R.
 *
 * @par Description
 * Passes in position and walks through list until getting to selected position,
 * returning the address of frequency at position
 *
 * @param[in]       pos - which node position to walk to
 *
 * @returns  value of frequency at position, 0 if overstepped
 *
 * @par Example
 * @verbatim

   @endverbatim
 *****************************************************************************/

int list::freqAt ( int pos )
{
    //Define variables
    int i = 0;
    node* tempptr = headptr;

    //Increment until at position
    for ( i = 0; tempptr == nullptr && i < pos; ++i )
    {
        tempptr = tempptr->next;
    }

    //If at the end of the list
    if ( tempptr == nullptr )
    {
        return 0;
    }

    //Return address of frequency
    return tempptr->frequency;
}