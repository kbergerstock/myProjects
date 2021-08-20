//	FILE:	 WSTDIO.CPP

//	PURPOSE: Contains functions for managing a standard I/O window.
//			Provides a means for easily sending text to a window
//			for debugging, etc.

//	FUNCTIONS:
//			SetupStdioDC() - Initializes DC.
//			ResetStdioDC() - Selects former font into DC.
//			GetStdioLine() - Returns pointer to specified line in buffer.
//			StdioUpdate() - Scroll and update displayed text.
//			putStdio() - Process I/O window messages.
//			StdioPaint() - Paint procedure for I/O window.
//			InitStdio() - Initialize values used by I/O window.
//
//			stdioInit() - Define/register I/O window class.
//			wopen() - Create a default I/O window.
//			CreateStdioWindow() - Create a customized I/O window.
//			wputs() - Puts a string in the I/O window.
//			wputc() - add a char to a line in the I/O window
//			StdioWndProc() - Processes messages for the I/O window.
//

#include "wstdio.h"
// #include "stdmenu.h"
// #include "stdlib.h"

static char AppName[] = "WSTDIO";
static char AppDesc[] = "WSTDIO";

WSTDIO::WSTDIO()
{
	Init();
    if(hInstance && !isRegistered(AppName))
        Register();
}

WSTDIO::WSTDIO(HINSTANCE hInst)
{
	hInstance = hInst;
	Init();
    if(hInstance && !isRegistered(AppName))
        Register();
}

void WSTDIO::Init(void)
{
	hWnd = NULL;						// Handle to standard I/O window
	bInited = FALSE;

	// initialize screen buffer to nulls
	int i,j;
	for(i=0; i<_MaxLines; i++)
	for(j=0; j<81; j++)
		sScrBuff[i][j] = '\0';

	nFirstLine = 0;
	nLastLine = _MaxLine;
	nCurrPos = 0;
}

WSTDIO::~WSTDIO()
{
}

//========================================================================

// FUNCTION: SetupStdioDC(HWND, HDC)

// PURPOSE:  Sets up the I/O window DC. Called at GetDC/BeginPaint time.

//========================================================================

void WSTDIO::SetupStdioDC(HWND hWnd, HDC hDC)
{
  if(hWnd)
   {
	RECT rClRect;

	GetClientRect(hWnd,&rClRect);

	// set origin to 25(+1 extra) lines from the bottom of the window
	SetViewportOrgEx(hDC,0,rClRect.bottom - ((_MaxLines+1) * nStdioCharHeight),NULL);

	SetMapMode(hDC, MM_ANISOTROPIC);

	// Set the extents such that one unit horizontally or
	// vertically is one character width or height.
	SetWindowExtEx(hDC,1,1,NULL);

	// Set the viewport such that the last line in the buffer is
	// displayed at the bottom of the window.
	SetViewportExtEx(hDC,nStdioCharWidth,nStdioCharHeight,NULL);

	// Set the background mode to opaque, and select the font.
	SetBkMode(hDC,OPAQUE);
	hOldFont = (HFONT)SelectObject(hDC,GetStockObject(Stdio_FONT));
   }
}


//========================================================================

// FUNCTION: ResetStdioDC(HDC)

// PURPOSE:  Prepare to release the DC by selecting the system font.

//========================================================================

void WSTDIO::ResetStdioDC(HDC hDC)
{
   if(hWnd)
	SelectObject(hDC,hOldFont);
}



//========================================================================

// FUNCTION: GetStdioLine(short)

// PURPOSE:  Return a pointer to the specified line of the display.

//========================================================================

char *WSTDIO::GetStdioLine(int ndx)
{
	int pos;

	// find the first line (one past the last line since we have a
	// circular buffer). index to the desired line from there.
	pos = nLastLine + 1;
	if(pos == _MaxLines) pos = 0;

	pos = pos + ndx;
	if(pos > _MaxLine) pos = pos - _MaxLines;

	return(sScrBuff[pos]);
}



//========================================================================

// FUNCTION: StdioUpdate(HWND, HDC, int)

