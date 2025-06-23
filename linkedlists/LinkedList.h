#ifndef _LL_H_ 
#define _LL_H_ 

template <typename T>
class Node 
{
private:
    T data;
    Node* next;

public:
    Node() = default;

    Node(T data) : data(data), next(nullptr)
    {

    }

    Node(T data, Node* next) : data(data), next(next)
    {
    }

    T getData()
    {
        return data;
    }

    Node* getNext()
    {
        return next;
    }

    void setNext(Node* nxt)
    {
        this->next = nxt;
    }

    // use default copy ctor
};

template<typename T>
class LinkedList
{
private:
    Node<T>* head;

    bool ensureHead(T data);

public:
    ~LinkedList();

    void print();

    void addToEnd(T data);

    void addToStart(T data);

    void insertAfter(T key, T data);

    void insertBefore(T key, T data);

    void deleteAt(T key);

    bool hasLoop();
};

#endif // _LL_H_ 
