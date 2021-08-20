// lockable object class
#include <windows.h>

#ifndef __lockableObject_h
#define __lockableObject_h

class lockableObject
{
    public:
        lockableObject() {}
        virtual ~lockableObject() {}
        virtual void Lock() = 0;
        virtual void Unlock() = 0;
};

class Lock
{
    private:
        lockableObject *_pto;
    public:
        Lock(lockableObject* pto)
            {
                _pto = pto;
                _pto->Lock();
            }

         Lock(lockableObject& pto)
            {
                _pto = &pto;
                _pto->Lock();
            }

        ~Lock()
            {
                _pto->Unlock();
            }
};

#endif

