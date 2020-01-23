#include "MyQueue.h"

void MyQueue::pop()
{
    Node* tmp = getHead();
    Node* prv = NULL;
    if(tmp == NULL)
        return;
    
    while(tmp->getN() != NULL)
    {
        prv = tmp;
        tmp = tmp->getN();
    }
    
    if(prv == NULL)
        setHead(prv);
    else
        prv->setN(tmp->getN());
    
    delete(tmp);
}

int MyQueue::getTop()
{
    Node* tmp = getHead();
    if(tmp == NULL)
        return -1;
    
    while(tmp->getN() != NULL)
    {
        tmp = tmp->getN();
    }
    
    return tmp->getE();
    
}