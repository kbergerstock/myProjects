#ifndef __WINDOWS_H
#define  STRICT
#include <windows.h>
#include <windowsx.h>
#endif

#ifndef  __MODELESS_H
#define  __MODELESS_H

// class defineing a base modeless dialog box

class MODELESS
{
  private:
  	 HWND  		hPrevious;				// the previous modeless window
  protected:
     DLGPROC    lpfnDlgProc;
     HINSTANCE  hInstance;
	 HWND 	    hParent;
     HWND	    hDlg;
   	 COLORREF 	newBK;
	 HBRUSH   	hBkBrush;

   	 COLORREF 	hiliteBK;
	 HBRUSH   	hHiliteBrush;

  public:
	 MODELESS( HINSTANCE );
	 virtual ~MODELESS();

     virtual BOOL DlgProc(HWND hDlg, UINT msg, WPARAM wParam, LPARAM lParam);

     HWND Create(HWND ,LPSTR );

     void Display(void);

     void Destroy(void);

     void Update(void);

     HWND GetDlgHwnd(void) { return hDlg; }

	 HINSTANCE GetInstance(void) { return hInstance; }
};

typedef MODELESS*	pMODELESS;

#endif

