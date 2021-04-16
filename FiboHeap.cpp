#include "FiboHeap.h"

template <class T>
FiboHeap<T>::FiboHeap()
{
    this->size = 0;
    this->n = 0;
}

template <class T>
FiboHeap<T>::~FiboHeap()
{
    this->rootList.makeEmpty();
}

template <class T>
void FiboHeap<T>::insert(int key, T data)
{
    NODE *p = new NODE;
    p->data = data;
    p->key = key;
    if (this->rootList.isEmpty())
        this->rootList.insert(p, this->rootList.first());
    else if (this->rootList.retrieve(this->rootList.first())->key > key)
    {
        NODE *q = this->rootList.retrieve(this->rootList.first());
        this->rootList.first()->data = p;
        this->rootList.insert(q, this->rootList.first());
    }

    this->size++;
}

template <class T>
typename FiboHeap<T>::NODE *FiboHeap<T>::minimum()
{
    return this->rootList.retrieve(this->rootList.first());
}