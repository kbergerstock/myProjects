// this header incpsulates the main thread functions 
// so that the test thread is defined and started from here

#include "cThread.h"


DWORD cThread::run()
{
    // while the exit flag is not set run the main job in a loop
    while(!exit_event.isSet() )
        {
            if(run_event.isSet() )        
                runThread();
        }

    return 0;
}

cThread::cThread () : threadObject()
{

}

cThread::cThread (tEVENT& _exit,tEVENT& _run) : threadObject()
{
    exit_event = _exit;
    run_event = _run;
}

cThread::~cThread() 
{ 
}
