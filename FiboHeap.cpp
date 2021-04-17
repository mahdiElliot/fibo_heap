#include "FiboHeap.h"

template <class T>
FiboHeap<T>::Node::Node(int key, T data)
{
    this->key = key;
    this->data = data;
}

template <class T>
FiboHeap<T>::Node::Node(int key, T data, bool mark)
{
    this->key = key;
    this->data = data;
    this->mark = mark;
}

template <class T>
FiboHeap<T>::Node::Node(int key, T data, bool mark, CircularDoubleLinkedList<Node *> &children)
{
    this->key = key;
    this->data = data;
    this->mark = mark;
    this->children = children;
}

template <class T>
FiboHeap<T>::Node::~Node() {}

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
bool FiboHeap<T>::Node::getMark()
{
    return this->mark;
}

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
        this->rootList.changeData(p, this->rootList.first());
        this->rootList.insert(q, this->rootList.first());
    }
    else
        this->rootList.insert(p, this->rootList.first());

    this->size++;
}

template <class T>
typename FiboHeap<T>::Node *FiboHeap<T>::minimum()
{
    if (this->rootList.isEmpty())
        return NULL;

    return this->rootList.retrieve(this->rootList.first());
}

template <class T>
void FiboHeap<T>::findNewMin()
{
    void *minimum = this->rootList.first();
    void *first = this->rootList.next(this->rootList.first());
    while (this->rootList.castToNode(first) != this->rootList.first())
    {
        Node *temp = this->rootList.retrieve(this->rootList.castToNode(first));
        int k = temp->getKey();
        if (k < this->rootList.retrieve(this->rootList.castToNode(minimum))->getKey())
            minimum = first;

        first = this->rootList.next(this->rootList.castToNode(first));
    }

    Node *temp = this->rootList.retrieve(this->rootList.castToNode(minimum));
    this->rootList.changeData(
        this->rootList.retrieve(this->rootList.first()),
        this->rootList.castToNode(minimum));
    this->rootList.changeData(temp, this->rootList.first());
}

template <class T>
void FiboHeap<T>::consolidate(int degree)
{
    void *arr[degree + 1] = {NULL};
    void *x = this->rootList.first();
    arr[this->rootList.retrieve(this->rootList.castToNode(x))->children.Size()] = x;

    void *first = this->rootList.next(this->rootList.first());
    // std::cerr << this->rootList.retrieve(this->rootList.first())->getKey() << "\n";

    while (this->rootList.castToNode(first) != this->rootList.first())
    {
        Node *temp = this->rootList.retrieve(this->rootList.castToNode(first));
        if (arr[temp->children.Size()] == NULL)
            arr[temp->children.Size()] = first;
        else
        {
            Node *temp2 = this->rootList.retrieve(this->rootList.castToNode(arr[temp->children.Size()]));
            if (temp->getKey() < temp2->getKey())
            {
                temp->children.insert(temp2, temp->children.first());
                this->rootList.del(this->rootList.castToNode(arr[temp->children.Size()]));
                first = this->rootList.next(this->rootList.castToNode(first));
            }
            else
            {
                temp2->children.insert(temp, temp2->children.first());
                x = first;
                first = this->rootList.next(this->rootList.castToNode(first));
                this->rootList.del(this->rootList.castToNode(x));
            }
        }
    }
}

template <class T>
typename FiboHeap<T>::Node *FiboHeap<T>::extractMin()
{
    if (this->rootList.isEmpty())
        return NULL;

    Node *ret = minimum();
    int degree = ret->children.Size();
    this->rootList.concat(ret->children);
    this->rootList.del(this->rootList.first());
    size--;
    if (this->rootList.isEmpty())
        return ret;

    findNewMin();

    consolidate(degree);

    return ret;
}