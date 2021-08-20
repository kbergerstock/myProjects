// -----------------------------------------------
//	skeleton application
//	(c) K. R. Bergerstock,1998
// --------------------------------------------------

#ifndef __WINDOWS_H
#define STRICT
#include <windows.h>
#include <windowsx.h>
#endif

#include "skeleton.h"
#include "skeleton.rh"

#include "random.h"
#include "cPROCESS.h"

#include "about.h"
#include "wmacros.h"

#define BITMAP_TRW	  399
#define BITMAP_PASS   400
#define BITMAP_FAIL   401
#define BITMAP_BLANK  402
#define BITMAP_M_PASS 403
#define BITMAP_M_FAIL 404

#if defined(__BORLANDC__)
#pragma argsused
#endif
int PASCAL WinMain (HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdLine, int nCmdShow)
{
	// the following three lines verify that only one copy of this program
    // is capable of runing under a win32 enviroment.
	HANDLE hMutex = CreateMutex(NULL,true,"SKELETON");
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

APP::APP()
{
	SubProcess = new SlidePROCESS;
}

APP::~APP()
{
    delete SubProcess;
}

void APP::Start(HWND h)
{ SubProcess->Start(h); }

// main thread is processed here
#if defined(__BORLANDC__)
#pragma argsused
#endif
void APP::AuxRun(HWND hwnd)
{

}

// ------------------------------------------------------------

static char szAppName[] = "SKELETON" ;
static char szAppDesc[] = "SKELETON APPLICATION";

AppWin::AppWin(HINSTANCE hInst,int nCmdShow) : AppWinFrame(hInst,nCmdShow)
{
  // set up the window parameters
  SetName(szAppName,szAppDesc);
  SetBkGnd(GetStockBrush(LTGRAY_BRUSH));
  SetSize(100,40,600,450);
  SetMenu("SKELETON");
  SetIcon("RIP_LARGE");
  SetSmallIcon("RIP_SMALL");
  SetExStyle(WS_EX_OVERLAPPEDWINDOW	);

  StatusBar = NULL;
  hStatusBar = NULL;
  Slide = NULL;
  hSlide = NULL;
  position = 0.0;
  dir = 1.0;
  SlideTwo = NULL;
  hSlideTwo = NULL;

  FileName[0] = FileDesc[0] = '\0';

  // if creation suceeded then display the window
  if(Create())
  {
	Show(nCmdShow);
	Update();
  }
}

AppWin::~AppWin()
{
	if(StatusBar != NULL)
		delete StatusBar;
    if(Slide != NULL)
    	delete Slide;
    if(SlideTwo != NULL)
    	delete SlideTwo;
}

void AppWin::Paint(HDC hdc)
{
	int sx = cxChar;
	int sy = cyChar;

	LOGBRUSH lb;
	GetObject(GetBkGnd(),sizeof(LOGBRUSH),LPSTR(&lb) );
	COLORREF oldBK = SetBkColor(hdc,lb.lbColor);
	sy += 20* cyChar;

	StrOut(hdc,sx,sy,szAppDesc);

	SetBkColor(hdc,oldBK);
}

#if defined(__BORLANDC__)
#pragma argsused
#endif
void AppWin::OnTimer(HWND hwnd, UINT uId)
{
	double q = amt.NextVal(2.0);
	double np = position + dir * q;
    if(np > 100.0 || np < 0.0)
    	{ dir *= -1.0; }
	position += dir * q;
    Slide->Draw(position);
}

void AppWin::OnCreated(HWND hwnd)
{
	getTextMetrics(hwnd);								// fill in the text size parameters

	SetTimer(hwnd,1,100,NULL);							// install a timer

	StatusBar = new cSTATBAR(hwnd,GetBkGnd()); 			// create status bar
    hStatusBar = StatusBar->Create(hwnd,STATBAR);

	StatusBar->SetMessageOne("one");
    StatusBar->SetMessageTwo("two");
    StatusBar->SetMessageThree("three");
    StatusBar->SetMessageFour("four");

    Slide = new cSLIDE(hwnd);
    Slide->SetTitle("Slide One Control");
    Slide->SetPos(150,10,200,300);
    hSlide = Slide->Create(hwnd,SLIDECONTROL);

    SlideTwo = new cSLIDE(hwnd);
    SlideTwo->SetTitle("Slide Two Control");
    SlideTwo->SetPos(375,10,200,300);
    hSlideTwo = SlideTwo->Create(hwnd,SLIDECONTROL+10);
}

void AppWin::OnDestroy(HWND hwnd)
{
	KillTimer(hwnd,1);							// destroy the timer
	Window::OnDestroy(hwnd);					// call the lowlevel destroy function
}

#if defined(__BORLANDC__)
#pragma argsused
#endif
void AppWin::OnCommand(HWND hwnd, int id, HWND hwndCtl, UINT codeNotify)
{
	switch(id)
     {
       case IDM_DATAWIN:
       	DataWin.wopen(hwnd,NULL);
        break;

       case IDM_EXIT:
        ExitWindow();
       	break;

       case IDM_ABOUT:
        {
        	pDIALOGBOX pBox = new AboutBox(hInstance);
            pBox->Display(hwnd,"AboutBox");
            delete pBox;
        }
        break;

       default:
		AppWinFrame::OnCommand(hwnd,id,hwndCtl,codeNotify);
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

       case WM_SLIDECONTROL:
       	SlideTwo->Draw(double(lParam)/100.0);
        break;

	 }

	return AppWinFrame::WndProc(hwnd,msg,wParam,lParam);
}

#if defined(__BORLANDC__)
#pragma argsused
#endif
void AppWin::OnSize(HWND hwnd, UINT state, int cx, int cy)
{
	StatusBar->Draw(hwnd,hStatusBar);
	WinBase::OnSize(hwnd,state,cx,cy);
}

void AppWin::Run(void)
{
	APP App;
	App.Start(hWnd);
	App.Run(hWnd);							// run the application
}

