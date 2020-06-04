#ifndef PQTYPE_H_INCLUDED
#define PQTYPE_H_INCLUDED
#include "heaptype.h"
#include "point.h"

class FullPQ
{};
class EmptyPQ
{};
class PQType
{
public:
    PQType(int);
    ~PQType();
    void MakeEmpty();
    bool IsEmpty();
    bool IsFull();
    void Enqueue(point);
    void Dequeue(point&);
private:
    int length;
    
    //HeapType items[maxItems];
    int maxItems;
    
    HeapType* items;
};
#include "pqtype.tpp"
#endif // PQTYPE_H_INCLUDED
