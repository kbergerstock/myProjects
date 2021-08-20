// -----------------------------------------------
//	winbase.h
//	(c) K. R. Bergerstock,1996
//	version 2 - converted to win 32 api calls 
// --------------------------------------------------

#ifndef __WINDOWS_H
#define  STRICT
#include <windows.h>
#include <windowsx.h>
#endif

#ifndef __WINDBASE_H
#define  __WINDBASE_H

#define  WM_WIN_CREATED (WM_USER+255)
#define  WM_WIN_CLEAR	(WM_USER+256)
#define  WM_CHILD_CLEAR (WM_USER+257)
#define  WM_UPDATE		(WM_USER+258)

//--------------------------------------------------------------------

LRESULT CALLBACK MainWndProc (HWND , UINT , WPARAM , LPARAM );

//--------------------------------------------------------------------

class cMAIN
{
  private:
	static HWND hDlgModeless;

  protected:
    int bQuit;

  public:
	static char szCurrentDir[];
	static char szINIname[];

	cMAIN();
    ~cMAIN();

	int Run(HWND);
	virtual void AuxRun(HWND) {};
	void  CreateINIname(LPSTR);
	LPSTR GetINIname(void);
    static void  SetDlgModeless(HWND);
    static HWND  GetDlgModeless(void) { return hDlgModeless; }
};


//-------------------------------------------------------------------- 

class WinBase
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
    WinBase() : LastFocus(0) {};
    WinBase(HINSTANCE _hInstance, int _nCmdShow = true)
        : LastFocus(0) {hInstance = _hInstance; nCmdShow = _nCmdShow; };
    ~WinBase() {};

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

class Window : public WinBase
{
  protected:

  public:
    Window(HINSTANCE _hInstance, int _nCmdShow = true)
        : WinBase(_hInstance,_nCmdShow){}
	virtual bool Create(void) = 0;

};

class ChildWindow : public WinBase
{
  protected:
	int	 Control_id;						// child window control id
	HWND  hParent;							// handle to the parent window

  public:


	int GetID(void)	 { return Control_id; }

	virtual HWND Create (HWND, int ) = 0;

};

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
