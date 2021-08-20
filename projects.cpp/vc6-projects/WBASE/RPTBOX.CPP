// reportbox.cpp

#include "rptbox.h"
#include "rptbox.rh"
#include "wmacros.h"

REPORTBOX::REPORTBOX(HINSTANCE hInst,int x, int y, int w, int h) : AppWinFrame(hInst,0)
{
    char *cName = "RPTBOX";
	hWnd = NULL;								// indiacte unopened window
	SetStyle( WS_POPUP | WS_CAPTION | WS_VSCROLL | WS_VISIBLE );
	SetName(cName,LPSTR("RPT"));
	SetMenu("DIALOG_MENU");
	SetSize(x,y,w,h);
    ExitKey = VK_F5;

    if(!isRegistered(cName))
        Register();
}

REPORTBOX::~REPORTBOX()
{

}

HWND REPORTBOX::Display(HWND hWndParent, BOOL bQuit)
{
	hParent = hWndParent;
	// if the window  is already created, return the handle
	if(hWnd == NULL)
	  if(Create() )
		{
			Show(SW_SHOWNORMAL);
			Update();
			bRptQuit = bQuit;
		}
   return hWnd;
}

void REPORTBOX::OnDestroy(HWND hwnd)
{
	if(bRptQuit)
		WinBase::OnDestroy(hwnd);
	hWnd = NULL;
}

void REPORTBOX::SetReport(LPSTR fName)
{
	Report.Close();        				// close the old file
    Report.Open(fName);					// open the new file
    Report.Init();

	float nr = float(Report.GetNumRecords() - float(NUMLINES) );
	nVscrollInc = nr > 100.0 ? 100.0/nr : nr/100.0;
	nVscrollPos = 100.0;
}

void REPORTBOX::SetTitle(int id)
{
	ReportId = id;
	char buf[40];

	LoadString(hI,ReportId+10,LPSTR(buf),39);			// get the name of the new file
    SetReport(LPSTR(buf) );
}

void REPORTBOX::SetTitle(char *fName)
{
	ReportId = 0;
    SetReport(LPSTR(fName));
}



#pragma argsused
void REPORTBOX::OnKey(HWND hdlg, UINT vk, BOOL fDown, int cRepeat, UINT flags)
{
	if(vk == ExitKey)
		PostMessage(hdlg,WM_COMMAND,UINT(IDD_CLOSE),0L);

	switch(vk)
	 {
		case VK_PRIOR:
			Scroll(hdlg,-NUMLINES);
			break;

		 case VK_NEXT:
			Scroll(hdlg,NUMLINES);
			break;
	 }
}

#pragma argsused
void REPORTBOX::OnKeyDown(HWND hdlg, UINT vk, BOOL fDown, int cRepeat, UINT flags)
{
	switch(vk)
	 {
		case VK_NUMPAD8:
		case VK_UP:
			SendMessage(hdlg,WM_VSCROLL,SB_LINEDOWN,0L);
			break;

		case VK_NUMPAD2:
		case VK_DOWN:
			SendMessage(hdlg,WM_VSCROLL,SB_LINEUP,0L);
			break;
	 }
}

#pragma argsused
void REPORTBOX::OnCommand(HWND hwnd, int id, HWND hwndCtl, UINT codeNotify)
{
	switch(id)
	 {
		case IDD_CLOSE: 						// close the report window
            ExitKey = VK_F5;					// restore the default exit key
            ExitWindow();
			break;

		case IDD_EXIT:							// close the application
			ExitWindow();
			SendMessage(hParent,WM_CLOSE,0,0L);
			break;
	 }
}

void REPORTBOX::OnCreated(HWND hwnd)
{
	char buf[40];
	LoadString(hI,ReportId,LPSTR(buf),39);				// fetch the report name
	SetWindowText(hwnd,LPSTR(buf)); 					// and display it in the caption bar

	HDC hdc = GetDC(hwnd);								// get the vertical font size
	TEXTMETRIC tm;
	GetTextMetrics(hdc,&tm);
	cyChar = tm.tmHeight + tm.tmExternalLeading;
	ReleaseDC(hwnd,hdc);

	SetScrollPos(hwnd,SB_VERT,short(nVscrollPos),TRUE);
	SetFocus(hwnd);
}

void REPORTBOX::Scroll(HWND hwnd, int lines)
{
	static int flag = 0;

	nVscrollPos += (float(lines) * nVscrollInc);
	if(nVscrollPos > 0.0 && nVscrollPos <100.0)
	 {
		Report.Scroll(hwnd,lines);
		flag = 1;
	 }
	else
	 {
		if(nVscrollPos <= 0.0)
			{
				nVscrollPos = 0.0;
				if(flag)
					{ Report.Top(hwnd); flag = 0; }
			}
		if(nVscrollPos >= 100.0)
			{
				nVscrollPos = 100.0;
				if(flag)
					{ Report.Bottom(hwnd); flag = 0; }
			}
	 }
	short nVs = short(nVscrollPos);
	SetScrollPos(hwnd,SB_VERT,nVs,TRUE);
}

void REPORTBOX::OnPaint(HWND hwnd)
{
	HDC hdc;
	PAINTSTRUCT ps;
	hdc = BeginPaint(hwnd, &ps);
	RECT update = ps.rcPaint;
	Report.ShowData(hdc,update);
	EndPaint(hwnd,&ps);
}

#pragma argsused
void REPORTBOX::OnVScroll(HWND hwnd, HWND hwndCtl, UINT code, int pos)
{
	switch(code)
	 {
		case SB_LINEUP:
			Scroll(hwnd,1);
			break;
		case SB_LINEDOWN:
			Scroll(hwnd,-1);
			break;
	 }
}

#pragma argsused
LRESULT REPORTBOX::WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
  switch(msg)
	{
	   HANDLE_MSG(hwnd,WM_KEYUP,OnKey);
	   HANDLE_MSG(hwnd,WM_VSCROLL,OnVScroll);
	   HANDLE_MSG(hwnd,WM_KEYDOWN,OnKeyDown);

	  default:
	   //	return cWinFrame::WndProc (hwnd , msg , wParam , lParam);
		return AppWinFrame::WndProc(hwnd,msg,wParam,lParam);
   }
}
