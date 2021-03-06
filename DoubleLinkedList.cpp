#include <iostream>
#include "DoubleLinkedList.h"

template <class T>
DoubleLinkedList<T>::DoubleLinkedList()
{
    this->l = NULL;
    this->size = 0;
}

template <class T>
DoubleLinkedList<T>::~DoubleLinkedList()
{
   makeEmpty();
}

template <class T>
void DoubleLinkedList<T>::reverse1(NODE *&head)
{
    if (head == NULL)
        return;

    if (head->next == NULL)
    {
        head->prev = NULL;
        return;
    }

    NODE *p = head->next;
    reverse1(head->next);
    p->next = head;
    head->prev = p;
    head->next = NULL;
}

template <class T>
int DoubleLinkedList<T>::Size() { return size; }

template <class T>
typename DoubleLinkedList<T>::NODE *DoubleLinkedList<T>::first() { return l; }

template <class T>
typename DoubleLinkedList<T>::NODE *DoubleLinkedList<T>::next(typename DoubleLinkedList<T>::NODE *p)
{
    if (p == NULL)
        return NULL;

    return p->next;
}

template <class T>
typename DoubleLinkedList<T>::NODE *DoubleLinkedList<T>::prev(typename DoubleLinkedList<T>::NODE *p)
{
    if (p == NULL)
        return NULL;

    return p->prev;
}

template <class T>
bool DoubleLinkedList<T>::isEmpty()
{
    return l == NULL;
}

template <class T>
void DoubleLinkedList<T>::makeEmpty()
{
    NODE *p = l;

    while (l != NULL)
    {
        p = l->next;
        delete l;
        l = p;
    }
    delete p;
}

template <class T>
void DoubleLinkedList<T>::insert(T key, NODE *p)
{
    size++;
    NODE *q = new NODE;
    q->data = key;

    if (p == NULL)
    {
        q->next = l;
        q->prev = NULL;

        if (l != NULL)
            l->prev = q;

        l = q;
    }
    else
    {
        q->next = p->next;

        if (p->next != NULL)
            p->next->prev = q;
        q->prev = p;
        p->next = q;
    }
}

template <class T>
void DoubleLinkedList<T>::del(NODE *&p)
{
    if (p == NULL)
        return;

    size--;
    if (p == l)
    {
        l = l->next;
        l->prev = NULL;
        delete p;
        p = l;
    }
    else
    {
        NODE *q = p->next;
        if (q != NULL)
            q->prev = p->prev;

        p->prev->next = q;

        delete p;
        p = q;
    }
}

template <class T>
T DoubleLinkedList<T>::retrieve(NODE *p)
{
    if (p == NULL)
        return -9999;

    return p->data;
}

template <class T>
typename DoubleLinkedList<T>::NODE *DoubleLinkedList<T>::search(T key)
{
    NODE *p = l;
    while (p != NULL)
    {
        if (p->data == key)
            return p;

        p = p->next;
    }

    return NULL;
}

template <class T>
void DoubleLinkedList<T>::reverse()
{
    reverse1(l);

    while (l->prev != NULL) //for sure must be done
        l = l->prev;
}
