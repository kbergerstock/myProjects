//*******************************************************************
//              
//  FILE:       3DCURVES.CPP
//              
//  AUTHOR:     Keith R. Bergerstock
//              
//  PROJECT:    3d
//              
//  COMPONENT:  AppWin
//              
//  DATE:       29.07.2004
//              
//  COMMENTS:   - main start file for 3d curves program
//              
//              
//*******************************************************************

// Includes

#include "3dcurves.h"
#include "3dcurves.rh"

#include "surfaceB.h"
#include "pga6_3.h"
#include "about32.h"

int PASCAL WinMain (HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdLine, int nCmdShow)
{
	AppWin appWin(hInstance,nCmdShow);

	if(appWin.IsOk() )
    	appWin.Run();

	return 0;
}

// ----------------------------------------------------------------

static	char Name[] = "3DCURVES" ;
static	char Desc[] = "32 bit version of 3d curves";

AppWin::AppWin(HINSTANCE hInst,int nCmdShow) 
 : cAppWinFrame(Name,Desc, hInst, nCmdShow) , 
   wSurface(IDM_SURFACE_A)
{
	SetSize(0,0,640,480);
    SetLargeIcon(IDI_ICON1);
    SetMenu(DEMO3D);
	SetBkGnd( (HBRUSH) GetStockObject(BLACK_BRUSH) );

	isOk = Register();					// register the window class

	if(isOk)
	   isOk = Create();					// create the window

	if(isOk)
	  {
		Show(nCmdShow);					// show the window and update it
		Update();
      }
}

void AppWin::Paint(HDC hdc)
{
	SetBkColor(hdc,RGB(0,0,0));
	SetTextColor(hdc,RGB(0,255,255));

    switch(wSurface)
     {
		case  IDM_SURFACE_A:
            {
			SurfaceA Curve(Size.cx,Size.cy);
			Curve.Draw(hdc,RGB(0,255,0) );
            }
            break;

		case  IDM_SURFACE_B:
            {
			SurfaceB Curve(Size.cx,Size.cy);
			Curve.Draw(hdc,RGB(0,255,0) );
            }
            break;

		case  IDM_PGA6_3:
        	{
		    PGA6_3 Curve(Size.cx,Size.cy);
		    Curve.Draw(hdc );
            }
            break;
     }
}


void AppWin::OnTimer(HWND hwnd, UINT uId)
{
    // advance the idtifier as to which surface to paint
    wSurface++;
    if(wSurface > IDM_PGA6_3)
    {
        wSurface = IDM_SURFACE_A;
    }

    // tell the wondow system to redraw the main window of this application
    InvalidateRect(hwnd,NULL,TRUE);
}


void AppWin::OnCommand(HWND hwnd, int id, HWND hwndCtl, UINT codeNotify)
{
	switch(id)
     {
		case  IDM_SURFACE_A:
		case  IDM_SURFACE_B:
		case  IDM_PGA6_3:
        	wSurface = id;
            InvalidateRect(hwnd,NULL,TRUE);
        	break;

		case  IDM_ABOUT:
            {
        	    AboutBox Box(hInstance,IDB_BITMAP1);
                Box.Display(hwnd,"AboutBox");
            }
        	break;

		case  IDM_EXIT:
        	ExitWindow();
        	break;
     }
}

void AppWin::OnCreated(HWND hwnd)
{
	SetTimer(hwnd,1,5000,NULL);							// install a timer
}

void AppWin::OnDestroy(HWND hwnd)
{
	KillTimer(hwnd,1);							// destroy the timer
	Window::OnDestroy(hwnd);					// call the lowlevel destroy function
}


