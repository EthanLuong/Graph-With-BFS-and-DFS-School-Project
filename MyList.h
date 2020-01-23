#ifndef MYLIST_H
#define MYLIST_H

#include "Node.h"

class MyList
{
 private:
 Node* head;
 int numElem;
  
 public:
  MyList();
   ~MyList();
  void show();
  void insert (int v1);
  void remove (int v1);
  bool inList(int v1);
  bool isEmpty();
  int getNumElem();
  int getElemAt(int n);
  
  //Functions for child classes
  Node* getHead();
  Node* setHead(Node* n);
  void incElem();
  void decElem();
};

#endif