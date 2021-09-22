//timer.h

#ifndef __WINDOWS_H
#define STRICT
#include <windows.h>
#endif

#ifndef __TIMER_H
#define __TIMER_H

#ifdef __DLL_EXPORT__
class _export TIMER
#else
class TIMER
#endif
{
	private:
		DWORD start;
		DWORD end;
		DWORD delta;

	public:
		TIMER() {};
        ~TIMER() {};
        TIMER(DWORD Delta) { Start(Delta); }
		void Start(DWORD Delta);
        void Delay(DWORD delta);
        DWORD Elapsed(void);
		bool IsDone(void);
};
#endif

