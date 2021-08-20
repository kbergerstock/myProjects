// class tEvent
// class wrapper for the windows events

#ifndef __WINDOWS_H
#ifndef STRICT
	#define STRICT
#endif
#include <windows.h>
#endif

#ifndef __tEVENT_H
#define __tEVENT_H

class cEVENT;

class tEVENT
{
	private:
    	HANDLE EventHandle;
        bool signal;
        bool refFlag;
        friend class cEVENT;

    public:
		tEVENT();
        tEVENT(LPSTR eventName);
        tEVENT(HANDLE);
        tEVENT(const tEVENT&);
        virtual ~tEVENT();

        void  Set();
        void  Clear();
        bool  Wait();
		bool  Wait(DWORD);
		bool  isSet();

        HANDLE GetHandle();
};


// this class holds a copy of a tEVENT
// NOTE !!!! it does not repeat NOT close the handle to the event
class cEVENT 
{
	private:
    	HANDLE EventHandle;
        bool signal;
        bool refFlag;
    public:

        cEVENT() 
         {
            signal = false;
            refFlag = false;
            EventHandle = 0;
         }
        virtual ~cEVENT()
         {
         }

        const cEVENT& operator=(const tEVENT& e)
          {
            signal = e.signal;
            EventHandle = e.EventHandle;
            return *this;
          } 

        bool isSet(void)
         {
	        DWORD r = WaitForSingleObject(EventHandle,0);
            return r == WAIT_OBJECT_0  ? true : false;
         }

        bool Wait(void)
         {
	        DWORD r = WaitForSingleObject(EventHandle,INFINITE);
            return r == WAIT_OBJECT_0  ? true : false;
         } 
        
        bool Wait(DWORD t)
         {
	        DWORD r = WaitForSingleObject(EventHandle,t);
            return r == WAIT_OBJECT_0  ? true : false;
         }         

        void Set(void)
         {
            if(EventHandle)
             {
	            signal = true;
	            SetEvent(EventHandle);
              }  
         }

        void Clear(void)
         {
            if(EventHandle)
             {
	            signal = false;
	            ResetEvent(EventHandle);
             }
         }
};

#endif