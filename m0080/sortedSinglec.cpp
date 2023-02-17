#include "sortedSingle.h"

bool sortedSingle::remove(int item)
{
    node* previous;
    node* current = headptr;
    previous = current;

    if (headptr == nullptr)
    {
        return false;
    }

    while (current != nullptr)
    {
        if (current->theItem == item)
        {
            if (previous == headptr)
            {
                headptr = current->next;
                delete current;
                return true;
            }
            previous->next = current->next;
            delete current;
            return true;
        }
        previous = current;
        current = current->next;

    }
    return false;
}



void sortedSingle::clear()
{
    node* temp;

    while (headptr != nullptr)
    {
        temp = headptr;
        headptr = temp->next;
        delete temp;
    }
}