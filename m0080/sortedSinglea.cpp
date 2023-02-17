#include "sortedSingle.h"



sortedSingle::sortedSingle()
{
    headptr = nullptr;
}



sortedSingle::~sortedSingle()
{
    node* temp;
    
    while (headptr != nullptr)
    {
        temp = headptr;
        headptr = temp->next;
        delete temp;
    }
}




bool sortedSingle::empty()
{
    if (headptr == nullptr)
    {
        return true;
    }

    return false;
}



int sortedSingle::size()
{
    node* temp = nullptr;
    temp = headptr;
    int count;

    if (headptr == nullptr)
    {
        return 0;
    }

    for (count = 1; temp->next != nullptr; count++)
    {
        temp = temp->next;
    }

    return count;
}



bool sortedSingle::find(int item)
{
    node* temp = nullptr;
    temp = headptr;
    bool found = false;

    while (temp != nullptr)
    {
        if (temp->theItem == item)
        {
            found = true;
        }
        temp = temp->next;
    }

    return found;
}



int sortedSingle::retrievePosition(int item)
{
    node* temp = nullptr;
    temp = headptr;
    int where = 1;

    while (temp != nullptr)
    {
        if (temp->theItem == item)
        {
            return where;
        }
        temp = temp->next;
        where++;
    }

    return 0;
}
