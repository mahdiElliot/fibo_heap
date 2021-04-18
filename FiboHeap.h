#ifndef _FIBOHEAP_H_
#define _FIBOHEAP_H_
#include "doubleLinkedList/circularDoubleLinkedList/CircularDoubleLinkedList.h"

template <class T>
class FiboHeap
{
private:
    class Node
    {
    private:
        T data;

    public:
        Node *parent;
        int key;
        bool mark;
        void *index;
        CircularDoubleLinkedList<Node *> children;

        Node(int key, T data);
        Node(int key, T data, bool mark);
        Node(int key, T data, bool mark, CircularDoubleLinkedList<Node *> &children);
        ~Node();

        int getKey();

        T getData();
        void setData(T data);
    };

    int size;

    void consolidate();

    void findNewMin();

    void cut(Node *x);

    void cascadeCut(Node *y);

public:
    CircularDoubleLinkedList<Node *> rootList;

    FiboHeap();
    ~FiboHeap();

    int Size();

    void insert(int key, T data);

    Node *minimum();

    Node *extractMin();

    void unionHeap(FiboHeap<T> &h);

    void decreaseKey(int key, Node *x);
};

#include "FiboHeap.cpp"
#endif