#include <windows.h>
#include <process.h>
#include "tEVENT.h"

#ifndef __threadObject_h
#define __threadObject_h

typedef unsigned (WINAPI *PBEGINTHREADEX_THREADFUNC)(LPVOID lpThreadParameter);
typedef unsigned *PBEGINTHREADEX_THREADID;

class threadPool;

class threadObject
{
    protected:
        HANDLE          m_hThread;
        DWORD           m_ThreadId;
        cEVENT          exit_event;         // when set the thread exits
        tEVENT          run_event;          // when set the thread body executes
        threadPool*     pool;

        virtual DWORD  run();

        static DWORD WINAPI threadFunc(LPVOID param);

    public:
        threadObject();
        threadObject(tEVENT&);
        ~threadObject();
        
        HANDLE startThread(threadPool* _p);

        void WaitForExit();
        HANDLE getThreadHandle()    { return m_hThread; }
        void Suspend()              { SuspendThread(m_hThread); }
        void Resume()               { ResumeThread(m_hThread); }
        int isRunning()             { return run_event.isSet(); }
        void startThread()          { run_event.Set(); }
        void stopThread()           { run_event.Reset(); }
};

typedef threadObject* pOBJ;

class threadPool 
{
    private:
        tEVENT exit_event;
        HANDLE handles[10];         // max thread allowed in application / for now
        pOBJ   threads[10];
        int ndx;

        friend class threadObject;

    public:
        threadPool() : exit_event()
            { 
                ndx = 0; 
            }
        ~threadPool()
            {
                if(ndx > 0)
                    WaitForMultipleObjects(ndx,handles,TRUE,INFINITE);
            }
    
        int install(threadObject& obj)
            {
                int v = -1;
                if(ndx < 10)
                    {
                        threads[ndx] = &obj;
                        handles[ndx] = obj.startThread(this);
                        v = ndx;
                        ndx++;
                    }
                return v;
            }

        int start(threadObject& obj)
            {
                int v = install(obj);
                startThreads();
                return v;
            }

         int remove(HANDLE h)
            {
                return 0;
            }
        
         void KillThreads()
            {
                exit_event.Set();
            }   

        const tEVENT& getExitEvent() { return exit_event; }

        void startThreads()
            {
                for(int i = 0; i < ndx; i++)
                    threads[i]->startThread();
            }
        void stop_threads()
            {
                for(int i = 0; i < ndx; i++)
                    threads[i]->startThread();
            }

};
#endif