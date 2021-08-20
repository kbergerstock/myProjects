//*******************************************************************
//              
//  FILE:       cAPPBASE.CPP
//              
//  AUTHOR:     Keith R. Bergerstock
//              
//  PROJECT:    wCONTROLS
//              
//  COMPONENT:  cAppWinFrame
//              
//  DATE:       29.07.2004
//              08.07.2017 
//  COMMENTS:   -
//              
//              
//*******************************************************************

// Includes
#include "cAPPBASE32.h"

cAppWinFrame::cAppWinFrame(HINSTANCE _hInstance, int _nCmdShow) : 
    Window(_hInstance,_nCmdShow)
{
    // set defaults
    appLargeIcon = appSmallIcon = MenuResourceId = 0;
    appName = appDesc = NULL;
    
    // set default back ground color
    bkGnd = (HBRUSH)(COLOR_BACKGROUND + 1);

    // set default size
    _x = _y = _h = _w = CW_USEDEFAULT;

    // set default window style
    _style = WS_OVERLAPPEDWINDOW;
    _ex_style = 0;
}

cAppWinFrame::~cAppWinFrame() 
{
	delete [] appName;
	delete [] appDesc;
}



void cAppWinFrame::SetSize(int x,int y,int w,int h)
{
  _x = x;
  _y = y;
  _w = w;
  _h = h;
}


void cAppWinFrame::SetBkGnd(HBRUSH brush)
{  
    bkGnd = brush; 
}


bool cAppWinFrame::Register()
{

  bool  isOk = false;
  
  if(!isRegistered(appName))            // if this clas has not been registered
	{									 // then register the class
        WNDCLASSEX  wndclass ;

        wndclass.style		 = CS_HREDRAW | CS_VREDRAW ;
        wndclass.lpfnWndProc = ::MainWndProc;
        wndclass.cbClsExtra	 = 0;
        wndclass.cbWndExtra	 = sizeof(Window*);
        wndclass.hInstance	 = hInstance ;

        if(appLargeIcon) 
         {
            wndclass.hIcon 	 = LoadIcon(hInstance,RSC(appLargeIcon) );
         }
        else
         {
            wndclass.hIcon 	  = LoadIcon (NULL,IDI_APPLICATION);
         }

        wndclass.hCursor		  = LoadCursor (NULL, IDC_ARROW) ;

        wndclass.hbrBackground  = bkGnd;

        if(MenuResourceId)
         {
            wndclass.lpszMenuName = RSC(MenuResourceId);
         }
        else
         {
            wndclass.lpszMenuName = NULL;
         }

        wndclass.lpszClassName = appName;

        if(appSmallIcon)
         {
            wndclass.hIconSm 	= LoadIcon(hInstance,RSC(appSmallIcon) );
         }
        else
         {
            wndclass.hIconSm    = NULL;
         }

        wndclass.cbSize		 = sizeof(WNDCLASSEX);

        isOk =  (RegisterClassEx (&wndclass) ? true: false);
   }
  else
   {
    isOk = true;
   }  

 return isOk;
}


bool cAppWinFrame::Create()					        // create the windows
{
	if(Register() )
     {
      hWnd = CreateWindowEx ( _ex_style,
                            appName,
                            appDesc,
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
        Show(nCmdShow);
       }
      }
     else
     	hWnd = 0;  

  return ( hWnd ? true: false);				// return TRUE if creation process worked
};


void cAppWinFrame::OnPaint(HWND hwnd)
{
	HDC hdc;
	PAINTSTRUCT ps;
	hdc = BeginPaint(hwnd, &ps);
	Paint(hdc);
	EndPaint(hwnd,&ps);
}

void cAppWinFrame::OnUpdate(HWND hwnd)
{
  RECT rect;
  GetClientRect(hwnd,&rect);
  Size.cx = rect.right;
  Size.cy = rect.bottom;
  InvalidateRect(hwnd,&rect,true);
}

void cAppWinFrame::OnSysCommand(HWND hwnd, UINT uCmd, int x, int y)
{
   FORWARD_WM_SYSCOMMAND(hwnd,uCmd,x,y,DefWindowProc);
}

void cAppWinFrame::OnCommand(HWND hwnd, int id, HWND hwndCtl, UINT codeNotify)
{
  MessageBox(hwnd,_T("Function Not Impemented"),_T("NOT IMPLEMENTED"),MB_ICONINFORMATION | MB_OK);
}

void cAppWinFrame::OnKey(HWND hwnd, UINT uVK, BOOL bDown, int iRepeat, UINT uFlags)
{
	FORWARD_WM_KEYUP(hwnd, uVK, iRepeat, uFlags,DefWindowProc);
}

void cAppWinFrame::OnCreated(HWND hwnd)
{
	getTextMetrics(hwnd);								// fill in the text size parameters
}

// THE CLASS CALL BACK FUNCTION
LRESULT cAppWinFrame::WndProc (HWND hwnd , UINT msg , WPARAM wParam , LPARAM lParam)
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

void cAppWinFrame::Run(void)
{
    // create the message loop and execute it
	cAppFrame app;
	app.Run(hWnd);
}
