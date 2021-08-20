//*******************************************************************
//              
//  FILE:       cAPPBASE32.H
//              
//  AUTHOR:     Keith R. Bergerstock
//              
//  PROJECT:    wCONTROLS
//              
//  COMPONENT:  cAppFrame
//              
//  DATE:       29.07.2004
//              08.07.2017                
//              
//  COMMENTS:   -
//              
//              
//*******************************************************************

#pragma warning (disable:4786)

// Includes

#ifndef __myWinBase_h
#include "myWinBase.h"
#endif

#include <TCHAR.h>

#ifndef __cAPPBASE32_H
#define __cAPPBASE32_H

//*******************************************************************
//              
//  CLASS:      cAppFrame
//              
//  COMMENTS:   -
//              
//*******************************************************************

class cAppFrame : public cMAIN
{

  public:
  cAppFrame () : cMAIN() { };
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

class cAppWinFrame : public Window
{
  protected:
	HBRUSH bkGnd;			// application background
	TCHAR* appName;         // application name
	TCHAR* appDesc;		    // application description

    int  MenuResourceId;	// id of a menu resource	
    int  appLargeIcon;      // id of a large icon resource
    int  appSmallIcon;      // id of a smalll icon resource

    int _x;                // window orgin
	int _y;
    
	int _w;                // window width
	int _h;                // window hieght

	DWORD _style;			// window style
    DWORD _ex_style;

	// message cracker handling routines
	virtual void OnPaint(HWND);
	virtual void OnSysCommand(HWND hwnd, UINT uCmd, int x, int y);
	virtual void OnCommand(HWND , int , HWND , UINT );
	virtual void OnCreated(HWND);
	virtual void OnUpdate(HWND);
	virtual void OnKey(HWND , UINT , BOOL , int , UINT );
	virtual void OnChar(HWND,UINT,int) {};
	virtual void OnTimer(HWND,UINT){};
    virtual void OnMove(HWND,int,int){};

    virtual void Paint(HDC hdc) {};
//    virtual void Paint(Canvas& canvas) {};

    //class window procedure
	virtual LRESULT WndProc( HWND, UINT, WPARAM , LPARAM );

  public:
	bool Register();
	bool Create();

    void SetMenu(int id)        { MenuResourceId = id; }
	void SetLargeIcon(int id)   { appLargeIcon = id; }
    void SetSmallIcon(int id)   { appSmallIcon = id; }
	void SetSize(int,int,int,int);
    void SetStyle(DWORD style) { _style = style; };
    void SetExStyle(DWORD style) { _ex_style = style; };
	void SetBkGnd(HBRUSH);
	HBRUSH GetBkGnd(void) { return bkGnd; };

    void Run(void);

    cAppWinFrame(HINSTANCE, int);
	virtual ~cAppWinFrame();

};

#endif
