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

#include "windbase.h"

// --------------------------------------------------
// static members

HWND cMSGLOOP::hDlgModeless = 0;

HINSTANCE cWINBASE::hInstance = 0;

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
	Window *pWindow = (Window*) GetPointer( hwnd );

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

cMSGLOOP::cMSGLOOP()
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
 bQuit = FALSE;
 while(!bQuit)
  {
	if(PeekMessage( &msg,NULL,0,0,PM_REMOVE) )
	  {
		if(msg.message == WM_QUIT)
			bQuit = TRUE;
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

    while( (bQuit = GetMessage( &msg, NULL, 0, 0 )) != 0)
     { 
        if (bQuit == -1)
          {
            // handle the error and possibly exit
            throw("WINDOW ERROR");
          }
        else if(hDlgModeless == 0 || !IsDialogMessage(hDlgModeless, &msg) )
		  {
			  TranslateMessage (&msg) ;
			  DispatchMessage (&msg) ;
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

void cWINBASE::OnDestroy(HWND hwnd)
{
	if(LastFocus)
      	SetFocus(LastFocus);
	PostQuitMessage (0) ;
}

void cWINBASE::OnSize(HWND hwnd, UINT state, int cx, int cy)
{
	Size.cx = cx;
	Size.cy = cy;
}

void cWINBASE::Show(void)
{
  RECT rect;
  GetClientRect(hWnd,&rect);
  Size.cx = rect.right;
  Size.cy = rect.bottom;
  InvalidateRect(hWnd,&rect,FALSE);
  Update();
}

void cWINBASE::ExitWindow(void)
{
	SendMessage(hWnd,WM_CLOSE,0,0L);
}

void cWINBASE::Clear(void)
{
  RECT rect;
  GetClientRect(hWnd,&rect);
  Size.cx = rect.right;
  Size.cy = rect.bottom;
  InvalidateRect(hWnd,&rect,TRUE);
  Update();
}

void cWINBASE::setFocus(void)
{
	LastFocus = SetFocus(hWnd);
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
	return GetClassInfoEx(hInstance,szClassName,&WindowClass) ? true : false;
}

void cWINBASE::Move(int x,int y ,int h ,int w)
{
	MoveWindow(hWnd,x,y,h,w,true);
}




