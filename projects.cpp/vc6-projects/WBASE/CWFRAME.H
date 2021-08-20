// -----------------------------------------------
//	cwframe.h
//	(c) K. R. Bergerstock,1996
//	base class for child windows
// --------------------------------------------------

#ifndef __WINDBASE_H
#include "windbase.h"
#endif

#ifndef  __CWFRAME_H
#define  __CWFRAME_H

class cWinFrame: public ChildWindow
{
  protected:
   bool isRegisteredOk;

   COLORREF newBK;
   COLORREF oldBK;
   HBRUSH   bkGnd;

   bool     bQuit;			// flag to send app quit message

   DWORD    _style;         // window style
   DWORD    _ex_style;		// exteneded style

   LONG _x;                  // window orgin
   LONG _y;
   LONG _w;                  // window width
   LONG _h;                  // window hieght

	// message cracker handling routines
	virtual void OnCommand(HWND hwnd, int id, HWND hwndCtl, UINT codeNotify);
    virtual void OnKey(HWND , UINT , BOOL , int , UINT ){};
	virtual void OnChar(HWND,UINT,int) {};
	virtual void OnTimer(HWND,UINT){};
	virtual void OnUpdate(HWND);
	virtual void OnPaint(HWND);
	virtual void OnCreated(HWND);
	virtual void OnDestroy(HWND);
	virtual void OnLButtonDown(HWND hwnd, BOOL fDoubleClick, int x, int y, UINT keyFlags){};
	virtual void OnLButtonUp(HWND hwnd, int x, int y, UINT keyFlags){};
	virtual void OnRButtonDown(HWND hwnd, BOOL fDoubleClick, int x, int y, UINT keyFlags){};
	virtual void OnRButtonUp(HWND hwnd, int x, int y, UINT flags){};
	virtual void OnMButtonDown(HWND hwnd, BOOL fDoubleClick, int x, int y, UINT keyFlags){};
	virtual void OnMButtonUp(HWND hwnd, int x, int y, UINT flags){};

    // child window procedure
	virtual LRESULT WndProc( HWND, UINT, WPARAM , LPARAM );

  public:

	cWinFrame();

    virtual bool Register(void);
    bool isRegistered(void) {return WinBase::isRegistered(szWinName); }
	HWND Create(HWND, int);
    HWND wopen(HWND,int);

	void SetSize(int,int,int,int);
    void SetLocation(int,int);
	void SetStyle(DWORD);
    void SetExStyle(DWORD);
	void SetBkGnd(HBRUSH);
	void SetName(LPSTR);
	void SetDesc(LPSTR);
    void SetQuit(void) { bQuit = TRUE; }

	virtual void Paint(HWND,HDC) = 0;

};
#endif
