// template class impementation of a stack

#include "tFIFO.h"

#ifndef __tQUEUE_H
#define __tQUEUE_H

const int max_stack_size = 2048;

template <class TYPE> class tQUEUE : public tFIFO
{
  private:

  public:
    tQUEUE()
      {
        resize(max_stack_size);
      }

   ~tQUEUE()  {}
};

#endif
