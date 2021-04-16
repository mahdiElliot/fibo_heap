#include<iostream>
#include "DoubleLinkedList.h"

using namespace std;

class CircularDoubleLinkedList {
    private:

    struct node {
        int data;
        node *next;
        node *prev;
    };

    node *l;
    int size;

    public:

    CircularDoubleLinkedList()
    {
        l=new node;
        l->data=-999;
        l->prev=l;
        l->next=l;
        size=0;
    }

    int Size()  {   return size;    }

    node *first()   {   return l->next;   }

    node *next(node *p)
    {
        if(p == NULL)   return NULL;

        return p->next;
    }

    node *prev(node *p)
    {
        if(p == NULL)   return NULL;

        return p->prev;
    }

    bool isEmpty()
    {
        return l->next == l;
    }

    void makeEmpty()
    {
        node *p=l->next;
        while(p!=l)
        {  
            node *q=p->next;
            delete p;
            p=q;
        }
        l->next=l;
    }

    void insert(int key , node *p)
    {
        size++;

        node *q=new node;
        q->data=key;
        q->next=p->next;
        q->prev=p;
        p->next->prev=q;
        p->next=q;

        if(q->next == l)
            l->prev=q;
    }

    void del(node *p)
    {
        if(l->next=l)   return;

        size--;

        node *q=p->next;

        p->prev->next=q;
        q->prev=p->prev;
        
        delete p;
        p=q;
    }

    int retrieve(node *p)
    {
        return p->data;
    }

    node *search(int key)
    {
        node *p=l->next;

        while(p!=l)
        {
            if(p->data == key)
                return p;
            p=p->next;
        }

        return p;
    }
};

int main()
{
    DoubleLinkedList<int> l;
    l.insert(8,l.first());
    l.insert(12,l.first());
    l.insert(25,l.next(l.first()));
    l.reverse();
    cout<<l.retrieve(l.first())<<endl;

    // CircularDoubleLinkedList list;
    // list.insert(5,list.first());
    // list.insert(10,list.first());
    // list.insert(34,list.next(list.first()));
    // cout<<list.retrieve(list.prev(list.prev(list.first())))<<endl;

    // list.makeEmpty();
    // cout<<list.retrieve(list.first())<<endl;
    return 0;
}