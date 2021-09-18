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
        #define OEMRESOURCE
    #endif

    #define WIN32_LEAN_AND_MEAN
    
    #include <windows.h>
    #include <WinUser.h>
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

	void Run(HWND);
    void run();

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
  private:
    static HINSTANCE __hInstance;

  protected:
    int       __nCmdShow;

	HWND    __hWnd;
    HWND    __LastFocus;

    char    szWinName[WIN_NAME_SIZE];	// application name
    char    szWinDesc[WIN_DESC_SIZE];	// application description

	//SIZE    Size;		   			    // holds width and height of client screen
	LONG    cxChar,cyChar,cxCaps;       // font size
    HBRUSH  bkGnd;					    // window background
    HANDLE  menu;
    HANDLE  icon;
    HANDLE  iconSm;
    HANDLE  cursor;
    HWND    hwndParent;

    bool    bQuit;				// flag to send app quit message

    DWORD   class_style;	    // class style
    DWORD   dwExtStyle;         // extended window style
    DWORD   dwStyle;			// window style

    int    _x;					// window orgin
    int    _y;
    int    _w;					// window width
    int    _h;					// window hieght

  public:
 
    cWINBASE(int _nCmdShow, LPCSTR szName = nullptr, LPCSTR szDesc = nullptr);
    
    ~cWINBASE() {};

    static void set_hInstance(HINSTANCE);
    inline HINSTANCE hInstance() { return __hInstance; }
    inline HWND hWnd() { return __hWnd; }
    inline void setHWND(HWND hwnd) { __hWnd = hwnd; }
    inline int nCmdShow() { return __nCmdShow; }
	void getTextMetrics(HWND);
    void Show( int nCmdShow) { ShowWindow(hWnd(), nCmdShow); }
    void SetName(LPCSTR, LPCSTR);
    void setFocus();
	void Show();
    void Clear();
    void ExitWindow();

	void Update() { UpdateWindow(hWnd()); }
    void Move(int,int,int,int);

    bool Create();              // create the window    
	bool Register();            // register the window class
    bool isRegistered(LPSTR);

	virtual void OnPaint(HWND) = 0;
	virtual void OnDestroy(HWND);
	virtual void OnSize(HWND , UINT , int , int );
	virtual void OnCommand(HWND , int , HWND , UINT ) = 0;
	virtual LRESULT WndProc( HWND, UINT, WPARAM , LPARAM ) = 0;

    virtual HANDLE loadCursor(); 
    virtual HANDLE loadIcon(int id); 
    inline void setMenu(int id) {menu = HANDLE(MAKEINTRESOURCE(id)); }
    inline void setIcon(int id) { icon = (id == NULL) ? NULL : loadIcon(id); }
    inline void setSmIcon(int id) { iconSm = (id == NULL) ? NULL : loadIcon(id); }
    inline void SetSize(int w, int h) { _h = h; _w = w; };
    inline void SetPosition(int x, int y) { _x = x; _y = y; };
    inline void SetClassStyle(DWORD style) { class_style = style; };
    inline void SetExtStyle(DWORD style) { dwExtStyle = style; }
    inline void SetWinStyle(DWORD style) { dwStyle = style; };
    inline void SetBkGnd(HBRUSH brush) { bkGnd = brush; };
    inline void setParentHwnd(HWND parent) { hwndParent = parent; }
    inline HBRUSH BkGnd() { return bkGnd; };
    inline HWND hParent() { return hwndParent; }
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
