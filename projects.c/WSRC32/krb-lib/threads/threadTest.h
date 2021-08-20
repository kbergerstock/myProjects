#include "cthread.h"
#include "threadObject.h"

class runDouble : public threadObject
{
    private:
        DWORD run();
        
};

class runTriple : public threadObject
{
    private:
        DWORD run();
        
};

class runBigLoop : public cThread
{
    private:
        void runThread();
    public:
        
};