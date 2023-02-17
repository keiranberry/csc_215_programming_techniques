/** *********************************************************************
 * @file
 *
 * @brief Contains prototypes for functions as well as the template class 
 * queue functions.
 ***********************************************************************/

#pragma once
#include <random>
#include <cmath>
#include <fstream>
#include <iostream>
#include <string>
#include <cctype>
#include <iomanip>
#include <stack>

using namespace std;

/** ********************************************************************
* @brief Structure to be filled in with the card's face value and suit.
***********************************************************************/
struct card
{
/** ********************************************************************
* @brief Int to be filled in with the card's face value
***********************************************************************/
    int faceValue;
/** ********************************************************************
* @brief Int to be filled in with the card's suit
***********************************************************************/
    int suit;
};



/*****************************************************************************
*                     Class Prototype
*****************************************************************************/
/**
 * @brief Class definition for a linked list-based template queue
*/
template <typename TY>
class queue
{
    public: 
        queue();
        ~queue();

        bool enque(TY item);
        bool deque(TY& item);
        bool front(TY& item);
        bool isEmpty();
        int size();

        template <class TY>
        friend ostream& operator<<(ostream& out, queue<TY>& l);
    private:
/**
* @brief Structure containing the information for a queue node
*/
        struct node
        {
            TY value; /**< The template value to be stored in the queue */
            node* next; /**< The pointer to the next node in the queue */
        };
        node* headptr;/**< The address of the first node in the queue */
        node* tailptr;/**< The address of the last node in the queue */

};



/** **********************************************************************
 *  @author Keiran Berry
 *
 *  @par Description
 *  Constructs the linked list-based queue
 ************************************************************************/
template<typename TY>
queue<TY>::queue()
{
    //initialize headptr and tailptr
    headptr = nullptr;
    tailptr = nullptr;
}



/** **********************************************************************
 *  @author Keiran Berry
 *
 *  @par Description
 *  Deconstructs the linked list-based queue
 ************************************************************************/
template<typename TY>
queue<TY>::~queue()
{
    node* temp;

    //delete every node
    while (headptr != nullptr)
    {
        temp = headptr;
        headptr = temp->next;
        delete temp;
    }
}



/** **********************************************************************
 *  @author Keiran Berry
 *
 *  @par Description
 *  Enques the item which is passed in, putting it at the end of the 
 *  queue by putting it where tailptr points.
 *
 *  @param[in] item - the template item which will be enqued
 *
 *  @returns  A boolean value, whether item has been enqued or not.
 *
 *
 *  @par Example
 *  @verbatim
    queue<int> q;
    int item = 1;

    q.enque(1);

    //q.size() is now 1, and the item in the queue is now 1

    @endverbatim
 ************************************************************************/
template<typename TY>
bool queue<TY>::enque(TY item)
{
    node* temp = new(nothrow)node;
    //if temp doesnt allocate leave
    if (temp == nullptr)
    {
        return false;
    }

    //fill in temp
    temp->value = item;
    temp->next = nullptr;

    //if its the first thing, head and tailptr will both be pointing to it
    if (size() == 0)
    {
        headptr = temp;
        tailptr = temp;
    }

    //otherwise put it at tailptr
    else
    {
        tailptr->next = temp;
        tailptr = temp;
    }

    return true;
}



/** **********************************************************************
 *  @author Keiran Berry
 *
 *  @par Description
 *  Changes item to the item which was dequed. Then deques the item at 
 *  the front by deleting its node. 
 *
 *  @param[in] item - the item which will be dequed
 *
 *  @returns  A boolean value, whether item has been dequed or not.
 *
 *
 *  @par Example
 *  @verbatim
    queue<int> q;
    int item;

    bool dequed = q.deque(item);

    //dequed is now false

    q.enque(1);

    changed = q.deque(item);

    //item is now 1 and dequed is true


    //q.size() is now 0

    @endverbatim
 ************************************************************************/
template<typename TY>
bool queue<TY>::deque(TY& item)
{
    node* temp;
    temp = headptr;
    //if there is nothing to deque, leave so we dont crash
    if (temp == nullptr)
    {
        return false;
    }
    item = headptr->value;
    //if there is only one item, set headptr and tailptr to nullptr
    if (size() == 1)
    {
        delete temp;
        headptr = nullptr;
        tailptr = nullptr;
        return true;
    }
    //otherwise just deque it
    else
    {
        headptr = headptr->next;
        delete temp;
        return true;
    }
}



