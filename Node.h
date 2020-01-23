#ifndef NODE_H
#define NODE_H
#include <cstdio>
class Node
{
 private:
  int elem;
  Node* next;
  
 public:
  Node ();
  Node (int v1);
  Node (int v1, Node* n);
  
  void setE (int e);
  int getE ();
  void setN (Node* n);
  Node* getN();
};

#endif