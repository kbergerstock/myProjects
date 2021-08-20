// -----------------------------------------------
//	wavebox.cpp
//	(c) K. R. Bergerstock,1996
//	wave form display box for CTM PER test
// --------------------------------------------------

#include "msgbox.h"


static char AppName[] = "MSGBOX" ;
static char AppDesc[] = "Message Box";

int cMsgBox::isRegistered = 0;

cMsgBox::cMsgBox(HWND pHwnd, int control_id)
{
   Register();                              // Register the Window
   Create(pHwnd,control_id);				// create this instance of the child window
   hParent = pHwnd;                         // save the parent windows window handle
   Control_id = control_id;                 // save the id of this controls instance
   data = new STRARRAY();					// allocate memory storage
   data->ALLOC();							// for data
}

cMsgBox::~cMsgBox()
{
	data->FREE();							// deallocate memory storage
	DestroyWindow(hWnd);
}

BOOL cMsgBox::Register(void)
{
  szWinName = AppName;
  szWinDesc = AppDesc;

  if(!MAIN::hPinstance && ! isRegistered) // if this clas has not been registered
   {								      // then register the class
	  WNDCLASS	 wndclass ;

	  wndclass.style		 = CS_HREDRAW | CS_VREDRAW ;
	  wndclass.lpfnWndProc	 = ::MainWndProc;
	  wndclass.cbClsExtra	 = 0;
	  wndclass.cbWndExtra	 = sizeof(Window*);
	  wndclass.hInstance	 = MAIN::hInstance ;
	  wndclass.hIcon		 = NULL;
	  wndclass.hCursor		 = LoadCursor (NULL, IDC_ARROW) ;
	  wndclass.hbrBackground = HBRUSH( 1 + COLOR_SCROLLBAR);
	  wndclass.lpszMenuName  = NULL;
	  wndclass.lpszClassName = szWinName ;

	  isRegistered =  (RegisterClass (&wndclass) ? TRUE : FALSE );
   }
 return isRegistered;
}

#pragma argsused
HWND cMsgBox::Create(HWND hwnd, int control_id) 		// create the window
{
  hWnd = CreateWindow ( szWinName,
						szWinDesc,
						WS_POPUP |WS_VISIBLE | WS_BORDER,
						200,
						50,
						400,
						200,
						hwnd,					// parents window handle
						NULL,
						MAIN::hInstance,
						NULL) ;

  if(hWnd)										// if creation process was successful
   {
	SetPointer(hWnd,this);						// set a pointer to the class into the CbWndExtra
	SendMessage(hWnd,WM_WIN_CREATED,0,0L);		// send a window created message to the call back function
   }

  return  hWnd; 								// return the handle to the child window
};


void cMsgBox::OnPaint(HWND hwnd)
{
   HDC hdc;
   PAINTSTRUCT ps;

   COLORREF oldBK;
   COLORREF newBK = GetSysColor(COLOR_SCROLLBAR);

   hdc = BeginPaint(hwnd, &ps);

   HFONT hFont = (HFONT)GetStockObject(ANSI_FIXED_FONT);
   HFONT hOld  = (HFONT)SelectFont(hdc,hFont);
   TEXTMETRIC tm;
   GetTextMetrics(hdc,&tm);
   cxChar = tm.tmAveCharWidth;
   cyChar = tm.tmHeight + tm.tmExternalLeading;

   oldBK = SetBkColor(hdc,newBK);
   data->Paint(hdc,8,3);
   SetBkColor(hdc,oldBK);
   SelectFont(hdc,hOld);
   EndPaint(hwnd,&ps);
}

#pragma argsused
void cMsgBox::OnCommand(HWND hwnd, int id, HWND hwndCtl, UINT codeNotify)
{
   switch(id)
	{
	   default:
		 MessageBox(hwnd,"Function Not Impemented","NOT IMPLEMENTED",MB_ICONINFORMATION | MB_OK);
		 break;
	}
}

// THE CLASS CALL BACK FUNCTION
LRESULT cMsgBox::WndProc (HWND hwnd , UINT msg , WPARAM wParam , LPARAM lParam)
 {
	 switch (msg)
	   {
		  HANDLE_MSG(hwnd,WM_PAINT,OnPaint);
		  HANDLE_MSG(hwnd,WM_SIZE,OnSize);
		  HANDLE_MSG(hwnd,WM_COMMAND,OnCommand);

          case WM_KEYUP:
            PostMessage(hParent,msg,wParam,lParam);
            return 0;

		  case WM_WIN_CREATED:
			return 0;
		 }

	 return DefWindowProc (hwnd, msg, wParam, lParam) ;
 }

void cMsgBox::DisplayMsg(char far* szMsg)
{
  data->AddLine(szMsg);
}

void cMsgBox::DisplayMsg(UINT idResource)
{
  char buffer[128];
  LoadString(MAIN::hInstance,idResource,LPSTR(buffer),128);
  data->AddLine(buffer);
  Show();
}
