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

HANDLE cTaskThread::startTask(pvTaskFunc _task)
{
    m_hThread = (HANDLE)_beginthreadex(NULL,
                                        0,
                                        (PBEGINTHREADEX_THREADFUNC)_task,
                                        (LPVOID)this,
                                        0,
                                        (PBEGINTHREADEX_THREADID)&m_ThreadId );
    if(!m_hThread)  
        throw -1;

    return m_hThread;
}
