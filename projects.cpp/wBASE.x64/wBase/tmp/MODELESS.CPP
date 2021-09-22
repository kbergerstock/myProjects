#include "modeless.h"
#include "windbase.h"


#if defined(__BORLANDC__)
#pragma argsused
#endif
BOOL CALLBACK ModelessDlgProc(HWND hDlg, UINT msg, WPARAM wParam, LPARAM lParam)
{
	pMODELESS pBox = (pMODELESS) GetUserData(hDlg);
    if(pBox )
	    return (pBox->DlgProc(hDlg,msg,wParam,lParam) );
    else
		return false;
}

MODELESS::MODELESS(HINSTANCE hinst)
{
  hInstance = hinst;
  lpfnDlgProc = ModelessDlgProc;
}

MODELESS::~MODELESS()
{
  Destroy();
}

#if defined(__BORLANDC__)
#pragma argsused
#endif
BOOL MODELESS::DlgProc(HWND hDlg, UINT msg, WPARAM wParam, LPARAM lParam)
{
	return false;
}

// used to create a modeless dialog box
HWND MODELESS::Create(HWND hwnd,LPSTR lpszTemplate)
{
	hParent = hwnd;
	hDlg = CreateDialog(hInstance,lpszTemplate,hParent,lpfnDlgProc);
    if(hDlg)   									// if the creation was successful
    {
    	SetUserData(hDlg,this);					// store a pointer to the dialog class in the window structure
        hPrevious = cMAIN::GetDlgModeless();    // retrieve the previos modless window handle
        cMAIN::SetDlgModeless(hDlg);		    // set the current modeless window handle
    	SendMessage(hDlg,WM_WIN_CREATED,0,0L);	// send ok i'm created message
        ShowWindow(hDlg,SW_SHOWNORMAL);			// display the window
    }
	return hDlg;
}

void MODELESS::Display(void)
{
	ShowWindow(hDlg,SW_SHOWNORMAL);
}


void MODELESS::Destroy(void)
{
   DestroyWindow(hDlg);						   // destroy the current window
   cMAIN::SetDlgModeless(hPrevious);    	   // reset to the previous modeless dialog box
}

void MODELESS::Update(void)
{
  RECT rect;
  GetClientRect(hDlg,&rect);
  InvalidateRect(hDlg,&rect,TRUE);
  UpdateWindow(hDlg);
}



