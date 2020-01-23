#include "Node.h"
////Node methods
//

//Constructor with no paramers
Node::Node()
{
    this->elem = -1;
    this->next = NULL;
    
}

//Constructor with one parameter
Node::Node(int v1)
{
    this->elem = v1;
    this->next = NULL;
}

//Constructor with two paramters
Node::Node(int v1, Node* next)
{
    this->elem  = v1;
    this->next = next;
}

//Sets element of Node
void Node::setE(int v1)
{
    this->elem = v1;
}

//Returns element of node
int Node::getE()
{
    return this->elem;
}

//Sets next node
void Node::setN(Node* newNode)
{
    this->next = newNode;
}

//Returns pointer to next node
Node* Node::getN()
{
    return this->next;
}
