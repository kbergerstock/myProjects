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
//              
//  COMMENTS:   -
//              
//              
//*******************************************************************

// Includes

#include "cAppBase.h"



cAppWinFrame::cAppWinFrame(HINSTANCE _hInstance, int _nCmdShow, LPSTR appName , LPSTR appDesc ) :
    cWINBASE(_hInstance, _nCmdShow, appName, appDesc)
{
    // set defaults
    SetStyle( WS_OVERLAPPEDWINDOW);
    SetExStyle(0);

    // fix try register class catch
    try
    {
        if (Register())
        {
            Create();
        }
    }
    catch (...)
    {
        // FIX HANDLE THE ERROR
    }
}

cAppWinFrame::~cAppWinFrame() 
{
    //fix unregister class
}

// create the window
bool cAppWinFrame::Create()					        
{
    hwnd = CreateWindowEx( _ex_style,
                        szWinName,
                        szWinDesc,
                        _style,
                        _x,						// set window orgin
                        _y,
                        _w,						// set window height
                        _h,						// set window width
                        NULL,
                        NULL,
                        hInstance(),
                        NULL) ;

    if(hWnd)									// if creation process was successful
    {
        SetPointer(hwnd,LONG_PTR(this));		// set a pointer to the class into the CbWndExtra
        SendMessage(hwnd,WM_WIN_CREATED,0,0L);	// send a window created message to the call back function
        Show(nCmdShow);
    }
  return ( hWnd ? true: false);				    // return true if creation process worked
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
  _w = rect.right;
  _y = rect.bottom;
  InvalidateRect(hwnd,&rect,true);
}

void cAppWinFrame::OnSysCommand(HWND hwnd, UINT uCmd, int x, int y)
{
   FORWARD_WM_SYSCOMMAND(hwnd,uCmd,x,y,DefWindowProc);
}

void cAppWinFrame::OnCommand(HWND hwnd, int id, HWND hwndCtl, UINT codeNotify)
{
  MessageBox(hwnd,"Function Not Impemented","NOT IMPLEMENTED",MB_ICONINFORMATION | MB_OK);
}

void cAppWinFrame::OnKey(HWND hwnd, UINT uVK, bool bDown, int iRepeat, UINT uFlags)
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
}
