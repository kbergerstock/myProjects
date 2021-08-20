// template class impementation of a stack

#include "tARRAY.h"

#ifndef __tFIFO_H
#define __tFIFO_H

template <class TYPE> class tFIFO
{
  protected:
    int             stack_size;
    tARRAY<TYPE>    stack;
    int             stack_rndx;
    int             stack_tndx;

  public:
    tFIFO()
      {
            stack_size = 0;
            stack_rndx = 0;
            stack_tndx = 0;
      }

   ~tFIFO()  {}

   void push(TYPE _v);
   TYPE pop (void);

   void resize(int new_stack_size);

   void reset()
    {
        stack_rndx = 0;
        stack_tndx = 0;
    }     

   int  hasData() 
    {
        return stack_tndx == stack_rndx ? 0 : 1;
    }

};

template <class TYPE> void tFIFO<TYPE>::push(TYPE _v)
{
    stack[stack_rndx++] = _v;
    if(stack_rndx > stack_size)
        stack_rndx = 0;
}

template <class TYPE> TYPE tFIFO<TYPE>::pop(void)
{
    TYPE r;
    
    memset(&r,0,sizeof(r));

    if(stack_tndx != stack_rndx)
        r = stack[stack_tndx++];
    if(stack_tndx > stack_size)
        stack_tndx = 0;

  return r;
}

template <class TYPE> void tFIFO<TYPE>::resize(int new_stack_size)
{
    stack_size = new_stack_size;
    stack.resize(new_stack_size);
    stack_rndx = stack_tndx = 0;
}


#endif
