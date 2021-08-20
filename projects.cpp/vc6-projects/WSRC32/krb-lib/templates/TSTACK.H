// template class impementation of a stack

#include "tARRAY.h"

#ifndef __STACK_H
#define __STACK_H

const int max_stack_size = 2048;

template <class TYPE> class STACK
{
  private:
    int stack_size;
    tARRAY<TYPE> stack;
	int ndx;

  public:
    STACK()
      {
            stack_size = max_stack_size;
            stack.resize(max_stack_size);
            ndx = 0;
      }

   ~STACK()  {}

   void push(TYPE _v);
   TYPE pop (void);
   int isOverFlowed(void) { return overflow; }

};

template <class TYPE> void STACK<TYPE>::push(TYPE _v)
{
    if(ndx >= stack_size)
    {
      stack_size += max_stack_size;
      stack.resize(stack_size);
    }
     stack[ndx++] = _v;
}


template <class TYPE> TYPE STACK<TYPE>::pop(void)
{
	if(ndx > 0)
	 {
	   ndx--;
       return stack[ndx];
	 }

  return 0;
}

#endif
