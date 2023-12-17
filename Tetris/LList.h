#pragma once

#ifndef INT_LINKED_LIST
#define INT_LINKED_LIST
#include <iostream>
#include <string>
using namespace std;

class LLNode
{
public:
    LLNode()
    {
        next = 0;
    }
    LLNode(string el, LLNode* ptr = 0)
    {
        info = el;
        next = ptr;
    }

    string info;
    LLNode* next;
};

class LList
{
public:
    LList()
    {
        head = 0;
        tail = 0;
        size = 0;
    }

    ~LList();

    int isEmpty()
    {
        return head == 0;
    }

    int GetSize(void);
    string GetAt(int);
    void ReplaceInfoAtNode(int, string);
    void addToHead(string);
    void addToMiddle(int, string);
    void addToTail(string);
    string deleteFromHead();
    string deleteFromTail();
    void deleteNode(string);
    bool isInList(string) const;
    void printAll() const;

private:
    LLNode* head, * tail;
    int size;
};

#endif