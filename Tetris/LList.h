#pragma once


#include <iostream>
#include <string>
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
        info = value;
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
    void addToHead(T);
    void addToMiddle(int, T);
    void addToTail(T);
    T deleteFromHead();
    T deleteFromTail();
    void deleteNode(const T);
    bool isInList(T) const;
    void printAll() const;

private:
    LLNode<T> *head, * tail;
    int size;
};

