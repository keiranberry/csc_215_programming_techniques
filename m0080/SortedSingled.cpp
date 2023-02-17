#include "sortedSingle.h"

sortedSingle::sortedSingle(sortedSingle& l)
{
    node* source;
    node* destination;

    if (l.headptr == nullptr)
    {
        headptr = nullptr;
        return;
    }

    headptr = new (nothrow) node;
    headptr->theItem = l.headptr->theItem;
    headptr->next = nullptr;

    source = l.headptr->next;
    destination = headptr;

    while (source != nullptr)
    {
        destination->next = new(nothrow) node;
        destination = destination->next;
        destination->theItem = source->theItem;
        destination->next = nullptr;
        source = source->next;
    }

    return;
}