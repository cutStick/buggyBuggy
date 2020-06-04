#include "pqtype.h"
#include "point.h"
PQType::PQType(int max)
{
    maxItems = max;
    point.elements = new items[max];
    length = 0;
}
PQType::~PQType()
{
    delete [] items.elements;
}
void PQType::MakeEmpty()
{
    length = 0;
}
bool PQType::IsEmpty()
{
    return length == 0;
}
bool PQType::IsFull()
{
    return length == maxItems;
}
void PQType::Enqueue(point newItem)
{
    if (IsFull())
        throw FullPQ();
    else
    {
        length++;
        items.elements[length-1] = newItem;
        items.ReheapUp(0, length-1);
    }
}
void PQType::Dequeue(point& item)
{
    if (IsEmpty())
        throw EmptyPQ();
    else
    {
        item = items.elements[0];
        items.elements[0] = items.elements[length-1];
        length--;
        items.ReheapDown(0, length-1);
    }
}
