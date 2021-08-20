//*******************************************************************
//              
//  FILE:       cDIALOG.H
//              
//  AUTHOR:     Keith R. Bergerstock
//              
//  PROJECT:   wbase32
//              
//  COMPONENT:  cDIALOGBOX
//              
//  DATE:       29.07.2004
//              
//  COMMENTS:   - modal dialog box shell
//              
//              
//*******************************************************************

// Includes

#ifndef __WINDOWS_H
#define  STRICT
#include <windows.h>
#include <windowsx.h>
#include <tchar.h>
#endif

#ifndef  __cDIALOG32_H
#define  __cDIALOG32_H

BOOL FAR PASCAL MainDlgProc(HWND , UINT , WPARAM , LPARAM );

class cDIALOGBOX;

typedef cDIALOGBOX*	pDIALOGBOX;

class cDIALOGBOX
{
  private:
	 HINSTANCE      hInstance;
     HWND           hDlgWin;
     pDIALOGBOX     parent;             // used to set up a linked list
    
     friend  BOOL FAR PASCAL MainDlgProc(HWND , UINT , WPARAM , LPARAM ); 

     void cDIALOGBOX::set_handle(HWND hdlg);

  protected:
	 HWND 	   hParent;
     HWND	   hDlg;

  public:
	 cDIALOGBOX( HINSTANCE);
	 virtual ~cDIALOGBOX();

	 virtual void Display(HWND , LPCWSTR);

	 virtual BOOL DlgProc(HWND , UINT , WPARAM , LPARAM ) = 0;
    
	 HINSTANCE GetInstance(void) { return hInstance; }

};


#endif

