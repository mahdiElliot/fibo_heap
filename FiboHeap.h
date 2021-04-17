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
        int key;
        bool mark;
        T data;

    public:
        CircularDoubleLinkedList<Node *> children;

        Node(int key, T data);
        Node(int key, T data, bool mark);
        Node(int key, T data, bool mark, CircularDoubleLinkedList<Node *> &children);
        ~Node();

        int getKey();

        T getData();
        void setData(T data);

        bool getMark();
    };

    int size;
    int n;
    CircularDoubleLinkedList<Node *> rootList;

    void consolidate(int degree);

    void findNewMin();

public:
    FiboHeap();
    ~FiboHeap();

    void insert(int key, T data);

    Node *minimum();

    Node *extractMin();
};

#include "FiboHeap.cpp"
#endif