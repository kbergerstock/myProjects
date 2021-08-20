// this header incpsulates the main thread functions 
// so that the test thread is defined and started from here

#include "test_thread.h"


DWORD cTestThread::run()
{
    // while the exit flag is not set run the main job in a loop
    while(!exit_flag)
        runThread();

    return 0;
}

cTestThread::cTestThread () : threadObject(),exit_flag(false)
{
}
      // make sere that the thread is exited and cleand up  
cTestThread::~cTestThread() 
{ 
    setExitFlag(); 
    WaitForExit(); 
}
