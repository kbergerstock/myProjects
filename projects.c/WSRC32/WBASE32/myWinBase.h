// -----------------------------------------------
//	myWinBase.h (fomally wm_msgs.h)
//	(c) K. R. Bergerstock,1996, 2017
//	version 2 - converted to win 32 api calls 
//  and modified to UNICODE 2017
// --------------------------------------------------

#include "myWindows.h"
#include <TCHAR.h>

#ifndef __myWinBase_H
#define  __myWinBase_h

//--------------------------------------------------------------------
LRESULT CALLBACK MainWndProc (HWND , UINT32 , WPARAM , LPARAM );
//--------------------------------------------------------------------
TCHAR* TDEEPCOPY(TCHAR*);
#define RSC(IDS) (MAKEINTRESOURCE(IDS))
//--------------------------------------------------------------------

class cMAIN
{
  private:
	static HWND hDlgModeless;
	TCHAR* szCurrentDir;
	TCHAR* szINIname;

  protected:
    int bQuit;

  public:
	cMAIN();
    ~cMAIN();

	int Run(HWND);                  // message handler loop
	virtual void AuxRun(HWND) {};
	void  CreateINIname(TCHAR*);
	const TCHAR* GetINIname(void);
    static void  SetDlgModeless(HWND);
    static HWND  GetDlgModeless(void) { return hDlgModeless; }
};

//-------------------------------------------------------------------- 

class WinBase
{
private:

	TCHAR* appName;
	TCHAR* appDesc;

  protected:
    static HINSTANCE hInstance;
    int nCmdShow;

	HWND hWnd;
    HWND LastFocus;

	SIZE Size;		   			// holds width and height of client screen
	UINT32 cxChar,cyChar,cxCaps;

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
    
    bool isRegistered(TCHAR*);

	virtual bool Register(void) = 0;

	virtual void OnPaint(HWND) = 0;
	virtual void OnDestroy(HWND);
	virtual void OnSize(HWND , UINT , int , int );
	virtual void OnCommand(HWND , int , HWND , UINT ) = 0;

	virtual LRESULT WndProc( HWND, UINT, WPARAM , LPARAM ) = 0;
	TCHAR*  getStringTableElement(UINT ids);

	void    setAppName(TCHAR* Name) { appName = TDEEPCOPY(Name); }
	void    setAppName(UINT IDS) { appName = getStringTableElement(IDS); }
	TCHAR*  getAppName() { return appName; }

	void    setAppDesc(TCHAR* desc) { appDesc = TDEEPCOPY(desc); }
	void    setAppDesc(UINT ids) { appDesc = getStringTableElement(ids); }
	TCHAR*  getAppDesc() { return appDesc; }

	HWND    GetWindowHandle(void) { return hWnd; }
    HWND    operator() (void) { return hWnd; }
    static  HINSTANCE GetInstance(void) { return hInstance; }

};

// -------------------------------------------------------------------------
class Window : public WinBase
{
  protected:

  public:
    Window(HINSTANCE _hInstance, int _nCmdShow = true)
        : WinBase(_hInstance,_nCmdShow){}
	virtual bool Create(void) = 0;
};

// ------------------------------------------------------------------------
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
