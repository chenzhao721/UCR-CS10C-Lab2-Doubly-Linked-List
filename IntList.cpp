#include "IntList.h"

using namespace std;

void IntList::push_front(int value)
{
    IntNode *pnew = new IntNode(value);
    IntNode *pnext = dummyHead->next;
    dummyHead->next = pnew;
    pnew->next = pnext;
    pnext->prev = pnew;
    pnew->prev = dummyHead;

}

void IntList::pop_front()
{
    if(dummyHead->next==dummyTail) return;
    IntNode *pnext = dummyHead->next->next;
    IntNode *pcurr = dummyHead->next;
    dummyHead->next = pnext;
    pnext->prev = dummyHead;
    delete pcurr;

}

void IntList::push_back(int value)
{
    IntNode *pnew = new IntNode(value);
    IntNode *psucc = dummyTail->prev;
    psucc->next = pnew;
    pnew->next = dummyTail;
    pnew->prev = psucc;
    dummyTail->prev = pnew;
}

void IntList::pop_back()
{
    if(dummyHead->next==dummyTail) return;
    IntNode *psucc = dummyTail->prev->prev;
    IntNode *pcurr = dummyTail->prev;
    delete pcurr;
    psucc->next = dummyTail;
    dummyTail->prev = psucc;
}

bool IntList::empty() const
{
    if(dummyHead->next==dummyTail) return true;
    else return false;
}

ostream& operator<<(ostream &out, const IntList &rhs)
{
    IntNode *phead = rhs.dummyHead;
    IntNode *ptail = rhs.dummyTail;
    IntNode *pIter = nullptr;
    if(phead->next == ptail) return out;

    for(pIter=phead->next; pIter!=ptail->prev; pIter=pIter->next)
    {
        out<<pIter->data<<" ";
    }

    out<<pIter->data;
    return out;

}

void IntList::printReverse() const
{
    IntNode *pIter = nullptr;
    if(dummyHead->next == dummyTail) return;
    for(pIter=dummyTail->prev; pIter!=dummyHead->next; pIter=pIter->prev)
    {
        cout<<pIter->data<<" ";
    }

    cout<<pIter->data;
}

// void IntList::printReverse() const{
//    for(IntNode* cur = dummyTail->prev; cur != dummyHead; cur = cur->prev){
//         cout<< cur->data;
//         if(cur->prev != dummyHead)
//         {
//             cout<< " ";
//         }
//     }
// }