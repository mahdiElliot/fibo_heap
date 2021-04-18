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
    heap.prune(3);
    // cout << heap.extractMin()->getKey() << endl;
    cout<<heap.Size()<<endl;
    // cout << heap.extractMin()->getKey() << endl;
    // cout << heap.extractMin()->getKey() << endl;
    // cout << heap.extractMin()->getKey() << endl;
    // cout << heap.extractMin()->getKey() << endl;

    // cout << heap.rootList.retrieve(heap.rootList.next(heap.rootList.first()))->getKey() << endl;
    // cout << heap.rootList.Size() << endl;
    // cout << heap.rootList.retrieve(heap.rootList.first())->children.first()->data->getKey() << endl;
    // heap.decreaseKey(2, heap.rootList.retrieve(heap.rootList.first()));
    // heap.decreaseKey(1, heap.rootList.retrieve(heap.rootList.next(heap.rootList.first())));
    // heap.decreaseKey(2, heap.rootList.retrieve(heap.rootList.first())->children.first()->data);
    // heap.deleteKey(heap.rootList.retrieve(heap.rootList.first())->children.first()->data);
    // cout << heap.minimum()->getKey() << endl;
    // cout<<heap.Size()<<endl;
    // cout << heap.rootList.Size() << endl;
    // FiboHeap<int> heap2;
    // heap.insert(19, 90);
    // heap.insert(1, 21);

    // heap.unionHeap(heap2);
    // cout << heap.extractMin()->getKey() << endl;
    // cout << heap.extractMin()->getKey() << endl;
    // cout << heap.extractMin()->getKey() << endl;
    // cout << heap.extractMin()->getKey() << endl;
    // cout << heap.extractMin()->getKey() << endl;
    // cout << heap.extractMin()->getKey() << endl;
    // cout << heap.extractMin()->getKey() << endl;
    // cout << heap.extractMin()->getKey() << endl;
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