/** **********************************************************************
 *  @author Keiran Berry
 *
 *  @par Description
 *  Changes item to the item in the front of the queue. Also returns a 
 *  boolean value, false if the item has not been filled in and true 
 *  if it has. If the queue is empty and there is no item at the front,
 *  then false is returned. Otherwise, true is returned and item contains 
 *  the value of the item at the front of the list.
 *
 *  @param[in] item - the item which is to be filled by what is at the front
 *
 *  @returns  A boolean value, whether item has been changed or not.
 *
 *
 *  @par Example
 *  @verbatim
    queue<int> q;
    int item;

    bool changed = q.front(item);

    //changed is now false

    q.enque(1);

    changed = q.front(item);

    //item is now 1 and changed is now true


    //qSize is now 3

    @endverbatim
 ************************************************************************/
template<typename TY>
bool queue<TY>::front(TY& item)
{
    //look at the value of headptr
    if (size() == 0)
    {
        return false;
    }

    else
    {
        item = headptr->value;
        return true;
    }
}



/** **********************************************************************
 *  @author Keiran Berry
 *
 *  @par Description
 *  Returns whether a queue is empty or not. This is done by seeing if 
 *  headptr is pointing to nullptr. If it's not, then it is pointing 
 *  to something in the queue which means it isn't empty.
 *
 *  @returns  A boolean value, whether the queue is empty or not.
 *
 *
 *  @par Example
 *  @verbatim
    queue<int> q;
    
    bool empty = q.isEmpty();

    //empty is now true

    q.enque(1);

    empty = q.isEmpty();

    //empty is now false

    @endverbatim
 ************************************************************************/
template<typename TY>
bool queue<TY>::isEmpty()
{
    //if headptr is nullptr, its empty
    if (headptr == nullptr)
    {
        return true;
    }

    return false;
}



/** **********************************************************************
 *  @author Keiran Berry
 *
 *  @par Description
 *  Returns the size of a queue. This is accomplished by stepping
 *  through each node starting at headptr and incrementing temp by one
 *  until temp-> next is nullptr. A counter is incremented as temp
 *  steps through and the final count of nodes is returned at the end.
 *
 *  @returns  An int value, the size of the queue.
 *
 *
 *  @par Example
 *  @verbatim
    queue<int> q;
    q.enque(1);
    q.enque(4);
    q.enque(3);
    int qSize;

    qSize = q.size();


    //qSize is now 3

    @endverbatim
 ************************************************************************/
template<typename TY>
int queue<TY>::size()
{
    //while temp is not nullptr, increment temp and size by one
    node* temp = headptr;
    int count = 0;

    while (temp != nullptr)
    {
        temp = temp->next;
        count++;
    }

    return count;
}



/** **********************************************************************
 *  @author Keiran Berry
 *
 *  @par Description
 *  Outputs a queue to an ostream, using the overloaded operator which 
 *  outputs cards. This just loops outputting cards and clearing the queue 
 *  until there is no more dynamic memory allocated and the whole queue 
 *  has been output.
 *
 *  @param[in] out - the ostream output
 *
 *  @param[in] l - the queue to be output
 *
 *  @returns  An ostream, the output of the operator
 *
 *
 *  @par Example
 *  @verbatim
    queue q;
    //q has been filled

    cout << q;

    // q is output and every 13 cards there is an endl

    @endverbatim
 ************************************************************************/
template <class TY>
ostream& operator<<(ostream& out, queue<TY>& l)
{
    int i = 0;
    TY curr;
    while (!l.isEmpty())
    {
        l.front(curr);
        out << curr;
        l.deque(curr);
        if (i> 0 && i % 13 == 0)
        {
            out << endl;
        }
        i++;
    }

    return out;
}




//prototypes here
void usageStatement();
bool openInput(ifstream& file, string fileName);
bool openOutput(ofstream& file, string fileName);
void dealHands(queue<card>& hand, int seedIn);
void file(ifstream& input, queue<card>& player);
void playRound(queue<card>& player1, queue<card>& player2);
void giveCards(queue<card>& winner, stack<card>& w, stack<card>& l);
void equal(queue<card>& player1, queue<card>& player2,
    stack<card>& p1, stack<card>& p2);
int playGame(queue<card>& player1, queue<card>& player2);
void cOutput(queue<card>& player1, queue<card>& player2, int rounds);
void fOutput(queue<card>& player1, queue<card>& player2, int rounds,
    ofstream& output);
bool operator<(card& c1, card& c2);
bool operator>(card& c1, card& c2);
bool operator==(card& c1, card& c2);
bool operator!=(card& c1, card& c2);
ostream& operator<<(ostream& out, card& l);