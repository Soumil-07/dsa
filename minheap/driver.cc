#include <iostream>
#include "MinHeap.h"

int main()
{
    MinHeap<int> heap;
    heap.insert(5);
    heap.insert(3);
    heap.insert(8);
    heap.insert(1);

    while (!heap.empty())
    {
        auto top = heap.top();
        if (top)
        {
            std::cout << *top << " ";
        }
        else
        {
            std::cout << "Heap is empty";
        }

        heap.pop();
    }
    std::cout << std::endl;

    return 0;
}
