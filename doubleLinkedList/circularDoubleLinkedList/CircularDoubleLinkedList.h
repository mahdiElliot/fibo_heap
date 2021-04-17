#ifndef _CIRCULARDOUBLELINKEDLIST_H_
#define _CIRCULARDOUBLELINKEDLIST_H_
#include "../DoubleLinkedList.h"

template <class T>
class CircularDoubleLinkedList : public DoubleLinkedList<T>
{
public:
    CircularDoubleLinkedList();
    ~CircularDoubleLinkedList();

    typename DoubleLinkedList<T>::NODE *first();

    typename DoubleLinkedList<T>::NODE *next(typename DoubleLinkedList<T>::NODE *p);

    typename DoubleLinkedList<T>::NODE *prev(typename DoubleLinkedList<T>::NODE *p);

    bool isEmpty();

    void makeEmpty();

    void insert(T key, typename DoubleLinkedList<T>::NODE *p);

    void del(typename DoubleLinkedList<T>::NODE *p);

    void concat(CircularDoubleLinkedList<T> &list);

    typename DoubleLinkedList<T>::NODE *search(T key);
};

#include "CircularDoubleLinkedList.cpp"

#endif