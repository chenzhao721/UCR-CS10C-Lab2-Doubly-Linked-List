#ifndef __INTLIST_H__
#define __INTLIST_H__

#include <iostream>

using namespace std;

struct IntNode {
    int data;
    IntNode *prev;
    IntNode *next;
    IntNode(int data) : data(data), prev(0), next(0) {}
};

class IntList
{
    private:
    IntNode *dummyHead;
    IntNode *dummyTail;

    public:
    IntList()
    {
        dummyHead = new IntNode(0);
        dummyTail = new IntNode(0);

        dummyHead->next = dummyTail;
        dummyTail->prev = dummyHead;

    };

    ~IntList()
    {
        IntNode *pCurr = dummyHead->next;
        while(pCurr!=0) 
        {
            delete pCurr->prev;
            pCurr = pCurr->next;
        }

        delete pCurr;

    }

    void push_front(int value);
    void pop_front();
    void push_back(int value);
    void pop_back();
    bool empty() const;
    friend ostream& operator<<(ostream &out, const IntList &rhs);
    void printReverse() const;

};

#endif