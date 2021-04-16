#ifndef _FIBOHEAP_H_
#define _FIBOHEAP_H_
#include "doubleLinkedList/circularDoubleLinkedList/CircularDoubleLinkedList.h"

template <class T>
class FiboHeap
{
private:
    struct node
    {
        int key;
        T data;
        CircularDoubleLinkedList<node*> rootList;
    };

    typedef node NODE;

    int size;
    int n;
    CircularDoubleLinkedList<node*> rootList;

public:
    FiboHeap();
    ~FiboHeap();

    void insert(int key, T data);

    NODE *minimum();
};

#include "FiboHeap.cpp"
#endif