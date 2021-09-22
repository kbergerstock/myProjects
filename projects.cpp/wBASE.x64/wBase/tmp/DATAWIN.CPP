// datawin.cpp

#ifndef __DATAWIN_H
#include "datawin.h"
#endif

cDATAWIN::cDATAWIN() : cWinFrame()
{
	// set up the window parameters
	SetName("DATAWIN");
    SetDesc("Data Window");
	SetStyle(WS_OVERLAPPEDWINDOW | WS_HSCROLL | WS_VSCROLL | WS_VISIBLE);
    SetExStyle(WS_EX_OVERLAPPEDWINDOW );
    SetSize(0,0,600,400);

    // register the window
    if(!isRegistered() )
    	Register();
}

cDATAWIN::~cDATAWIN()
{
}

HWND cDATAWIN::wopen(HWND hParent,int id)
{
	POINT p;
    // window position when opened
    p.x = p.y = 0;
    // convert it to screen coordinates
    ClientToScreen(hParent,&p);
    // wet the window location
    SetLocation(p.x,p.y);
    // open the window
    return cWinFrame::wopen(hParent,id);
}


void cDATAWIN::Paint(HWND hwnd, HDC hdc)
{
}


void cDATAWIN::OnKey(HWND hwnd, UINT uVK, BOOL bDown, int iRepeat, UINT uFlags)
{
	FORWARD_WM_KEYUP(hParent, uVK, iRepeat, uFlags,DefWindowProc);
}