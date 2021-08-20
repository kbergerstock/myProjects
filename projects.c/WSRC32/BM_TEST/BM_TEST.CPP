// -----------------------------------------------
//	skeleton application
//	(c) K. R. Bergerstock,1998
// --------------------------------------------------

#include "WM_MSGS.h"

#include "bm_test.h"
#include "cRANDOM.h"

#include "bm_bitmaps.rh"

#include "about.h"
#include "wmacros.h"

int PASCAL WinMain (HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdLine, int nCmdShow)
{
	// the following three lines verify that only one copy of this program
    // is capable of runing under a win32 enviroment.
	HANDLE hMutex = CreateMutex(NULL,true,_T("BM_TEST"));
    DWORD error = GetLastError();
    if(error != ERROR_ALREADY_EXISTS)
     {
         AppWin appWin(hInstance,nCmdShow);

         if(appWin.IsOk() )
         	appWin.Run();
	 }
    else
        MessageBox(NULL,"Application already running","ERROR",MB_OK);

    ReleaseMutex(hMutex);
	return 0;
}


// ------------------------------------------------------------

static char szAppName[] = "BM_TEST" ;
static char szAppDesc[] = "BITMAP / SPRITE TEST APPLICATION";

AppWin::AppWin(HINSTANCE hInst,int nCmdShow) : cAppWinFrame(szAppName,szAppDesc,hInst,nCmdShow)
{
    isOk = false;
    // set up the window parameters
    SetLargeIcon(IDI_LARGE);
    SetSmallIcon(IDI_SMALL);
    SetSize(100,40,640,480);
    SetBkGnd((HBRUSH)GetStockBrush(LTGRAY_BRUSH));
    // SetExStyle(WS_EX_OVERLAPPEDWINDOW	);

	if(Create() )                   // if the window was created
	  {
		Show(nCmdShow);			  	// show the window and update it
		Update();
        isOk = true;
      }

}

AppWin::~AppWin()
{

}


void AppWin::Paint(HDC hdc)
{
    bkgnd.Draw(hdc,0,0);
    saucer.Draw(hdc);
}

static int x = 0;
static int y = 0;
static int x_dir = 2;
static int y_dir = 2;


void AppWin::OnTimer(HWND hwnd, UINT uId)
{
	x += x_dir;
    y += y_dir;
    if( x < -10 || x > 560)
      {
    	x_dir *= -1;
        x += x_dir;
      }
    if( y < -30 || y > 350)
      {
      	y_dir *= -1;
        y += y_dir;
      }

	saucer.Move(x,y);

    HDC hdc = GetDC(hwnd);
    bkgnd.Draw(hdc,0,0);
    saucer.Draw(hdc);
    ReleaseDC(hwnd,hdc);
}

void AppWin::OnCreated(HWND hwnd)
{
    // fill in the text size parameters
	getTextMetrics(hwnd);								

    // install a timer
	SetTimer(hwnd,1,25,NULL);							

    // load in the background bitmap
    bkgnd.Create(hInstance,IDB_BKGND);	

    // load in the bitmaps that defing the sprite	            
    saucer.Create(hInstance,IDB_SAUCER,IDB_SAUCER_MASK);
}

void AppWin::OnDestroy(HWND hwnd)
{
	KillTimer(hwnd,1);							// destroy the timer
	Window::OnDestroy(hwnd);					// call the lowlevel destroy function
}


void AppWin::OnCommand(HWND hwnd, int id, HWND hwndCtl, UINT codeNotify)
{
	switch(id)
     {
       case CM_EXIT:
        ExitWindow();
       	break;

       case CM_ABOUT:
        {
        	pDIALOGBOX pBox = new AboutBox(hInstance);
            pBox->Display(hwnd,"AboutBox");
            delete pBox;
        }
        break;

       default:
		cAppWinFrame::OnCommand(hwnd,id,hwndCtl,codeNotify);
        break;
     }
}


// THE CLASS CALL BACK FUNCTION
LRESULT AppWin::WndProc (HWND hwnd , UINT msg , WPARAM wParam , LPARAM lParam)
{
	switch (msg)
	 {
	   HANDLE_MSG(hwnd,WM_TIMER,OnTimer);
       HANDLE_MSG(hwnd,WM_COMMAND,OnCommand);
	 }

	return cAppWinFrame::WndProc(hwnd,msg,wParam,lParam);
}

void AppWin::OnSize(HWND hwnd, UINT state, int cx, int cy)
{
	cWINBASE::OnSize(hwnd,state,cx,cy);
}



