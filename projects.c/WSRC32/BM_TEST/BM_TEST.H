// -----------------------------------------------
//	skeleton application header file
//	(c) K. R. Bergerstock,1998
// --------------------------------------------------

#ifndef __cAPPBASE32_H
#include "cAPPBASE32.h"
#endif

#ifndef __STATBAR_H
#include "statbar.h"
#endif

#include "cSPRITE.h"

#ifndef __BM_TEST_H
#define __BM_TEST_H

class AppWin : public cAppWinFrame
{
  private:
  	int isOk;

	cBITMAP bkgnd;

    cSPRITE saucer;

	// message cracker handling routines
	void OnDestroy(HWND);
	void OnCreated(HWND);
	void OnSize(HWND , UINT , int , int );
	void OnTimer(HWND , UINT );
    void OnCommand(HWND , int , HWND , UINT );

	// paint routine
	void Paint(HDC);

	// message handler
	virtual LRESULT WndProc( HWND, UINT, WPARAM , LPARAM );

  public:
	AppWin(HINSTANCE,int);
	~AppWin();
    int IsOk(void) { return isOk; }
};


#endif

