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
#include "aboutDialog.rh"

void DrawBitMap(HDC hdc, HBITMAP hBitmap, short xStart, short yStart);

AboutBox::AboutBox(HINSTANCE hinst) :
   cDIALOGBOX(hinst), hControl(0)
{
  hBitmap = 0;
}

AboutBox::AboutBox(HINSTANCE hinst, int id_bitmap) :
   cDIALOGBOX(hinst), hControl(0)
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
   InvalidateRect(hwnd,NULL,true);
   UpdateWindow(hwnd);

   if(hBitmap)
    {
	   HDC hdc = GetDC(hwnd);
	   DrawBitMap(hdc,hBitmap,2,2);
	   ReleaseDC(hwnd,hdc);
    }   
}

INT_PTR AboutBox::DlgProc(HWND hDlg, UINT msg, WPARAM wparam, LPARAM lparam)
{
  switch(msg)
	{
	  case WM_PAINT:
		   Paint(hControl);
		   return true;

	  case WM_INITDIALOG:
		   hControl = GetDlgItem(hDlg,IDD_ABOUT_DISPLAY);
		   return true;

	  case WM_COMMAND:
			 switch(wparam)
			  {
			  case IDD_ABOUT_OK:
				EndDialog(hDlg,0);
				return true;
		   }
		  break;
   }
  return false;
}


