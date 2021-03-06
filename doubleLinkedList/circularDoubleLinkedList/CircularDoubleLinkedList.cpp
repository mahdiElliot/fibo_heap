#include "CircularDoubleLinkedList.h"
#include "../DoubleLinkedList.h"

template <class T>
CircularDoubleLinkedList<T>::CircularDoubleLinkedList()
{
    this->l = new typename DoubleLinkedList<T>::NODE;
    this->l->prev = this->l;
    this->l->next = this->l;
    this->size = 0;
}

template <class T>
CircularDoubleLinkedList<T>::~CircularDoubleLinkedList()
{
}

template <class T>
typename DoubleLinkedList<T>::NODE *CircularDoubleLinkedList<T>::first()
{
    return this->l->next;
}

template <class T>
typename DoubleLinkedList<T>::NODE *CircularDoubleLinkedList<T>::next(typename DoubleLinkedList<T>::NODE *p)
{
    if (p->next == this->l)
        return first();
    return p->next;
}

template <class T>
typename DoubleLinkedList<T>::NODE *CircularDoubleLinkedList<T>::prev(typename DoubleLinkedList<T>::NODE *p)
{
    if (p->prev == this->l)
        return p->prev->prev;
    return p->prev;
}

template <class T>
void CircularDoubleLinkedList<T>::makeEmpty()
{
    typename DoubleLinkedList<T>::NODE *p = this->l->next;
    while (p != this->l)
    {
        typename DoubleLinkedList<T>::NODE *q = p->next;
        delete p;
        p = q;
    }
    this->l->next = this->l;
}

template <class T>
bool CircularDoubleLinkedList<T>::isEmpty()
{
    return this->l->next == this->l;
}

template <class T>
void CircularDoubleLinkedList<T>::insert(T key, typename DoubleLinkedList<T>::NODE *p)
{
    if (p == NULL)
        p = first();

    this->size++;

    typename DoubleLinkedList<T>::NODE *q = new typename DoubleLinkedList<T>::NODE;
    q->data = key;
    q->next = p->next;
    q->prev = p;
    p->next->prev = q;
    p->next = q;

    if (q->next == this->l)
        this->l->prev = q;
}

template <class T>
void CircularDoubleLinkedList<T>::del(typename DoubleLinkedList<T>::NODE *p)
{
    if (p == NULL || this->l->next == this->l)
        return;

    this->size--;

    typename DoubleLinkedList<T>::NODE *q = p->next;

    p->prev->next = q;
    q->prev = p->prev;

    delete p;
    p = NULL;
}

template <class T>
typename DoubleLinkedList<T>::NODE *CircularDoubleLinkedList<T>::search(T key)
{
    typename DoubleLinkedList<T>::NODE *p = this->l->next;

    while (p != this->l)
    {
        if (p->data == key)
            return p;
        p = p->next;
    }

    return p;
}

template <class T>
void CircularDoubleLinkedList<T>::concat(CircularDoubleLinkedList<T> &list)
{
    if (list.isEmpty())
        return;
    if (isEmpty())
    {
        this->l = list.l;
        return;
    }

    typename DoubleLinkedList<T>::NODE *p = list.first();
    list.l->prev->next = this->l;
    p->prev = this->l->prev;
    this->l->prev->next = p;
    this->l->prev = list.l->prev;
    list.l->next = list.l;
    list.l->prev = list.l;
    this->size += list.size;
    list.size = 0;
}
