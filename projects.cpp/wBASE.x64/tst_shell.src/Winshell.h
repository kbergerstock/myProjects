#ifndef __WINDOWS_H
#ifndef STRICT
#define STRICT
#endif

#define WIN32_LEAN_AND_MEAN

#include <windows.h>
#include <windowsx.h>
#endif

#include "cAppBase.h"

#ifndef __WINSHELL_h
#define __WINSHELL_h


class cWINSHELL : public cAppWinFrame
{

    private:
		// message cracker handling routines
		void OnCommand(HWND, int, HWND, UINT);

		// paint routine
		void Paint(HDC);

		// message handler
		LRESULT WndProc(HWND, UINT, WPARAM, LPARAM);

    public:

        cWINSHELL(int);
        ~cWINSHELL();
};

#endif