//*******************************************************************
//              
//  FILE:       ABOUT.CPP
//              
//  AUTHOR:     Keith R. Bergerstock
//              
//  PROJECT:    3d
//              
//  COMPONENT:  AboutBox
//              
//  DATE:       29.07.2004
//              
//  COMMENTS:   -
//              
//              
//*******************************************************************

// Includes

#include "about.h"
#include "stdmenu.rh"

void DrawBitMap(HDC hdc, HBITMAP hBitmap, short xStart, short yStart);

AboutBox::AboutBox(HINSTANCE hinst) :
   cDIALOGBOX(hinst)
{
  hBitmap = 0;
}

AboutBox::AboutBox(HINSTANCE hinst, int id_bitmap) :
   cDIALOGBOX(hinst)
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


