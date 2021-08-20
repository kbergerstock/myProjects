// multiline edit control
// medit.cpp

#include "medit.h"
#include "cfile.h"

HWND mEDIT::Create(HWND hPwnd,HINSTANCE hInstance)
{
  hwndEdit = CreateWindow ( "edit",    			// edit class
						NULL,					// no title
						WS_CHILD | WS_VISIBLE | WS_HSCROLL | WS_VSCROLL | WS_BORDER | ES_LEFT | ES_MULTILINE | ES_AUTOHSCROLL | ES_AUTOVSCROLL,
						0,
						0,
						0,
						0,
						hPwnd,		  			// parents window handle
						HMENU(MEDIT_ID),        // control id
						hInstance,				// program instance
						NULL) ;					// no extra parameters

  return hwndEdit;
}

HWND mEDIT::Destroy(void)
{
   DestroyWindow(hwndEdit);
   hwndEdit = NULL;
   return hwndEdit;
}

void mEDIT::SetFocus(void)
{	::SetFocus(hwndEdit); }

void mEDIT::getTextMetrics(HWND hwnd)
{
	 HDC hdc = GetDC(hwnd);
	 TEXTMETRIC tm;

	 GetTextMetrics(hdc,&tm);
	 cxChar = tm.tmAveCharWidth;
	 cxCaps = (tm.tmPitchAndFamily & 1 ? 3 : 2 ) * cxChar / 2;
	 cyChar = tm.tmHeight + tm.tmExternalLeading;
	 ReleaseDC(hwnd,hdc);
}

void mEDIT::GetSize(HWND hPwnd)
{
   RECT rect;
   GetClientRect(hPwnd,&rect);					// get the size of the parent window
   getTextMetrics(hPwnd);

   _x = _y = 0;
   _w = rect.right;
   _h = rect.bottom - (cyChar + 4);
}

void mEDIT::Draw(HWND hPwnd)
{
  GetSize(hPwnd);
  MoveWindow(hwndEdit,_x,_y,_w,_h,TRUE);
}

// given a file name read it and put it in the edit control
BOOL mEDIT::FileRead(LPSTR szFileName)
{
	cFILE	File;
	LPSTR 	lpStrBuffer = LPSTR(File.ReadFile(szFileName));
	if(lpStrBuffer != NULL)
		SetWindowText(hwndEdit,lpStrBuffer);

	return lpStrBuffer == NULL ? FALSE : TRUE;
}


void mEDIT::FileWrite(LPSTR szFileName)
{
	cFILE File;
	WORD	wLength = GetWindowTextLength(hwndEdit);
	HGLOBAL	hBuffer = HGLOBAL(SendMessage(hwndEdit,EM_GETHANDLE,0,0L));
	LPBYTE 	lpBuffer = LPBYTE(LocalLock(hBuffer) );
	File.WriteFile(szFileName,lpBuffer,wLength);
	LocalUnlock(hBuffer);

}

void mEDIT::New(void)
{ SetWindowText(hwndEdit,"\0"); }

