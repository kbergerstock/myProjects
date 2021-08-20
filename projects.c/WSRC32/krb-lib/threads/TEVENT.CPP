// class tevent functions

#ifndef __tEVENT_H
#include "tEVENT.H"
#endif

tEVENT::tEVENT()
{
    // create an event

    //set security attributes to inherit handle
    // SECURITY_ATTRIBUTES sa = {sizeof(SECURITY_ATTRIBUTES), EVENT_MODIFY_STATE | SYNCHRONIZE, TRUE};
    //create the events

    //  must be manually reset
    /// initial state == non signaled
	EventHandle = CreateEvent( NULL,true,false,NULL);
    signal = false;
    refFlag = true;
}

tEVENT::tEVENT(LPSTR eventName)
{
    //  must be manually reset
    /// initial state == non signaled
	EventHandle = CreateEvent( NULL,true,false,eventName);
    signal = false;
    refFlag = true;
    
}

tEVENT::tEVENT(HANDLE h)
{
	signal = false;
    refFlag = false;
    EventHandle = h;
}

tEVENT::tEVENT(const tEVENT& t)
{
	signal = t.signal;
    refFlag = false;
    EventHandle = t.EventHandle;
}


tEVENT::~tEVENT()
{
	if(refFlag)
 		CloseHandle(EventHandle);

    refFlag = false;
}

void tEVENT::Set()
{
	signal = true;
	SetEvent(EventHandle);
}

void tEVENT::Clear()
{
	signal = false;
	ResetEvent(EventHandle);
}

HANDLE tEVENT::GetHandle()
{
	return EventHandle;
}

bool tEVENT::isSet()
{
	DWORD r = WaitForSingleObject(EventHandle,0);
    return r == WAIT_OBJECT_0  ? true : false;
}

bool tEVENT::Wait()
{
	DWORD r = WaitForSingleObject(EventHandle,INFINITE);
    return r == WAIT_OBJECT_0  ? true : false;
}

bool tEVENT::Wait(DWORD t)
{
	DWORD r = WaitForSingleObject(EventHandle,t);
    return r == WAIT_OBJECT_0  ? true : false;
}

