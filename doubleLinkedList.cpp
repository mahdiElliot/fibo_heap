#include <iostream>
#include "FiboHeap.h"

using namespace std;

int main()
{
    FiboHeap<int> heap;
    heap.insert(5, 70);
    heap.insert(9, 80);
    heap.insert(3, 90);
    heap.insert(15, 21);
    heap.insert(2, 54);
    heap.insert(16, 68);
    // cout<<heap.minimum()->getKey()<<endl;
    cout<<heap.extractMin()->getKey()<<endl;
    cout<<heap.extractMin()->getKey()<<endl;
    cout<<heap.extractMin()->getKey();
    // CircularDoubleLinkedList<int> x;
    // x.insert(4, x.first());
    // x.insert(8, x.first());
    // x.del(x.first());
    // x.insert(6, x.first());
    // x.insert(19, x.first());
    // CircularDoubleLinkedList<int> y;
    // y.insert(9, y.first());
    // y.insert(10, y.first());
    // y.insert(12, y.first());
    // x.concat(y);
    // cout<<x.retrieve(x.next(x.next(x.next(x.next(x.next(x.next(x.first())))))));
    
    return 0;
}