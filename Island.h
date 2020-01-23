#ifndef ISLAND_H
#define ISLAND_H
#include "MyList.h"

class Island
{
private:
  int visited;
  MyList edges;
  
public:
  Island();
  void addEdge(int v1);
  void delEdge(int v1);
  //Returns true if v1 is in list false else
  bool inList(int v1);
  //Shows connected islands
  void showInfo();
  //Returns true if empty
  bool isEmpty();
  //Sets visited to -1 if false 0 if true
  void setVisited(bool a);
  //returns number of edges
  int numEdges();
  //Gets edge at position n
  int getEdgeAt(int n);
  //Returns true if already visited else false
  bool getVisited();
  //Gets previous island
  int getPrev();
  //Sets previous island
  void setPrev(int x);
  
};
#endif
