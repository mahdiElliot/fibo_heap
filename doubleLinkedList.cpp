#include <iostream>
#include "./doubleLinkedList/circularDoubleLinkedList/CircularDoubleLinkedList.h"

using namespace std;

int main()
{
    CircularDoubleLinkedList<int> list;
    list.insert(5,list.first());
    list.insert(10,list.first());
    list.insert(34,list.next(list.first()));
    // cout<<list.retrieve(list.prev(list.next(list.next(list.first()))));
    // cout<<list.retrieve(list.prev(list.first()));
    cout<<list.retrieve(list.prev(list.prev(list.first())))<<endl;

    // list.makeEmpty();
    // cout<<list.retrieve(list.first())<<endl;
    return 0;
}