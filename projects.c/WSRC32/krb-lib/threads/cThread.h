// this header incpsulates the main thread functions 
// so that the test thread is defined and started from here

#include "criticalSection.h"
#include "threadObject.h"
#include "tEVENT.h"

#ifndef __cTHREAD_h
#define __cTHREAD_h

class cThread : public threadObject
{
    protected:
        criticalSection cs;

        // call back function for derived class to override
        virtual void runThread()  = 0;      
        
        DWORD run();

    public:
      cThread ();
      cThread (bool);
      cThread ( tEVENT&,tEVENT& );

      // make sere that the thread is exited and cleand up  
      virtual ~cThread();

  
};

#endif
