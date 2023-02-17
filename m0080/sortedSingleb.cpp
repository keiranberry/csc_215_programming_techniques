#include "sortedSingle.h"

bool sortedSingle::insert(int item)
{
    node* current = headptr;
    node* previous = nullptr;
    node* temp = new (nothrow) node;

    if (temp == nullptr)
    {
        return false;
    }

    temp->theItem = item;
    temp->next = nullptr;

    if (headptr == nullptr)
    {
        headptr = temp;
        return true;
    }

    while (current != nullptr && item > current->theItem)
    {
        previous = current;
        current = current->next;
    }

    if (previous == nullptr)
    {
        temp->next = current;
        headptr = temp;
        return true;
    }

    temp->next = current;
    previous->next = temp;
    return true;
}



void sortedSingle::print(ostream& out, string seperator)
{
    node* temp = nullptr;
    temp = headptr;

    while (temp != nullptr)
    {
        out << temp->theItem;
        if (temp->next != nullptr)
        {
            out << seperator;
        }
        temp = temp->next;
    }
}