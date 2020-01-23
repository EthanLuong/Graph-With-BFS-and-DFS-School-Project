#ifndef MYSTACK_H
#define MYSTACK_H

#include "MyList.h"

class MyStack: public MyList
{
    public:
      //Pops element at front
      void pop();
      //Gets element at front
      int getTop();
};

#endif