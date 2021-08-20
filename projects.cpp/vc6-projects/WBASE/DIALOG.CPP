#include "dialog.h"

static int BoxNdx = 0;
static pDIALOGBOX BoxArray[10];			// array of dialog boxes pointers
static HWND hDlgWin[10] = {0,0,0 };

BOOL FAR PASCAL MainDlgProc(HWND hDlg, UINT msg, WPARAM wparam, LPARAM lparam)
 {	return (BoxArray[BoxNdx]->DlgProc(hDlg,msg,wparam,lparam) ); }


DIALOGBOX::DIALOGBOX(HINSTANCE hinst)
{
  if(BoxNdx < 10)
   {
	 hInstance = hinst;
	 lpfnDlgProc = (DLGPROC)MainDlgProc;
	 BoxArray[++BoxNdx] = this;
	 hDlgWin[BoxNdx] = NULL;
   }
}

DIALOGBOX::~DIALOGBOX()
{
  BoxArray[BoxNdx--] = NULL;
  if(hDlgWin[BoxNdx] != NULL)
	 SetFocus(hDlgWin[BoxNdx]);
}

void DIALOGBOX::Set_hDlg(HWND hdlg)
{
  hDlgWin[BoxNdx] = hdlg;
}


void DIALOGBOX::Display(HWND hwnd, LPSTR lpszTemplate)
{
  hParent = hwnd;
  int isOk = DialogBox(hInstance,lpszTemplate,hwnd,lpfnDlgProc);
  if( isOk == -1)
	  MessageBox(hwnd,"Unable to show box","ITS WRONG",MB_OK);
}


