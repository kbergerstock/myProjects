//*******************************************************************
//              
//  FILE:       cMODELESS.CPP
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

#include "cMODELESS.h"

inline void *GetUserData(HWND hWnd)
{
	return (void*)GetWindowLong(hWnd,GWL_USERDATA);
}

inline void SetUserData(HWND hWnd, void *ptr)
{
	SetWindowLong(hWnd, GWL_USERDATA, (LONG)ptr);
}


BOOL CALLBACK ModelessDlgProc(HWND hDlg, UINT msg, WPARAM wParam, LPARAM lParam)
{
	pMODELESS pBox = (pMODELESS) GetUserData(hDlg);
    if(pBox )
	    return (pBox->dlgProc(hDlg,msg,wParam,lParam) );
    else
		return false;
}

cMODELESS::cMODELESS(HINSTANCE hinst)
{
  hInstance = hinst;
}

cMODELESS::~cMODELESS()
{
  Destroy();
}

BOOL cMODELESS::dlgProc(HWND hDlg, UINT msg, WPARAM wParam, LPARAM lParam)
{
	return false;
}

// used to create a modeless dialog box
HWND cMODELESS::Create(HWND hwnd,LPSTR lpszTemplate)
{
	hParent = hwnd;
    DLGPROC lpfnDlgProc  = ModelessDlgProc;;
	hDlg = CreateDialog(hInstance,lpszTemplate,hParent,lpfnDlgProc);
    if(hDlg)   									// if the creation was successful
    {
    	SetUserData(hDlg,this);					// store a pointer to the dialog class in the window structure
    	SendMessage(hDlg,WM_WIN_CREATED,0,0L);	// send ok i'm created message
        ShowWindow(hDlg,SW_SHOWNORMAL);			// display the window
    }
	return hDlg;
}

void cMODELESS::Display(void)
{
	ShowWindow(hDlg,SW_SHOWNORMAL);
}


void cMODELESS::Destroy(void)
{
   DestroyWindow(hDlg);						   // destroy the current window
}

void cMODELESS::Update(void)
{
  RECT rect;
  GetClientRect(hDlg,&rect);
  InvalidateRect(hDlg,&rect,TRUE);
  UpdateWindow(hDlg);
}


