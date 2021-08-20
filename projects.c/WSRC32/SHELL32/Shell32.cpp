//*******************************************************************
//              
//  FILE:       Shell32.cpp
//              
//  AUTHOR:     Keith R. Bergerstock
//              
//  PROJECT:    shell32
//              
//  COMPONENT:  AppWin
//              
//  DATE:       29.07.2004
//              
//  COMMENTS:   -
//              
//              
//*******************************************************************

#pragma warning (disable:4786)

// Includes

#include "WR_SHELL32.h"
#include "SHELL32.H"
#include "HAT.h"


int PASCAL WinMain (HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdLine, int nCmdShow)
{
	AppWin appWin(hInstance,nCmdShow);

	if(appWin.IsOk() )
		appWin.Run();

	return 0;
}

// ----------------------------------------------------------------


AppWin::AppWin(HINSTANCE _hInstance, int _nCmdShow) 
    : cAppWinFrame( _hInstance,_nCmdShow )
{
	appName = getStringTableElement(IDS_WIN_NAME);
	appDesc = getStringTableElement(IDS_WIN_DESC);

	appLargeIcon = IDI_ICON1;
	appSmallIcon = IDI_ICON1;

	SetSize(0,0,640,480);
	SetBkGnd( (HBRUSH) GetStockObject(BLACK_BRUSH) );

	if(Create() )                   // if the window was created
	  {
		Show(nCmdShow);			  	// show the window and update it
		Update();
        isOk = true;
      }
}

void AppWin::Paint(HDC hdc)
{
	SetBkColor(hdc,RGB(0,0,0));
	SetTextColor(hdc,RGB(0,255,255));
	cHAT hat(hdc,Size);
}


