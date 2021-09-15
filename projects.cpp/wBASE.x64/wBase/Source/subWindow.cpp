// -----------------------------------------------
//	cwframe.cpp
//	(c) K. R. Bergerstock,1997
//	child window frame
// --------------------------------------------------

#ifndef  __subWindow_h
#include "subWindow.h"
#endif

subWindow::subWindow(HINSTANCE hIinstance, int nCmdShow, LPSTR name, LPSTR desc) : 
	cWINBASE(hInstance, nCmdShow, name, desc)
{
  bQuit = false;
  isRegisteredOk = false;
  _style = WS_CHILDWINDOW | WS_CLIPSIBLINGS	| WS_BORDER | WS_VISIBLE;
  _ex_style = 0;
  _x = 10;
  _y = 10;
  _w = 200;
  _h = 150;

  bkGnd = HBRUSH(COLOR_WINDOW +1);
  newBK = 0;

  menu = NULL;
  icon = NULL;
  cursor = NULL;
}


// create the window
HWND subWindow::CreateControl(HWND hwndParent)
{
	HWND hwnd = 0;
	hParent = hwndParent;
	if( Register() )
	{
  		hwnd = CreateWindowEx ( _ex_style,
			                    szWinName,
				                szWinDesc,
					            _style,
						        _x,
							    _y,
	                            _w,
		                        _h,
			                    hParent, 			// parents window handle
				                HMENU(Control_id),
					            hInstance,
						        NULL) ;

	    if(hwnd)									// if creation process was successful
	    {
		    SetPointer(hWnd,LONG_PTR(this));		// set a pointer to the class into the CbWndExtra
			SendMessage(hWnd,WM_WIN_CREATED,0,0L);	// send a window created message to the call back function
		}
	}

	return  hwnd; 									// return the handle to the child window
};


bool subWindow::Register(void)
{
  isRegisteredOk = isRegistered();
  if(!isRegisteredOk) 	 				// if this clas has not been registered
   {									// then register the class
	  WNDCLASSEX     wndclass ;

	  wndclass.style		 = CS_HREDRAW | CS_VREDRAW ;
	  wndclass.lpfnWndProc	 = ::MainWndProc;
	  wndclass.cbClsExtra	 = 0;
	  wndclass.cbWndExtra	 = sizeof(cWINBASE*);
	  wndclass.hInstance	 = hInstance ;
	  wndclass.hIcon		 = HICON(icon);
	  wndclass.hIconSm		 = HICON(iconSm);
	  wndclass.hCursor		 = HCURSOR(cursor); // LoadCursor(NULL, IDC_ARROW);
	  wndclass.hbrBackground = bkGnd;
	  wndclass.lpszMenuName  = NULL;
	  wndclass.lpszClassName = szWinName ;
      wndclass.cbSize		 = sizeof(WNDCLASSEX);

	  isRegisteredOk =  (RegisterClassEx (&wndclass) ? true : false );
   }
 return isRegisteredOk;
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


void subWindow::OnDestroy(HWND hwnd)
{
	hWnd = NULL;
	if(bQuit)
		PostQuitMessage (0);
}

void subWindow::SetSize(int x,int y,int w,int h)
{
  _x = x;
  _y = y;
  _w = w;
  _h = h;
}

void subWindow::SetLocation(int x, int y)
{
	_x = x;
    _y = y;
}

void subWindow::SetStyle(DWORD style)
{ _style = style; }

void subWindow::SetExStyle(DWORD exStyle)
{ _ex_style = exStyle; }

void subWindow::SetBkGnd(HBRUSH brush)
{  bkGnd = brush; }


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

