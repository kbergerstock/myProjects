//*******************************************************************
//              
//  FILE:       cWINDBASE.H
//              
//  AUTHOR:     Keith R. Bergerstock
//              
//  PROJECT:    WBASE32
//              
//  COMPONENT:  cMAIN
//              
//  DATE:       29.07.2004
//              
//  COMMENTS:   - version 2 - converted to win 32 api calls 
//              
//              
//*******************************************************************

// Includes


#ifndef __WINDOWS_H
    #ifndef STRICT
        #define STRICT
    #endif

    #define WIN32_LEAN_AND_MEAN
    
    #include <windows.h>
    #include <windowsx.h>
    #include <mmsystem.h>
#endif

#include "WM_MSGS.h"

#ifndef __WINDBASE_H
#define  __WINDBASE_H

//*******************************************************************
//              
//  FUNCTION:   MainWndProc
//              
//  RETURNS:    LRESULT CALLBACK
//              
//  PARAMETERS: HWND,UINT,WPARAM,LPARAM
//              
//  COMMENTS:   - main call back used by library to process window messages
//              
//*******************************************************************

LRESULT CALLBACK MainWndProc (HWND , UINT , WPARAM , LPARAM );


//*******************************************************************
//              
//  CLASS:      cMSGLOOP	
//              
//  COMMENTS:   - windows message loop class
//              
//*******************************************************************

class cMSGLOOP
{
  private:
	static HWND hDlgModeless;

  protected:
    int bQuit;

  public:
    
	char szCurrentDir[MAX_PATH+1];

	cMSGLOOP();
    ~cMSGLOOP();

	int Run(HWND);
    int	MessageLoop();

	virtual void AuxRun(HWND) { Sleep(25); }

	LPSTR  getAppPathName()             { return szCurrentDir; }
    static void  SetDlgModeless(HWND);
    static HWND  GetDlgModeless()       { return hDlgModeless; }
};


//*******************************************************************
//              
//  CLASS:      WinBase
//              
//  COMMENTS:   - base window class
//              
//*******************************************************************

class cWINBASE
{
  protected:
    static HINSTANCE hInstance;
    int nCmdShow;

	HWND hWnd;
    HWND LastFocus;

	LPSTR szWinName;
	LPSTR szWinDesc;

	SIZE Size;		   			// holds width and height of client screen
	LONG cxChar,cyChar,cxCaps;

  public:
    cWINBASE() : LastFocus(0) {};
    cWINBASE(HINSTANCE _hInstance, int _nCmdShow = true)
        : LastFocus(0) {hInstance = _hInstance; nCmdShow = _nCmdShow; };
    ~cWINBASE() {};

	void getTextMetrics(HWND);
    void Show( int nCmdShow) { ShowWindow(hWnd, nCmdShow); }
    void setFocus(void);
	void Show(void);
    void Clear(void);
    void ExitWindow(void);

	void Update(void) { UpdateWindow(hWnd); }
    void Move(int,int,int,int);
    
    bool isRegistered(LPSTR);

	virtual bool Register(void) = 0;

	virtual void OnPaint(HWND) = 0;
	virtual void OnDestroy(HWND);
	virtual void OnSize(HWND , UINT , int , int );
	virtual void OnCommand(HWND , int , HWND , UINT ) = 0;

	virtual LRESULT WndProc( HWND, UINT, WPARAM , LPARAM ) = 0;

	HWND GetWindowHandle(void) { return hWnd; }
    HWND operator() (void) { return hWnd; }
    static HINSTANCE GetInstance(void) { return hInstance; }

};

class Window : public cWINBASE
{
  protected:

  public:
    Window(HINSTANCE _hInstance, int _nCmdShow = true)
        : cWINBASE (_hInstance,_nCmdShow)
         {
         }

	virtual bool Create() = 0;

};

class ChildWindow : public cWINBASE
{
  protected:
	int	 Control_id;						// child window control id
	HWND  hParent;							// handle to the parent window

  public:


	int GetID(void)	 { return Control_id; }

	virtual HWND Create (HWND, int ) = 0;

};

// functions to set and retrive data from window structures

inline void *GetPointer(HWND hWnd)
{
	return (void*)GetWindowLong(hWnd, 0);
}

inline void *GetUserData(HWND hWnd)
{
	return (void*)GetWindowLong(hWnd,GWL_USERDATA);
}

inline void SetPointer(HWND hWnd, void *ptr)
{
	SetWindowLong(hWnd, 0, (LONG)ptr);
}

inline void SetUserData(HWND hWnd, void *ptr)
{
	SetWindowLong(hWnd, GWL_USERDATA, (LONG)ptr);
}

#endif
