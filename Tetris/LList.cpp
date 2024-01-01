#include "LList.h"

template <class T>
LList<T>::~LList()
{
    for (LLNode<T>* p; !isEmpty(); )
    {
        p = head->next;
        delete head;
        head = p;
    }
}

template <class T>
void LList<T>::addToHead(const T &el)
{
    head = new LLNode(el, head);
    if (tail == 0)
    {
        tail = head;
    }

    size++;
}

template <class T>
void LList<T>::addToMiddle(int x, T el)
{
    LLNode<T>* newNode = new LLNode(el);
    LLNode<T>* tmp = head;

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

template <class T>
void LList<T>::addToTail(const T &el)
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

template <class T>
T LList<T>::GetAt(int x)
{
    LLNode<T>* tmp = head;

    if (x >= 1 && x <= size)
    {
        for (int i = 1; i < x && tmp != NULL; i++)
        {
            tmp = tmp->next;
        }

        return tmp->info;
    }

    // return "0cb7c3e488b4184f68801f9898e63b4471dfe1d72487e3046de60c105cc4b043"; // sha-256 hash, for edge cases
}

template <class T>
void LList<T>::ReplaceInfoAtNode(int x, T line)
{
    LLNode<T>* tmp = head;

    for (int i = 1; i < x && tmp != NULL; i++)
    {
        tmp = tmp->next;
    }

    tmp->info = line;
}

template <class T>
int LList<T>::GetSize()
{
    return size;
}

template <class T>
T LList<T>::deleteFromHead()
{
    T el = head->info;
    LLNode<T>* tmp = head;

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

template <class T>
T LList<T>::deleteFromTail()
{
    T el = tail->info;

    if (head == tail)
    {
        delete head;
        head = tail = 0;
    }
    else
    {
        LLNode<T>* tmp;

        for (tmp = head; tmp->next != tail; tmp = tmp->next);

        delete tail;
        tail = tmp;
        tail->next = 0;
    }

    size--;
    return el;
}

template <class T>
void LList<T>::deleteNode(const T el)
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
            LLNode<T>* tmp = head;
            head = head->next;
            delete tmp;
        }
        else
        {
            LLNode<T>* pred, * tmp;

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

template <class T>
bool LList<T>::isInList(const T &el) const
{
    LLNode<T>* tmp;

    for (tmp = head; tmp != 0 && !(tmp->info == el); tmp = tmp->next);

    return tmp != 0;
}

template <class T>
void LList<T>::printAll() const
{
    for (LLNode<T>* tmp = head; tmp != 0; tmp = tmp->next)
    {
        cout << tmp->info << " ";
    }

    cout << endl;
}

template <class T>
T LList<T>::begin()
{
    return LList<T>::GetAt(0);
}

template <class T>
T LList<T>::end()
{
    return LList<T>::GetAt(size -1 );
}

