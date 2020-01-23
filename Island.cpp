#include "Island.h"





//Island Class MEthods 
//

//Constructor
Island::Island()
{
    this->visited = -1;
    
}


//Adds edge to value
void Island::addEdge(int v1)
{
    edges.insert(v1);
}

//Deletes edge to value
void Island::delEdge(int v1)
{
    edges.remove(v1);
}

//Returns true if there is edge to island
bool Island::inList(int v1)
{
    return edges.inList(v1);
}

//Shows info
void Island::showInfo()
{
    edges.show();
}

//Returns true if empty
bool Island::isEmpty()
{
    return edges.isEmpty();
}

//Sets visited to paramter
void Island::setVisited(bool a)
{
    if(a)
        this->visited = 0;
    else
        this->visited = -1;
}

//Returns number of edges
int Island::numEdges()
{
    return edges.getNumElem();
}

//Gets edge at nth position
int Island::getEdgeAt(int n)
{
    return edges.getElemAt(n);
}

//Returns visited
bool Island::getVisited()
{
    return this->visited != -1;
}

int Island::getPrev()
{
    return this->visited;
}

void Island::setPrev(int x)
{
    this->visited = x;
}