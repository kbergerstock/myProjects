#include "appbase.h"

// this is a test this is not a good test but this is a test

// ---------------------------------------------------------------- \\

AppWinFrame::AppWinFrame(HINSTANCE _hInstance, int _nCmdShow) : Window(_hInstance,_nCmdShow)
{
  bkGnd = (HBRUSH)(COLOR_WINDOW + 1);
  lstrcpy(AppName,"App Frame");
  lstrcpy(AppDesc,"Application Frame");
  _x = _y = _h = _w = CW_USEDEFAULT;
  AppLargeIcon[0] = AppSmallIcon[0] = AppMenu[0] = '\0';
  MenuResourceId = 0;
  _style = WS_OVERLAPPEDWINDOW;
  _ex_style = 0;
}

AppWinFrame::~AppWinFrame() {}

void AppWinFrame::SetName(LPSTR Name, LPSTR Desc)
{ lstrcpyn(AppName,Name,39); lstrcpyn(AppDesc,Desc,39); }

void AppWinFrame::SetIcon(LPSTR icon)
{  lstrcpyn(AppLargeIcon,icon,39); }

void AppWinFrame::SetSmallIcon(LPSTR icon)
{  lstrcpyn(AppSmallIcon,icon,39); }

void AppWinFrame::SetMenu(LPSTR menu)
{ lstrcpyn(AppMenu,menu,39); }

void AppWinFrame::SetSize(int x,int y,int w,int h)
{
  _x = x;
  _y = y;
  _w = w;
  _h = h;
}

void AppWinFrame::SetBkGnd(HBRUSH brush)
{  bkGnd = brush; }

bool AppWinFrame::Register(void)
{
  szWinName = AppName;
  szWinDesc = AppDesc;
  int isOk;
  
  if(!isRegistered(AppName))            // if this clas has not been registered
	{									// then register the class
	  WNDCLASSEX  wndclass ;

	  wndclass.style		 = CS_HREDRAW | CS_VREDRAW ;
	  wndclass.lpfnWndProc	 = ::MainWndProc;
	  wndclass.cbClsExtra	 = 0;
	  wndclass.cbWndExtra	 = sizeof(Window*);
	  wndclass.hInstance	 = hInstance ;
	  if(AppLargeIcon[0])
		  wndclass.hIcon 	 = LoadIcon(hInstance,AppLargeIcon);
	  else
		  wndclass.hIcon 	 = LoadIcon (NULL,IDI_APPLICATION);
	  wndclass.hCursor		 = LoadCursor (NULL, IDC_ARROW) ;
	  wndclass.hbrBackground = bkGnd;
      if(MenuResourceId)
      	  wndclass.lpszMenuName= MAKEINTRESOURCE(MenuResourceId);
      else
		  wndclass.lpszMenuName  = AppMenu;
	  wndclass.lpszClassName = szWinName ;
      if(AppSmallIcon[0])
		  wndclass.hIconSm 	 = LoadIcon(hInstance,AppSmallIcon);
	  else
      	wndclass.hIconSm 	     = NULL;

      wndclass.cbSize		 = sizeof(WNDCLASSEX);

	  isOk =  (RegisterClassEx (&wndclass) ? true: false);
   }
 return isOk;
}

bool AppWinFrame::Create(void)					// create the windows
{
	if(Register() )
     {
      hWnd = CreateWindowEx ( _ex_style,
                            szWinName,
                            szWinDesc,
                            _style,
                            _x,						// set window orgin
                            _y,
                            _w,						// set window height
                            _h,						// set window width
                            NULL,
                            NULL,
                            hInstance,
                            NULL) ;

      if(hWnd)										// if creation process was successful
       {
        SetPointer(hWnd,this);						// set a pointer to the class into the CbWndExtra
        SendMessage(hWnd,WM_WIN_CREATED,0,0L);		// send a window created message to the call back function
       }
      }
     else
     	hWnd = 0;  

  return ( hWnd ? true: false);				// return TRUE if creation process worked
};


void AppWinFrame::OnPaint(HWND hwnd)
{
	HDC hdc;
	PAINTSTRUCT ps;
	hdc = BeginPaint(hwnd, &ps);
	Paint(hdc);
	EndPaint(hwnd,&ps);

//	PaintCanvas canvas(hwnd);
//    Paint(canvas);
}

void AppWinFrame::OnUpdate(HWND hwnd)
{
  RECT rect;
  GetClientRect(hwnd,&rect);
  Size.cx = rect.right;
  Size.cy = rect.bottom;
  InvalidateRect(hwnd,&rect,true);
}

#if defined(__BORLANDC__)
#pragma argsused
#endif
void AppWinFrame::OnSysCommand(HWND hwnd, UINT uCmd, int x, int y)
{
   FORWARD_WM_SYSCOMMAND(hwnd,uCmd,x,y,DefWindowProc);
}

#if defined(__BORLANDC__)
#pragma argsused
#endif
void AppWinFrame::OnCommand(HWND hwnd, int id, HWND hwndCtl, UINT codeNotify)
{
  MessageBox(hwnd,"Function Not Impemented","NOT IMPLEMENTED",MB_ICONINFORMATION | MB_OK);
}

#if defined(__BORLANDC__)
#pragma argsused
#endif
void AppWinFrame::OnKey(HWND hwnd, UINT uVK, BOOL bDown, int iRepeat, UINT uFlags)
{
	FORWARD_WM_KEYUP(hwnd, uVK, iRepeat, uFlags,DefWindowProc);
}

void AppWinFrame::OnCreated(HWND hwnd)
{
	getTextMetrics(hwnd);								// fill in the text size parameters
}

// THE CLASS CALL BACK FUNCTION
LRESULT AppWinFrame::WndProc (HWND hwnd , UINT msg , WPARAM wParam , LPARAM lParam)
 {
	 switch (msg)
	   {
		  HANDLE_MSG(hwnd,WM_PAINT,OnPaint);
		  HANDLE_MSG(hwnd,WM_SIZE,OnSize);
		  HANDLE_MSG(hwnd,WM_DESTROY,OnDestroy);
		  HANDLE_MSG(hwnd,WM_SYSCOMMAND,OnSysCommand);
		  HANDLE_MSG(hwnd,WM_COMMAND,OnCommand);
		  HANDLE_MSG(hwnd,WM_KEYUP,OnKey);
		  HANDLE_MSG(hwnd,WM_CHAR,OnChar);
		  HANDLE_MSG(hwnd,WM_TIMER,OnTimer);
          HANDLE_MSG(hwnd,WM_MOVE,OnMove);


		  case WM_UPDATE:
			OnUpdate(hwnd); 						// update the window with the wave parameters
			return 0;

		  case WM_WIN_CREATED:
			OnCreated(hwnd);						// call the window init procedure
			return 0;
		 }

	 return DefWindowProc (hwnd, msg, wParam, lParam) ;
}

void AppWinFrame::Run(void)
{
	AppFrame app;
    app.Run(hWnd);
}
