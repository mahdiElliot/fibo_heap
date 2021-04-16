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
        T data;

    public:
        CircularDoubleLinkedList<Node *> children;

        Node(int key, T data);
        ~Node();

        int getKey();
        
        T getData();
        void setData(T data);
    };

    int size;
    int n;
    CircularDoubleLinkedList<Node *> rootList;

public:
    FiboHeap();
    ~FiboHeap();

    void insert(int key, T data);

    Node *minimum();

    Node *extractMin();
};

#include "FiboHeap.cpp"
#endif