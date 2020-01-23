#include "MyList.h"

////Linked list methods
//

//Constructor
MyList::MyList()
{
    this->head = NULL;
    numElem = 0;
}

MyList::~MyList()
{
    Node* tmp = head;
    Node* prv = NULL;
    while(tmp != NULL)
    {
        prv = tmp;
        tmp = tmp->getN();
        delete(prv);
    }    
}

//Inserts new Node 
void MyList::insert(int v1)
{
    Node* newNode = new Node(v1, head);
    head = newNode;
    numElem++;
}


//Reoves node that matches value given
void MyList::remove(int v1)
{
    Node* tmpNode = head;
    Node* prvNode = NULL;
    while(tmpNode != NULL)
    {
        if(tmpNode->getE() == v1)
            break;
        
        prvNode = tmpNode;
        tmpNode = tmpNode->getN();
    }
    
    if(tmpNode == NULL)
        return;
    
    if(prvNode == NULL)
        head = tmpNode->getN();
    else
        prvNode->setN(tmpNode->getN());
    
    delete(tmpNode);
    numElem--;
}

//Returns true if element is in list
bool MyList::inList(int v1)
{
    Node* tmp = head;
    while(tmp != NULL)
    {
        if(tmp->getE() == v1)
            return true;
        tmp = tmp->getN();
    }
    return false;
}

//Shows all elements in list
void MyList::show()
{
    Node* tmp = head;
    while(tmp != NULL)
    {
        printf("%d ", tmp->getE());
        tmp = tmp->getN();
    }
}

//Returns true if list is empty else returns false
bool MyList::isEmpty()
{
    if(head == NULL)
        return true;
    else
        return false;
}

//Returns element at nth position
int MyList::getElemAt(int n)
{
    if(n < 0)
        return -1;
    
    int count = 0;
    Node* tmp = head;
    while(count != n)
    {
        tmp = tmp->getN();
        count++;
    }
    return tmp->getE();
}

//Returns number of elements
int MyList::getNumElem()
{
    int count = 0;
    Node* tmp = head;
    while(tmp != NULL)
    {
        count++;
        tmp = tmp->getN();
    }
    return count;
}

Node* MyList::getHead()
{
    return this->head;
}
Node* MyList::setHead(Node* n)
{
    this->head = n;
}
  
void MyList::incElem()
{
    this->numElem++;
}
      
void MyList::decElem()
{
    this->numElem--;
}