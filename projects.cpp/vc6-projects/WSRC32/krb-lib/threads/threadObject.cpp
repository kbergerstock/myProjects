#include "threadObject.h"

threadObject::threadObject() 
{
    m_hThread = NULL;
    m_ThreadId = 0;
}

threadObject::threadObject(tEVENT& _exit)
{
    m_hThread = NULL;
    m_ThreadId = 0;
    exit_event = _exit;
}

threadObject::~threadObject()
{
    if(m_hThread != NULL)
     {
        CloseHandle(m_hThread);
        m_hThread = NULL;
        m_ThreadId = 0;
     }   
}


DWORD  threadObject::run()
{
    while(! exit_event.isSet() )
     {
     }
    return 0;
}

DWORD WINAPI threadObject::threadFunc(LPVOID param)
{
    threadObject* pto = (threadObject*)param;
    pto->run();
    return pto->pool->remove(pto->m_hThread);
}

void threadObject::WaitForExit()
{
    WaitForSingleObject(m_hThread,INFINITE);    
    CloseHandle(m_hThread);
    m_hThread = NULL;
    m_ThreadId = 0;
}

HANDLE threadObject::startThread(threadPool* pPool)
{
    pool = pPool;
    exit_event = pool->exit_event;

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

