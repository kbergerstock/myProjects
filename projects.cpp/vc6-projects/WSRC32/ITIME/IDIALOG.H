#include "cDLGWIN.h"

#ifndef __iDIALOG_H
#define __iDIALOG_H

class iDialog : public cDLGWIN
{
	private:
    	long jd_2000;				// julian day number for year 2000;
        SYSTEMTIME now;				// current system time

    	UINT days;
        UINT hours;
        UINT minutes;
        UINT seconds;

        void UpdateDisplay(HWND);

        BOOL dlgProc(HWND hDlg, UINT msg, WPARAM wParam, LPARAM lParam);

    public:
     iDialog( HINSTANCE , LPSTR);
	 ~iDialog();
};

#endif