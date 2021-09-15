//*******************************************************************
//              
//  FILE:       cAPPBASE.H
//              
//  AUTHOR:     Keith R. Bergerstock
//              
//  PROJECT:    wCONTROLS
//              
//  COMPONENT:  cAppFrame
//              
//  DATE:       29.07.2004
//              
//  COMMENTS:   -
//              
//              
//*******************************************************************

#pragma warning (disable:4786)

// Includes

#ifndef __cWINBASE_H
	#include "cWINBASE.h"
#endif

#ifndef __cAPPBASE_H
#define __cAPPBASE_H

//*******************************************************************
//              
//  CLASS:      cMSGLOOP
//              
//  COMMENTS:   -
//              
//*******************************************************************

class cAppFrame : public	cMSGLOOP
{

  public:
    cAppFrame () : cMSGLOOP() { MessageLoop(); };
    virtual ~cAppFrame() {};

    virtual void AuxRun(HWND) {};
};


//*******************************************************************
//              
//  CLASS:      cAppWinFrame
//              
//  COMMENTS:   - base class to encpsulate an application window
//              
//*******************************************************************

class cAppWinFrame : public cWINBASE
{
  protected:
	

	// message cracker handling routines
	virtual void OnPaint(HWND);
	virtual void OnSysCommand(HWND hwnd, UINT uCmd, int x, int y);
	virtual void OnCommand(HWND , int , HWND , UINT );
	virtual void OnCreated(HWND);
	virtual void OnUpdate(HWND);
	virtual void OnKey(HWND , UINT , bool , int , UINT );
	virtual void OnChar(HWND,UINT,int) {};
	virtual void OnTimer(HWND,UINT){};
    virtual void OnMove(HWND,int,int){};

    virtual void Paint(HDC hdc) {};

    //class window procedure
	virtual LRESULT WndProc( HWND, UINT, WPARAM , LPARAM );

  public:
	bool Create();

    void Run(void);

	cAppWinFrame(HINSTANCE _hinstance, int _nCmdShow, LPCSTR appName = "app", LPCSTR appDesc = "top level app window");
	virtual ~cAppWinFrame();

};

#endif
