// -----------------------------------------------
//	winbase.cpp
//	(c) K. R. Bergerstock,1996
//	version 1 - initial attempt
// --------------------------------------------------

#include "windbase.h"
// --------------------------------------------------

HWND cMAIN::hDlgModeless = 0;
char cMAIN::szCurrentDir[MAX_PATH+1];
char cMAIN::szINIname[MAX_PATH+1];

HINSTANCE WinBase::hInstance = 0;

cMAIN::cMAIN()
{
   	GetCurrentDirectory(MAX_PATH ,szCurrentDir);
   	lstrcat(szCurrentDir,"\\");
}
cMAIN::~cMAIN() {}

void cMAIN::SetDlgModeless(HWND hdlg)
{ hDlgModeless = hdlg; }

void cMAIN::CreateINIname(LPSTR szFileName)
{
 lstrcpy(szINIname,szCurrentDir);
 lstrcat(szINIname,szFileName);
}

LPSTR cMAIN::GetINIname(void)
{ return szINIname; }

int cMAIN::Run(HWND hwnd)
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

#if defined(__BORLANDC__)
#pragma argsused
#endif
void WinBase::OnDestroy(HWND hwnd)
{
	if(LastFocus)
      	SetFocus(LastFocus);
	PostQuitMessage (0) ;
}

#if defined(__BORLANDC__)
#pragma argsused
#endif
void WinBase::OnSize(HWND hwnd, UINT state, int cx, int cy)
{
	Size.cx = cx;
	Size.cy = cy;
}

void WinBase::Show(void)
{
  RECT rect;
  GetClientRect(hWnd,&rect);
  Size.cx = rect.right;
  Size.cy = rect.bottom;
  InvalidateRect(hWnd,&rect,FALSE);
  Update();
}

void WinBase::ExitWindow(void)
{
	SendMessage(hWnd,WM_CLOSE,0,0L);
}

void WinBase::Clear(void)
{
  RECT rect;
  GetClientRect(hWnd,&rect);
  Size.cx = rect.right;
  Size.cy = rect.bottom;
  InvalidateRect(hWnd,&rect,TRUE);
  Update();
}

void WinBase::setFocus(void)
{
	LastFocus = SetFocus(hWnd);
}

void WinBase::getTextMetrics(HWND hwnd)
{
	 HDC hdc = GetDC(hwnd);
	 TEXTMETRIC tm;

	 GetTextMetrics(hdc,&tm);
	 cxChar = tm.tmAveCharWidth;
	 cxCaps = (tm.tmPitchAndFamily & 1 ? 3 : 2 ) * cxChar / 2;
	 cyChar = tm.tmHeight + tm.tmExternalLeading;
	 ReleaseDC(hwnd,hdc);
}

bool WinBase::isRegistered(LPSTR szClassName)
{
    WNDCLASSEX WindowClass;
	WindowClass.cbSize = sizeof(WNDCLASSEX);
	return GetClassInfoEx(hInstance,szClassName,&WindowClass);
}

void WinBase::Move(int x,int y ,int h ,int w)
{
	MoveWindow(hWnd,x,y,h,w,true);
}

LRESULT CALLBACK MainWndProc (HWND hwnd , UINT msg , WPARAM wParam , LPARAM lParam)
{
	Window *pWindow = (Window*) GetPointer( hwnd );

	if ( pWindow == 0 )
	  return DefWindowProc( hwnd, msg, wParam, lParam );
	else
	  return pWindow->WndProc( hwnd, msg, wParam, lParam );
}

