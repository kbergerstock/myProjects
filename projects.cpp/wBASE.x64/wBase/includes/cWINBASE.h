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
//              - version 3 - compled using to run under natice xp
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
    #include <strsafe.h>
#endif

#include "WM_MSGS.h"

#ifndef __WINDBASE_H
#define __WINDBASE_H

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

#define WIN_NAME_SIZE 64
#define WIN_DESC_SIZE 128

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
    HINSTANCE hinstance;
    int     nCmdShow;

	HWND    hwnd;
    HWND    LastFocus;

    char    szWinName[WIN_NAME_SIZE];	// application name
    char    szWinDesc[WIN_DESC_SIZE];	// application description

	//SIZE    Size;		   			    // holds width and height of client screen
	LONG    cxChar,cyChar,cxCaps;       // font size
    HBRUSH  bkGnd;					    // window background
    HANDLE  menu;
    HANDLE  icon;
    HANDLE  iconSm;
    HANDLE  cursor;

    bool    bQuit;				// flag to send app quit message

    DWORD   _style;			    // window style
    DWORD   _ex_style;			// exteneded style

    LONG    _x;					// window orgin
    LONG    _y;
    LONG    _w;					// window width
    LONG    _h;					// window hieght

  public:
 
    cWINBASE(HINSTANCE _hInstance, int _nCmdShow, LPSTR szName = NULL, LPSTR szDesc = NULL);
    
    ~cWINBASE() {};

    inline HINSTANCE hInstance() { return hinstance; }
    inline HWND hWnd() { return hwnd; }
	void getTextMetrics(HWND);
    void Show( int nCmdShow) { ShowWindow(hwnd, nCmdShow); }
    void SetName(LPSTR, LPSTR);
    void setFocus();
	void Show();
    void Clear();
    void ExitWindow();

	void Update() { UpdateWindow(hwnd); }
    void Move(int,int,int,int);
    
    bool isRegistered(LPSTR);

    virtual bool Create() = 0;
	virtual bool Register();

	virtual void OnPaint(HWND) = 0;
	virtual void OnDestroy(HWND);
	virtual void OnSize(HWND , UINT , int , int );
	virtual void OnCommand(HWND , int , HWND , UINT ) = 0;
	virtual LRESULT WndProc( HWND, UINT, WPARAM , LPARAM ) = 0;

    inline HICON loadIcon(int id) { return HICON(LoadImage(hinstance, MAKEINTRESOURCE(id), IMAGE_ICON, 0, 0, LR_DEFAULTSIZE)); }
    inline void setMenu(int id) {menu = HANDLE(MAKEINTRESOURCE(id)); }
    inline void setIcon(int id) { icon = loadIcon(id); }
    inline void setSmIcon(int id) { iconSm = loadIcon(id); }
    inline void SetSize(int x, int y, int w, int h) { _x = x; _y = y; _h = h; _w = w; };
    inline void SetStyle(DWORD style) { _style = style; };
    inline void SetExStyle(DWORD style) { _ex_style = style; };
    inline void SetBkGnd(HBRUSH brush) { bkGnd = brush; };
    inline HBRUSH BkGnd() { return bkGnd; };
};


// functions to set and retrive data from window structures

inline LONG_PTR GetPointer(HWND hWnd)
{
	return GetWindowLongPtr(hWnd, 0);
}

inline LONG_PTR GetUserData(HWND hWnd)
{
	return GetWindowLongPtr(hWnd,GWLP_USERDATA);
}

inline void SetPointer(HWND hWnd, LONG_PTR ptr)
{
	SetWindowLongPtr(hWnd, 0, ptr);
}

inline void SetUserData(HWND hWnd, LONG_PTR ptr)
{
	SetWindowLongPtr(hWnd, GWLP_USERDATA, ptr);
}

#endif
