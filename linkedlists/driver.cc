#include "LinkedList.h"
#include <iostream>
#include <memory>

int main()
{ 
    std::cout << "BLOCK 1\n";
    auto ll = std::make_unique<LinkedList<int>>();
    ll->addToEnd(5);
    ll->addToEnd(12);
    ll->addToStart(42);
    ll->insertAfter(5, 7);
    ll->insertBefore(7, 21);
    ll->print();

    std::cout << "\nBLOCK 2\n";
    ll->deleteAt(7);
    ll->deleteAt(42);
    ll->print();

    std::cout << std::boolalpha << ll->hasLoop() << std::endl;
}
