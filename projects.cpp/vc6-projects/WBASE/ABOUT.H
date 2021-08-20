#ifndef  __WINDOWS_H
#define  STRICT
#include <windows.h>
#include <windowsx.h>
#endif

#ifndef __ABOUT_H
#define  __ABOUT_H

#include "dialog.h"

class AboutBox : public DIALOGBOX
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
