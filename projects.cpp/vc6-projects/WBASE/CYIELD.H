// cYIELD.h
// header file for class to display count totals
//

#include "y_log.h"
#include "cVALUE.h"
#include "cntr.h"

#ifndef __cYIELD_H
#define __cYIELD_H

class cYIELD : public cWinFrame
{
	private:
    	PART_COUNTER PartCounter;

        YIELD_DATA data;
        YIELD_LOG  Log;


	    cCELL	*Cells;

    public:
    	cYIELD(HWND,LPSTR);
        ~cYIELD();

        HWND Create(HWND, int);

		void Paint(HWND,HDC);

    	void Inc(int);
        void Reset(void);
};

#endif


