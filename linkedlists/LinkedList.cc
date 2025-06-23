#include <iostream>
#include "LinkedList.h"

template <typename T>
LinkedList<T>::~LinkedList()
    {
    auto current = head;
    while (current != nullptr)
    {
        auto next = current->getNext();
        delete current;
        current = next;
    }
}

template <typename T>
void LinkedList<T>::print()
{
    auto node = head;
    while (node != nullptr)
    {
        std::cout << node->getData() << std::endl;
        node = node->getNext();
    }
}

template <typename T>
bool LinkedList<T>::ensureHead(T data)
{
    if (this->head == nullptr)
    {
        this->head = new Node<T>(data);
        return true;
    }

    return false;
}

template <typename T>
void LinkedList<T>::addToEnd(T data)
{
    if (this->ensureHead(data))
        return;

    auto lastNode = head;
    while (lastNode->getNext() != nullptr)
    {
        lastNode = lastNode->getNext();
    }

    auto newLast = new Node<T>(data);
    lastNode->setNext(newLast);
}

template <typename T>
void LinkedList<T>::addToStart(T data)
{
    if (this->ensureHead(data))
        return;

    auto oldHead = this->head;
    this->head = new Node<T>(data);
    this->head->setNext(oldHead);
}

template <typename T>
void LinkedList<T>::insertAfter(T key, T data)
{
    auto node = this->head;
    while (node != nullptr)
    {
        if (node->getData() == key)
        {
            node->setNext(new Node<T>(data, node->getNext()));
            break;
        }
        node = node->getNext();
    }
}

template <typename T>
void LinkedList<T>::insertBefore(T key, T data)
{
    auto node = this->head;
    while (node != nullptr)
    {
        if (node->getNext() != nullptr && node->getNext()->getData() == key)
        {
            node->setNext(new Node<T>(data, node->getNext()));
            break;
        }
        node = node->getNext();
    }
}

template <typename T>
void LinkedList<T>::deleteAt(T key)
{
    if (this->head->getData() == key)
    {
        this->head = this->head->getNext();
        return;
    }

    auto node = this->head;
    while (node != nullptr)
    {
        if (node->getNext() != nullptr && node->getNext()->getData() == key)
        {
            node->setNext(node->getNext()->getNext());
            break;
        }
        node = node->getNext();
    }
}

template <typename T>
bool LinkedList<T>::hasLoop()
{
    auto fastPtr = head, slowPtr = head;

    while (true)
    {
        // one hop for slow slowPtr
        slowPtr = slowPtr->getNext();
        if (fastPtr->getNext() == nullptr)
            return false;
        // two hops for fastPtr
        fastPtr = fastPtr->getNext()->getNext();

        if (!slowPtr || !fastPtr)
            return false;
        if (slowPtr == fastPtr)
            return true;
    }
}

template class LinkedList<int>;
template class Node<int>;

