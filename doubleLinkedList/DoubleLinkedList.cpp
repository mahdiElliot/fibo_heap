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
    if (l == NULL)
        return;

    NODE *p = l->next;
    if (p == NULL)
    {
        delete l;
        l = NULL;
        return;
    }

    while (p != l)
    {
        NODE *q = p->next;
        if (q == NULL)
        {
            delete p;
            p = NULL;
            delete l;
            l = NULL;
            return;
        }
        delete p;
        p = q;
    }
    if (p != l)
    {
        delete l;
        l = NULL;
    }
    delete p;
    p = NULL;
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
typename DoubleLinkedList<T>::NODE *DoubleLinkedList<T>::castToNode(void *p)
{
    if (p == NULL)
        return NULL;
    return (NODE *)p;
}

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
void DoubleLinkedList<T>::del(NODE *p)
{
    if (p == NULL)
        return;

    size--;
    if (p == l)
    {
        if (l->next != NULL)
        {
            l = l->next;
            l->prev = NULL;
        }
        else
            l = NULL;
        delete p;
        p = NULL;
    }
    else
    {
        NODE *q = p->next;
        if (q != NULL)
            q->prev = p->prev;

        p->prev->next = q;

        delete p;
        p = NULL;
    }
}

template <class T>
T DoubleLinkedList<T>::retrieve(NODE *p)
{
    if (p == NULL)
        return (T)NULL;

    return p->data;
}

template <class T>
void DoubleLinkedList<T>::changeData(T data, NODE *p)
{
    if (p == NULL)
        return;
    p->data = data;
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

template <class T>
void DoubleLinkedList<T>::concat(DoubleLinkedList<T> &list)
{
    NODE *head = list.first();

    if (head == NULL)
        return;

    if (l == NULL)
    {
        l = head;
        return;
    }

    NODE *p = l;
    while (p->next != NULL)
        p = p->next;
    p->next = head;
    head->prev = p;
    list.l = NULL;
    size += list.size;
    list.size = 0;
}

template <class T>
void DoubleLinkedList<T>::display()
{
    if (isEmpty())
        return;
    std::cout << first()->data << " ";
    NODE *p = next(first());
    while (p != NULL && p != l)
    {
        std::cout << p->data << " ";
        p = p->next;
    }

    std::cout << '\n';
}