// PURPOSE:  Scroll the window by the number of lines we have received,
//			 and display the text in the invalidated areas.

//========================================================================

#if defined(__BORLANDC__)
#pragma argsused
#endif
void WSTDIO::StdioUpdate(HWND hWnd, HDC hDC, int iLinesOut)
{
	RECT rcRect;
	if(hWnd)
	{
		if(iLinesOut > 0)
		 {

		  // scroll screen by number of lines received
		  GetClientRect(hWnd,&rcRect);
		  rcRect.bottom -= nStdioCharHeight;

		  ScrollWindow(hWnd,0,-(nStdioCharHeight * iLinesOut),&rcRect,NULL);
		 }
		UpdateWindow(hWnd);
	}
}


//========================================================================

// FUNCTION: putStdio(HWND, HDC, WORD, LPSTR)

// PURPOSE:  Process incoming text to Stdio window.

//========================================================================
void WSTDIO::AdvanceLine(void)
{
  char *sBuffer;
  ++iLinesOut;			// increment lines to scroll
  nCurrPos = 0; 		// reset the current position in the line

  ++nLastLine;
  if(nLastLine > _MaxLine) nLastLine = 0;

  // clear the new line
  sBuffer = sScrBuff[nLastLine];
  for(short j=0; j<80; j++) sBuffer[j] = '\0';
}

void WSTDIO::putStdio(HWND hWnd, HDC hDC, WPARAM wParam, LPARAM lParam)
{
	short i;
	char *sBuffer;
	RECT rcInvalid;
	iLinesOut = 0;							// # of lines to scroll
    LPSTR lpStr = LPSTR(lParam);			// convert the lparam pointer to a string pointer
    int len = int(wParam);

	sBuffer = sScrBuff[nLastLine];			// pointer to current line

	// scan the text, handle any special characters, and display the rest.

	for(i=0; i < len ; i++){
	switch(lpStr[i]) {

		case '\r':              // return
								// move to the start of the line
		   nCurrPos = 0;		// reset the current position in the line
		   break;

		case '\n':              // new line
		  AdvanceLine();		// "scroll" the window
          sBuffer = sScrBuff[nLastLine];    // pointer to current line
		  break;

		case '\b':              // backspace

								// move back one space
		if(nCurrPos > 0) {

		--nCurrPos;
		sBuffer[nCurrPos] = '\0';
		rcInvalid.top = _MaxLine; rcInvalid.bottom = _MaxLine + 1;
		rcInvalid.left = nCurrPos;
		rcInvalid.right = nCurrPos + 1;
		LPtoDP(hDC,(POINT *) &rcInvalid, 2);

		// invalidate the area so that it gets redrawn
		if(hWnd)
			InvalidateRect(hWnd,&rcInvalid, TRUE);

		}
		break;

	case '\t':
		// ignore tabs for now
		break;

	default:
		if(nCurrPos > 79)
		 {
		  AdvanceLine();
		  sBuffer = sScrBuff[nLastLine];		  // pointer to current line
		 }
		//add char to buffer
		if(nCurrPos < 80)
		 {
			// put the character in the screen buffer
			sBuffer[nCurrPos] = lpStr[i]; // add char to screen line

			// calculate area to invalidate
			rcInvalid.top = _MaxLine; rcInvalid.bottom = _MaxLine + 1;
			rcInvalid.left = nCurrPos;
			++nCurrPos;
			rcInvalid.right = nCurrPos;
			sBuffer[nCurrPos] = 0;

			// only need to invalidate the area if it is on the last line
			if(iLinesOut == 0)
			   {
				LPtoDP(hDC,(POINT *) &rcInvalid, 2);
				// invalidate the area so that it gets redrawn
				if(hWnd)
					InvalidateRect(hWnd,&rcInvalid, FALSE);
				}
		}
		break;
	}
	// force scroll after 2 lines. you will scroll faster if you increase
	// this, but it may not look good.

	if(iLinesOut > 2) {
		StdioUpdate(hWnd, hDC, iLinesOut);
		iLinesOut = 0;
	}
	}

	// force scroll and update at the end of each bunch of characters.
	StdioUpdate(hWnd, hDC, iLinesOut);
}

