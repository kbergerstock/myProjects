// timer.cpp

#ifndef __TIMER_H
#include "timer.h"
#endif

#ifndef __MMSYSTEM_H
#include <mmsystem.h>
#endif

void TIMER::Start(DWORD Delta)
{
	delta = Delta;
	start = timeGetTime();
	end = start;
}

bool TIMER::IsDone(void)
{
	end = timeGetTime();
	DWORD thisDelta = end - start;
	return delta > thisDelta ? false : true;
}

void TIMER::Delay(DWORD delta)
{
	Start(delta);
    while(!IsDone() );
}

DWORD TIMER::Elapsed(void)
{
    return timeGetTime() - start;
}