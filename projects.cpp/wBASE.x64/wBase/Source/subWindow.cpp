//	cwframe.cpp
//	(c) K. R. Bergerstock,1997
//	child window frame
// --------------------------------------------------

#ifndef  __subWindow_h
#include "subWindow.h"
#endif

subWindow::subWindow( int _nCmdShow, LPCSTR name, LPCSTR desc) : 
	cWINBASE(_nCmdShow, name, desc), Control_id(0), newBK(0), oldBK(0)
{
}

// create the window
bool subWindow::CreateControl(HWND hwndParent, int control_id)
{
	bool isOk = false;
	if (isRegistered() )
	{
		Control_id = control_id;
		setParentHwnd(hwndParent);
		setIcon(NULL);
		setSmIcon(NULL);
		loadCursor();
		isOk = Create(control_id);
	}
	return isOk;
}

void subWindow::OnUpdate(HWND hwnd)
{
  RECT rect;
  GetClientRect(hwnd,&rect);
  InvalidateRect(hwnd,&rect,true);
}


void subWindow::OnCommand(HWND hwnd, int id, HWND hwndCtl, UINT codeNotify)
{
    MessageBox(hwnd,"Function Not Impemented","NOT IMPLEMENTED",MB_ICONINFORMATION | MB_OK);
}

void subWindow::OnPaint(HWND hwnd)
{
   HDC hdc;
   PAINTSTRUCT ps;
   hdc = BeginPaint(hwnd, &ps);
   Paint(hwnd,hdc); 					// call the top level paint module
   EndPaint(hwnd,&ps);
}

void subWindow::OnCreated(HWND hwnd)
{
  getTextMetrics(hwnd);
}


void subWindow::OnDestroy(HWND hWnd)
{
	setHWND(NULL);
	if(bQuit)
		PostQuitMessage (0);
}

// THE CLASS CALL BACK FUNCTION
LRESULT subWindow::WndProc (HWND hwnd , UINT msg , WPARAM wParam , LPARAM lParam)
 {
	 switch (msg)
	   {
		  HANDLE_MSG(hwnd,WM_PAINT,OnPaint);
		  HANDLE_MSG(hwnd,WM_SIZE,OnSize);
		  HANDLE_MSG(hwnd,WM_DESTROY,OnDestroy);
		  HANDLE_MSG(hwnd,WM_COMMAND,OnCommand);
          HANDLE_MSG(hwnd,WM_CHAR,OnChar);
          HANDLE_MSG(hwnd,WM_TIMER,OnTimer);
          HANDLE_MSG(hwnd,WM_KEYUP,OnKey);

          // HANDLE THE MOUSE CLICK MESSAGES
          HANDLE_MSG(hwnd,WM_LBUTTONDOWN,OnLButtonDown);
          HANDLE_MSG(hwnd,WM_LBUTTONUP,OnLButtonUp);
          HANDLE_MSG(hwnd,WM_LBUTTONDBLCLK,OnLButtonDown);
          HANDLE_MSG(hwnd,WM_RBUTTONDOWN,OnLButtonDown);
          HANDLE_MSG(hwnd,WM_RBUTTONUP,OnLButtonUp);
          HANDLE_MSG(hwnd,WM_RBUTTONDBLCLK,OnLButtonDown);
          HANDLE_MSG(hwnd,WM_MBUTTONDOWN,OnLButtonDown);
          HANDLE_MSG(hwnd,WM_MBUTTONUP,OnLButtonUp);
          HANDLE_MSG(hwnd,WM_MBUTTONDBLCLK,OnLButtonDown);

		  case WM_UPDATE:
            OnUpdate(hwnd); 
			return 0;

		  case WM_WIN_CREATED:
			OnCreated(hwnd);
			return 0;
		 }

	 return DefWindowProc (hwnd, msg, wParam, lParam) ;
 }

