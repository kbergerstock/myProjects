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
#endif

#ifndef  __cDIALOG_H
#define  __cDIALOG_H

INT_PTR MainDlgProc(HWND hDlg, UINT msg, WPARAM wparam, LPARAM lparam);

class cDIALOGBOX;

typedef cDIALOGBOX*	pDIALOGBOX;

class cDIALOGBOX
{
  private:
	 HINSTANCE      hInstance;
     HWND           hDlgWin;
     pDIALOGBOX     parent;             // used to set up a linked list
    
     friend INT_PTR MainDlgProc(HWND , UINT , WPARAM , LPARAM ); 

     void set_handle(HWND hdlg);

  protected:
	 HWND 	   hParent;
     HWND	   hDlg;

  public:
	 cDIALOGBOX( HINSTANCE);
	 virtual ~cDIALOGBOX();

	 virtual void Display(HWND , LPSTR);

	 virtual INT_PTR DlgProc(HWND , UINT , WPARAM , LPARAM ) = 0;
    
	 HINSTANCE GetInstance(void) { return hInstance; }

};


#endif

