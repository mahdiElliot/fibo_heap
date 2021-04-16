#ifndef _DOUBLELINKEDLIST_H_
#define _DOUBLELINKEDLIST_H_

template <class T>
class DoubleLinkedList
{
private:
    struct node
    {
        T data;
        node *next;
        node *prev;
    };

    typedef node NODE;
    NODE *l;
    int size;

    void reverse1(NODE *&head);

public:
    DoubleLinkedList();

    ~DoubleLinkedList();

    int Size();

    NODE *first();

    NODE *next(NODE *p);

    NODE *prev(NODE *p);

    bool isEmpty();

    void makeEmpty();

    void insert(T key , NODE *p);

    void del(node *&p);

    T retrieve(NODE *p);

    node *search(T key);

    void reverse();
};

#include "DoubleLinkedList.cpp"

#endif