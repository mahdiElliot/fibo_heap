#include "FiboHeap.h"
#include <cmath>

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
FiboHeap<T>::FiboHeap()
{
    this->size = 0;
}

template <class T>
FiboHeap<T>::~FiboHeap()
{
    this->rootList.makeEmpty();
}

template <class T>
int FiboHeap<T>::Size() { return this->size; }

template <class T>
void FiboHeap<T>::insert(int key, T data)
{
    Node *p = new Node(key, data, false);
    p->parent = NULL;
    p->leafIndex = NULL;
    if (this->rootList.isEmpty())
    {
        this->rootList.insert(p, this->rootList.first());
        p->index = this->rootList.first();
    }
    else if (this->rootList.retrieve(this->rootList.first())->getKey() > key)
    {
        Node *q = this->rootList.retrieve(this->rootList.first());
        p->index = this->rootList.first();
        this->rootList.changeData(p, this->rootList.first());
        this->rootList.insert(q, this->rootList.first());
        q->index = this->rootList.next(this->rootList.first());
    }
    else
    {
        this->rootList.insert(p, this->rootList.first());
        p->index = this->rootList.next(this->rootList.first());
    }

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
    Node *f = this->rootList.retrieve(this->rootList.first());
    f->index = minimum;
    this->rootList.changeData(f, this->rootList.castToNode(minimum));
    temp->index = this->rootList.first();
    this->rootList.changeData(temp, this->rootList.first());
}

template <class T>
void FiboHeap<T>::consolidate()
{
    int dn = (log(size + 1)) / (log(2));
    void *arr[dn + 1] = {NULL};
    void *x = this->rootList.first();
    arr[this->rootList.retrieve(this->rootList.first())->children.Size()] = x;

    void *current = this->rootList.next(this->rootList.first());

    while (this->rootList.castToNode(current) != this->rootList.first())
    {

        Node *temp = this->rootList.retrieve(this->rootList.castToNode(current));
        int degree = temp->children.Size();
        x = current;
        while (arr[degree] != NULL)
        {
            Node *temp2 = this->rootList.retrieve(this->rootList.castToNode(arr[degree]));
            if (temp->getKey() < temp2->getKey())
            {
                x = temp->index;
                temp2->parent = temp;
                temp2->mark = false;
                temp->children.insert(temp2, temp->children.first());

                if (temp2->children.isEmpty())
                {
                    this->leafs.insert(temp2, this->leafs.first());
                    temp2->leafIndex =
                        this->leafs.Size() == 1 ? this->leafs.first() : this->leafs.next(this->leafs.first());
                }

                temp2->index = temp->children.next(temp->children.first());
                this->rootList.del(this->rootList.castToNode(arr[degree]));
            }
            else
            {
                x = temp2->index;
                temp->parent = temp2;
                temp->mark = false;
                temp2->children.insert(temp, temp2->children.first());

                if (temp->children.isEmpty())
                {
                    this->leafs.insert(temp, this->leafs.first());
                    temp->leafIndex =
                        this->leafs.Size() == 1 ? this->leafs.first() : this->leafs.next(this->leafs.first());
                }

                temp->index = temp2->children.next(temp2->children.first());
                this->rootList.del(this->rootList.castToNode(current));
                current = temp2->index;
            }
            arr[degree] = NULL;
            degree++;
        }
        arr[degree] = x;

        current = this->rootList.next(this->rootList.castToNode(current));
    }

    findNewMin();
}

template <class T>
typename FiboHeap<T>::Node *FiboHeap<T>::extractMin()
{
    if (this->rootList.isEmpty())
        return NULL;

    Node *ret = minimum();
    if (ret->children.Size())
    {
        ret->children.retrieve(ret->children.first())->parent = NULL;
        void *l = ret->children.retrieve(ret->children.first())->leafIndex;
        if (l != NULL)
            this->leafs.del(this->leafs.castToNode(l));
        ret->children.retrieve(ret->children.first())->leafIndex = NULL;

        void *i = ret->children.next(ret->children.first());
        while (ret->children.castToNode(i) != ret->children.first())
        {
            ret->children.retrieve(ret->children.castToNode(i))->parent = NULL;
            l = ret->children.retrieve(ret->children.castToNode(i))->leafIndex;
            if (l != NULL)
                this->leafs.del(this->leafs.castToNode(l));
            ret->children.retrieve(ret->children.castToNode(i))->leafIndex = NULL;
            i = ret->children.next(ret->children.castToNode(i));
        }
    }
    this->rootList.concat(ret->children);
    this->rootList.del(this->rootList.first());
    size--;
    if (this->rootList.isEmpty())
        return ret;

    findNewMin();

    consolidate();

    return ret;
}

template <class T>
void FiboHeap<T>::unionHeap(FiboHeap<T> &h)
{
    if (h.rootList.isEmpty())
        return;

    Node *temp = this->rootList.retrieve(this->rootList.first());
    Node *temp2 = h.rootList.retrieve(h.rootList.first());
    if (temp2->getKey() < temp->getKey())
    {
        this->rootList.changeData(temp2, this->rootList.first());
        h.rootList.changeData(temp, h.rootList.first());
    }

    this->leafs.concat(h.leafs);
    this->rootList.concat(h.rootList);
    this->size += h.size;
    h.size = 0;
}

template <class T>
void FiboHeap<T>::cut(Node *x)
{
    x->parent->children.del(x->parent->children.castToNode(x->index));
    x->parent = NULL;
    x->mark = false;

    if (x->leafIndex != NULL)
        this->leafs.del(this->leafs.castToNode(x->leafIndex));
    x->leafIndex = NULL;

    this->rootList.insert(x, this->rootList.first());
    x->index = this->rootList.next(this->rootList.first());
}

template <class T>
void FiboHeap<T>::cascadeCut(Node *y)
{
    Node *z = y->parent;
    if (z == NULL)
        return;
    if (!y->mark)
        y->mark = true;
    else
    {
        cut(y);
        cascadeCut(z);
    }
}

template <class T>
void FiboHeap<T>::decreaseKey(int key, Node *x)
{
    if (key >= x->getKey())
        return;

    x->key = key;

    Node *y = x->parent;
    if (y != NULL && x->key < y->key)
    {
        cut(x);
        cascadeCut(y);
    }
    if (x->key < minimum()->key)
    {
        Node *temp = minimum();
        temp->index = x->index;
        this->rootList.changeData(temp, this->rootList.castToNode(temp->index));
        this->rootList.changeData(x, this->rootList.first());
        x->index = this->rootList.next(this->rootList.first());
    }
}

template <class T>
typename FiboHeap<T>::Node *FiboHeap<T>::deleteKey(Node *x)
{
    decreaseKey((int)-INFINITY, x);
    extractMin();
    return x;
}

template <class T>
void FiboHeap<T>::increaseKey(int key, Node *x)
{
    if (key <= x->getKey())
        return;

    deleteKey(x);
    insert(key, x->data);
}

template <class T>
void FiboHeap<T>::changeKey(int key, Node *x)
{
    if (key < x->getKey())
        decreaseKey(key, x);
    else
        increaseKey(key, x);
}

template <class T>
void FiboHeap<T>::prune(int r)
{
    if (r >= size)
        r = size;
    int i = 0;
    while (i < r && !this->leafs.isEmpty())
    {
        Node *q = this->leafs.retrieve(this->leafs.first());
        this->leafs.del(this->leafs.first());
        deleteKey(q);
        i++;
    }
    while (i < r)
    {
        extractMin();
        i++;
    }
}