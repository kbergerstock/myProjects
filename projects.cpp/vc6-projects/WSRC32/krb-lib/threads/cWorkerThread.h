#include <windows.h>
#include <process.h>
#include "tEVENT.h"

#ifndef __cWorkerThread_h
#define __cWorkerThread_h

typedef unsigned (WINAPI *PBEGINTHREADEX_THREADFUNC)(LPVOID lpThreadParameter);
typedef unsigned *PBEGINTHREADEX_THREADID;

class cWorkerThread
{
    protected:
        HANDLE          m_hThread;
        DWORD           m_ThreadId;
        cEVENT          exit_event;         // when set the thread exits
        tEVENT          run_event;          // when set the thread body executes

        virtual void run() = 0;             // used to make sure that a derived class implements a primary thread job

        static DWORD WINAPI threadFunc(LPVOID param);
        
        typedef cWorkerThread* pWorkerThread;

    public:
        cWorkerThread();
        cWorkerThread(tEVENT&);
        virtual ~cWorkerThread();
        
        HANDLE startThreadJob();

        void WaitForExit();
        HANDLE getThreadHandle()    { return m_hThread; }
        void Suspend()              { SuspendThread(m_hThread); }
        void Resume()               { ResumeThread(m_hThread); }
        int  isRunning()            { return run_event.isSet(); }
        void startThread()          { run_event.Set(); }
        void stopThread()           { run_event.Clear(); }
        void killThread()           { exit_event.Set(); WaitForExit(); }
        void kill()                 { exit_event.Set(); Sleep(150); }
};

class cTaskThread
{
    protected:
        HANDLE          m_hThread;
        DWORD           m_ThreadId; 

        static DWORD WINAPI taskFunc(LPVOID param);

        typedef cTaskThread* pTaskThread;

        virtual void execute() = 0;

    public:

        cTaskThread();
        ~cTaskThread();

        HANDLE startTask();
		void   WaitForExit();

};
#endif