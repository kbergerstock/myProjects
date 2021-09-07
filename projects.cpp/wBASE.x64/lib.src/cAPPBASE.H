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

#ifndef __WINDBASE_H
#include "windbase.h"
#endif

#ifndef __cAPPBASE_H
#define __cAPPBASE_H

#define APP_NAME_SIZE 64
#define APP_DESC_SIZE 128

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

class cAppWinFrame : public Window
{
  protected:
	HBRUSH bkGnd;					// application background
	char AppName[APP_NAME_SIZE];	// application name
	char AppDesc[APP_DESC_SIZE];	// application description

    int  MenuResourceId;	// id of a menu resource	
    int  appLargeIcon;      // id of a large icon resource
    int  appSmallIcon;      // id of a smalll icon resource

	LONG _x;                // window orgin
	LONG _y;
	LONG _w;                // window width
	LONG _h;                // window hieght

	DWORD _style;			// window style
    DWORD _ex_style;

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
	bool Register();
	bool Create();
	void SetName(LPCSTR,LPCSTR);
    void SetMenu(int id)        { MenuResourceId = id; }
	void SetLargeIcon(int id)   { appLargeIcon = id; }
    void SetSmallIcon(int id)   { appSmallIcon = id; }
	void SetSize(int,int,int,int);
    void SetStyle(DWORD style) { _style = style; };
    void SetExStyle(DWORD style) { _ex_style = style; };
	void SetBkGnd(HBRUSH);
	HBRUSH GetBkGnd(void) { return bkGnd; };

    void Run(void);

	cAppWinFrame(LPCSTR appName, LPCSTR appDesc, HINSTANCE, int);
    cAppWinFrame(HINSTANCE, int);
	virtual ~cAppWinFrame();

};

#endif
