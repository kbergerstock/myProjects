#include "about.h"
#include "stdmenu.h"

void DrawBitMap(HDC hdc, HBITMAP hBitmap, short xStart, short yStart);

AboutBox::AboutBox(HINSTANCE hinst) :
   DIALOGBOX(hinst)
{
  hBitmap = LoadBitmap(hinst,MAKEINTRESOURCE(ABOUT_BM) );
}

AboutBox::AboutBox(HINSTANCE hinst, int id_bitmap) :
   DIALOGBOX(hinst)
{
  hBitmap = LoadBitmap(hinst,MAKEINTRESOURCE(id_bitmap) );
}

AboutBox::~AboutBox()
{
  if(hBitmap)
	DeleteObject(hBitmap);
}

void AboutBox::Paint(HWND hwnd)
{
   InvalidateRect(hwnd,NULL,TRUE);
   UpdateWindow(hwnd);

   if(hBitmap)
    {
	   HDC hdc = GetDC(hwnd);
	   DrawBitMap(hdc,hBitmap,2,2);
	   ReleaseDC(hwnd,hdc);
    }   
}

#if defined(__BORLANDC__)
#pragma argsused
#endif
BOOL AboutBox::DlgProc(HWND hDlg, UINT msg, WPARAM wparam, LPARAM lparam)
{
  switch(msg)
	{
	  case WM_PAINT:
		   Paint(hControl);
		   return TRUE;

	  case WM_INITDIALOG:
		   hControl = GetDlgItem(hDlg,IDD_DISPLAY);
		   return TRUE;

	  case WM_COMMAND:
			 switch(wparam)
			  {
			  case IDD_ABOUT_OK:
				EndDialog(hDlg,0);
				return TRUE;
		   }
		  break;
   }
  return FALSE;
}


