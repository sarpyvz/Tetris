#pragma once


#include <iostream>
using namespace std;

template <class T>
class LLNode
{
public:
    LLNode()
    {
        next = nullptr;
    }
    LLNode(T el, LLNode<T>* ptr = 0)
    {
        info = el;
        next = ptr;
    }

    T info;
    LLNode<T>* next;
};

template<class T>
class LList
{
public:
    LList()
    {
        head = nullptr;
        tail = nullptr;
        size = 0;
    }

    ~LList();

    int isEmpty()
    {
        return head == 0;
    }

    int GetSize(void);
    T GetAt(int);
    void ReplaceInfoAtNode(int, T);
    void addToHead(const T &el);
    void addToMiddle(int, T);
    void addToTail(const T &el);
    T deleteFromHead();
    T deleteFromTail();
    void deleteNode(const T);
    bool isInList(const T &el) const;
    void printAll() const;
    T begin();
    T end();


private:
    LLNode<T> *head, * tail;
    int size;
};