//========================================================================

// FUNCTION: onPaint(HWND)

// PURPOSE:  The I/O window paint procedure.  Draws necessary text in
//			 the window.

//========================================================================

void WSTDIO::OnPaint(HWND hWnd )
{
	char *psLine;
	int i;
	PAINTSTRUCT ps;
	HDC hDC;
	RECT rcUpdate;
	int nVPaintBeg, nVPaintEnd, nHPaintBeg, nHPaintEnd;

	hDC = BeginPaint( hWnd, (LPPAINTSTRUCT)&ps );
	SetupStdioDC(hWnd,hDC);

	rcUpdate = ps.rcPaint;
	DPtoLP(hDC,(POINT *) &rcUpdate, 2);

	// calculate first and last lines to update
	nVPaintBeg = max (0L, rcUpdate.top);
	nVPaintEnd = min (long(_MaxLines), rcUpdate.bottom);

	// calculate the first and last columns to update
	nHPaintBeg = max (0L, rcUpdate.left);
	nHPaintEnd = min (80L, rcUpdate.right);

	// display the lines that need to be drawn
	for(i = nVPaintBeg; i < nVPaintEnd; i++)
	 {
		psLine = GetStdioLine(i) + nHPaintBeg;
		TextOut(hDC, nHPaintBeg, i, psLine, lstrlen(psLine));
	 }
	ResetStdioDC(hDC);
	EndPaint( hWnd, (LPPAINTSTRUCT)&ps );
}

#if defined(__BORLANDC__)
#pragma argsused
#endif
void WSTDIO::OnColorChange(HWND hWnd )
{
	// if the colors have been changed in the control panel,
	// we need to change also.

	StdiobkRGB = GetSysColor(COLOR_WINDOW); 		// background color
	StdiotextRGB = GetSysColor(COLOR_WINDOWTEXT);	// text color
}

void WSTDIO::OnGetMinMax(HWND hwnd, MINMAXINFO far* lpMinMaxInfo)
{
	if(!bInited) InitStdio(hwnd);

	// constrain the sizing of the window to 80 by 25 characters.
	LPPOINT ptMinMaxInfo;
	ptMinMaxInfo = (LPPOINT) lpMinMaxInfo;

	ptMinMaxInfo[1].x = nStdioCharWidth * 80
				 + 2 * GetSystemMetrics(SM_CXFRAME);
	ptMinMaxInfo[1].y = nStdioCharHeight * 26
				 + 2 * GetSystemMetrics(SM_CYFRAME);

	ptMinMaxInfo[4].x = nStdioCharWidth * 80
				 + 2 * GetSystemMetrics(SM_CXFRAME);
	ptMinMaxInfo[4].y = nStdioCharHeight * 26
				 + 2 * GetSystemMetrics(SM_CYFRAME);

}
void WSTDIO::OnDestroy(HWND hwnd)
{
   GetWindowRect(hwnd,&wRect);				// save the window size
   if(bStdioQuit)
	 cWINBASE::OnDestroy(hwnd);
   hWnd = NULL;
}


// pass the characters recieved back to the parent window
#if defined(__BORLANDC__)
#pragma argsused
#endif
void WSTDIO::OnChar(HWND hwnd ,UINT uChar, int iRepeat)
{
   FORWARD_WM_CHAR(hParent,uChar,iRepeat,PostMessage);
}

#if defined(__BORLANDC__)
#pragma argsused
#endif
void WSTDIO::OnCommand(HWND hwnd, int id, HWND hwndCtl, UINT codeNotify) {}

#if defined(__BORLANDC__)
#pragma argsused
#endif
void WSTDIO::OnKey(HWND hwnd, UINT uVK, BOOL bDown, int iRepeat, UINT uFlags)
{
  switch (uVK)
   {
	  case VK_F4:
		 PostMessage(hwnd,WM_CLOSE,0,0L);
		 break;

	  default:
		  FORWARD_WM_KEYUP(hParent, uVK, iRepeat, uFlags,MainWndProc);
		  break;
   }
}

