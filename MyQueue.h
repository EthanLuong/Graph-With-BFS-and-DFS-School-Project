#ifndef MYQUEUE_H
#define MYQUEUE_H

#include "MyList.h"
//Queue class
class MyQueue: public MyList
{
    public:
      //Deletes delement at end (Insert adds to front)
      void pop();
      //Gets element at end (Insert adds to front)
      int getTop();
};

#endif