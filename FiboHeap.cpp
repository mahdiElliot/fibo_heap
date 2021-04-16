#include "FiboHeap.h"

template <class T>
FiboHeap<T>::Node::Node(int key, T data)
{
    this->key = key;
    this->data = data;
}

template <class T>
int FiboHeap<T>::Node::getKey()
{
    return this->key;
}

template <class T>
T FiboHeap<T>::Node::getData()
{
    return this->data;
}

template <class T>
void FiboHeap<T>::Node::setData(T data)
{
    this->data = data;
}

template <class T>
FiboHeap<T>::Node::~Node() {}

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
    Node *p = new Node(key, data);
    if (this->rootList.isEmpty())
        this->rootList.insert(p, this->rootList.first());
    else if (this->rootList.retrieve(this->rootList.first())->getKey() > key)
    {
        Node *q = this->rootList.retrieve(this->rootList.first());
        this->rootList.first()->data = p;
        this->rootList.insert(q, this->rootList.first());
    }

    this->size++;
}

template <class T>
typename FiboHeap<T>::Node *FiboHeap<T>::minimum()
{
    return this->rootList.retrieve(this->rootList.first());
}

template <class T>
typename FiboHeap<T>::Node *FiboHeap<T>::extractMin()
{
    CircularDoubleLinkedList<Node *> children = this->rootList.retrieve(this->rootList.first())->children;
    this->rootList.del(this->rootList.first());
    return NULL;
}