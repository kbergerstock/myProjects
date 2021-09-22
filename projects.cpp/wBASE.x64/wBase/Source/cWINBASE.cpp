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
   	StringCchCat(szCurrentDir,MAX_PATH,"\\");
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

void cMSGLOOP::Run(HWND hwnd)
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
void cMSGLOOP::run()
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
}

//*******************************************************************
//              
//  CLASS:      cWINBASE
//              
//  COMMENTS:   - base window class
//              
//*******************************************************************

HINSTANCE cWINBASE::__hInstance = NULL;
void cWINBASE::set_hInstance(HINSTANCE hInstance)
{
	__hInstance = hInstance;
}

cWINBASE::cWINBASE( int _nCmdShow, LPCSTR szName, LPCSTR szDesc)
	: __nCmdShow(_nCmdShow), __hWnd(0), __LastFocus(0), cxChar(0), cyChar(0), cxCaps(0)
{
	SetName(szName, szDesc);
	menu   = NULL;
	icon   = NULL;
	iconSm = NULL;
	cursor = loadCursor();

	// set default back ground color
	bkGnd = (HBRUSH)(COLOR_BACKGROUND + 1);
	// set default size
	_x = 10;
	_y = 10;
	_h = 480;
	_w = 640;
}

void cWINBASE::SetName(LPCSTR szName, LPCSTR szDesc = NULL)
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
	if(__LastFocus)
      	SetFocus(__LastFocus);
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
  GetClientRect(hWnd(),&rect);
  _w = rect.right;
  _h = rect.bottom;
  InvalidateRect(hWnd(),&rect,false);
  Update();
}

HANDLE cWINBASE::loadMenu(int id) 
{
	return (id == NULL) ? NULL :MAKEINTRESOURCE(id);
}

HANDLE cWINBASE::loadIcon(int id)
{
	return LoadImage(hInstance(), MAKEINTRESOURCE(id), IMAGE_ICON, 0, 0, LR_DEFAULTSIZE); 
}

HANDLE cWINBASE::loadCursor()
{
	return LoadImage(NULL, MAKEINTRESOURCE(OCR_NORMAL), IMAGE_CURSOR, 0, 0, LR_DEFAULTSIZE | LR_SHARED);
}

void cWINBASE::ExitWindow()
{
	SendMessage(hWnd(),WM_CLOSE,0,0L);
}

void cWINBASE::Clear()
{
  RECT rect;
  GetClientRect(hWnd(),&rect);
  _w = rect.right;
  _h = rect.bottom;
  InvalidateRect(hWnd(),&rect,true);
  Update();
}

void cWINBASE::setFocus()
{
	__LastFocus = SetFocus(hWnd());
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

bool cWINBASE::isRegistered()
{
    WNDCLASSEX WindowClass;
	WindowClass.cbSize = sizeof(WNDCLASSEX);
	return GetClassInfoEx(hInstance(),szWinName,&WindowClass) ? true : false;
}

void cWINBASE::Move(int x,int y ,int h ,int w)
{
	MoveWindow(hWnd(),x,y,h,w,true);
}