//========================================================================

// FUNCTION: InitStdio(HWND)

// PURPOSE:  Initialize variables used by I/O window.

//========================================================================

void WSTDIO::InitStdio(HWND hWnd)
{
	HDC hDC;								// retrieve the text parameters
	TEXTMETRIC Metrics; 					// for the font we want to use

	// get the text metrics for the font we are using
	hDC = GetDC(hWnd);
	hOldFont = (HFONT)SelectObject(hDC,GetStockObject(Stdio_FONT));
	GetTextMetrics(hDC,&Metrics);
	SelectObject(hDC,hOldFont);
	ReleaseDC(hWnd,hDC);

	// calculate the height and width of the font
	nStdioCharWidth = Metrics.tmMaxCharWidth;
	nStdioCharHeight = Metrics.tmHeight + Metrics.tmExternalLeading;

	// get the background and forground colors we are going to use
	StdiobkRGB = GetSysColor(COLOR_WINDOW); // background color
	StdiotextRGB = GetSysColor(COLOR_WINDOWTEXT); // text color

	bInited = TRUE;
}


//========================================================================

// FUNCTION: Register(void)

// PURPOSE:  Initialize the stdio module. Registers the window class.

// RETURNS:  Status of RegisterClass().

//========================================================================

bool WSTDIO::Register()
{
  szWinName = AppName;
  szWinDesc = AppDesc;
  bool isOK = (hInstance == NULL) ? false : true;

  // create the stdio window
  if(isOK ) 		                    // if this clas has not been registered
	{									// then register the class
	  WNDCLASS	 wndclass ;

	  wndclass.style		 = CS_HREDRAW | CS_VREDRAW ;
	  wndclass.lpfnWndProc	 = ::MainWndProc;
	  wndclass.cbClsExtra	 = 0;
	  wndclass.cbWndExtra	 = sizeof(Window*);
	  wndclass.hInstance	 = hInstance ;
	  wndclass.hIcon		 = LoadIcon (hInstance, "TTYICON") ;
	  wndclass.hCursor		 = LoadCursor (NULL, IDC_ARROW) ;
	  wndclass.hbrBackground = HBRUSH(COLOR_WINDOW + 1);
	  wndclass.lpszMenuName  = NULL;
	  wndclass.lpszClassName = szWinName ;

	  isOK =  (RegisterClass (&wndclass) ? true: false);
   }

	hStdioInst = hInstance;

	return isOK;
}


//========================================================================

// FUNCTION: wopen(HWND, BOOL)

// PURPOSE:  Create a default style stdio window. If bQuit is TRUE,
//			 PostQuitMessage will be called when the window is closed.
//			 Therefore, the stdio window can be used for the main
//			 application window.

// RETURNS:  Handle to window created.

//========================================================================

#if defined(__BORLANDC__)
#pragma argsused
#endif
HWND WSTDIO::Create (HWND hWndParent, int id )		// create the window
{
  hParent = hWndParent; 							// save the handle to the parent window
  if(!bInited)
	{
	 GetWindowRect(hParent,&wRect);
	 wRect.left += 5;
	 wRect.top += 25;
	 wRect.right -= 5;
	 wRect.bottom -=26;
	}

  hWnd = CreateWindow ( szWinName,
						szWinDesc,
						WS_OVERLAPPEDWINDOW,
						wRect.left,
						wRect.top,
						wRect.right  - wRect.left,
						wRect.bottom -	wRect.top,
						hParent,
						NULL,
						hStdioInst,
						NULL) ;

  if(hWnd)										// if creation process was successful
   {
	SetPointer(hWnd,this);						// set a pointer to the class into the CbWndExtra
	SendMessage(hWnd,WM_WIN_CREATED,0,0L);		// send a window created message to the call back function
   }

  return  hWnd; 								// return the handle to the new window

};

