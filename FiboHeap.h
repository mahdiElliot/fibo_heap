#ifndef _FIBOHEAP_H_
#define _FIBOHEAP_H_
#include "doubleLinkedList/circularDoubleLinkedList/CircularDoubleLinkedList.h"
template <class T>
class FiboHeap
{
private:
    struct node {
        T data;
        node **chid;
    }

    typedef node NODE;

    NODE *min;
    CircularDoubleLinkedList<NODE> rootList;

public:
    FiboHeap();
    ~FiboHeap();

    void insert(T data);



};
#endif