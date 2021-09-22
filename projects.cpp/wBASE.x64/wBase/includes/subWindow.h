// -----------------------------------------------
//	cwframe.h
//	(c) K. R. Bergerstock,1996
//	base class for child windows
// --------------------------------------------------

#ifndef __cWINBASE_H
#include "cWINBASE.h"
#endif

#ifndef  __subWindow_h
#define  __subWindow_h

// sub windows are used to create child windows or custom controls
class subWindow : public cWINBASE
{
protected:
	int	  Control_id;			// child window control id

	COLORREF newBK;
	COLORREF oldBK;

	 // message cracker handling routines
	virtual void OnCommand(HWND hWnd, int id, HWND hwndCtl, UINT codeNotify);
	virtual void OnKey(HWND, UINT, bool, int, UINT) {};
	virtual void OnChar(HWND, UINT, int) {};
	virtual void OnTimer(HWND, UINT) {};
	virtual void OnUpdate(HWND);
	virtual void OnPaint(HWND);
	virtual void OnCreated(HWND);
	virtual void OnDestroy(HWND);
	virtual void OnLButtonDown(HWND hWnd, bool fDoubleClick, int x, int y, UINT keyFlags) {};
	virtual void OnLButtonUp(HWND hWnd, int x, int y, UINT keyFlags) {};
	virtual void OnRButtonDown(HWND hWnd, bool fDoubleClick, int x, int y, UINT keyFlags) {};
	virtual void OnRButtonUp(HWND hWnd, int x, int y, UINT flags) {};
	virtual void OnMButtonDown(HWND hWnd, bool fDoubleClick, int x, int y, UINT keyFlags) {};
	virtual void OnMButtonUp(HWND hWnd, int x, int y, UINT flags) {};

	// child window procedure
	virtual LRESULT WndProc(HWND, UINT, WPARAM, LPARAM);

public:
	inline int GetID(void) { return Control_id; }

	subWindow(int , LPCSTR , LPCSTR);

	bool CreateControl(HWND, int);

	virtual void Paint(HWND,HDC) = 0;

};
#endif
