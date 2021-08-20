#include "cPROCESS.h"

#ifdef _SKELETON_
	#include "cSlide.h"
	#include "timer.h"
#endif


cPROCESS::~cPROCESS()
{
	if(GetStatus() == Running)
     {
		Terminate();       	  		// send a terminate signal
		while(! isDone() ) ;  		// wait until terminate signal is processed
	}
}

void cPROCESS::Start(HWND h)
{
	hwnd = h;
    if(!started)
     {
		TThread::Start();
        started = true;
     }
	mode = 1;
}

void cPROCESS::Stop()
{
    mode = 0;
}

int cPROCESS::Run()
{
	return 0;
}

int cPROCESS::Paint()
{
	return 0;
}

#ifdef _SKELETON_
    int SlidePROCESS::Run()
    {
        double q;
        double np;
        TIMER  timer(100);

        while(!ShouldTerminate())
         {
            if(timer.IsDone() )
             {
                q = a.NextVal(2.0);
                np = p + d * q;
                if(np > 100.0 || np < 0.0)
                    { d *= -1.0; }
                p+= d * q;

                SendMessage(hwnd,WM_SLIDECONTROL,0L,LPARAM(p * 100.0 + .05) );
                timer.Start(100);
             }
         }

        return 0;
    }
#endif