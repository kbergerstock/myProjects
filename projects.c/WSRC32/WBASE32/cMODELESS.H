//*******************************************************************
//              
//  FILE:       cMODELESS.H
//              
//  AUTHOR:     Keith R. Bergerstock
//              
//  PROJECT:    shell32
//              
//  COMPONENT:  cMODELESS
//              
//  DATE:       29.07.2004
//              
//  COMMENTS:   -
//              
//              
//*******************************************************************

#pragma warning (disable:4786)

// Includes

#include "wm_msgs.h"

#ifndef  __cMODELESS_H
#define  __cMODELESS_H

// class defineing a base modeless dialog box

class cMODELESS
{
  private:
  	 HWND  		hPrevious;				// the previous modeless window

     virtual    BOOL dlgProc(HWND hDlg, UINT msg, WPARAM wParam, LPARAM lParam);
     friend     BOOL CALLBACK ModelessDlgProc(HWND hDlg, UINT msg, WPARAM wParam, LPARAM lParam);

  protected:     
     HINSTANCE  hInstance;
	 HWND 	    hParent;
     HWND	    hDlg;
   	 COLORREF 	newBK;
	 HBRUSH   	hBkBrush;

   	 COLORREF 	hiliteBK;
	 HBRUSH   	hHiliteBrush;

  public:
	 cMODELESS( HINSTANCE );
	 virtual ~cMODELESS();

     HWND Create(HWND ,LPSTR );

     void Display(void);

     void Destroy(void);

     void Update(void);   

     HWND GetDlgHwnd(void) { return hDlg; }

	 HINSTANCE GetInstance(void) { return hInstance; }
};

typedef cMODELESS*	pMODELESS;

#endif

