#include "cWorkerThread.h"

cWorkerThread::cWorkerThread() 
{
    m_hThread = NULL;
    m_ThreadId = 0;
}

cWorkerThread::cWorkerThread(tEVENT& _exit)
{
    m_hThread = NULL;
    m_ThreadId = 0;
    exit_event = _exit;
}

cWorkerThread::~cWorkerThread()
{
    if(m_hThread != NULL)
     {
        CloseHandle(m_hThread);
        m_hThread = NULL;
        m_ThreadId = 0;
     }   
}

// main thread job is interfaced here
DWORD WINAPI cWorkerThread::threadFunc(LPVOID param)
{
    cWorkerThread* pto = (cWorkerThread*)param;

    while(! pto->exit_event.isSet() )
     {
        if(pto->run_event.isSet() )  
            pto->run();
        else 
            pto->run_event.Wait(25);
     }
    pto->stopThread();
    return 0;
}

void cWorkerThread::WaitForExit()
{
    WaitForSingleObject(m_hThread,INFINITE);    
    CloseHandle(m_hThread);
    m_hThread = NULL;
    m_ThreadId = 0;
}

// install the thread job
HANDLE cWorkerThread::startThreadJob()
{
    m_hThread = (HANDLE)_beginthreadex(NULL,
                                        0,
                                        (PBEGINTHREADEX_THREADFUNC)threadFunc,
                                        (LPVOID)this,
                                        0,
                                        (PBEGINTHREADEX_THREADID)&m_ThreadId );
    if(!m_hThread)  
        throw -1;

    return m_hThread;
}

/* --------------------------------- */

cTaskThread::cTaskThread() 
{
    m_hThread = NULL;
    m_ThreadId = 0;
}

cTaskThread::~cTaskThread()
{
    if(m_hThread != NULL)
     {
        CloseHandle(m_hThread);
        m_hThread = NULL;
        m_ThreadId = 0;
     }   
}

DWORD WINAPI cTaskThread::taskFunc(LPVOID param)
{
    cTaskThread* pto = (cTaskThread*)param;

    pto->execute();

    return 0;
}

HANDLE cTaskThread::startTask()
{
    m_hThread = (HANDLE)_beginthreadex(NULL,
                                        0,
                                        (PBEGINTHREADEX_THREADFUNC)taskFunc,
                                        (LPVOID)this,
                                        0,
                                        (PBEGINTHREADEX_THREADID)&m_ThreadId );
    if(!m_hThread)  
        throw -1;

    return m_hThread;
}

void cTaskThread::WaitForExit()
{
    WaitForSingleObject(m_hThread,INFINITE);    
    CloseHandle(m_hThread);
    m_hThread = NULL;
    m_ThreadId = 0;
}