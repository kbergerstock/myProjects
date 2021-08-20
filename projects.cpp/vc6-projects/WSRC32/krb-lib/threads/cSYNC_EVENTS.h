// this objct can be used to sync events
// wraps wait for multiple objects and tevent handles

#include "tEVENT.h"

#ifndef __cSYNC_EVENTS_H
#define __cSYNC_EVENTS_H

class cSYNC_EVENTS
{
    private:
        HANDLE _event_handles[10];
        DWORD  _len;

    public:
        cSYNC_EVENTS() : _len(0) {}
        ~cSYNC_EVENTS() {}

    void add(tEVENT& t)
        {
            add(t.GetHandle() );
        }

    void add(HANDLE h)
       {
        if(_len < 10)
            _event_handles[_len++] = h;
       }

    DWORD wait( DWORD dwMs)
      {
        if(_len)
            return WaitForMultipleObjects(_len,_event_handles,FALSE,dwMs);
        else
            return 0;
      }

    DWORD wait()
      {
        if(_len)
            return WaitForMultipleObjects(_len,_event_handles,FALSE,INFINITE);
        else
            return 0;
      }

    DWORD sleep()
      {
        if(_len)
            return WaitForMultipleObjects(_len,_event_handles,TRUE,INFINITE);
        else
            return 0;
      }

};
#endif