//*******************************************************************
//              
//  FILE:       cDIALOG.CPP
//              
//  AUTHOR:     Keith R. Bergerstock
//              
//  PROJECT:    wbase32
//              
//  COMPONENT:  DIALOGBOX
//              
//  DATE:       29.07.2004
//              
//  COMMENTS:   - modal dialog box base class
//              
//              
//*******************************************************************

#pragma warning (disable:4786)

// Includes

#include "cDIALOG.h"

// storage to a dialog box pointer that will be used to call the active dialog box handler
static pDIALOGBOX   pDialogBox = 0;


// routine passed to the dialog box creation function to handle the dialog messages
BOOL FAR PASCAL MainDlgProc(HWND hDlg, UINT msg, WPARAM wparam, LPARAM lparam)
{	
    // if a WM_INITDIALOG - make sure that the doalog object knows it's handle
    if(msg == WM_INITDIALOG )
     {
        pDialogBox->set_handle(hDlg);
     }
    
    return pDialogBox->DlgProc(hDlg,msg,wparam,lparam); 
}


// constructor = sores hinst
cDIALOGBOX::cDIALOGBOX(HINSTANCE hinst)
{
    hInstance = hinst;
}

// destructor
cDIALOGBOX::~cDIALOGBOX()
{
}

// store the handle to the dialog box
void cDIALOGBOX::set_handle(HWND hdlg)
{
   hDlgWin = hdlg;
}


// ok this is the guts of a modal dialog base class
void cDIALOGBOX::Display(HWND hwnd, LPSTR lpszTemplate)
{
    // store the handle to the parent window
    hParent = hwnd;

    // save the contents of the dialog box pointer 
    parent =  pDialogBox;

    // set the diaplog box point to this object
    pDialogBox = this;

    // create a modal dialog box
    int isOk = DialogBox(hInstance,lpszTemplate,hwnd, MainDlgProc );
    // error trap return value
    if( isOk == -1)
      {
        MessageBox(hwnd,"Unable to show box","ITS WRONG",MB_OK);
      }

    // reset the dialog box pointer to previous setting
    pDialogBox = parent;
    // if it was an active box - ie parent != 0 then reset the focus to that box
    if(parent)
     {
        SetFocus(parent->hDlgWin);
     }

}


