// -----------------------------------------------
//	skeleton application header file
//	(c) K. R. Bergerstock,1998
// --------------------------------------------------

#ifndef __APPBASE_H
#include "appbase.h"
#endif

#ifndef __STATBAR_H
#include "statbar.h"
#endif

#ifndef __cSLIDE_H
#include "cSLIDE.h"
#endif

#ifndef __DATAWIN_H
#include "datawin.h"
#endif

#include "cRANDOM.h"
#include "cPROCESS.h"

#ifndef __POPFILE_H
#include "popfile.h"
#endif

#ifndef __SKELETON_H
#define __SKELETON_H

#pragma argsused
class APP : public	AppFrame
{
  private:
  	cPROCESS *SubProcess;

  public:
  APP();
  ~APP();

  void Start(HWND);	
  void AuxRun(HWND);
};


class AppWin : public AppWinFrame
{
  private:
  	int isOk;

	char FileName[_MAX_PATH];
	char FileDesc[_MAX_PATH];

    cDATAWIN  DataWin;				// the data windows	
    HWND hDataWin;

	cSTATBAR *StatusBar;			// pointer to a status bar class
	HWND hStatusBar;				// handle to a status bar child window

    cSLIDE *Slide;					// pointer to a slide class
    HWND hSlide;					// handle to a slide child control
    double position;            	// slide position
    double dir;						// slide direction of motion
	cRANDOM amt;					// slide motion amount

    cSLIDE *SlideTwo;
    HWND hSlideTwo;

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
    void Run(void);
};


#endif