HWND WSTDIO::wopen(HWND hWndParent, bool bQuit)
{
	// if window already created, return handle
	if(hWnd != NULL) return hWnd;

	Create(hWndParent,1);
	if(hWnd)
	 {
	   Show(SW_SHOW);
	   Update();

	   bStdioQuit = bQuit;
	 }
	return hWnd;
}


//========================================================================

// FUNCTION: CreateStdioWindow(LPSTR, DWORD, int, int, int, int, HWND,
//							  HANDLE, BOOL)

// PURPOSE:  Create an I/O window with definable name, style, size, etc.

// RETURNS:  Handle to window created.

//========================================================================

HWND WSTDIO::CreateStdioWindow(LPSTR lpWindowName, DWORD dwStyle,
					   int X, int Y, int nWidth, int nHeight,
					   HWND hWndParent, HINSTANCE hInstance, bool bQuit)
{
  // if window is not already created, then create window
  if(hWnd == NULL)
  {
	hParent = hWndParent;
	hWnd = CreateWindow ( szWinName,
						lpWindowName,
						dwStyle,
						X,
						Y,
						nWidth,
						nHeight,
						hParent,
						NULL,
						hInstance,
						NULL) ;

	if(hWnd)									// if creation process was successful
	 {
	  SetPointer(hWnd,this);					// set a pointer to the class into the CbWndExtra
	  SendMessage(hWnd,WM_WIN_CREATED,0,0L);	// send a window created message to the call back function
	  bStdioQuit = bQuit;
	 }
  }
  return  hWnd; 								// return the handle to the new window
}

//========================================================================

// FUNCTION: wputc(char)

// PURPOSE:  Equivalent to putc() stdio function. Currently, '\n' is
//			 not recognized as in '\r\n', as with normal puts(). Must
//			 send '\r\n' explicitly.

// RETURNS:  Status of wopen(), if called, otherwise TRUE.

//========================================================================

bool WSTDIO::wputc(char c)
{
   char szbuf[2];
   szbuf[0] = c; szbuf[1] = 0;
   return wputs(LPSTR(szbuf));
}

//========================================================================

// FUNCTION: wputs(LPSTR)

// PURPOSE:  Equivalent to puts() stdio function. Currently, '\n' is
//			 not recognized as in '\r\n', as with normal puts(). Must
//			 send '\r\n' explicitly.

// RETURNS:  Status of wopen(), if called, otherwise TRUE.

//========================================================================


bool WSTDIO::wputs(LPSTR lpStr)
{
	HDC hDC;
	int nStrLen;

	hDC = GetDC(hWnd);
	SetupStdioDC(hWnd,hDC);
	nStrLen = lstrlen(lpStr);

	putStdio(hWnd,hDC,nStrLen,LPARAM(lpStr));

	ResetStdioDC(hDC);
	ReleaseDC(hWnd,hDC);

	return true;
}


//========================================================================

// FUNCTION: Stdio WndProc(HWND, UINT, WPARAM, LPARAM)

// PURPOSE:  Process messages for the I/O window. This function should
//			 be exported in the application's .DEF file.

//========================================================================

LRESULT WSTDIO::WndProc( HWND hwnd, UINT msg, WPARAM wParam , LPARAM lParam )
{
	 switch (msg)
	   {
		  HANDLE_MSG(hwnd,WM_PAINT,OnPaint);
		  HANDLE_MSG(hwnd,WM_SIZE,OnSize);
		  HANDLE_MSG(hwnd,WM_DESTROY,OnDestroy);
		  HANDLE_MSG(hwnd,WM_SYSCOLORCHANGE,OnColorChange);
		  HANDLE_MSG(hwnd,WM_GETMINMAXINFO,OnGetMinMax);
		  HANDLE_MSG(hwnd,WM_CHAR,OnChar);
          HANDLE_MSG(hwnd,WM_KEYUP,OnKey);

		  case WM_WIN_CREATED:
			InitStdio(hwnd);						// call the window init procedure
			return 0;
		 }

	 return DefWindowProc (hwnd, msg, wParam, lParam) ;
}


