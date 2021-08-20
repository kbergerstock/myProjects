// thread process
#include <classlib/thread.h>

#ifdef _SKELETON_
	#include "cRANDOM.H"
#endif

#ifndef __cPROCESS_H
#define __cPROCESS_H

class cPROCESS : public TThread
{
	private:
        int started;
        virtual int Run();

   	protected:
    	int mode;
        HWND 	hwnd;   		// handle to main window
        virtual int Paint();    // paint module for the process
        

    public:
    	cPROCESS(){started = mode = 0; hwnd = NULL;};
    	virtual ~cPROCESS();
        void Start(HWND h);
        BOOL isDone(void) 	{ return GetStatus() == Finished; }
        void Stop();
};

    #ifdef _SKELETON_
    class SlidePROCESS: public cPROCESS
    {
        private:
            double p;		// position
            double d;		// direction
            cRANDOM a;		// amount

            int Run();

        public:
            SlidePROCESS() : cPROCESS(), p(0.0), d(1.0) ,a(100) {};
            ~SlidePROCESS(){};
    };
    #endif
#endif