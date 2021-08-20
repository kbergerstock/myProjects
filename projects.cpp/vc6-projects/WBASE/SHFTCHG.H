// class shiftchange header file
#ifndef __WINDOWS_H
#define STRICT
#include <windows.h>
#endif

#ifndef __DOS_H
#include <dos.h>
#endif

#ifndef __SHFTCHG_H
#define __SHFTCHG_H

class SHIFTCHANGE
{
	private:
    	int ShiftChange;
        int zones[3];
        struct time ct;

        int parse(LPSTR,LPSTR);

    public:
    	SHIFTCHANGE();
        ~SHIFTCHANGE();
        void Run(void);
        void Init(LPSTR);
        int isShiftChange(void);
};


#endif