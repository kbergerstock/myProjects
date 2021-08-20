// critical section object

#include"lockableObject.h"

#ifndef __criticalSection_h
#define __criticalSection_h

class criticalSection : public lockableObject
{
    private:
        CRITICAL_SECTION _cs;
    public:
        criticalSection()           { InitializeCriticalSection(&_cs); }
        virtual ~criticalSection()  { DeleteCriticalSection(&_cs); }
        virtual void Lock()         { EnterCriticalSection(&_cs); }
        virtual void Unlock()       { LeaveCriticalSection(&_cs); }
};

template <class T> class tSAFE
{
	private:
        criticalSection cs;
    	T _v;
    public:

    	tSAFE() { _v = 0; }
        tSAFE(T _t) { Lock l(cs); _v = _t; }
        tSAFE(tSAFE& t) { Lock l(cs); _v = t._v; }
        operator T() { Lock l(cs); return _v; } 

        const tSAFE& operator = (const T _q) { Lock l(cs); _v = _q; return *this; }
        const tSAFE& operator = (const tSAFE &t) {Lock l(cs); _v = t._v; return *this; }

        const tSAFE& operator+= (T _q) { Lock l(cs); _v += _q; return *this; }
};

#endif