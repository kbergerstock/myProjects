//*******************************************************************
//              
//  FILE:       Windbase.cpp
//              
//  AUTHOR:     Keith R. Bergerstock
//              
//  PROJECT:    WBASE32
//              
//  COMPONENT:  cMAIN
//              
//  DATE:       29.07.2004
//              
//  COMMENTS:   - - version 2 - converted to win 32 api calls 
//              
//              
//*******************************************************************

// Includes
#include <strsafe.h>
#include "cWINBASE.h"

// --------------------------------------------------
// static members

HWND cMSGLOOP::hDlgModeless = 0;

//*******************************************************************
//              
//  FUNCTION:   MainWndProc
//              
//  RETURNS:    LRESULT CALLBACK
//              
//  PARAMETERS: HWND,UINT,WPARAM,LPARAM
//              
//  COMMENTS:   - main call back used by library to process window messages
//              
//*******************************************************************

LRESULT CALLBACK MainWndProc (HWND hwnd , UINT msg , WPARAM wParam , LPARAM lParam)
{
	cWINBASE *pWindow = (cWINBASE*) GetPointer( hwnd );

	if ( pWindow == 0 )
	  return DefWindowProc( hwnd, msg, wParam, lParam );
	else
	  return pWindow->WndProc( hwnd, msg, wParam, lParam );
}

//*******************************************************************
//              
//  CLASS:      cMAIN
//              
//  COMMENTS:   - windows message loop class
//              
//*******************************************************************

cMSGLOOP::cMSGLOOP():bQuit(false)
{
   	GetCurrentDirectory(MAX_PATH ,szCurrentDir);
   	lstrcat(szCurrentDir,"\\");
}

cMSGLOOP::~cMSGLOOP() {}

void cMSGLOOP::SetDlgModeless(HWND hdlg)
{ 
    hDlgModeless = hdlg; 
}
//*******************************************************************
//              
//  FUNCTION:   Run
//              
//  RETURNS:    int
//              
//  PARAMETERS: HWND hwnd
//              
//  COMMENTS:   - message loop processor that allows auxRun task to perfoem
//              
//*******************************************************************

int cMSGLOOP::Run(HWND hwnd)
{
 MSG msg;
 bQuit = false;
 while(!bQuit)
  {
	if(PeekMessage( &msg,NULL,0,0,PM_REMOVE) )
	  {
		if(msg.message == WM_QUIT)
			bQuit = true;
        else if(hDlgModeless == 0 || !IsDialogMessage(hDlgModeless, &msg) )
			{
			  TranslateMessage (&msg) ;
			  DispatchMessage (&msg) ;
			}
	  }
	else
	 {
	  AuxRun(hwnd);
	 }
  }
 return msg.wParam ;
}

//*******************************************************************
//              
//  FUNCTION:   MessageLoop
//              
//  RETURNS:    int
//              
//  PARAMETERS: -
//              
//  COMMENTS:   - normal BLOCKED windows message loop
//              
//*******************************************************************
int cMSGLOOP::MessageLoop()
{
    MSG msg;

    while( (bQuit = GetMessageA( &msg, NULL, 0, 0 )) != 0)
     { 
        if (bQuit == -1)
          {
            // handle the error and possibly exit
            throw("WINDOW ERROR");
          }
        else if(hDlgModeless == 0 || !IsDialogMessage(hDlgModeless, &msg) )
		  {
			  TranslateMessage(&msg) ;
			  DispatchMessage(&msg) ;
		  }
     }

    return msg.wParam;
}

//*******************************************************************
//              
//  CLASS:      cWINBASE
//              
//  COMMENTS:   - base window class
//              
//*******************************************************************

cWINBASE::cWINBASE(HINSTANCE _hInstance, int _nCmdShow, LPSTR szName, LPSTR szDesc)
	: nCmdShow(_nCmdShow), hwnd(0), LastFocus(0), cxChar(0), cyChar(0), cxCaps(0), _x(0),_y(0),_w(0),_h(0)
{
	hinstance = _hInstance;
	SetName(szName, szDesc);
	menu = NULL;
	icon = NULL;
	iconSm = NULL;

	// set default back ground color
	bkGnd = (HBRUSH)(COLOR_BACKGROUND + 1);
	// set default size
	_x = _y = _h = _w = CW_USEDEFAULT;

}

void cWINBASE::SetName(LPSTR szName, LPSTR szDesc = NULL)
{
	if (szName == NULL)
		StringCchCopy(szWinName, WIN_NAME_SIZE - 1, "SHELL x64");
	else
		StringCchCopy(szWinName, WIN_NAME_SIZE - 1, szName);

	if (szDesc == NULL)
		StringCchCopy(szWinDesc, WIN_DESC_SIZE - 1, szWinName);
	else
		StringCchCopy(szWinDesc, WIN_DESC_SIZE - 1, szDesc);
}

void cWINBASE::OnDestroy(HWND hwnd)
{
	if(LastFocus)
      	SetFocus(LastFocus);
	PostQuitMessage (0) ;
}

void cWINBASE::OnSize(HWND hwnd, UINT state, int cx, int cy)
{
	_w = cx;
	_h = cy;
}

void cWINBASE::Show()
{
  RECT rect;
  GetClientRect(hwnd,&rect);
  _w = rect.right;
  _h = rect.bottom;
  InvalidateRect(hwnd,&rect,false);
  Update();
}

void cWINBASE::ExitWindow()
{
	SendMessage(hwnd,WM_CLOSE,0,0L);
}

void cWINBASE::Clear()
{
  RECT rect;
  GetClientRect(hwnd,&rect);
  _w = rect.right;
  _h = rect.bottom;
  InvalidateRect(hwnd,&rect,true);
  Update();
}

void cWINBASE::setFocus()
{
	LastFocus = SetFocus(hwnd);
}

void cWINBASE::getTextMetrics(HWND hwnd)
{
	 HDC hdc = GetDC(hwnd);
	 TEXTMETRIC tm;

	 GetTextMetrics(hdc,&tm);
	 cxChar = tm.tmAveCharWidth;
	 cxCaps = (tm.tmPitchAndFamily & 1 ? 3 : 2 ) * cxChar / 2;
	 cyChar = tm.tmHeight + tm.tmExternalLeading;
	 ReleaseDC(hwnd,hdc);
}

bool cWINBASE::isRegistered(LPSTR szClassName)
{
    WNDCLASSEX WindowClass;
	WindowClass.cbSize = sizeof(WNDCLASSEX);
	return GetClassInfoEx(hinstance,szClassName,&WindowClass) ? true : false;
}

void cWINBASE::Move(int x,int y ,int h ,int w)
{
	MoveWindow(hwnd,x,y,h,w,true);
}
