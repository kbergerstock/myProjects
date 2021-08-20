//*******************************************************************
//              
//  FILE:       ABOUT.H
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

#ifndef  __WINDOWS_H
#define  STRICT
#include <windows.h>
#include <windowsx.h>
#include <tchar.h>
#endif

#ifndef __ABOUT32_H
#define  __ABOUT32_H

#include "cDIALOG32.h"

class AboutBox : public cDIALOGBOX
{
  private:
	 HBITMAP hBitmap;
	 HWND	 hControl;

  public:

	 AboutBox(HINSTANCE);
     AboutBox(HINSTANCE,int);
	 ~AboutBox();

	 void Paint(HWND);

	 BOOL DlgProc(HWND hDlg, UINT msg, WPARAM wparam, LPARAM lparam);

};

#endif
