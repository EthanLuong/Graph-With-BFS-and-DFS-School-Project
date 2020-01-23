#include "MyStack.h"

void MyStack::pop()
{
    Node* head = getHead();
    if(head == NULL)
        return;
    this->setHead(head->getN());
    delete(head);
    decElem();
}

int MyStack::getTop()
{
    Node* head = getHead();
    if(head == NULL)
        return -1;
    return head->getE();
}