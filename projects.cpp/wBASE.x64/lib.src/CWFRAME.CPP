// -----------------------------------------------
//	cwframe.cpp
//	(c) K. R. Bergerstock,1997
//	child window frame
// --------------------------------------------------

#ifndef __CWFRAME_H
#include "cwframe.h"
#endif

static char Name[] = "cwf" ;
static char Desc[] = "cwf";

cWinFrame::cWinFrame() : ChildWindow()
{
  hWnd = hParent = NULL;
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
  SetName(Name);
  SetDesc(Desc);
}

HWND cWinFrame::wopen(HWND hWndParent, int control_id)
{
	// if window already created, return handle
	if(hWnd != NULL) return hWnd;

	if(Create(hWndParent,control_id) )
	 {
	   Show(SW_SHOW);
	   Update();
	 }
	return hWnd;
}

// create the window
HWND cWinFrame::Create(HWND hwnd, int control_id)
{
  hParent = hwnd;
  if( Register() )
   {
  	hWnd = CreateWindowEx ( _ex_style,
                            szWinName,
                            szWinDesc,
                            _style,
                            _x,
                            _y,
                            _w,
                            _h,
                            hParent, 				// parents window handle
                            reinterpret_cast<HMENU>(control_id),
                            hInstance,
                            NULL) ;

      if(hWnd)										// if creation process was successful
       {
        SetPointer(hWnd,LONG_PTR(this));			// set a pointer to the class into the CbWndExtra
        SendMessage(hWnd,WM_WIN_CREATED,0,0L);		// send a window created message to the call back function
       }
	 }
	else
     hWnd = 0;

  return  hWnd; 								// return the handle to the child window
};


bool cWinFrame::Register(void)
{
  isRegisteredOk = isRegistered();
  if(!isRegisteredOk) 	 				// if this clas has not been registered
   {									// then register the class
	  WNDCLASSEX     wndclass ;

	  wndclass.style		 = CS_HREDRAW | CS_VREDRAW ;
	  wndclass.lpfnWndProc	 = ::MainWndProc;
	  wndclass.cbClsExtra	 = 0;
	  wndclass.cbWndExtra	 = sizeof(Window*);
	  wndclass.hInstance	 = hInstance ;
	  wndclass.hIcon		 = NULL;
	  wndclass.hCursor		 = LoadCursor (NULL, IDC_ARROW) ;
	  wndclass.hbrBackground = bkGnd;
	  wndclass.lpszMenuName  = NULL;
	  wndclass.lpszClassName = szWinName ;
      wndclass.hIconSm 	     = NULL;
      wndclass.cbSize		 = sizeof(WNDCLASSEX);

	  isRegisteredOk =  (RegisterClassEx (&wndclass) ? true : false );
   }
 return isRegisteredOk;
}


void cWinFrame::OnUpdate(HWND hwnd)
{
  RECT rect;
  GetClientRect(hwnd,&rect);
  InvalidateRect(hwnd,&rect,true);
}


void cWinFrame::OnCommand(HWND hwnd, int id, HWND hwndCtl, UINT codeNotify)
{
    MessageBox(hwnd,"Function Not Impemented","NOT IMPLEMENTED",MB_ICONINFORMATION | MB_OK);
}

void cWinFrame::OnPaint(HWND hwnd)
{
   HDC hdc;
   PAINTSTRUCT ps;
   hdc = BeginPaint(hwnd, &ps);
   Paint(hwnd,hdc); 					// call the top level paint module
   EndPaint(hwnd,&ps);
}

void cWinFrame::OnCreated(HWND hwnd)
{
  getTextMetrics(hwnd);
}


void cWinFrame::OnDestroy(HWND hwnd)
{
	hWnd = NULL;
	if(bQuit)
		PostQuitMessage (0);
}

void cWinFrame::SetSize(int x,int y,int w,int h)
{
  _x = x;
  _y = y;
  _w = w;
  _h = h;
}

void cWinFrame::SetLocation(int x, int y)
{
	_x = x;
    _y = y;
}

void cWinFrame::SetStyle(DWORD style)
{ _style = style; }

void cWinFrame::SetExStyle(DWORD exStyle)
{ _ex_style = exStyle; }

void cWinFrame::SetBkGnd(HBRUSH brush)
{  bkGnd = brush; }

void cWinFrame::SetName(LPSTR name)
{ szWinName = name; }

void cWinFrame::SetDesc(LPSTR desc)
{ szWinDesc = desc; }


// THE CLASS CALL BACK FUNCTION
LRESULT cWinFrame::WndProc (HWND hwnd , UINT msg , WPARAM wParam , LPARAM lParam)
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

