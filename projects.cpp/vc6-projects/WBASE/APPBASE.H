
#ifndef __WINDBASE_H
#include "windbase.h"
#endif

// #ifndef __CANVAS_H
// #include "canvas.h"
// #endif

#ifndef __APPBASE_H
#define __APPBASE_H

#if defined(__BORLANDC__)
#pragma argsused
#endif
class AppFrame : public	cMAIN
{

  public:
  AppFrame () : cMAIN() {};
  virtual ~AppFrame() {};

  virtual void AuxRun(HWND) {};
};


class AppWinFrame : public Window
{
  protected:
	HBRUSH bkGnd;			// application background
	char AppName[40];		// application name
	char AppDesc[40];		// application description
	char AppMenu[40];		// application menu name
	char AppLargeIcon[40];	// application large icon
    char AppSmallIcon[40];	// application small icon
    int  MenuResourceId;	// id of a menu resource	

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
	virtual void OnKey(HWND , UINT , BOOL , int , UINT );
	virtual void OnChar(HWND,UINT,int) {};
	virtual void OnTimer(HWND,UINT){};
    virtual void OnMove(HWND,int,int){};

    virtual void Paint(HDC hdc) {};
//    virtual void Paint(Canvas& canvas) {};

    //class window procedure
	virtual LRESULT WndProc( HWND, UINT, WPARAM , LPARAM );

  public:
	bool Register(void);
	bool Create(void);
	void SetName(LPSTR,LPSTR);
	void SetMenu(LPSTR);
    void SetMenu(int id) { MenuResourceId = id; }
	void SetIcon(LPSTR);
    void SetSmallIcon(LPSTR);
	void SetSize(int,int,int,int);
    void SetStyle(DWORD style) { _style = style; };
    void SetExStyle(DWORD style) { _ex_style = style; };
	void SetBkGnd(HBRUSH);
	HBRUSH GetBkGnd(void) { return bkGnd; };

    void Run(void);

	AppWinFrame(HINSTANCE,int);
	~AppWinFrame();

};

#endif
