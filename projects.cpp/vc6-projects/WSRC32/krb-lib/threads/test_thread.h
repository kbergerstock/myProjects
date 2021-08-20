// this header incpsulates the main thread functions 
// so that the test thread is defined and started from here

#include "criticalSection.h"
#include "threadObject.h"

#ifndef __test_thread_h
#define __test_thread_h

class cTestThread : public threadObject
{
    protected:
        criticalSection cs;
        bool exit_flag;
        
        virtual void runThread(void)  = 0;    // call back function for derived class to override
        
        DWORD run();
    public:
      cTestThread ();
      // make sere that the thread is exited and cleand up  
      virtual ~cTestThread();

    // set the exit flag to exit the thread
      void setExitFlag()  
            {   
                Lock l(cs);
                exit_flag = true;
            }
};

#endif
