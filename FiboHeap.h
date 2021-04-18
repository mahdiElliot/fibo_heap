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
        void *leafIndex;
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

    CircularDoubleLinkedList<Node *> leafs;

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

    Node *deleteKey(Node *x);

    void unionHeap(FiboHeap<T> &h);

    void decreaseKey(int key, Node *x);

    void increaseKey(int key, Node *x);

    void changeKey(int key, Node *x);

    void prune(int r);
};

#include "FiboHeap.cpp"
#endif