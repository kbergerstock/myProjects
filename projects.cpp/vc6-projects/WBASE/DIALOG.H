#ifndef __WINDOWS_H
#define  STRICT
#include <windows.h>
#include <windowsx.h>
#endif

#ifndef  __DIALOG_H
#define  __DIALOG_H

BOOL FAR PASCAL MainDlgProc(HWND , UINT , WPARAM , LPARAM );

class DIALOGBOX
{
  private:
	 HINSTANCE hInstance;
	 DLGPROC   lpfnDlgProc;

  protected:
	 HWND 	   hParent;
     HWND	   hDlg;

  public:
	 DIALOGBOX( HINSTANCE);
	 virtual ~DIALOGBOX();

	 virtual void Display(HWND , LPSTR);

	 virtual BOOL DlgProc(HWND , UINT , WPARAM , LPARAM ) = 0;

	 virtual void Set_hDlg(HWND);

	 HINSTANCE GetInstance(void) { return hInstance; }

};

typedef DIALOGBOX*	pDIALOGBOX;

#endif

