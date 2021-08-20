// datawin.h

#ifndef _CWFRAME_H
#include "cwframe.h"
#endif

#ifndef __DATAWIN_H
#define __DATAWIN_H

class cDATAWIN : public cWinFrame
{
	private:

    	void Paint(HWND,HDC);
        void OnKey(HWND,UINT,BOOL,int,UINT);

    public:
    	cDATAWIN();
        ~cDATAWIN();

        HWND wopen(HWND,int);

};

#endif