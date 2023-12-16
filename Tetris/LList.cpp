#include "LList.h"
#include <string>

LList::~LList()
{
    for (LLNode* p; !isEmpty(); )
    {
        p = head->next;
        delete head;
        head = p;
    }
}

void LList::addToHead(string el)
{
    head = new LLNode(el, head);
    if (tail == 0)
    {
        tail = head;
    }

    size++;
}

void LList::addToMiddle(int x, string el)
{
    LLNode* newNode = new LLNode(el);
    LLNode* tmp = head;

    if (x >= 1 && x <= size)
    {
        size++;

        for (int i = 1; i < (x - 1) && tmp != NULL; i++)
        {
            tmp = tmp->next;
        }

        newNode->next = tmp->next;
        tmp->next = newNode;
    }
}

void LList::addToTail(string el)
{
    if (tail != 0)
    {
        tail->next = new LLNode(el);
        tail = tail->next;
    }
    else
    {
        head = tail = new LLNode(el);
    }

    size++;
}

string LList::GetAt(int x)
{
    LLNode* tmp = head;

    if (x >= 1 && x <= size)
    {
        for (int i = 1; i < x && tmp != NULL; i++)
        {
            tmp = tmp->next;
        }

        return tmp->info;
    }

    return "0cb7c3e488b4184f68801f9898e63b4471dfe1d72487e3046de60c105cc4b043"; // sha-256 hash, for edge cases
}

void LList::ReplaceInfoAtNode(int x, string line)
{
    LLNode* tmp = head;

    for (int i = 1; i < x && tmp != NULL; i++)
    {
        tmp = tmp->next;
    }

    tmp->info = line;
}

int LList::GetSize()
{
    return size;
}

string LList::deleteFromHead()
{
    string el = head->info;
    LLNode* tmp = head;

    if (head == tail)
    {
        head = tail = 0;
    }
    else
    {
        head = head->next;
    }

    delete tmp;
    size--;
    return el;
}

string LList::deleteFromTail()
{
    string el = tail->info;

    if (head == tail)
    {
        delete head;
        head = tail = 0;
    }
    else
    {
        LLNode* tmp;

        for (tmp = head; tmp->next != tail; tmp = tmp->next);

        delete tail;
        tail = tmp;
        tail->next = 0;
    }

    size--;
    return el;
}

void LList::deleteNode(string el)
{
    if (head != 0)
    {
        if (head == tail && el == head->info)
        {
            delete head;
            head = tail = 0;
        }
        else if (el == head->info)
        {
            LLNode* tmp = head;
            head = head->next;
            delete tmp;
        }
        else
        {
            LLNode* pred, * tmp;

            for (pred = head, tmp = head->next;
                tmp != 0 && !(tmp->info == el);
                pred = pred->next, tmp = tmp->next);

            if (tmp != 0)
            {
                pred->next = tmp->next;

                if (tmp == tail)
                {
                    tail = pred;
                }

                delete tmp;
            }
        }
    }
}

bool LList::isInList(string el) const
{
    LLNode* tmp;

    for (tmp = head; tmp != 0 && !(tmp->info == el); tmp = tmp->next);

    return tmp != 0;
}

void LList::printAll() const
{
    for (LLNode* tmp = head; tmp != 0; tmp = tmp->next)
    {
        cout << tmp->info << " ";
    }

    cout << endl;
}