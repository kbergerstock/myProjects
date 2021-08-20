// -----------------------------------------------
//	myWinBase.cpp
//	(c) K. R. Bergerstock,1996, 2017
//	version 2 - converted to 32 bit code
//  and modified to handle unicode
// --------------------------------------------------

#include "myWinBase.h"
// --------------------------------------------------

HWND cMAIN::hDlgModeless = 0;
HINSTANCE WinBase::hInstance = 0;
//--------------------------------------------------------------------
TCHAR* TDEEPCOPY(TCHAR* buf)
{
	size_t t = _tcslen(buf);
	TCHAR *el = new TCHAR[t + 1];
	size_t i = 0;
	for (i = 0; i < t; i++)
		el[i] = buf[i];
	el[i] = 0;
	return el;
}
//--------------------------------------------------------------------
cMAIN::cMAIN()
{
	TCHAR* cd = new TCHAR[4098];
   	GetCurrentDirectory(MAX_PATH ,cd);
   	lstrcat(szCurrentDir,L"\\");
	szCurrentDir = TDEEPCOPY(cd);
	delete[] cd;
}

cMAIN::~cMAIN() 
{
	delete[] szCurrentDir;
	delete[] szINIname;
}

void cMAIN::SetDlgModeless(HWND hdlg)
{ hDlgModeless = hdlg; }

void cMAIN::CreateINIname(TCHAR* szFileName)
{
	size_t t = _tcslen(szCurrentDir) + _tcslen(szINIname) + 10;
	szINIname = new TCHAR[t];
	lstrcpy(szINIname,szCurrentDir);
	lstrcat(szINIname,szFileName);
}

const TCHAR* cMAIN::GetINIname(void)
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

//--------------------------------------------------------------------

void WinBase::OnDestroy(HWND hwnd)
{
	if(LastFocus)
      	SetFocus(LastFocus);
	PostQuitMessage (0) ;
}

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

bool WinBase::isRegistered(TCHAR* szClassName)
{
    WNDCLASSEX WindowClass;
	WindowClass.cbSize = sizeof(WNDCLASSEX);
	return GetClassInfoEx(hInstance,szClassName,&WindowClass);
}

void WinBase::Move(int x,int y ,int h ,int w)
{
	MoveWindow(hWnd,x,y,h,w,true);
}

TCHAR* WinBase::getStringTableElement(UINT ids)
{
	// creates a sparse copy of the resource string	
	TCHAR* buf = new TCHAR[4098];
	LoadString(hInstance, ids, buf, 4097);
	TCHAR* el = TDEEPCOPY(buf);
	delete[] buf;
	return el;
}
// ---------------------------------------------------------------------

LRESULT CALLBACK MainWndProc (HWND hwnd , UINT msg , WPARAM wParam , LPARAM lParam)
{
	Window *pWindow = (Window*) GetPointer( hwnd );

	if ( pWindow == 0 )
	  return DefWindowProc( hwnd, msg, wParam, lParam );
	else
	  return pWindow->WndProc( hwnd, msg, wParam, lParam );
}

