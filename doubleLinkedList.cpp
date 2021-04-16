#include <iostream>
#include "FiboHeap.h"

using namespace std;

int main()
{
    FiboHeap<int> heap;
    heap.insert(5, 70);
    heap.insert(9, 80);
    heap.insert(3, 90);
    cout<<heap.minimum()->getData();
    cout<<heap.extractMin()->getData();

    return 0;
}